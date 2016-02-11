#include "NFWizard2.h"
#include "ui_NFWizard2.h"
#include "FolderTreeGenerator.h"
#include "CubeInterruptFileProcessor.h"
#include "MainFilesProcessor.h"
#include "XMLKeilModify.h"

#include <QtCore>
#include <QFileDialog>
#include <QMessageBox>


NFWizard2::NFWizard2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NFWizard2)
{
    ui->setupUi(this);
    dialogConfigHelp = new DialogConfigurationHelp(this);
    dialogConfigHelp->layout()->setSizeConstraint(QLayout::SetFixedSize);
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
    generateTemplates(fileInfo.dir().path());
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

    fileInfo.setFile(fileuVision);
    fileDir = fileInfo.dir();
    fileDir.cd("Source");
    QString maincppFile = fileDir.filePath("main.cpp");
    //QString maincppFile = generateMaincpp();

    if (!MainFilesProcessor::processFiles(cubeMainFile, maincppFile)) {
        QMessageBox::warning(this, tr("NFWizard2"),tr("Error processing STM32CubeMx Src/%1 file and"
                                                      " Source/%2").arg("main.c").arg("main.cpp"));
    }
}

void NFWizard2::processXmlFiles()
{
    QDir cubeDir = QFileInfo(fileCube).dir();
    if(!cubeDir.cdUp()){
        QMessageBox::critical(this,tr("NFWizard2"),tr("Error. File not founnd."));
        return;
    }
    QFileInfoList fileList = cubeDir.entryInfoList(QStringList("*.gpdsc"),QDir::Files,QDir::Type);
    if(fileList.size() != 1){
        QMessageBox::critical(this,tr("NFWizard2"),tr("Error. File not founnd."));
        return;
    }
    XMLModifyNamespace::XMLKeilModify XmlDoc(fileuVision,fileList[0].absoluteFilePath());
    XmlDoc.updateCubeXml();
    XmlDoc.updateUvisionXml();
}

void NFWizard2::generateTemplates(const QString &projectRootRef)
{
    if (!QDir::setCurrent(projectRootRef)) {
        qDebug() << "could not switch to " << projectRootRef;
    }
    qDebug() << "Current path: " << QDir::currentPath();

    typedef QPair<QString, QString> FilePair;
    typedef QList<FilePair> FilePairList;
    FilePairList fileList;
    fileList << FilePair("://Templates/main.cpp", "Source/main.cpp")
             << FilePair("://Templates/.gitignore", ".gitignore")
             << FilePair("://Templates/README.md", "README.md")
             << FilePair("://Templates/KeilCopyLib.bat", "Scripts/KeilCopyLib.bat");
    FilePair filePair;
    bool retval = false;
    foreach (filePair, fileList) {
        retval = QFile::copy(filePair.first, filePair.second);
        if (retval) {
            QFile::setPermissions(filePair.second, QFileDevice::WriteOther);
        }else {
            qDebug() << "error coping " << filePair.second << " template" << "all ready copied?";
        }
    }
}

void NFWizard2::on_actionAbout_Qt_triggered()
{
    QApplication::aboutQt();
}

void NFWizard2::on_actionAbout_triggered()
{
    QString info;
    QTextStream infoWriter(&info);
    infoWriter << QStringLiteral("Released under Beerware license") << endl
               << QStringLiteral("Contact:") << endl
               << QStringLiteral("Ernesto Cruz Olivera: ecruzolivera@gmail.com") << endl
               << QStringLiteral("Manuel A. Linarez Páez: manuel.linares@cneuro.edu.cu") << endl;
    QMessageBox::information(this, "NFWizard 2", info);
}

void NFWizard2::on_actionUVision_Configuration_triggered()
{
    dialogConfigHelp->setWindowTitle("Keil uVision recomended Text Editor Options");
    dialogConfigHelp->setHelpImage(":/Assets/keilEditorOptions.PNG");
    dialogConfigHelp->setHelpText("Edit > Configuration > Editor");
    dialogConfigHelp->adjustSize();
    dialogConfigHelp->show();
}

void NFWizard2::on_actionSTM32CubeMx_Configuration_triggered()
{
    dialogConfigHelp->setWindowTitle("STM32CubeMx Projects Options");
    dialogConfigHelp->setHelpImage(":/Assets/Stm32CubeMxProjectOptions.PNG");
    dialogConfigHelp->setHelpText("Project > Settings > Code Generator");
    dialogConfigHelp->adjustSize();
    dialogConfigHelp->show();
}
