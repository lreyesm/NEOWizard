#include "NFWizard2.h"
#include "ui_NFWizard2.h"
#include "FolderTreeGenerator.h"
//#include "CubeInterruptFileProcessor.h"
#include "MainFilesProcessor.h"
#include "XMLKeilModify.h"
#include "TextFileProcessor.h"

#include <QtCore>
#include <QFileDialog>
#include <QMessageBox>


NFWizard2::NFWizard2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NFWizard2)
{
    ui->setupUi(this);

    //cubeVersion=QString("4.26");

    dialogConfigHelp = new DialogConfigurationHelp(this);
    dialogConfigHelp->layout()->setSizeConstraint(QLayout::SetFixedSize);
    loadSettings();
}

NFWizard2::~NFWizard2()
{
    saveSettings();
    delete ui;
}

void NFWizard2::on_pushButton_uVisionBrowse_clicked()
{
    fileuVision = QFileDialog::getOpenFileName(this, tr("Open Keil uVision Project"),
                                               fileuVision_Path,
                                               tr("uVision Project Files (*.uvprojx)"));
    if (QFile::exists(fileuVision)) {
        ui->lineEdit_uVisionPath->setText(fileuVision);
        fileuVision_Path = QFileInfo(fileuVision).dir().path();
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

void NFWizard2::processMain_H_file(const QString& main_h_path){

    TextFileProcessor main_h_FileProcessor;
    main_h_FileProcessor.setFilename(main_h_path);

    main_h_FileProcessor.setStartLine("#ifdef __cplusplus");       ////inicio del contenido a eliminar
    main_h_FileProcessor.setEndLine("#endif /* __MAIN_H__ */"); ////fin del contenido a eliminar
    main_h_FileProcessor.setReplacementString("\n/*Delete by NEOWizard*/\n\n #endif /* __MAIN_H__ */\n\n");
    main_h_FileProcessor.processMethod();



}

void NFWizard2::processMain_cpp_Error_function(const QString &main_cpp_path){

    TextFileProcessor main_cpp_FileProcessor;
    main_cpp_FileProcessor.setFilename(main_cpp_path);
                                        //// ignora espacios en blanco antes de la linea de codigo
    main_cpp_FileProcessor.setStartLine("_Error_Handler(__FILE__, __LINE__);");       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine("_Error_Handler(__FILE__, __LINE__);"); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString("/*Start of replaced code of NEOWizard*/\n     Error_Handler();\n    /*End of replaced code of NEOWizard*/\n  }\n");
    main_cpp_FileProcessor.replace_all_lines_code_instances();

}

void NFWizard2::checkCubeVersion(){

    QFileInfo fileInfo(fileCube);
    QDir fileDir(fileInfo.dir());
    fileDir.cd("Src");   // pone la direccion de Src como ruta actual para comprobar q existe main.c

    if (!fileDir.exists("main.c")) {
        QMessageBox::warning(this, tr("NFWizard2"),tr("Error STM32CubeMx Src/%1 file not found").arg("main.c"));
        return;
    }
    QString cubeMainFile = fileDir.filePath("main.c");  //almacena la direccion del main.c en cubeMainFile

    QFile file(cubeMainFile);  //comprueba q existe el archivo main.c generado por STCubeMx
    if (!file.exists()) {
        qDebug() << "file: " << file.fileName() << " not found!";
        return;
    }
    if (!file.open(QFile::ReadOnly | QFile::Text)) {  // abre el main.c generado por STCubeMX como lectura
        qDebug() << "file: " << file.fileName() << " could not be opened for read!";
        return;
    }
    QTextDocument cubeMainDoc;  //variable para guardar texto del main.c
    cubeMainDoc.setPlainText(file.readAll());  // guarda el contenido del main.c en cubeMainDoc
    file.close();

    QTextCursor cursorSysClockConfigStart = cubeMainDoc.find(QString("  * @brief System Clock Configuration")); ////si contiene este codigo es version 4.26
    QTextCursor cursorSysClockConfigEnd = cubeMainDoc.find(MainFilesProcessor::SYSCLOCK_CONFIG_END_LINE);

    if (cursorSysClockConfigStart.hasSelection() && cursorSysClockConfigEnd.hasSelection()) {
        MainFilesProcessor::SYSCLOCK_CONFIG_START_LINE = "  * @brief System Clock Configuration";
        //QMessageBox::information(this, "NEOWizard", "Selected Version 4.26 of STCubeMx \n\nIf you do not correctly select the file \nmain.cpp it is not correctly generated"/*+MainFilesProcessor::SYSCLOCK_CONFIG_START_LINE*/);
        qDebug() << "Selected Version 4.26 of STCubeMx (  \"* @brief System Clock Configuration\" en main.c) ";
        cubeVersion = QString("4.26");
    }else {
        MainFilesProcessor::SYSCLOCK_CONFIG_START_LINE = "/** System Clock Configuration";
        //QMessageBox::information(this, "NEOWizard", "Selected Version 4.20 of STCubeMx \n\nIf you do not correctly select the file \nmain.cpp it is not correctly generated"/*+MainFilesProcessor::SYSCLOCK_CONFIG_START_LINE*/);
        qDebug() << "Selected Version 4.20 of STCubeMx ( \"/** System Clock Configuration\" en main.c)";
        cubeVersion = QString("4.20");
    }

}

void NFWizard2::on_pushButton_Generate_clicked()
{
    this->checkCubeVersion();  ////chequea la version de cube a utilizar para obtener funcion sys_clock_config

    QFileInfo fileCubeInfo(fileCube);
    QFileInfo fileuVisionInfo(fileuVision);

    if (fileCubeInfo.exists() && fileuVisionInfo.exists()) {

        generateProjectFileTree(); ////Genera las carpetas necesarias y copia los templates (main.cpp)
        processInterrupFile();     ////borra las funciones de interrupcion incompatibles con keil
        processMainFiles();        //// Copia el texto de "includes", inicializacion y configuracion de perifericos y relojes del Main.c al Main.cpp

        if( cubeVersion == QString("4.26")){

            QDir fileDir(fileCubeInfo.dir());
            //fileDir.cdUp();
            processMain_H_file(fileDir.path()+QString("/Inc/main.h"));      ////Modifica el archivo main.h, para version de Cube 4.26, el cual da error al compilar en keil

            processMain_cpp_Error_function(fileuVisionInfo.dir().path()+QString("/Source/main.cpp"));
        }

        processHalConfigFile();    //// Cambia el #define TICK_INT_PRIORITY ((uint32_t)0x00U) a #define TICK_INT_PRIORITY ((uint32_t)0x0fU)
        processXmlFiles();         ////Modifica el archivo *.gpdsc para añadirle el *_it.h y *_it.c modificados
                                   ////Modifica el archivo *.uvprojx para añadirle direccion del main.cpp
    }else{
        QMessageBox::warning(this, tr("NEOWizard"),tr("Projects path not valid"));
        return;
    }
    QMessageBox::information(this, tr("NEOWizard"),tr("Project Generation complete"));

}


void NFWizard2::generateProjectFileTree()
{
    QStringList projectFolderTree;
    if (ui->checkBox_FolderStruct->isChecked()) { //genera las carpetas necesarias
        projectFolderTree << "Doc"
                          << "Include"
                          << "Lib"
                          << "Scripts"
                          << "Tests";
    }
    projectFolderTree << "Source"; // always generate Source folder
    QFileInfo fileInfo(fileuVision);
    FolderTreeGenerator::generateFileTree(fileInfo.dir().path(), projectFolderTree);
    generateTemplates(fileInfo.dir().path()); //genera los templates en la direccion del proyecto
}

void NFWizard2::processInterrupFile()
{
    QList<FunctionDelimiters> delimiters; // inicio y fin de funciones a eliminar almacenadas en esta lista de estructuras
    FunctionDelimiters systickHandler = {QStringLiteral("void SysTick_Handler(void)"),
                                         QStringLiteral("/* USER CODE END SysTick_IRQn 1 */"),
                                         QStringLiteral("\n/* Deleted by NEOWizard */\n\n")};
    delimiters << systickHandler;

    FunctionDelimiters svcHandler = {QStringLiteral("void SVC_Handler(void)"),
                                     QStringLiteral("/* USER CODE END SVCall_IRQn 1 */"),
                                     QStringLiteral("\n/* Deleted by NEOWizard */\n\n")};
    delimiters << svcHandler;

    FunctionDelimiters pendsvhandler = {QStringLiteral("void PendSV_Handler(void)"),
                                        QStringLiteral("/* USER CODE END PendSV_IRQn 1 */"),
                                        QStringLiteral("\n/* Deleted by NEOWizard */\n\n")};

    delimiters << pendsvhandler;

    QFileInfo fileInfo(fileCube);
    QDir cubeInterrupDir(fileInfo.dir());
    cubeInterrupDir.cd("Src");
    QStringList fileList = cubeInterrupDir.entryList(QStringList("*_it.c"));
    if (!cubeInterrupDir.exists(fileList.first())) { // Should be only one file
        QMessageBox::warning(this, tr("NFWizard2"),tr("Error STM32CubeMx Src/%1 file not found").arg(fileList.first()));
        return;
    }
    QDir::setCurrent(cubeInterrupDir.path());
    TextFileProcessor itFileProcessor;
    itFileProcessor.setFilename(fileList.first());
    foreach (const FunctionDelimiters &delimiter, delimiters) {  //estos son los delimitadores
        itFileProcessor.setStartLine(delimiter.startLine);       //del contenido a eliminar
        itFileProcessor.setEndLine(delimiter.endLine);
        itFileProcessor.setReplacementString(delimiter.mssg);
        itFileProcessor.processMethod();
    }
    QDir::setCurrent(fileuVision);
}

void NFWizard2::processMainFiles()
{
    QFileInfo fileInfo(fileCube);
    QDir fileDir(fileInfo.dir());
    fileDir.cd("Src");   // pone la direccion de Src como ruta actual para comprobar q existe main.c

    if (!fileDir.exists("main.c")) {
        QMessageBox::warning(this, tr("NFWizard2"),tr("Error STM32CubeMx Src/%1 file not found").arg("main.c"));
        return;
    }
    QString cubeMainFile = fileDir.filePath("main.c");  //almacena la direccion del main.c en cubeMainFile

    fileInfo.setFile(fileuVision); ////almacena la direccion de proyecto keil
    fileDir = fileInfo.dir();  //// guarda su direccion de keil en un QDir
    fileDir.cd("Source");  ////se situa en la carpeta Source de proyecto keil
    QString maincppFile = fileDir.filePath("main.cpp"); //guarda la direccion del main.cpp de la carpeta source en mainCppFile
    //QString maincppFile = generateMaincpp();

    if (!MainFilesProcessor::processFiles(cubeMainFile, maincppFile)) {  ////llama a la funcion processFiles para modificar el main.cpp
        QMessageBox::warning(this, tr("NFWizard2"),tr("Error processing STM32CubeMx Src/%1 file and"
                                                      " Source/%2").arg("main.c").arg("main.cpp"));
    }
}

void NFWizard2::processXmlFiles()
{
    ////fileCube tiene la direccion asignada al proyecto STCubeMX
    QDir cubeDir = QFileInfo(fileCube).dir();  ////Guarda la direccion de cubeDir (".../STCubeGenerated")
    if(!cubeDir.cdUp()){   ////Sube a la direccion (".../STM32F429ZITx")
        QMessageBox::critical(this,tr("NFWizard2"),tr("Error. File not founnd."));
        return;
    }
    QFileInfoList fileList = cubeDir.entryInfoList(QStringList("*.gpdsc"),QDir::Files,QDir::Type);  //Busca archivos *.gpdsc (1 solo)
    if(fileList.size() != 1){   ////Solo debe haber un archivo *.gpdsc
        QMessageBox::critical(this,tr("NFWizard2"),tr("Error. File not founnd."));
        return;
    }
    XMLModifyNamespace::XMLKeilModify XmlDoc(fileuVision,fileList[0].absoluteFilePath());  //Contructor de XMLKeilModify le pasa como parametros

    XmlDoc.updateCubeXml();    ////modifica el *.gpdsc (XML) y le añade al nodo <project_files> del XML los archivos *.c y *.h
                               ////la direccion de *.uvprojx y la direccion de *.gpdsc

    XmlDoc.updateUvisionXml();  ////modifica el archivo *.uvprojx de Keil, añade nodes con la direccion del archivo main.cpp
                                ////y cambia intancias de "Target 1" por "DEBUG"
}

void NFWizard2::processHalConfigFile()
{
    QFileInfo fileInfo(fileCube);
    QDir fileDir(fileInfo.dir());
    fileDir.cd("Inc");
    QStringList fileList = fileDir.entryList(QStringList("*_hal_conf.h"));
    if (!fileDir.exists(fileList.first())) { // Should be only one file
        QMessageBox::warning(this, tr("NFWizard2"),tr("Error STM32CubeMx Src/%1 file not found").arg(fileList.first()));
        return;
    }
    QDir::setCurrent(fileDir.path());
    TextFileProcessor halConfigFileProcessor;
    halConfigFileProcessor.setFilename(fileList.first());
    halConfigFileProcessor.setStartLine("#define  TICK_INT_PRIORITY");
    halConfigFileProcessor.setEndLine("/*!< tick interrupt priority */");
    halConfigFileProcessor.setReplacementString("#define  TICK_INT_PRIORITY            ((uint32_t)0x0fU)   /*!< tick interrupt priority */");
    halConfigFileProcessor.processTextBlock();
}

void NFWizard2::saveSettings()
{
    QSettings settings("CNEURO", "NFWizard2");
    settings.setValue("App/FileuVision", fileuVision);
    settings.setValue("App/FileuVision_Path", fileuVision_Path);
    settings.setValue("App/FileCube", fileCube);
    settings.setValue("App/LastPath", lastPath);
}

void NFWizard2::loadSettings()
{
    QSettings settings("CNEURO", "NFWizard2");
    fileuVision = settings.value("App/FileuVision", "").toString();
    fileuVision_Path = settings.value("App/FileuVision_Path", "").toString();
    fileCube = settings.value("App/FileCube","").toString();
    lastPath = settings.value("App/LastPath", QDir::homePath()).toString();

    if (!fileuVision.isEmpty()) {
        ui->lineEdit_uVisionPath->setText(fileuVision);
    }
    if (!fileCube.isEmpty()) {
        ui->lineEdit_CubePath->setText(fileCube);
    }

}

void NFWizard2::generateTemplates(const QString &projectRootRef)
{
    if (!QDir::setCurrent(projectRootRef)) {
        qDebug() << "could not switch to " << projectRootRef;
    }
    qDebug() << "Current path: " << QDir::currentPath();

    if(QFile::exists((projectRootRef)+QString("/Source/main.cpp"))){

       qDebug() << "main.cpp file exist, proceeding to erase it";

       if(!(QFile::remove((projectRootRef)+QString("/Source/main.cpp")))){
           qDebug() << "Could not remove previous main.cpp file";
    }
    }
    typedef QPair<QString, QString> FilePair;
    typedef QList<FilePair> FilePairList;
    FilePairList fileList;

    fileList << FilePair("://Templates/main.cpp", "Source/main.cpp")
             << FilePair("://Templates/.gitignore", ".gitignore")
             << FilePair("://Templates/README.md", "README.md")
             << FilePair("://Templates/KeilCopyLib.bat", "Scripts/KeilCopyLib.bat");
    FilePair filePair;
    bool retval = false;
    foreach (filePair, fileList) {  ////copia los templates (main.ccp) donde en la carpeta "Source"
        retval = QFile::copy(filePair.first, filePair.second);
        if (retval) {   ////le da permisos de escritura a los templates
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
               << QStringLiteral("Manuel A. Linarez Páez: manuel.linares@cneuro.edu.cu") << endl
               << QStringLiteral("Luis A. Reyes Morales: luis.reyes@cneuro.edu.cu") << endl;
    QMessageBox::information(this, "NEOWizard", info);
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


////Este es el slot para la version de seleccion de version de Cube, posteriormente esta automatica la seleccion
//void NFWizard2::on_comboBox_currentIndexChanged(const QString &arg1)
//{
//    if(arg1.contains(QString("4.20"))){

//        MainFilesProcessor::SYSCLOCK_CONFIG_START_LINE = "/** System Clock Configuration";
//        QMessageBox::information(this, "NEOWizard", "Selected Version 4.26 of STCubeMx \n\nIf you do not correctly select the file \nmain.cpp it is not correctly generated"/*+MainFilesProcessor::SYSCLOCK_CONFIG_START_LINE*/);
//    }
//    else if (arg1.contains(QString("4.26"))){

//        MainFilesProcessor::SYSCLOCK_CONFIG_START_LINE = "  * @brief System Clock Configuration";
//        QMessageBox::information(this, "NEOWizard", "Selected Version 4.26 of STCubeMx \n\nIf you do not correctly select the file \nmain.cpp it is not correctly generated"/*+MainFilesProcessor::SYSCLOCK_CONFIG_START_LINE*/);
//    }

//}

