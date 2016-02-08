#include "NFWizard2.h"
#include "ui_NFWizard2.h"
#include <QtCore>
#include <QFileDialog>
#include <FolderTreeGenerator.h>
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
        processMainFiles();
        processXmlFiles();
    }else{
        QMessageBox::warning(this, tr("NFWizard 2"),tr("Projects path not valid"));
    }
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
    FolderTreeGenerator::generateFileTree(fileuVision, projectFolderTree);
}

void NFWizard2::processMainFiles()
{
    QDir cubeMainDir(fileCube);
    if (!cubeMainDir.exists("Src/main.c")) {
        QMessageBox::warning(this, tr("NFWizard2"),tr("STM32CubeMx Src/main.c file not found, Generation aborted"));
        return;
    }
    qDebug() << "main found";

    TextFileParser::TextLineList_t tokenList;
    tokenList << TextFileParser::TextLinePair_t("/* Includes ------------------------------------------------------------------*/",
                                                "/* USER CODE BEGIN Includes */")
              << TextFileParser::TextLinePair_t("  /* Initialize all configured peripherals */",
                                                "  /* USER CODE BEGIN 2 */")
              << TextFileParser::TextLinePair_t("void SystemClock_Config(void)",
                                                "/* USER CODE BEGIN 4 */");

    QDir::setCurrent(cubeMainDir.path());
    TextFileParser fileParser;
    if (!fileParser.setFileName("Src/main.c")) {
        QMessageBox::warning(this, tr("NFWizard2"),tr("STM32CubeMx Src/main.c could no be opened, Generation aborted"));
        return;
    }
    fileParser.addTextLinePairList(tokenList);
    fileParser.startParsing();
}

void NFWizard2::processXmlFiles()
{

}
