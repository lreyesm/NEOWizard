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
    if(uvisionXmlFile.isEmpty()){  //Si no esta vacio el String del camino del XML de Keil (*.uvprojx)
        return false;
    }
    QFile file(uvisionXmlFile); //lo abre como lectura
    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }
    if (!xmlDocument.setContent(&file)) { //pone el contenido de este XML en xmlDocument
        file.close();
        return false;
    }
    file.close();
    QDomNode node = getNodeWithText(xmlDocument,"GroupName","Source"); //busca un nodo <GroupName> con elemento "Source"
    if(node.isNull()){  //si retorna un nodo vacio
        node = getNodeWithText(xmlDocument,"GroupName","Source Group 1"); //Busca el nodo <GroupName> con nombre "Source Group 1"
        if(node.isNull()){
            node = createGroup(xmlDocument,"Source");
        }else{
            node.firstChild().toText().setData("Source");
        }
    }

    switch(existsFilesInGroup(xmlDocument,"Source","main.cpp")){
    case NoFilesElement:
        node = getNodeWithText(xmlDocument,"GroupName","Source"); //Busca el nodo <GroupName> con nombre "Source"
        node.parentNode().appendChild(xmlDocument.createElement("Files"));
        node.nextSiblingElement("Files").  //busca el siguiente nodo <Files> y le añade
                appendChild(createFileUVision(xmlDocument,"main.cpp","8",".\\Source\\main.cpp"));
        break;
    case NoFileElement:
        node = getNodeWithText(xmlDocument,"GroupName","Source"); //Busca el nodo <GroupName> con nombre "Source"
        node.nextSiblingElement("Files").  //crea un nodo <File> con hijo: info de main.cpp
                appendChild(createFileUVision(xmlDocument,"main.cpp","8",".\\Source\\main.cpp"));
        break;
    default:
        break;
    }
    QDomNodeList list = xmlDocument.elementsByTagName("TargetName");//Busca nodo <TargetName>
    if(list.item(0).firstChild().toText().data() == "Target 1"){ //busca el primer nodo con "Target 1" de texto
        list.item(0).firstChild().toText().setData("Debug"); // le pone al texto "Debug"
    }
    list = xmlDocument.elementsByTagName("targetInfo"); //Busca nodos <targetInfo>
    for(int i=0; i<list.size(); i++){
        if(list.item(i).toElement().attributeNode("name").value() == "Target 1"){ //busca el nodo <targetInfo> con atributo nombre "Target 1"
            list.item(i).toElement().attributeNode("name").setValue("Debug"); //le cambia el nombre por "Debug"
        }
    }
    list = xmlDocument.elementsByTagName("Cads");  //Busca nodos <Cads>
    QDomElement elem = list.item(0).firstChildElement("VariousControls"); //Busca primer nodo <VariousControls>
    elem = elem.firstChildElement("Define"); //Busca primer nodo <Define>
    if(elem.text().isEmpty()){  //si no tiene texto el nodo
        elem.appendChild(xmlDocument.createTextNode("DEBUG"));//Añade al nodo <Define> un hijo con texto DEBUG
    }else if (!elem.text().contains("DEBUG")) {  //si no contiene el texto "DEBUG" lo añade
        elem.firstChild().toText().setData(elem.text().append(", DEBUG")); //añade el texto "DEBUG"
    }

    file.open(QIODevice::WriteOnly); //abre el archivo como escritura (archivo *.uvprojx)
    QTextStream outUvision(&file);   //crea un doc de texto con la direccion de archivo *.uvprojx
    xmlDocument.save(outUvision,QDomNode::EncodingFromTextStream); //Salva los cambios en el archivo *.uvprojx)
    file.close();
    return true;
}

bool XMLKeilModify::updateCubeXml(){
    if(cubeXmlFile.isEmpty()){  // Chequea si hay algo en el QString
        return false;
    }
    QFile file(cubeXmlFile); // Abre el archivo como lectura
    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }
    if (!xmlDocument.setContent(&file)){ // analiza el documento XML de los datos en bytes y lo pone como contenido del documento (variable)
        file.close();   //xmlDocument ahora tiene el XML de *.gpdsc
        return false;
    }
    file.close();
    QDomNode node = deleteAllFilesCube(xmlDocument);
    node.appendChild(xmlDocument.createElement("project_files")); // le agrega al nodo <generator> un nodo hijo <project_files>
    QDir sourceDir(QFileInfo(cubeXmlFile).dir().absolutePath().append("/STCubeGenerated/Src/"),
                   "*.c",QDir::Type,QDir::Files);  //Almacena la direccion de "/STCubeGenerated/Src/"
    QStringList filesList = sourceDir.entryList(); //Almacena una lista de los archivos *.c en "/STCubeGenerated/Src/"
    QString temp;
    for(int i=0; i<filesList.size(); i++){
        temp = filesList[i];  //Comprueba si en la lista de archivos existen los encuestados en el if
        if((!temp.contains("_hal_msp.c")) && (!temp.contains("main.c")) && (!temp.contains("system_"))){
            addFileCube(xmlDocument,"source",temp.prepend("STCubeGenerated/Src/"));
        }    //Si existen se añade al nodo <project_files> en un nodo <file> con atributo "source" y "name" la direccion del archivo "*_it.c"
    }        //aqui se añaden al XML la direccion del "*_it.c"
    sourceDir.cdUp();    //
    sourceDir.cd("Inc"); //
    addFileCube(xmlDocument,"header",sourceDir.entryInfoList(QStringList("*_it.h"),QDir::Files,QDir::Type)
                .at(0).fileName().prepend("STCubeGenerated/Inc/"));
                //Añade al nodo <project_files> un nodo <file category="header" name="STCubeGenerated/Inc/stm32f4xx_it.h"/>
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
    QDomNodeList list = doc.elementsByTagName(tag);  //devuelve una lista de los nodos <"tag">
    for(int i=0; i<list.size(); i++){
        if(list.item(i).toElement().text() == text){ //busca dentro del nodo <"tag"> con nombre "text"
            return list.item(i);  //si lo encuentra devuelve el nodo <"tag"> que posee nombre "text"
        }
    }
    return QDomNode();  //si no lo encuentra devuelve un XML vacio
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
    QDomNode groupName = getNodeWithText(doc,"GroupName",group);  //busca en XML el nodo <GroupName> con nombre "Source"
    QDomElement temp;
    if(groupName.isNull()){
        return NoGroupElement;
    }else{
        temp = groupName.parentNode().firstChildElement("Files"); //si existe Busca el nodo <Files> hijo del nodo <GroupName>
        if(temp.isNull()){
            return NoFilesElement;
        }else{
            temp = temp.firstChildElement("File"); //Busca el primer nodo <File> hijo del nodo <Files>
            while(!temp.isNull()){  //hasta q el nodo sea nulo, o sea q no hay mas nodos <FileName>
                if(temp.firstChildElement("FileName").text() != file){//busca nodo <FileName> de nombre "file"
                    return NoFileElement;  //no es el nodo q busca (el q contiene tiene <Filename> "file")
                }
                temp = temp.nextSiblingElement("File"); //devuelve el siguiente nodo <File>
            }
        }
    }
    return FileElementPresent;  //si encuentra el nodo <"group"> con nombre "file" devuelve encontrado
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
    QDomNodeList list = doc.elementsByTagName("project_files"); // devuelve un QDomList q tiene todos los nodos "project_files" en el XML
    if(list.size() > 1){                                        //(<project_files> dentro del XML)
        return QDomNode(); //si la lista es mayor q uno devuelve in QDomNode vacio (solo debe haber un <project_files>)
    }
    QDomNode parent = list.item(0).parentNode();  // retorna el padre del nodo si no tiene retorna un nodo NULL (nodo <generator> del XML)
    parent.removeChild(list.item(0)); //elimina el nodo hijo (<project_files>) devuelve el Nodo hijo (<project_files>) en caso de exito
    return parent;  // retorna el nodo <generator> del XML del STCubeMX (.gpdsc)
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
    QDomNodeList list = doc.elementsByTagName("project_files"); //Devuelve nodos (<project_files>)
    QDomElement elemTemp;
    if(list.size() > 1){
        return false;
    }
    elemTemp = doc.createElement("file"); //crea un nodo <file> en el elemTemp
    elemTemp.setAttribute("category",category); //añade un atributo "category" dentro del nodo <file>
    elemTemp.setAttribute("name",name);   //añade un atributo "name" dentro del nodo <file>
    list.item(0).appendChild(elemTemp);   //añade a nodo <project_files> el nodo hijo <file>
    return true;
}

}
