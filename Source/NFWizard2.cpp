#include "NFWizard2.h"
#include "ui_NFWizard2.h"
#include <QtCore>
#include <QFileDialog>
#include <FolderTreeGenerator.h>
#include <QMessageBox>

using namespace FileParserNamespace;

NFWizard2::NFWizard2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NFWizard2)
{
    ui->setupUi(this);
    fileCube = "";
    fileuVision = "";
}

NFWizard2::~NFWizard2()
{
    delete ui;
}

void NFWizard2::on_pushButton_uVisionBrowse_clicked()
{
    fileuVision = QFileDialog::getOpenFileName(this, tr("Open Keil uVision Project"),
                                               QDir::homePath(),
                                               tr("uVision Project Files (*.uvprojx)"));
    if (QFile::exists(fileuVision)) {
        ui->lineEdit_uVisionPath->setText(fileuVision);
        directoryuVision = QFileInfo(fileuVision).dir();
    }
}

void NFWizard2::on_pushButton_CubeBrowse_clicked()
{
    fileCube = QFileDialog::getOpenFileName(this, tr("Open STM32CubeMx Project"),
                                            QDir::homePath(),
                                            tr("STM32CubeMx Project Project Files (*.ioc)"));
    if (QFile::exists(fileCube)) {
        ui->lineEdit_CubePath->setText(fileCube);
        directoryCube = QFileInfo(fileCube).dir();
    }
}

void NFWizard2::on_pushButton_Generate_clicked()
{
    QFileInfo fileCubeInfo(fileCube);
    QFileInfo fileuVisionInfo(fileuVision);
    if (fileCubeInfo.exists() && fileuVisionInfo.exists()) {
        generateProjectFileTree();
        processMainFiles();
        processXmlFiles();
    }else{
        QMessageBox::warning(this, tr("NFWizard 2"),tr("Projects path not valid"));
    }
}

void NFWizard2::on_cubeMainFileProcessed()
{
    QFile file("main2.c");
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        qDebug()<< "could not open the file";
        return;
    }
    QTextStream fileWriter(&file);
    ParsedData parsedData = fileParser.getParsedData();
    TokenTupleList_t tokens = parsedData.keys();
    foreach (const TokenTuple_t& token, tokens) {
         fileWriter << token.first << endl
                 << parsedData.value(token)
                 << token.second << endl
                 << endl;
    }
    file.close();
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
    FolderTreeGenerator::generateFileTree(directoryuVision.path(), projectFolderTree);
}

void NFWizard2::processMainFiles()
{
    QDir cubeMainDir(directoryCube);
    if (!cubeMainDir.exists("Src/main.c")) {
        QMessageBox::warning(this, tr("NFWizard2"),tr("STM32CubeMx Src/main.c file not found, Generation aborted"));
    }
    qDebug() << "main found";

    TokenTupleList_t tokenList;
    tokenList << TokenTuple_t("/* Includes ------------------------------------------------------------------*/",
                              "/* USER CODE BEGIN Includes */")
              << TokenTuple_t("  /* Initialize all configured peripherals */",
                              "  /* USER CODE BEGIN 2 */")
              << TokenTuple_t("void SystemClock_Config(void)",
                              "/* USER CODE BEGIN 4 */");

    QDir::setCurrent(cubeMainDir.path());
    if (!fileParser.setFileName("Src/main.c")) {

    }
    fileParser.addTokenTupleList(tokenList);
    connect(&fileParser, SIGNAL(parsingFinished()), this, SLOT(on_cubeMainFileProcessed()));
    fileParser.startParsing();
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
