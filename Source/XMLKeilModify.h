#ifndef XMLKEILMODIFY_H
#define XMLKEILMODIFY_H

#include <QtCore>
#include <QDomDocument>
#include <QDomNode>
#include <QDir>

namespace XMLModifyNamespace {

enum FilePresent{
    NoGroupElement,NoFilesElement,NoFileElement,FileElementPresent
};

class XMLKeilModify
{
public:
    XMLKeilModify();
    XMLKeilModify(const QString& uvisionFile, const QString& cubeFile);
    void setUvisionXmlFile(const QString& dir);
    void setCubeXmlFile(const QString& dir);
    bool updateUvisionXml();
    bool updateCubeXml();

private:
    QString uvisionXmlFile;
    QString cubeXmlFile;
    QDomDocument xmlDocument;

    QDomNode getNodeWithText(QDomDocument& doc,QString tag,QString text);
    void changeGroupName(QDomDocument& doc,QString oldGroupName,QString newGroupName);
    QDomElement createFileUVision(QDomDocument& doc,QString name,QString type,QString path);
    void deleteFileUVision(QDomDocument& doc,QString groupName,QString fileName);
    QDomNode createGroup(QDomDocument& doc,QString name);
    FilePresent existsFilesInGroup(QDomDocument& doc,QString group,QString file);
    QDomNode existsFileCube(QDomDocument& doc,QString fileName);
    QDomNode deleteAllFilesCube(QDomDocument& doc);
    bool deleteFileCube(QDomDocument& doc,QString fileName);
    bool addFileCube(QDomDocument& doc,QString category,QString name);
};//XMLKeilModify

}//XMLModifyNamespace


#endif // XMLKEILMODIFY_H
