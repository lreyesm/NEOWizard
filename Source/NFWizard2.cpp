#include "NFWizard2.h"
#include "ui_NFWizard2.h"
#include "FolderTreeGenerator.h"
#include "CubeInterruptFileProcessor.h"
#include "MainFilesProcessor.h"

#include <QtCore>
#include <QFileDialog>
#include <QMessageBox>


NFWizard2::NFWizard2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NFWizard2)
{
    ui->setupUi(this);
    fileCube = "";
    fileuVision = "";
    lastPath = QDir::homePath();
}

NFWizard2::~NFWizard2()
{
    delete ui;
}

void NFWizard2::on_pushButton_uVisionBrowse_clicked()
{
    fileuVision = QFileDialog::getOpenFileName(this, tr("Open Keil uVision Project"),
                                               lastPath,
                                               tr("uVision Project Files (*.uvprojx)"));
    if (QFile::exists(fileuVision)) {
        ui->lineEdit_uVisionPath->setText(fileuVision);
        lastPath = QFileInfo(fileuVision).dir().path();
    }
}

void NFWizard2::on_pushButton_CubeBrowse_clicked()
{
    fileCube = QFileDialog::getOpenFileName(this, tr("Open STM32CubeMx Project"),
                                            lastPath,
                                            tr("STM32CubeMx Project Project Files (*.ioc)"));
    if (QFile::exists(fileCube)) {
        ui->lineEdit_CubePath->setText(fileCube);
        lastPath = QFileInfo(fileCube).dir().path();
    }
}

void NFWizard2::on_pushButton_Generate_clicked()
{
    QFileInfo fileCubeInfo(fileCube);
    QFileInfo fileuVisionInfo(fileuVision);
    if (fileCubeInfo.exists() && fileuVisionInfo.exists()) {
        generateProjectFileTree();
        processInterrupFile();
        processMainFiles();
        processXmlFiles();
    }else{
        QMessageBox::warning(this, tr("NFWizard 2"),tr("Projects path not valid"));
        return;
    }
    QMessageBox::information(this, tr("NFWizard 2"),tr("Project Generation complete"));
}


void NFWizard2::generateProjectFileTree()
{
    QStringList projectFolderTree;
    if (ui->checkBox_FolderStruct->isChecked()) {
        projectFolderTree << "Doc"
                          << "Include"
                          << "Lib"
                          << "Scripts"
                          << "Tests";
    }
    projectFolderTree << "Source"; // always generate Source folder
    QFileInfo fileInfo(fileuVision);
    FolderTreeGenerator::generateFileTree(fileInfo.dir().path(), projectFolderTree);

    if (!QDir::setCurrent(fileInfo.dir().path())) {
        qDebug() << "could not switch to " << fileInfo.dir().path();
    }
        qDebug() << "Current path: " << QDir::currentPath();

    if (!QFile::copy("://Templates/main.cpp", "Source/main.cpp")) {
        qDebug() << "error coping main.cpp template";
    }
    if (!QFile::copy("://Templates/.gitignore", ".gitignore")) {
        qDebug() << "error coping gitignore template";
    }
    if (!QFile::copy("://Templates/README.md", "README.md")) {
        qDebug() << "error coping README template";
    }
    if (!QFile::copy("://Templates/KeilCopyLib.bat", "Scripts/KeilCopyLib.bat")) {
        qDebug() << "error coping KeilCopyLib template";
    }
}

void NFWizard2::processInterrupFile()
{
    QFileInfo fileInfo(fileCube);
    QDir cubeInterrupDir(fileInfo.dir());
    cubeInterrupDir.cd("Src");
    QStringList fileList = cubeInterrupDir.entryList(QStringList("*_it.c"));
    if (!cubeInterrupDir.exists(fileList.first())) { // Should be only one file
        QMessageBox::warning(this, tr("NFWizard2"),tr("Error STM32CubeMx Src/%1 file not found").arg(fileList.first()));
        return;
    }
    QDir::setCurrent(cubeInterrupDir.path());
    if (!CubeInterruptFileProcessor::processFile(fileList.first())) {
        QMessageBox::warning(this, tr("NFWizard2"),tr("Error processing STM32CubeMx Src/%1 file").arg(fileList.first()));
    }
    QDir::setCurrent(fileuVision);
}

QString NFWizard2::generateMaincpp()
{
    QFileInfo fileInfo(fileuVision);
    QDir uVisionDir(fileInfo.dir());
    uVisionDir.cd("Source");
    if (!uVisionDir.exists("main.cpp")) {
        //TODO: copy main.cpp template to Source/
    }
    return uVisionDir.filePath("main.cpp");
}

void NFWizard2::processMainFiles()
{
    QFileInfo fileInfo(fileCube);
    QDir fileDir(fileInfo.dir());
    fileDir.cd("Src");

    if (!fileDir.exists("main.c")) {
        QMessageBox::warning(this, tr("NFWizard2"),tr("Error STM32CubeMx Src/%1 file not found").arg("main.c"));
        return;
    }
    QString cubeMainFile = fileDir.filePath("main.c");
    QString maincppFile = generateMaincpp();

    if (!MainFilesProcessor::processFiles(cubeMainFile, maincppFile)) {
        QMessageBox::warning(this, tr("NFWizard2"),tr("Error processing STM32CubeMx Src/%1 file and"
                                                      " Source/%2").arg("main.c").arg("main.cpp"));
    }
}

void NFWizard2::processXmlFiles()
{
    QDir cubeDir = QFileInfo(fileCube).dir();
    cubeDir.cdUp();
    QFileInfoList fileList = cubeDir.entryInfoList(QStringList("*.gpdsc"),QDir::Files,QDir::Type);
    if(fileList.size() > 1){
        return;
    }
    XMLModifyNamespace::XMLKeilModify XmlDoc(fileuVision,fileList[0].absoluteFilePath());
    XmlDoc.updateCubeXml();
    XmlDoc.updateUvisionXml();
}
