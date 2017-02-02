#include "XMLKeilModify.h"

namespace XMLModifyNamespace {

XMLKeilModify::XMLKeilModify()
{

}

XMLKeilModify::XMLKeilModify(const QString &uvisionFile, const QString &cubeFile)
{
    setCubeXmlFile(cubeFile);
    setUvisionXmlFile(uvisionFile);
}

bool XMLKeilModify::updateUvisionXml(){
    if(uvisionXmlFile.isEmpty()){
        return false;
    }
    QFile file(uvisionXmlFile);
    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }
    if (!xmlDocument.setContent(&file)) {
        file.close();
        return false;
    }
    file.close();
    QDomNode node = getNodeWithText(xmlDocument,"GroupName","Source");
    if(node.isNull()){
        node = getNodeWithText(xmlDocument,"GroupName","Source Group 1");
        if(node.isNull()){
            node = createGroup(xmlDocument,"Source");
        }else{
            node.firstChild().toText().setData("Source");
        }
    }

    switch(existsFilesInGroup(xmlDocument,"Source","main.cpp")){
    case NoFilesElement:
        node = getNodeWithText(xmlDocument,"GroupName","Source");
        node.parentNode().appendChild(xmlDocument.createElement("Files"));
        node.nextSiblingElement("Files").
                appendChild(createFileUVision(xmlDocument,"main.cpp","8",".\\Source\\main.cpp"));
        break;
    case NoFileElement:
        node = getNodeWithText(xmlDocument,"GroupName","Source");
        node.nextSiblingElement("Files").
                appendChild(createFileUVision(xmlDocument,"main.cpp","8",".\\Source\\main.cpp"));
        break;
    default:
        break;
    }
    QDomNodeList list = xmlDocument.elementsByTagName("TargetName");
    if(list.item(0).firstChild().toText().data() == "Target 1"){
        list.item(0).firstChild().toText().setData("Debug");
    }
    list = xmlDocument.elementsByTagName("targetInfo");
    for(int i=0; i<list.size(); i++){
        if(list.item(i).toElement().attributeNode("name").value() == "Target 1"){
            list.item(i).toElement().attributeNode("name").setValue("Debug");
        }
    }
    list = xmlDocument.elementsByTagName("Cads");
    QDomElement elem = list.item(0).firstChildElement("VariousControls");
    elem = elem.firstChildElement("Define");
    if(elem.text().isEmpty()){
        elem.appendChild(xmlDocument.createTextNode("DEBUG"));
    }else if (!elem.text().contains("DEBUG")) {
        elem.firstChild().toText().setData(elem.text().append(", DEBUG"));
    }

    file.open(QIODevice::WriteOnly);
    QTextStream outUvision(&file);
    xmlDocument.save(outUvision,QDomNode::EncodingFromTextStream);
    file.close();
    return true;
}

bool XMLKeilModify::updateCubeXml(){
    if(cubeXmlFile.isEmpty()){
        return false;
    }
    QFile file(cubeXmlFile);
    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }
    if (!xmlDocument.setContent(&file)) {
        file.close();
        return false;
    }
    file.close();
    QDomNode node = deleteAllFilesCube(xmlDocument);
    node.appendChild(xmlDocument.createElement("project_files"));
    QDir sourceDir(QFileInfo(cubeXmlFile).dir().absolutePath().append("/STCubeGenerated/Src/"),
                   "*.c",QDir::Type,QDir::Files);
    QStringList filesList = sourceDir.entryList();
    QString temp;
    for(int i=0; i<filesList.size(); i++){
        temp = filesList[i];
        if((!temp.contains("_hal_msp.c")) && (!temp.contains("main.c")) && (!temp.contains("system_"))){
            addFileCube(xmlDocument,"source",temp.prepend("STCubeGenerated/Src/"));
        }
    }
    sourceDir.cdUp();
    sourceDir.cd("Inc");
    addFileCube(xmlDocument,"header",sourceDir.entryInfoList(QStringList("*_it.h"),QDir::Files,QDir::Type)
                .at(0).fileName().prepend("STCubeGenerated/Inc/"));

    file.open(QIODevice::WriteOnly);
    QTextStream outCube(&file);
    xmlDocument.save(outCube,2);
    file.close();
    return true;
}

void XMLKeilModify::setCubeXmlFile(const QString &dir){
    if(!dir.isNull() && dir.contains(".gpdsc")){
        cubeXmlFile = dir;
    }
}

void XMLKeilModify::setUvisionXmlFile(const QString &dir){
    if(!dir.isNull() && dir.contains(".uvprojx")){
        uvisionXmlFile = dir;
    }
}

QDomNode XMLKeilModify::getNodeWithText(QDomDocument& doc,QString tag,QString text){
    QDomNodeList list = doc.elementsByTagName(tag);
    for(int i=0; i<list.size(); i++){
        if(list.item(i).toElement().text() == text){
            return list.item(i);
        }
    }
    return QDomNode();
}

void XMLKeilModify::changeGroupName(QDomDocument& doc,QString oldGroupName,QString newGroupName){
    QDomNode group = getNodeWithText(doc,"GroupName",oldGroupName);
    if(!group.isNull()){
        group.firstChild().toText().setData(newGroupName);
    }
}

QDomElement XMLKeilModify::createFileUVision(QDomDocument& doc,QString name,QString type,QString path){
    QDomElement temp;
    QDomText textTemp;
    QDomElement newFile;
    //Create File element.
    newFile = doc.createElement("File");
    //Create FileName element.
    temp = doc.createElement("FileName");
    newFile.appendChild(temp);
    //Create FileType element.
    temp = doc.createElement("FileType");
    newFile.appendChild(temp);
    //Create FilePath element.
    temp = doc.createElement("FilePath");
    newFile.appendChild(temp);
    //Create text element for the file name
    temp = newFile.firstChildElement();
    textTemp = doc.createTextNode(name);
    temp.appendChild(textTemp);
    //Create text element for the file type
    temp = temp.nextSiblingElement();
    textTemp = doc.createTextNode(type);
    temp.appendChild(textTemp);
    //Create text element for the file path
    temp = temp.nextSiblingElement();
    textTemp = doc.createTextNode(path);
    temp.appendChild(textTemp);
    return newFile;
}

void XMLKeilModify::deleteFileUVision(QDomDocument& doc,QString groupName,QString fileName){
    QDomNode group = getNodeWithText(doc,"GroupName",groupName);
    QDomElement filesElem = group.nextSiblingElement();
    QDomElement fileTemp = filesElem.firstChildElement();
    while(!fileTemp.isNull()){
        if(fileTemp.firstChildElement("FileName").text() == fileName){
            filesElem.removeChild(fileTemp);
        }
        fileTemp = fileTemp.nextSiblingElement();
    }
}

QDomNode XMLKeilModify::createGroup(QDomDocument& doc,QString name){
    QDomElement group = doc.createElement("Group");
    doc.elementsByTagName("Groups").item(0).toElement().appendChild(group);
    QDomElement temp = doc.createElement("GroupName");
    group.appendChild(temp);
    group = group.firstChildElement();
    QDomText text = doc.createTextNode(name);
    group.appendChild(text);
    return group;
}

FilePresent XMLKeilModify::existsFilesInGroup(QDomDocument& doc,QString group,QString file){
    QDomNode groupName = getNodeWithText(doc,"GroupName",group);
    QDomElement temp;
    if(groupName.isNull()){
        return NoGroupElement;
    }else{
        temp = groupName.parentNode().firstChildElement("Files");
        if(temp.isNull()){
            return NoFilesElement;
        }else{
            temp = temp.firstChildElement("File");
            while(!temp.isNull()){
                if(temp.firstChildElement("FileName").text() != file){
                    return NoFileElement;
                }
                temp = temp.nextSiblingElement("File");
            }
        }
    }
    return FileElementPresent;
}

QDomNode XMLKeilModify::existsFileCube(QDomDocument& doc,QString fileName){
    QDomNodeList list = doc.elementsByTagName("project_files");
    QDomElement elemTemp;
    if(list.size() > 1){
        return QDomNode();
    }
    elemTemp = list.item(0).firstChildElement();
    while(!elemTemp.isNull()){
        if(elemTemp.attribute("name").contains(fileName)){
            return elemTemp;
        }
        elemTemp = elemTemp.nextSiblingElement();
    }
    return QDomNode();
}

QDomNode XMLKeilModify::deleteAllFilesCube(QDomDocument& doc){
    QDomNodeList list = doc.elementsByTagName("project_files");
    if(list.size() > 1){
        return QDomNode();
    }
    QDomNode parent = list.item(0).parentNode();
    parent.removeChild(list.item(0));
    return parent;
}

bool XMLKeilModify::deleteFileCube(QDomDocument& doc,QString fileName){
    QDomNode temp = existsFileCube(doc,fileName);
    if(!temp.isNull()){
        temp.parentNode().removeChild(temp);
        return true;
    }
    return false;
}

bool XMLKeilModify::addFileCube(QDomDocument& doc,QString category,QString name){
    QDomNodeList list = doc.elementsByTagName("project_files");
    QDomElement elemTemp;
    if(list.size() > 1){
        return false;
    }
    elemTemp = doc.createElement("file");
    elemTemp.setAttribute("category",category);
    elemTemp.setAttribute("name",name);
    list.item(0).appendChild(elemTemp);
    return true;
}

}
