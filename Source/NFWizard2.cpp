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


    generate_project_folders = false;
    ui->mainToolBar->hide();
    ui->menuBar->hide();
    ui->statusBar->hide();

    //this->windows_appearence();
    this->hide_all_objects();
    this->show_generate();


    dialogConfigHelp = new DialogConfigurationHelp(this);
    //dialogConfigHelp->layout()->setSizeConstraint(QLayout::SetFixedSize);
    loadSettings();
}

NFWizard2::~NFWizard2()
{
    saveSettings();
    delete ui;
}

//void NFWizard2::windows_appearence(){

//    /*
//    ui->centralWidget->setPalette(QPalette(QColor(48,60,77)));
//    ui->centralWidget->setAutoFillBackground(true);

//    ui->statusBar->hide();

//    ////Configuracion de line edits de la app--------------------------------------------------------------------------------------------------------------
//    /// ------------------------------------------------------------------------------------------------------------------------------------------------
//    ui->lineEdit_uVisionPath->setStyleSheet(QStringLiteral("color: #555555; font: 11pt Myriad  Web;") + "border-image: url(NFWizard_icons/line_edit.png);");
//    ui->lineEdit_uVisionPath->setFixedSize(QSize(353,21));

//    ui->lineEdit_CubePath->setStyleSheet(QStringLiteral("color: #555555; font: 11pt Myriad  Web;") + "border-image: url(NFWizard_icons/line_edit.png);");
//    ui->lineEdit_CubePath->setFixedSize(QSize(353,21));

//    /// ------------------------------------------------------------------------------------------------------------------------------------------------



//    ////Configuracion de botones de la app--------------------------------------------------------------------------------------------------------------
//    /// ------------------------------------------------------------------------------------------------------------------------------------------------
//    ui->pushButton_CubeBrowse->setFlat(true);
//    ui->pushButton_CubeBrowse->setIcon((QIcon("NFWizard_icons/button_browse.png")));
//    ui->pushButton_CubeBrowse->setIconSize(QSize(85,21));
//    ui->pushButton_CubeBrowse->setFixedSize(85,21);

//    ui->pushButton_uVisionBrowse->setFlat(true);
//    ui->pushButton_uVisionBrowse->setIcon((QIcon("NFWizard_icons/button_browse.png")));
//    ui->pushButton_uVisionBrowse->setIconSize(QSize(85,21));
//    ui->pushButton_uVisionBrowse->setFixedSize(85,21);

//    ui->pushButton_Generate->setFlat(true);
//    ui->pushButton_Generate->setIcon((QIcon("NFWizard_icons/button_generate.png")));
//    ui->pushButton_Generate->setIconSize(QSize(84,22));
//    ui->pushButton_Generate->setFixedSize(84,22);

//    ui->pushButton_Quit->setFlat(true);
//    ui->pushButton_Quit->setIcon((QIcon("NFWizard_icons/button_quit.png")));
//    ui->pushButton_Quit->setIconSize(QSize(85,21));
//    ui->pushButton_Quit->setFixedSize(84,22);

//    ui->pushButton_generate_folders->setFlat(true);
//    ui->pushButton_generate_folders->setIcon((QIcon("NFWizard_icons/check_box_generate_project_folders.png")));
//    ui->pushButton_generate_folders->setIconSize(QSize(170,18));
//    ui->pushButton_generate_folders->setFixedSize(170,18);

//    ui->pushButton_Generate_tag->setFlat(true);
//    ui->pushButton_Generate_tag->setIcon((QIcon("NFWizard_icons/label_generate.png")));
//    ui->pushButton_Generate_tag->setIconSize(QSize(80,27));
//    ui->pushButton_Generate_tag->setFixedSize(75,27);
//    ui->pushButton_Generate_tag->move(0,1);

//    ui->pushButton_Help_tag->setFlat(true);
//    ui->pushButton_Help_tag->setIcon((QIcon("NFWizard_icons/label_help.png")));
//    ui->pushButton_Help_tag->setIconSize(QSize(23,27));
//    ui->pushButton_Help_tag->setFixedSize(75,27);
//    ui->pushButton_Help_tag->move(150,2);

//    ui->pushButton_Options_tag->setFlat(true);
//    ui->pushButton_Options_tag->setIcon((QIcon("NFWizard_icons/label_options.png")));
//    ui->pushButton_Options_tag->setIconSize(QSize(75,27));
//    ui->pushButton_Options_tag->setFixedSize(75,27);
//    ui->pushButton_Options_tag->move(75,2);

//    ui->pb_uVision_Config->setFlat(true);
//    ui->pb_uVision_Config->setStyleSheet(QStringLiteral("color: #DDDDDD; font: 11pt Segoe  UI;"));
//    //ui->pb_uVision_Config->setIconSize(QSize(75,27));
//    //ui->pb_uVision_Config->setFixedSize(75,27);

//    ui->pb_Stcube_Config->setFlat(true);
//    ui->pb_Stcube_Config->setStyleSheet(QStringLiteral("color: #DDDDDD; font: 11pt Segoe  UI;"));
//    //ui->pb_Stcube_Config->setIconSize(QSize(75,27));
//    //ui->pb_Stcube_Config->setFixedSize(75,27);

//    ui->pb_about_NEOW->setFlat(true);
//    ui->pb_about_NEOW->setStyleSheet(QStringLiteral("color: #DDDDDD; font: 11pt Segoe  UI;"));
//    //ui->pb_about_NEOW->setIconSize(QSize(75,27));
//    //ui->pb_about_NEOW->setFixedSize(75,27);

//    ui->pb_about_QT->setFlat(true);
//    ui->pb_about_QT->setStyleSheet(QStringLiteral("color: #DDDDDD; font: 11pt Segoe  UI;"));
//    //ui->pb_about_QT->setIconSize(QSize(75,27));
//    //ui->pb_about_QT->setFixedSize(75,27);

//    /// ------------------------------------------------------------------------------------------------------------------------------------------------



//    ////Configuracion de labels de la app--------------------------------------------------------------------------------------------------------------
//    /// ------------------------------------------------------------------------------------------------------------------------------------------------

//    ui->label_bar_background->setPixmap(QPixmap("NFWizard_icons/label_background_line.png"));
//    ui->label_bar_background->setFixedSize(QSize(640,27));
//    ui->label_bar_background->move(0,0);
//    ui->label_bar_background->lower();

//    ui->label_bar_selection->setPixmap(QPixmap("NFWizard_icons/label_selection.png"));
//    ui->label_bar_selection->setFixedSize(QSize(77,2));
//    ui->label_bar_selection->move(0,25);

//    ui->label_Cube->setPixmap(QPixmap("NFWizard_icons/label_cube.png"));
//    ui->label_Cube->setFixedSize(QSize(174,19));
//    //ui->label_Cube->move(387,192);

//    ui->label_uVision->setPixmap(QPixmap("NFWizard_icons/label_uVision.png"));
//    ui->label_uVision->setFixedSize(QSize(96,18));
//    //ui->label_uVision->move(387,192);

//    ui->label_generate_options->setPixmap(QPixmap("NFWizard_icons/label_generate_options.png"));
//    ui->label_generate_options->setFixedSize(QSize(120,19));
//    //ui->label_generate_options->move(387,192);

//    /// ------------------------------------------------------------------------------------------------------------------------------------------------

//    */

//    ////Configuracion de Widgets de posicion de la app--------------------------------------------------------------------------------------------------------------
//    /// ------------------------------------------------------------------------------------------------------------------------------------------------

//    ui->widget_dirs->move(90,40);

//    ui->widget_generate_options->move(90,180);

//    ui->widget_buttons_quit->move(310,230);

//    ui->widget_help_buttons->move(150,27);

//    //ui->widget_help_buttons->setStyleSheet(QStringLiteral("background: #15AC70; color: #DDDDDD; font: 11pt Segoe  UI;"));

//    /// ------------------------------------------------------------------------------------------------------------------------------------------------

//}

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

    if(cubeVersion == QString("4.26")){

        QString microcontroller_used;

        if(fileCube.contains("STM32F4")){

            microcontroller_used = QString("STM32F4_SELECTED  0");
        }
        else if(fileCube.contains("STM32F7")){

            microcontroller_used = QString("STM32F7_SELECTED  1");
        }

        main_h_FileProcessor.setStartLine("#ifdef __cplusplus");       ////inicio del contenido a eliminar
        main_h_FileProcessor.setEndLine("#endif /* __MAIN_H__ */"); ////fin del contenido a eliminar
        main_h_FileProcessor.setReplacementString(QString("\n/*Delete by NEOWizard*/\n\n/*Define by NEOWizard*/\n #define ")+microcontroller_used+QString("\n/*End of Define by NEOWizard*/\n\n#endif /* __MAIN_H__ */\n\n"));
        main_h_FileProcessor.processMethod();

        return;
    }

    if(cubeVersion == QString("4.20")){


    }
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

void NFWizard2::processMain_cpp_Clock_erro_code(const QString &main_cpp_path){

    TextFileProcessor main_cpp_FileProcessor;
    main_cpp_FileProcessor.setFilename(main_cpp_path);
                                        //// ignora espacios en blanco antes de la linea de codigo
    main_cpp_FileProcessor.setStartLine("RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSE;");       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine("RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSE;"); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString("/*Start of replaced code of NEOWizard*/\n  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;\n  /*End of replaced code of NEOWizard*/\n\n");
    main_cpp_FileProcessor.replace_all_lines_code_instances();

}
void NFWizard2::checkCubeVersion(){

    QFileInfo fileInfo(fileCube);
    QDir fileDir(fileInfo.dir());
    fileDir.cd("Src");   // pone la direccion de Src como ruta actual para comprobar q existe main.c

    if (!fileDir.exists("main.c")) {
        QMessageBox::warning(this, tr("NFWizard2"),tr("<font color = white >Error STM32CubeMx Src/%1 file not found").arg("main.c"));
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
        //QMessageBox::information(this, "NEOWizard", "<font color = white >Selected Version 4.26 of STCubeMx \n\nIf you do not correctly select the file \nmain.cpp it is not correctly generated"/*+MainFilesProcessor::SYSCLOCK_CONFIG_START_LINE*/);
        qDebug() << "Selected Version 4.26 of STCubeMx (  \"* @brief System Clock Configuration\" en main.c) ";
        cubeVersion = QString("4.26");
    }else {
        MainFilesProcessor::SYSCLOCK_CONFIG_START_LINE = "/** System Clock Configuration";
        //QMessageBox::information(this, "NEOWizard", "<font color = white >Selected Version 4.20 of STCubeMx \n\nIf you do not correctly select the file \nmain.cpp it is not correctly generated"/*+MainFilesProcessor::SYSCLOCK_CONFIG_START_LINE*/);
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

            processMain_H_file(fileDir.path()+QString("/Inc/main.h"));      ////Modifica el archivo main.h, para version de Cube 4.26, el cual da error al compilar en keil

            processMain_cpp_Error_function(fileuVisionInfo.dir().path()+QString("/Source/main.cpp"));

        }
        processMain_cpp_Clock_erro_code(fileuVisionInfo.dir().path()+QString("/Source/main.cpp"));

        processHalConfigFile();    //// Cambia el #define TICK_INT_PRIORITY ((uint32_t)0x00U) a #define TICK_INT_PRIORITY ((uint32_t)0x0fU)
        processXmlFiles();         ////Modifica el archivo *.gpdsc para añadirle el *_it.h y *_it.c modificados
                                   ////Modifica el archivo *.uvprojx para añadirle direccion del main.cpp
    }else{
        QMessageBox::warning(this, tr("NEOWizard"),tr("<font color = white >Projects path not valid"));
        return;
    }
    QMessageBox::information(this, tr("NEOWizard"),tr("<font color = white >Project Generation complete"));

}


void NFWizard2::generateProjectFileTree()
{
    QStringList projectFolderTree;
    if (generate_project_folders) { //genera las carpetas necesarias
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
        QMessageBox::warning(this, tr("NFWizard2"),tr("<font color = white >Error STM32CubeMx Src/%1 file not found").arg(fileList.first()));
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
        QMessageBox::warning(this, tr("NFWizard2"),tr("<font color = white >Error STM32CubeMx Src/%1 file not found").arg("main.c"));
        return;
    }
    QString cubeMainFile = fileDir.filePath("main.c");  //almacena la direccion del main.c en cubeMainFile

    fileInfo.setFile(fileuVision); ////almacena la direccion de proyecto keil
    fileDir = fileInfo.dir();  //// guarda su direccion de keil en un QDir
    fileDir.cd("Source");  ////se situa en la carpeta Source de proyecto keil
    QString maincppFile = fileDir.filePath("main.cpp"); //guarda la direccion del main.cpp de la carpeta source en mainCppFile
    //QString maincppFile = generateMaincpp();

    if (!MainFilesProcessor::processFiles(cubeMainFile, maincppFile)) {  ////llama a la funcion processFiles para modificar el main.cpp
        QMessageBox::warning(this, tr("NFWizard2"),tr("<font color = white >Error processing STM32CubeMx Src/%1 file and"
                                                      " Source/%2").arg("main.c").arg("main.cpp"));
    }
}

void NFWizard2::processXmlFiles()
{
    ////fileCube tiene la direccion asignada al proyecto STCubeMX
    QDir cubeDir = QFileInfo(fileCube).dir();  ////Guarda la direccion de cubeDir (".../STCubeGenerated")
    if(!cubeDir.cdUp()){   ////Sube a la direccion (".../STM32F429ZITx")
        QMessageBox::critical(this,tr("NFWizard2"),tr("<font color = white >Error. File not founnd."));
        return;
    }
    QFileInfoList fileList = cubeDir.entryInfoList(QStringList("*.gpdsc"),QDir::Files,QDir::Type);  //Busca archivos *.gpdsc (1 solo)
    if(fileList.size() != 1){   ////Solo debe haber un archivo *.gpdsc
        QMessageBox::critical(this,tr("NFWizard2"),tr("<font color = white >Error. File not founnd."));
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
        QMessageBox::warning(this, tr("NFWizard2"),tr("<font color = white >Error STM32CubeMx Src/%1 file not found").arg(fileList.first()));
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

    /*  Codigo añadido para eliminar main.cpp generado con versiones anteriores de NFWizard
     * el cual no es compatible porque NEOWizard busca otras lineas de codigo para remplazar
     * cofiguracion de relojes y remplazar las funciones de _Error_Handler(file, file)
     *
     * if(QFile::exists((projectRootRef)+QString("/Source/main.cpp"))){

       qDebug() << "main.cpp file exist, proceeding to erase it";

       if(!(QFile::remove((projectRootRef)+QString("/Source/main.cpp")))){
           qDebug() << "Could not remove previous main.cpp file";
       }
    }
    */
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
    QMessageBox::information(this, "<font color = white >NEOWizard", info);
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
//        QMessageBox::information(this, "NEOWizard", "<font color = white >Selected Version 4.26 of STCubeMx \n\nIf you do not correctly select the file \nmain.cpp it is not correctly generated"/*+MainFilesProcessor::SYSCLOCK_CONFIG_START_LINE*/);
//    }
//    else if (arg1.contains(QString("4.26"))){

//        MainFilesProcessor::SYSCLOCK_CONFIG_START_LINE = "  * @brief System Clock Configuration";
//        QMessageBox::information(this, "NEOWizard", "<font color = white >Selected Version 4.26 of STCubeMx \n\nIf you do not correctly select the file \nmain.cpp it is not correctly generated"/*+MainFilesProcessor::SYSCLOCK_CONFIG_START_LINE*/);
//    }

//}


void NFWizard2::on_pushButton_generate_folders_clicked()
{
    if(generate_project_folders == false){

         generate_project_folders = true;
         //ui->lineEdit_CubePath->setText("true");
         ui->pushButton_generate_folders->setStyleSheet( QStringLiteral("background-color: rgb(89, 99, 113);") + "border-image: url(:/Assets/check_box_on.png);");
    }
    else{

         generate_project_folders = false;
         //ui->lineEdit_CubePath->setText("false");
         ui->pushButton_generate_folders->setStyleSheet( QStringLiteral("background-color: rgb(89, 99, 113);") + "border-image: url(:/Assets/check_box_off.png);");
    }
}

void NFWizard2::on_pushButton_Quit_clicked()
{
     this->close();
}

void NFWizard2::on_pushButton_Help_tag_clicked()
{
    this->hide_all_objects();
    this->show_help();
}

void NFWizard2::on_pushButton_Options_tag_clicked()
{
    this->hide_all_objects();
    this->show_options();
}

void NFWizard2::on_pushButton_Generate_tag_clicked()
{
     this->hide_all_objects();
     this->show_generate();
}

void NFWizard2::hide_all_objects(){

    ui->pushButton_Generate_tag->setStyleSheet( QStringLiteral("background-color: rgb(89, 99, 113);") + "border-image: url(:/Assets/generate_tag_off.png);");
    ui->pushButton_Generate_tag->setFixedSize(56,18);
    ui->pushButton_Generate_tag->move(20,10);
    ui->pushButton_Help_tag->setStyleSheet( QStringLiteral("background-color: rgb(89, 99, 113);") + "border-image: url(:/Assets/help_tag_off.png);");
    ui->pushButton_Help_tag->setFixedSize(29,19);
    ui->pushButton_Help_tag->move(210,8);
    ui->pushButton_Options_tag->setStyleSheet( QStringLiteral("background-color: rgb(89, 99, 113);") + "border-image: url(:/Assets/options_tag_off.png);");
    ui->pushButton_Options_tag->setFixedSize(49,19);
    ui->pushButton_Options_tag->move(115,8);

    ui->widget_help_buttons->hide();

    ui->widget_buttons_quit->hide();
    ui->widget_dirs->hide();
    ui->widget_generate_options->hide();
}

void NFWizard2::show_generate(){

    ui->widget_buttons_quit->show();
    ui->widget_dirs->show();
    ui->widget_generate_options->show();

    ui->pushButton_Generate_tag->setStyleSheet( QStringLiteral("background-color: rgb(89, 99, 113);") + "border-image: url(:/Assets/generate_tag_on.png);");
    ui->pushButton_Generate_tag->setFixedSize(92,24);
    ui->pushButton_Generate_tag->move(0,9);
}

void NFWizard2::show_help(){

    ui->widget_help_buttons->show();

    ui->pushButton_Help_tag->setStyleSheet( QStringLiteral("background-color: rgb(89, 99, 113);") + "border-image: url(:/Assets/help_tag_on.png);");
    ui->pushButton_Help_tag->setFixedSize(67,25);
    ui->pushButton_Help_tag->move(190,8);
}

void NFWizard2::show_options(){

    ui->pushButton_Options_tag->setStyleSheet( QStringLiteral("background-color: rgb(89, 99, 113);") + "border-image: url(:/Assets/options_tag_on.png);");
    ui->pushButton_Options_tag->setFixedSize(103,25);
    ui->pushButton_Options_tag->move(90,8);
}

void NFWizard2::on_pb_uVision_Config_clicked()
{
    on_actionUVision_Configuration_triggered();
}

void NFWizard2::on_pb_Stcube_Config_clicked()
{
    on_actionSTM32CubeMx_Configuration_triggered();
}

void NFWizard2::on_pb_about_NEOW_clicked()
{
    on_actionAbout_triggered();
}

void NFWizard2::on_pb_about_QT_clicked()
{
    on_actionAbout_Qt_triggered();
}
