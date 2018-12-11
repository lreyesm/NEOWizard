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
#include <QMouseEvent>


NFWizard2::NFWizard2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NFWizard2)
{
    ui->setupUi(this);


    generate_project_folders = false;
    ui->mainToolBar->hide();
    ui->menuBar->hide();
    //ui->statusBar->hide();

    this->windows_widget_position();
    current_positions_minus_one =0;
    hide_all_objects();
    this->show_generate();
    this->set_points();

    connect(this,SIGNAL(check_warnings()),this,SLOT(check_for_warnings()));

    dialogConfigHelp = new DialogConfigurationHelp(this);
    //dialogConfigHelp->layout()->setSizeConstraint(QLayout::SetFixedSize);
    loadSettings();

}

NFWizard2::~NFWizard2()
{
    saveSettings();

    delete ui;
}

void NFWizard2::windows_widget_position(){

    this->setGeometry(200,200,1200,460);

    //ui->widget_state_machine_name->move((int)(this->geometry().width()/2), (int)(this->geometry().height()/2));

    ui->widget_options->move(0,0);
    ui->widget_add_delete_event->move(500,140);
    ui->pb_warning_state_machine->move(392,77);
    ui->widget_state_machine_name->move(500,140);
    ui->widget_layout_state_machine->move(370,0);
    ui->widget_options_buttons->move(90,80);
    ui->widget_options_thread_options->move(350,40);
    ui->widget_event_options->move(400,90);

    ui->pb_warning_state_machine->setParent(ui->widget_states);
    ui->pb_warning_state_machine->move(5,5);

    ui->widget_wait->setParent(ui->widget_states);
    ui->label_loading->setStyleSheet(QStringLiteral("background-color: rgb(48, 60, 77); color: rgb(21, 172, 112); font: 28pt \"Segoe UI\";"));
    ui->widget_wait->move(ui->widget_states->geometry().width()/2-ui->widget_wait->geometry().width()/2,
                     ui->widget_states->geometry().height()/2-ui->widget_wait->geometry().height()/2);

    ui->pb_configure_state_machine->setStyleSheet(QStringLiteral("color: rgb(21, 172, 112); font: 11pt \"Segoe UI\";"));
    ui->pb_configure_Main_thread->setStyleSheet(QStringLiteral("color: rgb(21, 172, 112); font: 11pt \"Segoe UI\";"));
    ui->pb_configure_thread_in_class->setStyleSheet(QStringLiteral("color: rgb(21, 172, 112); font: 11pt \"Segoe UI\";"));
    ui->pb_configure_thread_in_main->setStyleSheet(QStringLiteral("color: rgb(21, 172, 112); font: 11pt \"Segoe UI\";"));

    ui->pb_back->setStyleSheet(QStringLiteral("color: rgb(21, 172, 112); font: 11pt \"Segoe UI\";"));
    ui->pb_add_state->setStyleSheet(QStringLiteral("color: rgb(21, 172, 112); font: 11pt \"Segoe UI\";"));
    ui->pb_generate_state_machine->setStyleSheet(QStringLiteral("color: rgb(21, 172, 112); font: 11pt \"Segoe UI\";"));

    ui->pb_add_thread->setStyleSheet(QStringLiteral("color: rgb(21, 172, 112); font: 11pt \"Segoe UI\"; "));
    ui->cb_thread_priority->setStyleSheet(QStringLiteral("color: rgb(255, 245, 242); background-color: rgb(21, 172, 112); font: 11pt \"Segoe UI\";"));

    //ui->pb_ok->setStyleSheet(QStringLiteral("background-color: rgb(48, 60, 77); color: rgb(21, 172, 112); font: 11pt \"Segoe UI\";"));
    ui->pb_warning_state_machine->setStyleSheet(QStringLiteral("background-image: url(:/Assets/warning.png); background-color: rgb(89, 99, 113);"));
}

void NFWizard2::on_pushButton_uVisionBrowse_clicked()
{
    fileuVision = QFileDialog::getOpenFileName(this, tr("Open Keil uVision Project"),
                                               fileuVision_Path,
                                               tr("uVision Project Files (*.uvprojx)"));
    if (QFile::exists(fileuVision)) {
        ui->lineEdit_uVisionPath->setText(fileuVision);
        fileuVision_Path = QFileInfo(fileuVision).dir().path();
        if(!lastPath.contains(fileuVision_Path)){

            lastPath = fileuVision_Path+QString("/RTE/Device");
        }
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
    main_cpp_FileProcessor.setStartLine("void SystemClock_Config(void);");       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine("void Error_Handler(void);"); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString("/*Start of replaced code of NEOWizard*/\nvoid SystemClock_Config(void);\n/*End of replaced code of NEOWizard*/\n\n");
    main_cpp_FileProcessor.replace_all_lines_code_instances();

    main_cpp_FileProcessor.setStartLine("void Error_Handler(void)");       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine("void Error_Handler(void)"); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString("/*Start of replaced code of NEOWizard*/\nvoid _Error_Handler(char *file, int line)\n/*End of replaced code of NEOWizard*/\n{\n");
    main_cpp_FileProcessor.replace_all_lines_code_instances();

}

void NFWizard2::processMain_cpp_Clock_error_code(const QString &main_cpp_path){

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

            //QDir fileDir(fileCubeInfo.dir());

            //processMain_H_file(fileCubeInfo.dir().path()+QString("/Inc/main.h"));      ////Modifica el archivo main.h, para version de Cube 4.26, el cual da error al compilar en keil

            processMain_cpp_Error_function(fileuVisionInfo.dir().path()+QString("/Source/main.cpp"));

        }
        processMain_cpp_Clock_error_code(fileuVisionInfo.dir().path()+QString("/Source/main.cpp")); ////borra codigo de Error HSI\HSE generado por StCubeMx

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

void NFWizard2::process_Thread_in_Main_cpp_File(const QString thread_name, const QString main_thread_name, const QString thread_priority){

    TextFileProcessor main_cpp_FileProcessor;

    main_cpp_FileProcessor.setFilename(fileuVision_Path+QString("/Source/")+main_thread_name+QString(".cpp"));

    main_cpp_FileProcessor.setStartLine(main_thread_name+QString("::")+main_thread_name+QString("()"));       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine(main_thread_name+QString("::")+main_thread_name+QString("()")); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString(main_thread_name+QString("::")+main_thread_name+QString("():\n               ")
                                                +thread_name+QString("(")+thread_name+QString("Run,eObject::eThread::Priority")
                                                +thread_priority+QString(")"));
    main_cpp_FileProcessor.processTextBlock();

    main_cpp_FileProcessor.setStartLine("/*Threads Functions Implementation Generated Code*/");       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine("/*Threads Functions Implementation Generated Code*/"); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString(QString("/*Threads Functions Implementation Generated Code*/\n")
                                                +QString("void ")+main_thread_name
                                                +QString("::")+thread_name
                                                +QString("Run(eObject::eThread &thread)\n{\n\n}"));
    main_cpp_FileProcessor.processTextBlock();

}

void NFWizard2::process_Thread_in_Main_h_File(const QString thread_name, const QString main_thread_name){

    TextFileProcessor main_h_FileProcessor;

    main_h_FileProcessor.setFilename(fileuVision_Path+QString("/Include/")+main_thread_name+QString(".h"));

    main_h_FileProcessor.setStartLine("#include <eApplicationBase.h>");       ////inicio del contenido a eliminar
    main_h_FileProcessor.setEndLine("#include <eApplicationBase.h>"); ////fin del contenido a eliminar
    main_h_FileProcessor.setReplacementString(QString("#include <eApplicationBase.h>\n")+QString("#include <eThread.h>\n"));
    main_h_FileProcessor.processTextBlock();

    main_h_FileProcessor.setStartLine("/*User declare thread objects*/");       ////inicio del contenido a eliminar
    main_h_FileProcessor.setEndLine("/*User declare thread objects*/"); ////fin del contenido a eliminar
    main_h_FileProcessor.setReplacementString(QString("/*User declare thread objects*/\n")+QString("    eObject::eThread ")+thread_name+QString(";\n"));
    main_h_FileProcessor.processTextBlock();

    main_h_FileProcessor.setStartLine("/*User declare thread objects functions*/");       ////inicio del contenido a eliminar
    main_h_FileProcessor.setEndLine("/*User declare thread objects functions*/"); ////fin del contenido a eliminar
    main_h_FileProcessor.setReplacementString(QString("/*User declare thread objects functions*/\n")+QString("    static void ")+thread_name+QString("Run(eObject::eThread &thread);\n"));
    main_h_FileProcessor.processTextBlock();
}

void NFWizard2::process_Main_Thread_Files(const QString thread_name){

    TextFileProcessor main_cpp_FileProcessor;

    ////procesamiento del main_thread_name.h----------------------------------------------------------------------------------------------------------

    main_cpp_FileProcessor.setFilename(fileuVision_Path+QString("/Include/")+thread_name+QString(".h"));
                                        //// ignora espacios en blanco antes de la linea de codigo

    main_cpp_FileProcessor.setStartLine("#ifndef MAIN_THREAD_TEMPLATE_H");       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine("#define MAIN_THREAD_TEMPLATE_H"); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString(QString("#ifndef ")+thread_name.toUpper()+QString("_H\n")+QString("#define ")+thread_name.toUpper()+QString("_H\n"));
    main_cpp_FileProcessor.processTextBlock();

    main_cpp_FileProcessor.setStartLine("class Main_Thread_Template:public eObject::eApplicationBase<Main_Thread_Template>");       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine("class Main_Thread_Template:public eObject::eApplicationBase<Main_Thread_Template>"); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString(QString("class ")+thread_name+QString(":public eObject::eApplicationBase<")+thread_name+QString(">"));
    main_cpp_FileProcessor.processTextBlock();

    main_cpp_FileProcessor.setStartLine("Main_Thread_Template();");       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine("Main_Thread_Template();"); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString(thread_name+QString("();"));
    main_cpp_FileProcessor.processTextBlock();

    main_cpp_FileProcessor.setStartLine("#endif // MAIN_THREAD_TEMPLATE_H");       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine("#endif // MAIN_THREAD_TEMPLATE_H"); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString(QString("#endif // ")+thread_name.toUpper()+QString("_H"));
    main_cpp_FileProcessor.processTextBlock();

    ////-------------------------------------------------------------------------------------------------------------------------------------------

    ////Procesamiento del main_thread_name.cpp----------------------------------------------------------------------------------------------------------

    main_cpp_FileProcessor.setFilename(fileuVision_Path+QString("/Source/")+thread_name+QString(".cpp"));

    main_cpp_FileProcessor.setStartLine("#include \"Main_Thread_Template.h\"");       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine("#include \"Main_Thread_Template.h\""); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString(QString("#include \"")+thread_name+QString(".h\""));
    main_cpp_FileProcessor.processTextBlock();

    main_cpp_FileProcessor.setStartLine("Main_Thread_Template::Main_Thread_Template()");       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine("Main_Thread_Template::Main_Thread_Template()"); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString(thread_name+QString("::")+thread_name+QString("()"));
    main_cpp_FileProcessor.processTextBlock();

    main_cpp_FileProcessor.setStartLine("void Main_Thread_Template::userLoop()");       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine("void Main_Thread_Template::userLoop()"); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString(QString("void ")+thread_name+QString("::userLoop()"));
    main_cpp_FileProcessor.processTextBlock();
    ////-------------------------------------------------------------------------------------------------------------------------------------------

    processMainFile_add_Main_Thread_Exec(thread_name,fileuVision_Path+QString("/Source/main.cpp"));
}

void NFWizard2::processMainFile_add_Main_Thread_Exec(const QString thread_name, const QString main_cpp_dir){

    TextFileProcessor main_cpp_FileProcessor;
    main_cpp_FileProcessor.setFilename(main_cpp_dir);
                                        //// ignora espacios en blanco antes de la linea de codigo
    if(main_cpp_FileProcessor.check_if_code_exist(QString("#include \"")+thread_name+QString(".h\""),false)==0){

        main_cpp_FileProcessor.setStartLine("/* USER CODE BEGIN Includes */");       ////inicio del contenido a eliminar
        main_cpp_FileProcessor.setEndLine("/* USER CODE BEGIN Includes */"); ////fin del contenido a eliminar
        main_cpp_FileProcessor.setReplacementString(QString("/* USER CODE BEGIN Includes */\n#include \"")+thread_name+QString(".h\"\n"));
        main_cpp_FileProcessor.processTextBlock();
    }
    else{
        QMessageBox::information(this, "NEOWizard", QString("<font color = white >The code in main.cpp to include this main thread was already in the file"));
    }
    if(main_cpp_FileProcessor.check_if_code_exist("app.exec();",false)==0){

        main_cpp_FileProcessor.setStartLine("/* USER CODE BEGIN 2 */");       ////inicio del contenido a eliminar
        main_cpp_FileProcessor.setEndLine("/* USER CODE BEGIN 2 */"); ////fin del contenido a eliminar
        main_cpp_FileProcessor.setReplacementString(QString("/* USER CODE BEGIN 2 */\n\n  ")+QString("app.exec();"));
        main_cpp_FileProcessor.processTextBlock();
    }
    else{
        QMessageBox::information(this, "NEOWizard", QString("<font color = white >The code in main.cpp to execute this main thread was already in the file"));
    }
    if(main_cpp_FileProcessor.check_if_code_exist(thread_name+QString(" app;"),false)==0){

        main_cpp_FileProcessor.setStartLine("/* USER CODE BEGIN 2 */");       ////inicio del contenido a eliminar
        main_cpp_FileProcessor.setEndLine("/* USER CODE BEGIN 2 */"); ////fin del contenido a eliminar
        main_cpp_FileProcessor.setReplacementString(QString("/* USER CODE BEGIN 2 */\n\n  ")+thread_name+QString(" app;"));
        main_cpp_FileProcessor.processTextBlock();
    }
    else{
        QMessageBox::information(this, "NEOWizard", QString("<font color = white >The code in main.cpp to declare an object of this main thread was already in the file"));
    }
}

void NFWizard2::process_Thread_Files(const QString thread_name){

    TextFileProcessor main_cpp_FileProcessor;


    ////procesamiento del thread_name.h----------------------------------------------------------------------------------------------------------

    main_cpp_FileProcessor.setFilename(fileuVision_Path+QString("/Include/")+thread_name+QString(".h"));
                                        //// ignora espacios en blanco antes de la linea de codigo
                                        ///
    main_cpp_FileProcessor.setStartLine("#ifndef THREAD_NAME_H");       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine("#define THREAD_NAME_H"); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString(QString("#ifndef ")+thread_name.toUpper()+QString("_H\n")+QString("#define ")+thread_name.toUpper()+QString("_H\n"));
    main_cpp_FileProcessor.processTextBlock();

    main_cpp_FileProcessor.setStartLine("class Thread_Name : public eObject::eSingletonStaticBase<Thread_Name>");       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine("class Thread_Name : public eObject::eSingletonStaticBase<Thread_Name>"); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString(QString("class ")+thread_name+QString(" : public eObject::eSingletonStaticBase<")+thread_name+QString(">"));
    main_cpp_FileProcessor.processTextBlock();

    main_cpp_FileProcessor.setStartLine("Thread_Name();");       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine("Thread_Name();"); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString(thread_name+QString("();"));
    main_cpp_FileProcessor.processTextBlock();

    main_cpp_FileProcessor.setStartLine("eObject::eThread Thread_Name_Instance;");       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine("eObject::eThread Thread_Name_Instance;"); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString(QString("eObject::eThread ")+thread_name+QString("_Instance;"));
    main_cpp_FileProcessor.processTextBlock();

    main_cpp_FileProcessor.setStartLine("static void Thread_Name_Run(eObject::eThread &threadInstance);");       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine("static void Thread_Name_Run(eObject::eThread &threadInstance);"); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString(QString("static void ")+thread_name+QString("_Run(eObject::eThread &threadInstance);"));
    main_cpp_FileProcessor.processTextBlock();

    main_cpp_FileProcessor.setStartLine("inline eObject::eThread& Thread_Name::getThreadInstance(void)");       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine("inline eObject::eThread& Thread_Name::getThreadInstance(void)"); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString(QString("inline eObject::eThread& ")+thread_name+QString("::getThreadInstance(void)"));
    main_cpp_FileProcessor.processTextBlock();

    main_cpp_FileProcessor.setStartLine("return this->Thread_Name_Instance;");       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine("return this->Thread_Name_Instance;"); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString(QString("return this->")+thread_name+QString("_Instance;"));
    main_cpp_FileProcessor.processTextBlock();

    main_cpp_FileProcessor.setStartLine("#endif // THREAD_NAME_H");       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine("#endif // THREAD_NAME_H"); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString(QString("#endif // ")+thread_name.toUpper()+QString("_H"));
    main_cpp_FileProcessor.processTextBlock();
    ////-------------------------------------------------------------------------------------------------------------------------------------------


    ////Procesamiento del thread_name.cpp----------------------------------------------------------------------------------------------------------

    main_cpp_FileProcessor.setFilename(fileuVision_Path+QString("/Source/")+thread_name+QString(".cpp"));

    main_cpp_FileProcessor.setStartLine("#include \"Thread_Name.h\"");       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine("#include \"Thread_Name.h\""); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString(QString("#include \"")+thread_name+QString(".h\""));
    main_cpp_FileProcessor.processTextBlock();

    main_cpp_FileProcessor.setStartLine("Thread_Name::Thread_Name() : eSingletonStaticBase(this),Thread_Name_Instance(Thread_Name_Run, eThread::PriorityNormal)");       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine("Thread_Name::Thread_Name() : eSingletonStaticBase(this),Thread_Name_Instance(Thread_Name_Run, eThread::PriorityNormal)"); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString(thread_name+QString("::")+thread_name+QString("() : eSingletonStaticBase(this),")+thread_name+QString("_Instance(")+thread_name+QString("_Run, eThread::Priority")+ui->cb_thread_priority->currentText()+QString(")"));
    main_cpp_FileProcessor.processTextBlock();

    main_cpp_FileProcessor.setStartLine("Thread_Name_Instance.start();");       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine("Thread_Name_Instance.start();"); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString(QString("//")+thread_name+QString("_Instance.start();"));
    main_cpp_FileProcessor.processTextBlock();

    main_cpp_FileProcessor.setStartLine("void Thread_Name::Thread_Name_Run(eThread &threadInstance)");       ////inicio del contenido a eliminar
    main_cpp_FileProcessor.setEndLine("void Thread_Name::Thread_Name_Run(eThread &threadInstance)"); ////fin del contenido a eliminar
    main_cpp_FileProcessor.setReplacementString(QString("void ")+thread_name+QString("::")+thread_name+QString("_Run(eThread &threadInstance)"));
    main_cpp_FileProcessor.processTextBlock();
    ////-------------------------------------------------------------------------------------------------------------------------------------------

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

void NFWizard2::processXmlFiles_for_Threads(const QString thread_name){

    XMLModifyNamespace::XMLKeilModify XmlDoc;  ////Contructor de XMLKeilModify le pasa como parametros

    XmlDoc.setUvisionXmlFile(fileuVision);

    XmlDoc.updateUvisionXml_for_Threads(thread_name);  ////modifica el archivo *.uvprojx de Keil, añade nodes con la direccion del archivo thread_name.cpp

}


void NFWizard2::processXmlFiles()
{
    ////fileCube tiene la direccion asignada al proyecto STCubeMX
    QDir cubeDir = QFileInfo(fileCube).dir();  ////Guarda la direccion de cubeDir (".../STCubeGenerated")
    if(!cubeDir.cdUp()){   ////Sube a la direccion (".../STM32F429ZITx")
        QMessageBox::critical(this,tr("NFWizard2"),tr("<font color = white >Error. File not founnd."));
        return;
    }
    QFileInfoList fileList = cubeDir.entryInfoList(QStringList("*.gpdsc"),QDir::Files,QDir::Type);  ////Busca archivos *.gpdsc (1 solo)
    if(fileList.size() != 1){   ////Solo debe haber un archivo *.gpdsc
        QMessageBox::critical(this,tr("NFWizard2"),tr("<font color = white >Error. File not founnd."));
        return;
    }
    XMLModifyNamespace::XMLKeilModify XmlDoc(fileuVision,fileList[0].absoluteFilePath());  ////Contructor de XMLKeilModify le pasa como parametros

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

int NFWizard2::generateTemplates_for_Thread(const QString &projectRootRef,const QString thread_name){ ////Copia los templates thread.h y cpp en /Source/

    if (!QDir::setCurrent(projectRootRef)) {
        qDebug() << "could not switch to " << projectRootRef;
        QMessageBox::warning(this, "NEOWizard", QString("<font color = white >Coud not locate project folders \n Please generate project folders \n in \"Generate\" window or set location of uVision Project"));
         return -1;
    }
    qDebug() << "Current path: " << QDir::currentPath();

    typedef QPair<QString, QString> FilePair;
    typedef QList<FilePair> FilePairList;
    FilePairList fileList;

    if(add_thread_state == Thread_in_Class){
        fileList << FilePair("://Templates/thread_template.cpp", QString("Source/")+thread_name+QString(".cpp"))
                 << FilePair("://Templates/thread_template.h", QString("Include/")+thread_name+QString(".h"));
    }
    else if(add_thread_state == Main_Thead){

        fileList << FilePair("://Templates/main_thread_template.cpp", QString("Source/")+thread_name+QString(".cpp"))
                 << FilePair("://Templates/main_thread_template.h", QString("Include/")+thread_name+QString(".h"));
    }
    FilePair filePair;
    bool retval = false;

    foreach (filePair, fileList) {  ////copia los templates (main.ccp) donde en la carpeta "Source"
        retval = QFile::copy(filePair.first, filePair.second);
        if (retval) {   ////le da permisos de escritura a los templates
            QFile::setPermissions(filePair.second, QFileDevice::WriteOther);
        }else {
            QMessageBox::warning(this, "NEOWizard", QString("<font color = white >Could not generate project folders <br>May be there is already a file with that name in the project direction"));
            return 0;
        }
    }
    return 1;
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
    hide_all_objects();

    this->show_help();
}

void NFWizard2::show_update_tree_view(const bool expand, const QString item_name_parent, const QString item_name){

    ui->tw_state_machine->show();
    ui->tw_state_machine->clear();
    ui->tw_state_machine->setStyleSheet(QStringLiteral("color: rgb(21, 172, 112); font: 10pt \"Segoe UI\";"));

    QList<QTreeWidgetItem*> items;

    for(quint16 i=0;i< hierarchy_states.size();i++){

        items.append(new QTreeWidgetItem(QStringList(hierarchy_states[i]->get_state_name())));
                //QString name = items[i]->text(0);
    }

    for(quint16 i=0;i< hierarchy_states.size();i++){

        if(hierarchy_states[i]->get_state_parent()=="No Parent"){

            ui->tw_state_machine->addTopLevelItem(items[i]);
        }

        for(quint16 n=0; n< hierarchy_states[i]->get_direct_SubStates().size();n++){

            int index = get_state_index_with_name(hierarchy_states[i]->get_direct_SubStates()[n]);

            items[i]->addChild(items[index]);

        }

    }
    quint16 c=0;
    if(expand){
        for(quint16 i=0; i< items.size();i++){

            QString n = items[i]->text(0);

            if(item_name_parent == n){

                items[i]->setExpanded(true);
                c=i;
                break;
            }
        }
    }

    if(expand){
        QTreeWidgetItem* item;
        item = items[c];
        while(item->parent()!=NULL){
            item->parent()->setExpanded(true);
            item = item->parent();
        }
    }
    if(item_name!="Empty"){
        for(quint16 i=0; i< items.size();i++){

            QString n = items[i]->text(0);

            if(item_name == n){

                items[i]->setSelected(true);
                break;
            }
        }
    }

}

void NFWizard2::on_pushButton_Options_tag_clicked()
{
    hide_all_objects();
    this->show_options();
}

void NFWizard2::on_pushButton_Generate_tag_clicked()
{
     hide_all_objects();
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

    ui->widget_wait->hide();

    ui->tw_state_machine->hide();
    ui->widget_events->hide();
    ui->widget_add_delete_event->hide();

    ui->pb_warning_state_machine->hide();
    if(ui->pb_configure_state_machine->text()=="Back"){

        on_pb_configure_state_machine_clicked();
    }
    ui->widget_help_buttons->hide();

    ui->widget_buttons_quit->hide();
    ui->widget_dirs->hide();
    ui->widget_generate_options->hide();

    ui->widget_options_buttons->hide();
    ui->widget_options_thread_options->hide();
    ui->widget_layout_state_machine->hide();
    ui->widget_on_state_options->hide();

    ui->widget_event_options->hide();
    ui->le_state_to_search->hide();
    ui->pb_acept_main_thread->hide();

    ui->widget_state_machine_name->hide();
    ui->pb_load_state_machine->hide();
    ui->pb_load_from_Thread->hide();
    ui->pb_save_state_machine->hide();

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
    ui->widget_options_buttons->show();
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

int NFWizard2::check_if_compatible(const QString path, const QString main_thread_name, const QString header_source_quest, const QString line_code){

    TextFileProcessor main_FileProcessor;

    QString header_source = "";
    QString extension="";

    if(header_source_quest == "header"){

        header_source = "/Include/";
        extension = ".h";
    }
    else{
        header_source = "/Source/";
        extension = ".cpp";
    }

    main_FileProcessor.setFilename(path + header_source + main_thread_name + extension);

    return main_FileProcessor.check_if_code_exist(line_code, false);
}

void NFWizard2::on_pb_add_thread_clicked()
{
    if(!ui->le_thread_name->isHidden()){
        if(ui->le_thread_name->text().isEmpty()){

            QMessageBox::information(this, "NEOWizard", QString("<font color = white >Please add thread name"));
            return;
        }
    }
    if(!ui->le_main_thread_name->isHidden()){
        if(ui->le_main_thread_name->text().isEmpty()){

            QMessageBox::information(this, "NEOWizard", QString("<font color = white >Please add main thread name"));
            return;
        }
    }

    if(QMessageBox::information(this,"Confirmation","Add Thread?",QMessageBox::Ok,QMessageBox::Cancel)!=QMessageBox::Ok){
        return;
    }

    ui->widget_options_thread_options->hide();

    QFileInfo fileInfo(fileuVision);

    if(add_thread_state==Thread_in_Class){

        int retval = generateTemplates_for_Thread(fileInfo.dir().path(), ui->le_thread_name->text());////copia los templates para las carpetas del projecto
        if(retval == 0 || retval == 1){

            process_Thread_Files(ui->le_thread_name->text());
            processXmlFiles_for_Threads(ui->le_thread_name->text()); ////modifica XML de keil
            QMessageBox::information(this, "NEOWizard", QString("<font color = white >Thread generated correctly\nPlease save changes in uVision project"));
        }
    }
    if(add_thread_state==Main_Thead){

        if(generateTemplates_for_Thread(fileInfo.dir().path(), ui->le_main_thread_name->text())>=0){////copia los templates para las carpetas del projecto

            process_Main_Thread_Files(ui->le_main_thread_name->text());
            processXmlFiles_for_Threads(ui->le_main_thread_name->text()); ////modifica XML de keil
            QMessageBox::information(this, "NEOWizard", QString("<font color = white >Main Thread is generated correctly\nPlease save changes in uVision project"));
        }
    }
    if(add_thread_state==Thread_in_Main){

        int retval = check_if_compatible(fileInfo.dir().path(), ui->le_main_thread_name->text(), "header", "/*User declare thread objects*/");
        if(retval==0){

            QMessageBox::warning(this, "NEOWizard", QString("<font color = white >You need to add the code : /*User declare thread objects*/ <br>in the public section of your Main Thread header file.<br>NEOWizar will try to add it whitout your intervention."));
            retval = generate_guide_code_Main_Thread_h(fileInfo.dir().path(), ui->le_main_thread_name->text());
            if(retval==1){

                QMessageBox::information(this, "NEOWizard", QString("<font color = white >The automatic code adding worked fine"));
            }
            else if(retval ==-1){

                QMessageBox::information(this, "NEOWizard", QString("<font color = white >File not found, check if the project has the generate folders <br>or check the name of your Main Thread"));
                return;
            }
            else if(retval ==-2){

                QMessageBox::information(this, "NEOWizard", QString("<font color = white >Header File cannot be open for read, please try again"));
                return;

            }
            else if(retval ==-3){

                QMessageBox::information(this, "NEOWizard", QString("<font color = white >The Header file could not be written, please try again"));
                return;

            }
            else if(retval ==-4){

                QMessageBox::information(this, "NEOWizard", QString("<font color = white >Please remove spaces between -> \"private\" and \":\" in your main thread class, then try again"));
                return;

            }
            else if(retval ==0){

                QMessageBox::information(this, "NEOWizard", QString("<font color = white >Please add a private seccion in your Main Thread class -> \"private:\" , then try again"));
                return;

            }

        }
        else if(retval ==-1){

            QMessageBox::information(this, "NEOWizard", QString("<font color = white >Header File not found, check if the project has the generate folders <br>or check the name of your Main Thread"));
            return;
        }
        else if(retval ==-2){

            QMessageBox::information(this, "NEOWizard", QString("<font color = white >Header File cannot be open for read, please try again"));
            return;

        }
        this->process_Thread_in_Main_h_File(ui->le_thread_name->text(), ui->le_main_thread_name->text());

        retval = check_if_compatible(fileInfo.dir().path(), ui->le_main_thread_name->text(), "source", "/*Threads Functions Implementation Generated Code*/");
        if(retval == 0){

            QMessageBox::warning(this, "NEOWizard", QString("<font color = white >You need to add the code : /*Threads Functions Implementation Generated Code*/ <br>in your Main Thread source file.<br>NEOWizar will try to add it whitout your intervention."));

            retval = generate_guide_code_Main_Thread_cpp(fileInfo.dir().path(), ui->le_main_thread_name->text());
            if(retval==1){

                QMessageBox::information(this, "NEOWizard", QString("<font color = white >The automatic code adding worked fine"));
            }
            else if(retval==0){

                QMessageBox::information(this, "NEOWizard", QString("<font color = white >Add constructor implementation to your Main Thread Class, then try again"));
            }
            else if(retval ==-1){

                QMessageBox::information(this, "NEOWizard", QString("<font color = white >Source File not found, check if the project has the generate folders <br>or check the name of your Main Thread"));
                return;
            }
            else if(retval ==-2){

                QMessageBox::information(this, "NEOWizard", QString("<font color = white >Source File cannot be open for read, please try again"));
                return;

            }
            else if(retval ==-3){

                QMessageBox::information(this, "NEOWizard", QString("<font color = white >The Source file could not be written, please try again"));
                return;

            }

        }
        else if(retval ==-1){

            QMessageBox::information(this, "NEOWizard", QString("<font color = white >Source File not found, check if the project has the generate folders <br>or check the name of your Main Thread"));
            return;
        }
        else if(retval ==-2){

            QMessageBox::information(this, "NEOWizard", QString("<font color = white >Source File cannot be open for read, please try again"));
            return;

        }
        process_Thread_in_Main_cpp_File(ui->le_thread_name->text(), ui->le_main_thread_name->text(),ui->cb_thread_priority->currentText());

        QMessageBox::information(this, "NEOWizard", QString("<font color = white >Thread in Main :")+ui->le_thread_name->text()+QString(" generated correctly <br>Please save changes in uVision project"));
    }
}

int NFWizard2::generate_guide_code_Main_Thread_h(const QString path, const QString main_thread_name){

    TextFileProcessor main_FileProcessor;

    main_FileProcessor.setFilename(path + "/Include/" + main_thread_name + ".h");


    if(main_FileProcessor.check_if_code_exist("eObject::eThread "+ui->le_thread_name->text(), false)==1){

        QMessageBox::information(this, "NEOWizard", QString("<font color = white >Thread in Main :")+ui->le_thread_name->text()+QString(" already declare in header file of Main Thread"));
        return 2;
    }

    return main_FileProcessor.generate_code_in_main_thread_h();
}

int NFWizard2::generate_guide_code_Main_Thread_cpp(const QString path, const QString main_thread_name){

    TextFileProcessor main_FileProcessor;

    main_FileProcessor.setFilename(path + "/Source/" + main_thread_name + ".cpp");

    return main_FileProcessor.generate_code_in_main_thread_cpp(main_thread_name);
}

void NFWizard2::on_pb_configure_thread_in_class_clicked()
{
  add_thread_state = Thread_in_Class;
  ui->widget_options_thread_options->show();
  ui->le_thread_name->show();
  ui->l_thread_name->show();
  ui->l_thread_priority->show();
  ui->cb_thread_priority->show();
  ui->le_main_thread_name->hide();
  ui->l_main_thread_name->hide();
  ui->widget_layout_state_machine->hide();
}

void NFWizard2::on_pb_configure_thread_in_main_clicked()
{
   add_thread_state = Thread_in_Main;
   ui->widget_options_thread_options->show();
   ui->le_thread_name->show();
   ui->l_thread_name->show();
   ui->l_thread_priority->show();
   ui->cb_thread_priority->show();
   ui->le_main_thread_name->show();
   ui->l_main_thread_name->show();
   ui->widget_layout_state_machine->hide();
}

void NFWizard2::on_pb_configure_Main_thread_clicked()
{
    add_thread_state = Main_Thead;
    ui->widget_options_thread_options->show();
    ui->le_main_thread_name->show();
    ui->l_main_thread_name->show();
    ui->le_thread_name->hide();
    ui->l_thread_name->hide();
    ui->l_thread_priority->hide();
    ui->cb_thread_priority->hide();
    ui->widget_layout_state_machine->hide();

}

void NFWizard2::on_pb_configure_state_machine_clicked()
{
    if(ui->pb_configure_state_machine->text()!="Back"){

        ui->widget_layout_state_machine->show();
        ui->widget_state_info->hide();
        ui->widget_options_thread_options->hide();
        ui->pb_configure_state_machine->setText("Back");
        ui->pb_load_state_machine->show();
        ui->pb_save_state_machine->show();
        ui->pb_load_from_Thread->show();

        ui->pb_configure_thread_in_class->hide();
        ui->pb_configure_thread_in_main->hide();
        ui->pb_configure_Main_thread->hide();

        show_update_tree_view();

        emit check_warnings();
    }
    else{

        ui->pb_configure_state_machine->setText("Configure State Machine");

        ui->pb_configure_thread_in_class->show();
        ui->pb_configure_thread_in_main->show();
        ui->pb_configure_Main_thread->show();

        ui->pb_load_state_machine->hide();
        ui->pb_save_state_machine->hide();
        ui->pb_load_from_Thread->hide();
        ui->pb_warning_state_machine->hide();

        ui->widget_layout_state_machine->hide();
    }
}

void NFWizard2::check_for_warnings()
{
    ui->pb_warning_state_machine->setToolTip(QString(""));

    bool deploy_warning = false;

    if(!hierarchy_states.isEmpty()){
        for(quint16 i=0; i< hierarchy_states.size(); i++){

            if(!hierarchy_states[i]->get_direct_SubStates().isEmpty()){

               if(hierarchy_states[i]->get_state_initial() == "No Initial"){

                   ////Aqui agregar comentario
                   ui->pb_warning_state_machine->setToolTip(ui->pb_warning_state_machine->toolTip()
                                                            +QString("<font color=green> The State: ")
                                                            +hierarchy_states[i]->get_state_name()
                                                            +QString(" has no initial State<br><br>"));
                   deploy_warning = true;
               }
            }
            bool hasNext = false;
            for(quint8 n=0; n< hierarchy_states[i]->get_events_list().size(); n++){

                if(hierarchy_states[i]->get_events_list()[n].next_state != "No Next State"){

                    hasNext = true;
                }
            }
            if(!hasNext){

                ////Aqui agregar comentario
                ui->pb_warning_state_machine->setToolTip(ui->pb_warning_state_machine->toolTip()
                                                         +QString("<font color=green> The State: ")
                                                         +hierarchy_states[i]->get_state_name()
                                                         +QString(" has no next State<br><br>"));
                deploy_warning = true;
            }
        }
    }
    if(deploy_warning){

        ui->pb_warning_state_machine->show();
    }
    else{

        ui->pb_warning_state_machine->hide();
    }
}

void NFWizard2::on_pb_add_state_clicked()
{
    if(ui->l_name_current_state->text()=="No Parent"){
        if(current_positions_minus_one >= QHierarchy_State::MAX_SUB_STATE){

            QMessageBox::information(this, "NEOWizard", QString("<font color = white >You can't add more states in this Super State"));
            return;
        }
    }
    if(!ui->le_state_name->text().isEmpty()){


        current_state = ui->le_state_name->text();
        current_state_parent = ui->l_name_current_state->text();

        if(!add_state_in_superstate(current_state_parent, current_state, true)){
           return;
        }

        if(draw_super_state(current_state_parent)== QHierarchy_State::MAX_SUB_STATE){
            QMessageBox::information(this, "NEOWizard", QString("<font color = white >You can't add more state to this parent, please change of state"));
        }
        qDebug()<<"tam :"<<QString::number(hierarchy_states.size());

        ui->pb_generate_state_machine->setEnabled(true);       
    }
    else{
        QMessageBox::information(this, "NEOWizard", QString("<font color = white >Please add name to the state"));
    }
}

void NFWizard2::on_state_clicked(QString state_name){

    highlight_state(state_name);
    current_state = state_name;
    current_state_parent = ui->l_name_current_state->text();
    ui->widget_on_state_options->show();
    ui->widget_on_state_options->move(QWidget::mapFromGlobal(QCursor::pos()));

    //int index = get_state_index_with_name(current_state);
    //ui->widget_on_state_options->move(points[current_positions_minus_one][hierarchy_states[index]->get_position_in_superstate()]);
}

void NFWizard2::on_state_toggled(QString state_name){

    //ui->l_name_current_state->setText(state_name.toUpper());
    //clean_widget_state_machine();

}

void NFWizard2::clean_widget_state_machine(){

    for(int i=0; i< hierarchy_states.size(); i++){
        if(!hierarchy_states[i]->isHidden()){
            hierarchy_states[i]->hide();
        }
    }
}

void NFWizard2::set_points(){

    int x = ui->widget_states->size().rwidth();
    int y = ui->widget_states->size().rheight();
    int hieratic_state_circle_radius = 27;

    points[0].append(QPoint((int)(x/2)-hieratic_state_circle_radius,(int)(y/2)-hieratic_state_circle_radius));

    points[1].append(QPoint((int)(x/3)-hieratic_state_circle_radius,(int)(y/2)-hieratic_state_circle_radius));
    points[1].append(QPoint((int)(x/3)*2-hieratic_state_circle_radius,(int)(y/2)-hieratic_state_circle_radius));

    points[2].append(QPoint((int)(x/3)-hieratic_state_circle_radius,(int)(y/5)*2-hieratic_state_circle_radius));
    points[2].append(QPoint((int)(x/3)*2-hieratic_state_circle_radius,(int)(y/5)*2-hieratic_state_circle_radius));
    points[2].append(QPoint((int)(x/2)-hieratic_state_circle_radius,(int)(y/4)*3-hieratic_state_circle_radius));

    points[3].append(QPoint((int)(x/3)-hieratic_state_circle_radius,(int)(y/3)-hieratic_state_circle_radius));
    points[3].append(QPoint((int)(x/3)*2-hieratic_state_circle_radius,(int)(y/3)-hieratic_state_circle_radius));
    points[3].append(QPoint((int)(x/3)-hieratic_state_circle_radius,(int)(y/3)*2-hieratic_state_circle_radius));
    points[3].append(QPoint((int)(x/3)*2-hieratic_state_circle_radius,(int)(y/3)*2-hieratic_state_circle_radius));

    points[4].append(QPoint((int)(x/40)*15-hieratic_state_circle_radius,(int)(y/4)-hieratic_state_circle_radius));
    points[4].append(QPoint((int)(x/40)*25-hieratic_state_circle_radius,(int)(y/4)-hieratic_state_circle_radius));
    points[4].append(QPoint((int)(x/10)*3-hieratic_state_circle_radius,(int)(y/20)*11-hieratic_state_circle_radius));
    points[4].append(QPoint((int)(x/10)*7-hieratic_state_circle_radius,(int)(y/20)*11-hieratic_state_circle_radius));
    points[4].append(QPoint((int)(x/2)-hieratic_state_circle_radius,(int)(y/40)*31-hieratic_state_circle_radius));

    points[5].append(QPoint((int)(x/3)-hieratic_state_circle_radius,(int)(y/5)-hieratic_state_circle_radius));
    points[5].append(QPoint((int)(x/3)*2-hieratic_state_circle_radius,(int)(y/5)-hieratic_state_circle_radius));
    points[5].append(QPoint((int)(x/4)-hieratic_state_circle_radius,(int)(y/2)-hieratic_state_circle_radius));
    points[5].append(QPoint((int)(x/4)*3-hieratic_state_circle_radius,(int)(y/2)-hieratic_state_circle_radius));
    points[5].append(QPoint((int)(x/3)-hieratic_state_circle_radius,(int)(y/5)*4-hieratic_state_circle_radius));
    points[5].append(QPoint((int)(x/3)*2-hieratic_state_circle_radius,(int)(y/5)*4-hieratic_state_circle_radius));

    points[6].append(QPoint((int)(x/2)-hieratic_state_circle_radius,(int)(y/2)-hieratic_state_circle_radius));
    points[6].append(QPoint((int)(x/3)-hieratic_state_circle_radius,(int)(y/5)-hieratic_state_circle_radius));
    points[6].append(QPoint((int)(x/3)*2-hieratic_state_circle_radius,(int)(y/5)-hieratic_state_circle_radius));
    points[6].append(QPoint((int)(x/4)-hieratic_state_circle_radius,(int)(y/2)-hieratic_state_circle_radius));
    points[6].append(QPoint((int)(x/4)*3-hieratic_state_circle_radius,(int)(y/2)-hieratic_state_circle_radius));
    points[6].append(QPoint((int)(x/3)-hieratic_state_circle_radius,(int)(y/5)*4-hieratic_state_circle_radius));
    points[6].append(QPoint((int)(x/3)*2-hieratic_state_circle_radius,(int)(y/5)*4-hieratic_state_circle_radius));

    points[7].append(QPoint((int)(x/2)-hieratic_state_circle_radius,(int)(y/20)*7-hieratic_state_circle_radius));
    points[7].append(QPoint((int)(x/2)-hieratic_state_circle_radius,(int)(y/20)*13-hieratic_state_circle_radius));
    points[7].append(QPoint((int)(x/3)-hieratic_state_circle_radius,(int)(y/5)-hieratic_state_circle_radius));
    points[7].append(QPoint((int)(x/3)*2-hieratic_state_circle_radius,(int)(y/5)-hieratic_state_circle_radius));
    points[7].append(QPoint((int)(x/4)-hieratic_state_circle_radius,(int)(y/2)-hieratic_state_circle_radius));
    points[7].append(QPoint((int)(x/4)*3-hieratic_state_circle_radius,(int)(y/2)-hieratic_state_circle_radius));
    points[7].append(QPoint((int)(x/3)-hieratic_state_circle_radius,(int)(y/5)*4-hieratic_state_circle_radius));
    points[7].append(QPoint((int)(x/3)*2-hieratic_state_circle_radius,(int)(y/5)*4-hieratic_state_circle_radius));

    points[8].append(QPoint((int)(x/2)-hieratic_state_circle_radius,(int)(y/5)-hieratic_state_circle_radius));
    points[8].append(QPoint((int)(x/2)-hieratic_state_circle_radius,(int)(y/2)-hieratic_state_circle_radius));
    points[8].append(QPoint((int)(x/2)-hieratic_state_circle_radius,(int)(y/5)*4-hieratic_state_circle_radius));
    points[8].append(QPoint((int)(x/3)-hieratic_state_circle_radius,(int)(y/5)-hieratic_state_circle_radius));
    points[8].append(QPoint((int)(x/3)*2-hieratic_state_circle_radius,(int)(y/5)-hieratic_state_circle_radius));
    points[8].append(QPoint((int)(x/4)-hieratic_state_circle_radius,(int)(y/2)-hieratic_state_circle_radius));
    points[8].append(QPoint((int)(x/4)*3-hieratic_state_circle_radius,(int)(y/2)-hieratic_state_circle_radius));
    points[8].append(QPoint((int)(x/3)-hieratic_state_circle_radius,(int)(y/5)*4-hieratic_state_circle_radius));
    points[8].append(QPoint((int)(x/3)*2-hieratic_state_circle_radius,(int)(y/5)*4-hieratic_state_circle_radius));

    points[9].append(QPoint((int)(x/5)*2-hieratic_state_circle_radius,(int)(y/5)*2-hieratic_state_circle_radius));
    points[9].append(QPoint((int)(x/5)*3-hieratic_state_circle_radius,(int)(y/5)*2-hieratic_state_circle_radius));
    points[9].append(QPoint((int)(x/5)*2-hieratic_state_circle_radius,(int)(y/5)*3-hieratic_state_circle_radius));
    points[9].append(QPoint((int)(x/5)*3-hieratic_state_circle_radius,(int)(y/5)*3-hieratic_state_circle_radius));
    points[9].append(QPoint((int)(x/10)*3-hieratic_state_circle_radius,(int)(y/5)-hieratic_state_circle_radius));
    points[9].append(QPoint((int)(x/10)*7-hieratic_state_circle_radius,(int)(y/5)-hieratic_state_circle_radius));
    points[9].append(QPoint((int)(x/10)*2-hieratic_state_circle_radius,(int)(y/2)-hieratic_state_circle_radius));
    points[9].append(QPoint((int)(x/10)*8-hieratic_state_circle_radius,(int)(y/2)-hieratic_state_circle_radius));
    points[9].append(QPoint((int)(x/10)*3-hieratic_state_circle_radius,(int)(y/5)*4-hieratic_state_circle_radius));
    points[9].append(QPoint((int)(x/10)*7-hieratic_state_circle_radius,(int)(y/5)*4-hieratic_state_circle_radius));

    points[10].append(QPoint((int)(x/5)*2-hieratic_state_circle_radius,(int)(y/5)*2-hieratic_state_circle_radius));
    points[10].append(QPoint((int)(x/5)*3-hieratic_state_circle_radius,(int)(y/5)*2-hieratic_state_circle_radius));
    points[10].append(QPoint((int)(x/5)*2-hieratic_state_circle_radius,(int)(y/5)*3-hieratic_state_circle_radius));
    points[10].append(QPoint((int)(x/5)*3-hieratic_state_circle_radius,(int)(y/5)*3-hieratic_state_circle_radius));
    points[10].append(QPoint((int)(x/10)*3-hieratic_state_circle_radius,(int)(y/5)-hieratic_state_circle_radius));
    points[10].append(QPoint((int)(x/10)*7-hieratic_state_circle_radius,(int)(y/5)-hieratic_state_circle_radius));
    points[10].append(QPoint((int)(x/10)*2-hieratic_state_circle_radius,(int)(y/2)-hieratic_state_circle_radius));
    points[10].append(QPoint((int)(x/10)*8-hieratic_state_circle_radius,(int)(y/2)-hieratic_state_circle_radius));
    points[10].append(QPoint((int)(x/10)*3-hieratic_state_circle_radius,(int)(y/5)*4-hieratic_state_circle_radius));
    points[10].append(QPoint((int)(x/10)*7-hieratic_state_circle_radius,(int)(y/5)*4-hieratic_state_circle_radius));
    points[10].append(QPoint((int)(x/2)-hieratic_state_circle_radius,(int)(y/20)*17-hieratic_state_circle_radius));

    points[11].append(QPoint((int)(x/5)*2-hieratic_state_circle_radius,(int)(y/5)*2-hieratic_state_circle_radius));
    points[11].append(QPoint((int)(x/5)*3-hieratic_state_circle_radius,(int)(y/5)*2-hieratic_state_circle_radius));
    points[11].append(QPoint((int)(x/5)*2-hieratic_state_circle_radius,(int)(y/5)*3-hieratic_state_circle_radius));
    points[11].append(QPoint((int)(x/5)*3-hieratic_state_circle_radius,(int)(y/5)*3-hieratic_state_circle_radius));
    points[11].append(QPoint((int)(x/10)*3-hieratic_state_circle_radius,(int)(y/5)-hieratic_state_circle_radius));
    points[11].append(QPoint((int)(x/10)*7-hieratic_state_circle_radius,(int)(y/5)-hieratic_state_circle_radius));
    points[11].append(QPoint((int)(x/10)*2-hieratic_state_circle_radius,(int)(y/2)-hieratic_state_circle_radius));
    points[11].append(QPoint((int)(x/10)*8-hieratic_state_circle_radius,(int)(y/2)-hieratic_state_circle_radius));
    points[11].append(QPoint((int)(x/10)*3-hieratic_state_circle_radius,(int)(y/5)*4-hieratic_state_circle_radius));
    points[11].append(QPoint((int)(x/10)*7-hieratic_state_circle_radius,(int)(y/5)*4-hieratic_state_circle_radius));
    points[11].append(QPoint((int)(x/2)-hieratic_state_circle_radius,(int)(y/20)*17-hieratic_state_circle_radius));
    points[11].append(QPoint((int)(x/2)-hieratic_state_circle_radius,(int)(y/20)*3-hieratic_state_circle_radius));
}

void NFWizard2::on_pb_generate_state_machine_clicked()
{
   //qDebug()<<"Probando :  & \n";
   if(hierarchy_states.isEmpty()){

       QMessageBox::information(this, "NEOWizard","<font color = white >You haven't enter any state");
       return;
   }
   for(quint16 i=0; i< hierarchy_states.size(); i++)
       qDebug()<<"State :  "<<hierarchy_states[i]->get_state_name()<<"   Superstate : "<<hierarchy_states[i]->get_state_parent();

   if(ui->le_main_thread_name->text().isEmpty()){

       QMessageBox::information(this, "NEOWizard","<font color = white >Insert name of main thread");
       ui->widget_options_thread_options->show();
       ui->widget_options_thread_options->move(500,140);
       ui->le_main_thread_name->show();
       ui->l_main_thread_name->show();
       ui->le_thread_name->hide();
       ui->l_thread_name->hide();
       ui->l_thread_priority->hide();
       ui->cb_thread_priority->hide();
       ui->l_thread_stack_size->hide();
       ui->sb_thread_stack_size->hide();
       ui->pb_add_thread->hide();
       ui->pb_acept_main_thread->show();
       return;
   }
   else{

       if(QMessageBox::information(this,"Confirmation","<font color=white >Generate State Machine?",QMessageBox::Ok,QMessageBox::Cancel)==QMessageBox::Ok){
           generate_labels_for_state_machine(fileuVision_Path, ui->le_main_thread_name->text());
           generate_code_for_state_machine(ui->le_main_thread_name->text());
           ui->widget_options_thread_options->hide();
           QMessageBox::information(this, "NEOWizard","<font color = white >State Machine Generated");
       }
   }
}

int NFWizard2::draw_super_state(const QString &superState, const bool update_tree, const bool expand, const QString item_name){

    clean_widget_state_machine();

    QList<quint16> indexes = get_state_indexes_with_parent(superState);

    for(quint16 i=0; i < indexes.size(); i++){

        hierarchy_states[indexes[i]]->show();
    }

    ui->l_name_current_state->setText(superState);
    current_state_parent = superState;

    current_positions_minus_one = indexes.size()-1;

    int index = get_state_index_with_name(superState);

    if(index!=-1){

        ui->l_name_current_state->setToolTip(QString("<font color = green >")
                                             +QString("State Name : ")+hierarchy_states[index]->get_state_name()
                                             +QString("<br>Super State : ")+hierarchy_states[index]->get_state_parent()
                                             +QString("<br>Initial State  : ")+hierarchy_states[index]->get_state_initial()
                                             +QString("<br>Next State   : ")+hierarchy_states[index]->get_events_list()[0].next_state);
    }


    if(indexes.isEmpty()){
        qDebug()<<"Nada que dibujar";
        return 0;
    }

    for(quint16 i=0; i < indexes.size(); i++){

        if(current_positions_minus_one>=QHierarchy_State::MAX_SUB_STATE){
            break;
            qDebug()<<"Maxima cantidad de estados";
        }
        hierarchy_states[indexes[i]]->move(points[current_positions_minus_one][i]);
        hierarchy_states[indexes[i]]->set_position_in_superstate(i);

        if(i>=QHierarchy_State::MAX_SUB_STATE){
            break;
            qDebug()<<"Maxima cantidad de estados";
        }

    }
    if(superState != "No Parent"){
        show_update_tree_view(true, superState, item_name);
    }
    else{
        show_update_tree_view(false, "Empty", item_name);
    }

    emit check_warnings();

    return indexes.size();
}

void NFWizard2::on_pb_back_clicked()
{
    if(ui->l_name_current_state->text()==QString("No Parent")){

        QMessageBox::information(this, "NEOWizard","<font color = white >This state has\n no parent state");
        return;
    }

    if(!ui->widget_state_info->isHidden()){
        ui->widget_state_info->hide();
        int index = get_state_index_with_name(ui->l_name_current_state->text());

        if(index == -1){
            qDebug()<<"Estado no encontrado";
            return;
        }
        current_state = hierarchy_states[index]->get_state_name();
        current_state_parent = hierarchy_states[index]->get_state_parent();

        draw_super_state(current_state_parent);
        ui->pb_add_state->setEnabled(true);

        return;
    }

    int index = get_state_index_with_name(ui->l_name_current_state->text());

    if(index == -1){
        qDebug()<<"Estado no encontrado";
        return;
    }

    current_state = hierarchy_states[index]->get_state_name();  ////estado de donde viene
    current_state_parent = hierarchy_states[index]->get_state_parent(); ////estado a dibujar

    draw_super_state(current_state_parent);

}

void NFWizard2::on_pb_ok_clicked()
{

    int index = get_state_index_with_name(ui->l_name_current_state->text());

    if(index!=-1){


        if(!ui->le_super_state_name->text().isEmpty()){
            if(get_state_index_with_name(ui->le_super_state_name->text())!=-1 || ui->le_super_state_name->text()=="No Parent"){

                int parent_index = get_state_index_with_name(hierarchy_states[index]->get_state_parent());
                if(parent_index!=-1){  ////Eliminar hijo de la lista de hijos de antiguo padre
                    hierarchy_states[parent_index]->eliminate_child( hierarchy_states[index]->get_state_name());
                }
                ////Añadir el estado a la lista de hijos de nuevo padre
                int new_parent_index = get_state_index_with_name(ui->le_super_state_name->text());
                if(new_parent_index!=-1){

                    hierarchy_states[new_parent_index]->add_direct_sub_State(hierarchy_states[index]->get_state_name());
                    hierarchy_states[index]->set_state_parent(ui->le_super_state_name->text());
                }
            }
            else{
                QMessageBox::information(this, "NEOWizard", QString("<font green = white >Superstate not found, the State will mantain his old parent"));
            }
        }
        if(!ui->le_current_state_name->text().isEmpty()){
            if(get_state_index_with_name(ui->le_current_state_name->text())==-1){

                for(quint16 i=0; i< hierarchy_states[index]->get_direct_SubStates().size();i++){

                    int other_index = get_state_index_with_name(hierarchy_states[index]->get_direct_SubStates()[i]);
                    if(other_index!=-1){////insertar el nuevo padre a sus hijos

                        hierarchy_states[other_index]->set_state_parent(ui->le_current_state_name->text());
                    }
                }
                int parent_index = get_state_index_with_name(hierarchy_states[index]->get_state_parent());
                if(parent_index!=-1){  ////Eliminar hijo de la lista de hijos de antiguo padre
                    hierarchy_states[parent_index]->eliminate_child( hierarchy_states[index]->get_state_name());
                    hierarchy_states[parent_index]->add_direct_sub_State(ui->le_current_state_name->text());
                }
                hierarchy_states[index]->set_state_name(ui->le_current_state_name->text());
            }
            else{
                QMessageBox::information(this, "NEOWizard", QString("<font color = green >There is already a State with this name, the State will mantain his old name"));
            }
        }
        if(!ui->le_initial_state_name->text().isEmpty()){
            if(hierarchy_states[index]->look_for_child(ui->le_initial_state_name->text())){

                for(quint16 i=0; i< hierarchy_states[index]->get_direct_SubStates().size(); i++){

                    int index_other = get_state_index_with_name(hierarchy_states[index]->get_direct_SubStates()[i]);
                    hierarchy_states[index_other]->setInitial(false);
                    ////aqui cambiar foto de fondo de todos los estado
                }
                hierarchy_states[index]->set_state_initial(ui->le_initial_state_name->text());

                int child_index = get_state_index_with_name(ui->le_initial_state_name->text());
                hierarchy_states[child_index]->setInitial(true);
            }
            else{
                QMessageBox::information(this, "NEOWizard", QString("<font color = green >The initial State you are adding is not a child of State : ")+hierarchy_states[index]->get_state_name());
            }
        }
        if(!ui->le_entry_action->text().isEmpty())
            hierarchy_states[index]->set_state_entryAction(ui->le_entry_action->text());
        if(!ui->le_exit_action->text().isEmpty())
            hierarchy_states[index]->set_state_exitAction(ui->le_exit_action->text());
        if(!ui->le_default_state_name->text().isEmpty())
            hierarchy_states[index]->set_state_default(ui->le_default_state_name->text());

//        QHierarchy_State::QHierarchy_State_Event_t T_event;
//        T_event.event = "No Event"; ////Aqui agregar el evento de los listWidgets****************************************************************************
//        T_event.next_state = "No Next State";
//        T_event.state_action = "No Action";
//        hierarchy_states[index]->add_Event(T_event);


        hierarchy_states[index]->setToolTip(QString("<font color = green >State Name : ")+hierarchy_states[index]->get_state_name()
                                            +QString("<br>Super State : ")+hierarchy_states[index]->get_state_parent()
                                            +QString("<br>Initial State  : ")+hierarchy_states[index]->get_state_initial()
                                            +QString("<br>Next State  : ")+hierarchy_states[index]->get_events_list()[0].next_state);

        hierarchy_states[index]->setToolTipDuration(10000);

    }

    draw_super_state(hierarchy_states[index]->get_state_parent());
    clear_line_edits_and_list_widgets();
    ui->widget_state_info->hide();
    ui->pb_add_state->setEnabled(true);

}

int NFWizard2::get_state_index_with_name(const QString &state_name){

    for(quint16 i=0; i < hierarchy_states.size(); i++){

        if(hierarchy_states[i]->get_state_name()==state_name){

            return i;
        }
    }
    return -1;
}

QList<quint16> NFWizard2::get_state_indexes_with_parent(const QString &superState){

    QList<quint16> indexes;
    for(quint16 i=0; i < hierarchy_states.size(); i++){

        if(hierarchy_states[i]->get_state_parent()==superState){

            indexes.append(i);
        }
    }
    return indexes;
}

void NFWizard2::clear_line_edits_and_list_widgets(){

        ui->le_current_state_name->clear();

        ui->le_super_state_name->clear();

        ui->le_initial_state_name->clear();

        ui->le_entry_action->clear();

        ui->le_exit_action->clear();

        ui->le_default_state_name->clear();

        ui->lw_Actions->clear();

        ui->lw_Events->clear();

        ui->lw_Next_State->clear();
}

void NFWizard2::on_pb_open_state_clicked()
{
    clean_widget_state_machine();
    ui->widget_on_state_options->hide();
    draw_super_state(current_state);
}

void NFWizard2::on_pb_configure_state_clicked()
{
    clear_line_edits_and_list_widgets();
    clean_widget_state_machine();
    ui->widget_on_state_options->hide();
    ui->l_name_current_state->setText(current_state);
    ui->widget_state_info->show();
    ui->pb_add_state->setEnabled(false);
    ui->pb_warning_state_machine->hide();

    int index = get_state_index_with_name(current_state);

    if(index!=-1){

        ui->le_current_state_name->setText(hierarchy_states[index]->get_state_name());
        ui->le_super_state_name->setText(hierarchy_states[index]->get_state_parent());
        ui->le_initial_state_name->setText(hierarchy_states[index]->get_state_initial());
        ui->le_entry_action->setText(hierarchy_states[index]->get_state_on_entry_Action());
        ui->le_exit_action->setText(hierarchy_states[index]->get_state_on_exit_Action());
        ui->le_default_state_name->setText(hierarchy_states[index]->get_state_default());

        QStringList temp_to_add_events;
        QStringList temp_to_add_next_state;
        QStringList temp_to_add_actions;

        for(quint16 i =0; i< hierarchy_states[index]->get_events_list().size(); i++){
            temp_to_add_events.append( hierarchy_states[index]->get_events_list()[i].event);
            temp_to_add_next_state.append( hierarchy_states[index]->get_events_list()[i].next_state);
            temp_to_add_actions.append( hierarchy_states[index]->get_events_list()[i].state_action);
        }

        ui->lw_Events->addItems(temp_to_add_events);
        ui->lw_Next_State->addItems(temp_to_add_next_state);
        ui->lw_Actions->addItems(temp_to_add_actions);
    }
    else{
        qDebug()<<"No encontrado el estado en funcion : on_pb_configure_state_clicked";
    }
}

void NFWizard2::on_pb_add_sub_sate_clicked()
{
    ui->widget_on_state_options->hide();
    add_state_in_superstate(current_state, ui->le_state_name->text(), false);
}

void NFWizard2::on_pb_eliminate_state_clicked()
{
    ui->widget_on_state_options->hide();
    eliminate_State(current_state);
    //on_pb_generate_state_machine_clicked();
    draw_super_state(current_state_parent);
}

bool NFWizard2::add_state_in_superstate(const QString &superState, const QString& state_name, const bool show){

    if(superState!="No Parent"){ ////si tiene padre

        int index = get_state_index_with_name(superState);
        if(index !=-1){

            if(hierarchy_states[index]->get_subStates_count() >= QHierarchy_State::MAX_SUB_STATE){

                QMessageBox::information(this, "NEOWizard", QString("<font color = white >You can't add more State into this superstate"));
                return false;
            }
        }
        else{
            QMessageBox::information(this, "NEOWizard", QString("<font color = white >Cannot find the parent State"));
            return false;
        }
    }

    for(quint16 i=0; i < hierarchy_states.size(); i++){ ////no pueden haber 2 estados con el mismo nombre

        if(hierarchy_states[i]->get_state_name()==ui->le_state_name->text()){

            QMessageBox::information(this, "NEOWizard", QString("<font color = white >You can't have two state with the same name,\nPlease change name to the new state"));
            return false;
        }
    }
    if(superState != QString("No Parent")){ ////Si no existe el estado padre no añado estado
        int index = get_state_index_with_name(superState);
        if(index == -1){
            QMessageBox::warning(this, tr("NFWizard2"),tr("<font color = white >The parent State doesn't exist"));
            return false;
        }
    }
    QHierarchy_State *state = new QHierarchy_State(ui->widget_states, state_name);
    state->set_state_parent(superState);

    if(state->get_state_parent()!="No Parent"){ ////añade el estado a la lista de hijos directos de su estado padre

        int index = get_state_index_with_name(state->get_state_parent());
        if(index !=-1){
            hierarchy_states[index]->add_direct_sub_State(state_name);
        }
    }
    if(show){
        state->show();
    }
    connect(state,SIGNAL(signal_clicked(QString)),this,SLOT(on_state_clicked(QString)));
    connect(state,SIGNAL(signal_toggled(QString)),this,SLOT(on_state_toggled(QString)));
    state->setToolTip(QString("<font color =  green >State Name : ")+state->get_state_name()
                      +QString("<br>Super State : ")+state->get_state_parent()
                      +QString("<br>Initial State  : "+state->get_state_initial())
                      +QString("<br>Next State   : ")+state->get_events_list()[0].next_state);
    hierarchy_states.append(state);

    return true;
}

bool NFWizard2::eliminate_State(const QString &superState){

    int index = get_state_index_with_name(superState);
    if(index != -1){ ////encontrado

        for(quint16 i =0; i< hierarchy_states[index]->get_direct_SubStates().size();i++){


            int child_index = get_state_index_with_name( hierarchy_states[index]->get_direct_SubStates()[i]);
            if(child_index != -1){
                i--;
                eliminate_State(hierarchy_states[child_index]->get_state_name());
            }

        }

        int index_parent = get_state_index_with_name(hierarchy_states[index]->get_state_parent());

        if(index_parent!=-1){ ////si no tiene padre debe ser "No parent" superestado inicial

            hierarchy_states[index_parent]->eliminate_child(hierarchy_states[index]->get_state_name());
        }
        hierarchy_states[index]->hide();
        hierarchy_states[index]->deleteLater();
        hierarchy_states.removeOne(hierarchy_states[index]);

        return true;
    }
    else{ ////No encontrado el estado a eliminar
        return false;
    }
}

void NFWizard2::on_lw_Events_clicked(const QModelIndex &index)
{
    ui->widget_add_delete_event->show();
}

void NFWizard2::on_lw_Next_State_clicked(const QModelIndex &index)
{
    ui->widget_add_delete_event->show();
}

void NFWizard2::on_lw_Actions_clicked(const QModelIndex &index)
{
    ui->widget_add_delete_event->show();
}

void NFWizard2::on_pb_search_state_clicked()
{
    if(ui->le_state_to_search->isHidden()){

        ui->le_state_to_search->show();
        ui->widget_add_gen_buttons->hide();
    }
    else{
        ui->le_state_to_search->hide();
        ui->widget_add_gen_buttons->show();
    }

}

void NFWizard2::on_pb_add_event_clicked()
{
    ui->widget_event_options->hide();

    int index = get_state_index_with_name(current_state);

    QString event_action = "No Action";
    QString event_next_state = "No Next State";

    if(index!=-1){

        if(ui->le_event_ID_name->text().isEmpty()){

            QMessageBox::warning(this, tr("NFWizard2"),tr("<font color = white >Insert Event ID name"));
            return;
        }
        if(!ui->le_action_name->text().isEmpty()){

            event_action = ui->le_action_name->text();
        }
        if(!ui->le_next_state_name->text().isEmpty()){

            event_next_state = ui->le_next_state_name->text();
        }
        if(!ui->le_next_state_name->text().isEmpty() || !ui->le_action_name->text().isEmpty()){

            hierarchy_states[index]->add_Event(ui->le_event_ID_name->text(), event_next_state, event_action);
            QStringList temp_to_add_events;
            QStringList temp_to_add_next_state;
            QStringList temp_to_add_actions;
            ui->lw_Events->clear();
            ui->lw_Next_State->clear();
            ui->lw_Actions->clear();
            for(quint16 i =0; i< hierarchy_states[index]->get_events_list().size(); i++){
               temp_to_add_events.append( hierarchy_states[index]->get_events_list()[i].event);
               temp_to_add_next_state.append( hierarchy_states[index]->get_events_list()[i].next_state);
               temp_to_add_actions.append( hierarchy_states[index]->get_events_list()[i].state_action);
            }

            ui->lw_Events->addItems(temp_to_add_events);
            ui->lw_Next_State->addItems(temp_to_add_next_state);
            ui->lw_Actions->addItems(temp_to_add_actions);
        }
        else{
            QMessageBox::warning(this, tr("NFWizard2"),tr("<font color = white >Insert Action or Next State"));
            return;
        }

    }
}

void NFWizard2::on_pb_cancel_add_event_clicked()
{
   ui->widget_event_options->hide();
}

void NFWizard2::on_le_state_to_search_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){
        QStringList complete_list;
        for(quint16 i=0; i< hierarchy_states.size(); i++){
            if(hierarchy_states[i]->get_state_name().contains(arg1, Qt::CaseInsensitive)){
                complete_list.append(hierarchy_states[i]->get_state_name());
            }
        }

        complete_list_object_states = new QCompleter(complete_list,this);

        complete_list_object_states->setCaseSensitivity(Qt::CaseInsensitive);
        complete_list_object_states->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
        ui->le_state_to_search->setCompleter(complete_list_object_states);

        connect(complete_list_object_states,SIGNAL(highlighted(QString)),this, SLOT(on_selected_state_in_search(QString)));
    }
}

void NFWizard2::on_selected_state_in_search(const QString &state){

    int index = get_state_index_with_name(state);
    if(index!=-1){
        current_state = state;
        draw_super_state(hierarchy_states[index]->get_state_parent());
        qDebug()<<"State selected : "+state+" on function : on_selected_state_in_search";
    }
    highlight_state(state);
}

void NFWizard2::generate_definition_for_State_Machine_actions(const QString main_thread_name, const QString action){

    TextFileProcessor main_h_FileProcessor;
    QString toReplace_string = action
            +QString("(int event);");

    main_h_FileProcessor.setFilename(fileuVision_Path+QString("/Include/")+main_thread_name+QString(".h"));

    if(main_h_FileProcessor.check_if_code_exist(toReplace_string, false)==0){

        main_h_FileProcessor.setStartLine("/*Definition of Action Prototypes of State Machine*/");       ////inicio del contenido a eliminar
        main_h_FileProcessor.setEndLine("/*Definition of Action Prototypes of State Machine*/"); ////fin del contenido a eliminar
        main_h_FileProcessor.setReplacementString(QString("/*Definition of Action Prototypes of State Machine*/\n\n")
                                                  +QString("    void ")+toReplace_string);
        main_h_FileProcessor.processTextBlock();
    }

}
////////*********************************************************************************************************************
void NFWizard2::generate_definition_for_State_Machine_entries_funtions(const QString main_thread_name, const QString class_name){

    TextFileProcessor main_h_FileProcessor;

    QString toReplace_string = class_name +QString(" ")+class_name+QString("_Instance;");

    main_h_FileProcessor.setFilename(fileuVision_Path+QString("/Include/")+main_thread_name+QString(".h"));

    if(main_h_FileProcessor.check_if_code_exist(toReplace_string, false)==0){

        main_h_FileProcessor.setStartLine("private:");       ////inicio del contenido a eliminar
        main_h_FileProcessor.setEndLine("private:"); ////fin del contenido a eliminar
        main_h_FileProcessor.setReplacementString(QString("private:\n\n")
                                                  +QString("    ")+toReplace_string);
        main_h_FileProcessor.processTextBlock();
    }

    if(main_h_FileProcessor.check_if_code_exist(QString("#include \"")+class_name+QString(".h\""), false)==0){

        main_h_FileProcessor.setStartLine("#include <eApplicationBase.h>");       ////inicio del contenido a eliminar
        main_h_FileProcessor.setEndLine("#include <eApplicationBase.h>"); ////fin del contenido a eliminar
        main_h_FileProcessor.setReplacementString(QString("#include <eApplicationBase.h>\n\n")+QString("#include \"")+class_name+QString(".h\""));
        main_h_FileProcessor.processTextBlock();
    }

}
////////No uso esta funcion*********************************************************************************************************************
void NFWizard2::generate_definition_for_State_Machine_exits_funtions(const QString main_thread_name, const QString exitAction){

    TextFileProcessor main_h_FileProcessor;

    QString toReplace_string = QString("    void ")+exitAction
            +QString("();");
    main_h_FileProcessor.setFilename(fileuVision_Path+QString("/Include/")+main_thread_name+QString(".h"));

    if(main_h_FileProcessor.check_if_code_exist(toReplace_string, false)==0){

        main_h_FileProcessor.setStartLine("/*Definition of Exit Functions Prototypes of State Machine*/");       ////inicio del contenido a eliminar
        main_h_FileProcessor.setEndLine("/*Definition of Exit Functions Prototypes of State Machine*/"); ////fin del contenido a eliminar
        main_h_FileProcessor.setReplacementString(QString("/*Definition of Exit Functions Prototypes of State Machine*/\n\n")
                                                  +toReplace_string);
        main_h_FileProcessor.processTextBlock();
    }

}

void NFWizard2::generate_definition_for_State_Machine_events(const QString main_thread_name, const QString event_id, bool define_enum, bool last_event){

    TextFileProcessor main_h_FileProcessor;

    main_h_FileProcessor.setFilename(fileuVision_Path+QString("/Include/")+main_thread_name+QString(".h"));

    if(define_enum){

        QString toReplace_string = QString("/*Definition of Events ID of State Machine*/\n\n")
                +QString("enum ControlerEvents{\n");
        if(main_h_FileProcessor.check_if_code_exist(toReplace_string, false)==0){
            main_h_FileProcessor.setStartLine("/*Definition of Events ID of State Machine*/");       ////inicio del contenido a eliminar
            main_h_FileProcessor.setEndLine("/*Definition of Events ID of State Machine*/"); ////fin del contenido a eliminar
            main_h_FileProcessor.setReplacementString(toReplace_string+QString("/*EVENTS ID*/};"));

            main_h_FileProcessor.processTextBlock();
        }

    }
    else{

        if(event_id.contains("::")){
            QString class_name = event_id.section(':',0,0);

            if(main_h_FileProcessor.check_if_code_exist(QString("#include \"")+class_name+QString(".h\""), false)==0){

                main_h_FileProcessor.setStartLine("#include <eApplicationBase.h>");       ////inicio del contenido a eliminar
                main_h_FileProcessor.setEndLine("#include <eApplicationBase.h>"); ////fin del contenido a eliminar
                main_h_FileProcessor.setReplacementString(QString("#include <eApplicationBase.h>\n\n")+QString("#include \"")+class_name+QString(".h\""));
                main_h_FileProcessor.processTextBlock();
            }
        }
        else{
            QString last_event_whitout_comma = ",";
            if(last_event){
                last_event_whitout_comma = "\n";
            }

            QString toReplace_string = event_id
                    +last_event_whitout_comma;
            if(main_h_FileProcessor.check_if_code_exist(toReplace_string, false)==0){
                main_h_FileProcessor.setStartLine("/*EVENTS ID*/");       ////inicio del contenido a eliminar
                main_h_FileProcessor.setEndLine("/*EVENTS ID*/"); ////fin del contenido a eliminar
                main_h_FileProcessor.setReplacementString(QString("/*EVENTS ID*/\n")
                                                          +QString("    ")+toReplace_string);

                main_h_FileProcessor.processTextBlock();
            }
        }
    }

    /* Definition of Event Message Queue *////*********************************************************************************************************************************************************  

    if(main_h_FileProcessor.check_if_code_exist(QString("#include <eMessageQueue.h>\n")+QString("#define APP_QUEUE_SIZE 16\n"), false)==0){
    main_h_FileProcessor.setStartLine("#include <eApplicationBase.h>");       ////inicio del contenido a eliminar
    main_h_FileProcessor.setEndLine("#include <eApplicationBase.h>"); ////fin del contenido a eliminar
    main_h_FileProcessor.setReplacementString(QString("#include <eApplicationBase.h>\n\n#include <eMessageQueue.h>\n")+QString("#define APP_QUEUE_SIZE 16\n"));
    main_h_FileProcessor.processTextBlock();
    }
    ///*********************************************************************************************************************************************************


    /* Definition of Event Message Queue *////*********************************************************************************************************************************************************
    if(main_h_FileProcessor.check_if_code_exist("eObject::Declare::eMessageQueue<APP_QUEUE_SIZE> appEventQueue;", false)==0){
    main_h_FileProcessor.setStartLine("/*Definitions of State Machine*/");       ////inicio del contenido a eliminar
    main_h_FileProcessor.setEndLine("/*Definitions of State Machine*/"); ////fin del contenido a eliminar
    main_h_FileProcessor.setReplacementString(QString("/*Definitions of State Machine*/\n\n")+QString("    eObject::Declare::eMessageQueue<APP_QUEUE_SIZE> appEventQueue;"));
    main_h_FileProcessor.processTextBlock();
    }
    ///*********************************************************************************************************************************************************


}

int NFWizard2::generate_labels_for_state_machine(const QString path, const QString main_thread_name){

    TextFileProcessor main_FileProcessor;

    main_FileProcessor.setFilename(path+QString("/Include/")+main_thread_name+QString(".h"));

    main_FileProcessor.generate_machine_lines_in_main_thread_h();



    main_FileProcessor.setFilename(path+QString("/Source/")+main_thread_name+QString(".cpp"));


    main_FileProcessor.generate_machine_lines_in_main_thread_cpp(main_thread_name);



}

void NFWizard2::generate_code_for_state_machine(const QString main_thread_name){

    ui->widget_wait->show();
    ui->label_loading->setText("GENERATING...");

    TextFileProcessor main_cpp_FileProcessor;

    main_cpp_FileProcessor.setFilename(fileuVision_Path+QString("/Source/")+main_thread_name+QString(".cpp"));

    bool first_event = true;
    bool no_declaration_of_class_with_entries = true;
    QStringList events_ids;
    QStringList actions_names;
    QStringList exits_names;
    QStringList entries_names;

    /* USER CODE BEGIN Includes *////*********************************************************************************************************************************************************

    QString toReplace_string = QString("/* USER CODE BEGIN Includes */\n\n")+QString("#include <eHierarchicalStateMachine.h>\n\n");

    if(main_cpp_FileProcessor.check_if_code_exist(toReplace_string, false)==0){

        main_cpp_FileProcessor.setStartLine("/* USER CODE BEGIN Includes */");       ////inicio del contenido a eliminar
        main_cpp_FileProcessor.setEndLine("/* USER CODE BEGIN Includes */"); ////fin del contenido a eliminar
        main_cpp_FileProcessor.setReplacementString(toReplace_string);
        main_cpp_FileProcessor.processTextBlock();
    }
    ///*********************************************************************************************************************************************************

    /*Name of State Machine controller*////*********************************************************************************************************************************************************

    toReplace_string = QString("/*Name of State Machine controller*/\n\n")
            +QString("    eObject::eHierarchicalStateMachine controlerHSM;\n");

    if(main_cpp_FileProcessor.check_if_code_exist(toReplace_string, false)==0){

        main_cpp_FileProcessor.setStartLine("/*Name of State Machine controller*/");       ////inicio del contenido a eliminar
        main_cpp_FileProcessor.setEndLine("/*Name of State Machine controller*/"); ////fin del contenido a eliminar
        main_cpp_FileProcessor.setReplacementString(toReplace_string);
        main_cpp_FileProcessor.processTextBlock();
    }
    ///*********************************************************************************************************************************************************


    /*Generate the code for de Events Enum*////*********************************************************************************************************************************************************
    generate_definition_for_State_Machine_events(main_thread_name,"No Event",true,false);
    ///*********************************************************************************************************************************************************


    /*Ciclo que recorre todos los estados*/////***********************************************************************************************************************
    for(quint16 i=0; i< hierarchy_states.size(); i++){

        /*Definition of all Entry Functions from State Machine*////**********************************************************************************
        {
            QString entryAction = hierarchy_states[i]->get_state_on_entry_Action();
            if(entryAction!= "No Entry Action" && !entries_names.contains(entryAction)){

                entries_names.append(entryAction);

                if(!entryAction.contains("::")){

                    toReplace_string = QString("/*Definition of Entry Functions Prototypes of State Machine*/\n\n")
                            +QString("void ")+entryAction
                            +QString("();");

                    if(main_cpp_FileProcessor.check_if_code_exist(QString("void ")+entryAction
                                                                  +QString("();"), false)==0){
                        main_cpp_FileProcessor.setStartLine("/*Definition of Entry Functions Prototypes of State Machine*/");       ////inicio del contenido a eliminar
                        main_cpp_FileProcessor.setEndLine("/*Definition of Entry Functions Prototypes of State Machine*/"); ////fin del contenido a eliminar
                        main_cpp_FileProcessor.setReplacementString(toReplace_string);
                        main_cpp_FileProcessor.processTextBlock();
                    }
                }

                if(!entryAction.contains("::")){
                toReplace_string = hierarchy_states[i]->get_state_name()
                        +QString(".signalEntered.connect<&")
                        +entryAction+QString(">();");
                }
                else{

                    QString class_name = entryAction.section(':',0,0);

                    toReplace_string = hierarchy_states[i]->get_state_name()
                            +QString(".signalEntered.connect<")
                            +class_name
                            +QString(", &")
                            +entryAction
                            +QString(">(&")
                            +class_name
                            +QString("_Instance);");
                    if(no_declaration_of_class_with_entries){

                        no_declaration_of_class_with_entries=false;
                        generate_definition_for_State_Machine_entries_funtions(main_thread_name, class_name);

                    }
                }

                if(main_cpp_FileProcessor.check_if_code_exist(toReplace_string, false)==0){

                    main_cpp_FileProcessor.setStartLine("/*Definition of all Entry Actions from State Machine*/");       ////inicio del contenido a eliminar
                    main_cpp_FileProcessor.setEndLine("/*Definition of all Entry Actions from State Machine*/"); ////fin del contenido a eliminar
                    main_cpp_FileProcessor.setReplacementString(QString("/*Definition of all Entry Actions from State Machine*/\n")
                                                                +QString("    ")+toReplace_string);
                    main_cpp_FileProcessor.processTextBlock();
                }

                entries_names.append(entryAction);

                if(!entryAction.contains("::")){

                    toReplace_string = QString("void ")
                            +entryAction+QString("(){\n\n}");

                    if(main_cpp_FileProcessor.check_if_code_exist(toReplace_string, false)==0){

                        main_cpp_FileProcessor.setStartLine("/*Implementation of Entry Functions of State Machine*/");       ////inicio del contenido a eliminar
                        main_cpp_FileProcessor.setEndLine("/*Implementation of Entry Functions of State Machine*/"); ////fin del contenido a eliminar
                        main_cpp_FileProcessor.setReplacementString(QString("/*Implementation of Entry Functions of State Machine*/\n")
                                                                    +toReplace_string);
                        main_cpp_FileProcessor.processTextBlock();
                    }
                }
            }
        }
        ////***************************************************************************************************************************************

        /*Definition of all Exit Functions from State Machine*////**********************************************************************************
        {
            QString exitAction = hierarchy_states[i]->get_state_on_exit_Action();
            if(exitAction!= "No Exit Action" && !exits_names.contains(exitAction)){

                exits_names.append(exitAction);

                if(!exitAction.contains("::")){
                    toReplace_string = QString("void ")+exitAction
                            +QString("();");

                    if(main_cpp_FileProcessor.check_if_code_exist(toReplace_string, false)==0){

                        main_cpp_FileProcessor.setStartLine("/*Definition of Exit Functions Prototypes of State Machine*/");       ////inicio del contenido a eliminar
                        main_cpp_FileProcessor.setEndLine("/*Definition of Exit Functions Prototypes of State Machine*/"); ////fin del contenido a eliminar
                        main_cpp_FileProcessor.setReplacementString(QString("/*Definition of Exit Functions Prototypes of State Machine*/\n\n")
                                                                    +toReplace_string);
                        main_cpp_FileProcessor.processTextBlock();
                    }
                }

                if(!exitAction.contains("::")){
                toReplace_string = hierarchy_states[i]->get_state_name()
                        +QString(".signalExited.connect<&")
                        +exitAction+QString(">();");
                }
                else{

                    QString class_name = exitAction.section(':',0,0);

                    toReplace_string = hierarchy_states[i]->get_state_name()
                            +QString(".signalEntered.connect<")
                            +class_name
                            +QString(", &")
                            +exitAction
                            +QString(">(&")
                            +class_name
                            +QString("_Instance);");
                }

                if(main_cpp_FileProcessor.check_if_code_exist(toReplace_string, false)==0){
                    main_cpp_FileProcessor.setStartLine("/*Definition of all Exit Actions from State Machine*/");       ////inicio del contenido a eliminar
                    main_cpp_FileProcessor.setEndLine("/*Definition of all Exit Actions from State Machine*/"); ////fin del contenido a eliminar
                    main_cpp_FileProcessor.setReplacementString(QString("/*Definition of all Exit Actions from State Machine*/\n")
                                                                +QString("    ")+toReplace_string);
                    main_cpp_FileProcessor.processTextBlock();
                }
                
                exits_names.append(exitAction);

                if(!exitAction.contains("::")){

                    toReplace_string = QString("void ")
                            +exitAction+QString("(){\n\n}");
                    if(main_cpp_FileProcessor.check_if_code_exist(toReplace_string, false)==0){

                        main_cpp_FileProcessor.setStartLine("/*Implementation of Exit Functions of State Machine*/");       ////inicio del contenido a eliminar
                        main_cpp_FileProcessor.setEndLine("/*Implementation of Exit Functions of State Machine*/"); ////fin del contenido a eliminar
                        main_cpp_FileProcessor.setReplacementString(QString("/*Implementation of Exit Functions of State Machine*/\n")
                                                                    +toReplace_string);
                        main_cpp_FileProcessor.processTextBlock();
                    }
                }
            }
        }
        ////***************************************************************************************************************************************
        
        /*Comprobacion de que cada estado tenga estado siguiente*////******************************************************************************************************************
        quint8 next_states_size=0;
        for(quint16 n=0; n< hierarchy_states[i]->get_events_list().size(); n++){

            if(hierarchy_states[i]->get_events_list()[n].next_state!="No Next State"){
                next_states_size++;
            }

            /*Definition of all Events from State Machine*////************************************************************************************************************************************************
            {
                QString event_id = hierarchy_states[i]->get_events_list()[n].event;
                if(event_id!= "No Event" ){ ////si no es un evento vacio y no esta definido previamente

                    if(!events_ids.contains(event_id)){

                        events_ids.append(event_id);
                        if(first_event){
                            generate_definition_for_State_Machine_events(main_thread_name, event_id, false, true);
                            first_event = false;
                        }
                        else{
                            generate_definition_for_State_Machine_events(main_thread_name, event_id, false, false);
                        }
                    }
                    QString next_state = "";
                    QString action_state = "";
                    if(hierarchy_states[i]->get_events_list()[n].state_action != "No Action"){

                        action_state = QString(", ")+hierarchy_states[i]->get_events_list()[n].state_action;
                    }
                    if(hierarchy_states[i]->get_events_list()[n].next_state != "No Next State"){

                        next_state = QString(",")+hierarchy_states[i]->get_events_list()[n].next_state;
                    }

                    toReplace_string = hierarchy_states[i]->get_state_name()
                            +QString(".addEvent(")+event_id
                            +next_state+action_state
                            +QString(");");
                    if(main_cpp_FileProcessor.check_if_code_exist(toReplace_string, false)==0){

                        main_cpp_FileProcessor.setStartLine("/*Adding all Events from State Machine*/");       ////inicio del contenido a eliminar
                        main_cpp_FileProcessor.setEndLine("/*Adding all Events from State Machine*/"); ////fin del contenido a eliminar
                        main_cpp_FileProcessor.setReplacementString(QString("/*Adding all Events from State Machine*/\n")
                                                                    +QString("    ")+toReplace_string);

                        main_cpp_FileProcessor.processTextBlock();
                    }

                }
            }
            ///****************************************************************************************************************************************************


            ///*******************************************************************************************************************************************************
            /*Definition of all Actions from State Machine*////******************************************************************************************************************
            {

                QString action = hierarchy_states[i]->get_events_list()[n].state_action;
                if(action!= "No Action" && !actions_names.contains(action)){ ////si existe accion y no esta definida previamente

                    actions_names.append(action);

                    /*Definition of all Actions prototypes */////********************************************************************************************************
                    generate_definition_for_State_Machine_actions(main_thread_name, action);
                    ////**********************************************************************************************************************************************

                    /*Definition of all Actions *////******************************************************************************************************************
                    {
                        toReplace_string = action+QString(";\n    ")+action
                                +QString(".bind<")+main_thread_name+QString(", &")+main_thread_name
                                +QString("::")+action+QString(">(this);");
                        if(main_cpp_FileProcessor.check_if_code_exist(toReplace_string, false)==0){

                            main_cpp_FileProcessor.setStartLine("/*Definition of all eAction from State Machine*/");       ////inicio del contenido a eliminar
                            main_cpp_FileProcessor.setEndLine("/*Definition of all eAction from State Machine*/"); ////fin del contenido a eliminar
                            main_cpp_FileProcessor.setReplacementString(QString("/*Definition of all eAction from State Machine*/\n")
                                                                        +QString("    eObject::eState::eAction_t ")
                                                                        +toReplace_string);
                            main_cpp_FileProcessor.processTextBlock();
                        }
                    }
                    ///*************************************************************************************************************************************************

                    /*Implementation of all Actions functions *////*****************************************************************************************************
                    {
                        toReplace_string = main_thread_name+QString("::")
                                +action+QString("(int event){\n\n}");
                        if(main_cpp_FileProcessor.check_if_code_exist(toReplace_string, false)==0){

                            main_cpp_FileProcessor.setStartLine("/*Implementation of Action Prototypes of State Machine*/");       ////inicio del contenido a eliminar
                            main_cpp_FileProcessor.setEndLine("/*Implementation of Action Prototypes of State Machine*/"); ////fin del contenido a eliminar
                            main_cpp_FileProcessor.setReplacementString(QString("/*Implementation of Action Prototypes of State Machine*/\n")
                                                                        +QString("void ")+toReplace_string);
                            main_cpp_FileProcessor.processTextBlock();
                        }
                    }
                    ////*************************************************************************************************************************************************
                }
            }
            ///******************************************************************************************************************************************************

        }
        if(hierarchy_states[i]->get_events_list().size() == 0 && !hierarchy_states[i]->get_direct_SubStates().isEmpty()){

            QMessageBox::warning(this, "NEOWizard",QString("<font color = white >The State : ")
                                 +hierarchy_states[i]->get_state_name()
                                 +QString(" has no Next State (transitions).")
                                 +QString("<br>This will give you a compile error.")
                                 +QString("<br>Please set a transition to this state"));
        }
        ///*********************************************************************************************************************************************************


        /*Definition of all eState from State Machine*////******************************************************************************************************************
        {
            toReplace_string = QString::number((hierarchy_states[i]->get_events_list().size()<1)?1:hierarchy_states[i]->get_events_list().size())
                    +QString("> ")+hierarchy_states[i]->get_state_name()+QString(";");
            if(main_cpp_FileProcessor.check_if_code_exist(toReplace_string, false)==0){

                main_cpp_FileProcessor.setStartLine("/*Definition of all eState from State Machine*/");       ////inicio del contenido a eliminar
                main_cpp_FileProcessor.setEndLine("/*Definition of all eState from State Machine*/"); ////fin del contenido a eliminar
                main_cpp_FileProcessor.setReplacementString(QString("/*Definition of all eState from State Machine*/\n")
                                                            +QString("    eObject::Declare::eState<")
                                                            +toReplace_string);
                main_cpp_FileProcessor.processTextBlock();
            }
        }
        ///*******************************************************************************************************************************************************************


        /*Definition of all SuperStates from State Machine*////******************************************************************************************************************
        {
            if(hierarchy_states[i]->get_state_parent()!="No Parent"){

                toReplace_string = hierarchy_states[i]->get_state_name()
                        +QString(".setSuperstate(")
                        +hierarchy_states[i]->get_state_parent()
                        +QString(");");
                if(main_cpp_FileProcessor.check_if_code_exist(toReplace_string, false)==0){

                    main_cpp_FileProcessor.setStartLine("/*Definition of all SuperStates from State Machine*/");       ////inicio del contenido a eliminar
                    main_cpp_FileProcessor.setEndLine("/*Definition of all SuperStates from State Machine*/"); ////fin del contenido a eliminar
                    main_cpp_FileProcessor.setReplacementString(QString("/*Definition of all SuperStates from State Machine*/\n    ")
                                                                +toReplace_string);
                    main_cpp_FileProcessor.processTextBlock();
                }
            }
            else{ ////codigo para los estados sin padre
                if(hierarchy_states[i]->isInitial()){

                    toReplace_string = QString("hsm.setInitialState(")
                            +hierarchy_states[i]->get_state_name()
                            +QString(");");

                    if(main_cpp_FileProcessor.check_if_code_exist(toReplace_string, false)==0){

                        main_cpp_FileProcessor.setStartLine("/*Definition of the Inicial State of State Machine*/");       ////inicio del contenido a eliminar
                        main_cpp_FileProcessor.setEndLine("/*Definition of the Inicial State of State Machine*/"); ////fin del contenido a eliminar
                        main_cpp_FileProcessor.setReplacementString(QString("/*Definition of the Inicial State of State Machine*/\n    ")
                                                                    +QString("eObject::eHierarchicalStateMachine &hsm = controlerHSM;\n    ")
                                                                    +toReplace_string);
                        main_cpp_FileProcessor.processTextBlock();
                    }
                }

            }
        }
        ///******************************************************************************************************************************************************************


        /*Definition of all Inicial States from State Machine*////******************************************************************************************************************
        {
            int index_initial_sub_state = get_child_initial_index(hierarchy_states[i]->get_state_name());
            if(index_initial_sub_state!=-1){ ////si tiene estado inicial

                toReplace_string = hierarchy_states[i]->get_state_name()
                        +QString(".setInitialSubState(")
                        +hierarchy_states[index_initial_sub_state]->get_state_name()
                        +QString(");\n");

                if(main_cpp_FileProcessor.check_if_code_exist(toReplace_string, false)==0){
                    main_cpp_FileProcessor.setStartLine("/*Definition of all Inicial States from State Machine*/");       ////inicio del contenido a eliminar
                    main_cpp_FileProcessor.setEndLine("/*Definition of all Inicial States from State Machine*/"); ////fin del contenido a eliminar
                    main_cpp_FileProcessor.setReplacementString(QString("/*Definition of all Inicial States from State Machine*/\n    ")
                                                                +toReplace_string);
                    main_cpp_FileProcessor.processTextBlock();
                }
            }
            else{
                if(!hierarchy_states[i]->get_direct_SubStates().isEmpty()){

                    QMessageBox::warning(this, "NEOWizard",QString("<font color = white >The State : ")
                                         +hierarchy_states[i]->get_state_name()
                                         +QString(" has no Initial State.")
                                         +QString("<br>This will give you a run error."));
                }
            }
        }
        ///************************************************************************************************************************************************************
    }
    ///************************************************************************************************************************************************************

    /*Start of State Machine*////******************************************************************************************************************
    {
        toReplace_string = QString("    hsm.start();\n\n      std::uint32_t eventId;\n\n    while(true){\n")
                +QString("      instance().appEventQueue.get(eventId);\n")
                +QString("      hsm.dispatch(eventId);\n}");
        if(main_cpp_FileProcessor.check_if_code_exist(toReplace_string, false)==0){
            main_cpp_FileProcessor.setStartLine("/*Start of State Machine*/");       ////inicio del contenido a eliminar
            main_cpp_FileProcessor.setEndLine("/*Start of State Machine*/"); ////fin del contenido a eliminar
            main_cpp_FileProcessor.setReplacementString(QString("/*Start of State Machine*/\n")
                                                        +toReplace_string);
            main_cpp_FileProcessor.processTextBlock();
        }
    }
    ///*******************************************************************************************************************************************************************

    main_cpp_FileProcessor.setFilename(fileuVision_Path+QString("/Include/")+main_thread_name+QString(".h"));
    if(main_cpp_FileProcessor.check_if_code_exist(",};", false)==1){
        main_cpp_FileProcessor.setStartLine(",};");       ////inicio del contenido a eliminar
        main_cpp_FileProcessor.setEndLine(",};"); ////fin del contenido a eliminar
        main_cpp_FileProcessor.setReplacementString("\n};\n");
        main_cpp_FileProcessor.processTextBlock();
    }
    ui->widget_wait->hide();
}

int NFWizard2::get_child_initial_index(const QString &superState){

    int index_parent = get_state_index_with_name(superState);
    int index = -1;

    for(quint16 i=0; i< hierarchy_states[index_parent]->get_direct_SubStates().size(); i++){

        index = get_state_index_with_name(hierarchy_states[index_parent]->get_direct_SubStates()[i]);

        if(hierarchy_states[index]->isInitial()){

            return index;
        }
    }
    return -1;
}

void NFWizard2::on_pb_set_as_initial_clicked()
{
    int index = get_state_index_with_name(current_state);
    int index_parent = get_state_index_with_name(hierarchy_states[index]->get_state_parent());
    int index_other =0;

    if(index_parent!=-1){////Estado sin "No Parent"

        for(quint16 i=0; i< hierarchy_states[index_parent]->get_direct_SubStates().size(); i++){

            index_other = get_state_index_with_name(hierarchy_states[index_parent]->get_direct_SubStates()[i]);
            hierarchy_states[index_other]->setInitial(false);
            ////aqui cambiar foto de fondo de todos los estado
        }
        hierarchy_states[index_parent]->set_state_initial(current_state);
        hierarchy_states[index]->setInitial(true);

    }
    else{ ////Estado con "No Parent"
        for(quint16 i=0; i< hierarchy_states.size(); i++){

            if(hierarchy_states[i]->get_state_parent()=="No Parent"){
                hierarchy_states[i]->setInitial(false);
            }
        }
        hierarchy_states[index]->setInitial(true);
        ////aqui cambiar foto de fondo de este estado (circulo con i de inicial)
    }
    ui->widget_on_state_options->hide();

    if(index_parent!=-1){
        hierarchy_states[index_parent]->setToolTip(QString("<font color =  green >State Name : ")+hierarchy_states[index_parent]->get_state_name()
                                                   +QString("<br>Super State : ")+hierarchy_states[index_parent]->get_state_parent()
                                                   +QString("<br>Initial State  : "+hierarchy_states[index_parent]->get_state_initial())
                                                   +QString("<br>Next State   : ")+hierarchy_states[index_parent]->get_events_list()[0].next_state);
    }

    emit check_warnings();
}

void NFWizard2::on_pb_acept_main_thread_clicked()
{
    if(ui->le_main_thread_name->text().isEmpty()){

        QMessageBox::information(this, "NEOWizard",QString("<font color = white >Insert Main Thread name"));
        return;
    }
    ui->pb_acept_main_thread->hide();
    ui->pb_add_thread->show();
    ui->widget_options_thread_options->hide();
    ui->widget_options_thread_options->move(350,40);

}


void NFWizard2::on_le_event_ID_name_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){
        QStringList complete_list;
        for(quint16 i=0; i< hierarchy_states.size(); i++){
            for(quint16 n=0; n< hierarchy_states[i]->get_events_list().size(); n++){

                if(hierarchy_states[i]->get_events_list()[n].event.contains(arg1, Qt::CaseInsensitive) && hierarchy_states[i]->get_events_list()[n].event != "No Event"){
                    complete_list.append(hierarchy_states[i]->get_events_list()[n].event);
                }
            }
        }

        complete_list_object_events = new QCompleter(complete_list,this);

        complete_list_object_events->setCaseSensitivity(Qt::CaseInsensitive);
        complete_list_object_events->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
        ui->le_event_ID_name->setCompleter(complete_list_object_events);

        connect(complete_list_object_events,SIGNAL(highlighted(QString)),this, SLOT(on_selected_event(QString)));
    }
}



void NFWizard2::on_le_next_state_name_textChanged(const QString &arg1)
{

    if(!arg1.isEmpty()){
        QStringList complete_list;
        for(quint16 i=0; i< hierarchy_states.size(); i++){
            if(hierarchy_states[i]->get_state_name().contains(arg1, Qt::CaseInsensitive)){
                complete_list.append(hierarchy_states[i]->get_state_name());
            }
        }

        complete_list_object_states = new QCompleter(complete_list,this);

        complete_list_object_states->setCaseSensitivity(Qt::CaseInsensitive);
        complete_list_object_states->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
        ui->le_next_state_name->setCompleter(complete_list_object_states);
    }

}

void NFWizard2::on_le_action_name_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){
        QStringList complete_list;
        for(quint16 i=0; i< hierarchy_states.size(); i++){
            for(quint16 n=0; n< hierarchy_states[i]->get_events_list().size(); n++){

                if(hierarchy_states[i]->get_events_list()[n].state_action.contains(arg1, Qt::CaseInsensitive) && hierarchy_states[i]->get_events_list()[n].state_action != "No Action"){
                    complete_list.append(hierarchy_states[i]->get_events_list()[n].state_action);
                }
            }
        }

        complete_list_object_actions = new QCompleter(complete_list,this);

        complete_list_object_actions->setCaseSensitivity(Qt::CaseInsensitive);
        complete_list_object_actions->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
        ui->le_action_name->setCompleter(complete_list_object_actions);
    }
}

void NFWizard2::on_le_entry_action_textChanged(const QString &arg1)
{

    if(!arg1.isEmpty()){
        QStringList complete_list;
        for(quint16 i=0; i< hierarchy_states.size(); i++){

            if(hierarchy_states[i]->get_state_on_entry_Action().contains(arg1, Qt::CaseInsensitive)){
                complete_list.append(hierarchy_states[i]->get_state_on_entry_Action());
            }

        }

        complete_list_object_fuctions_exits_entries = new QCompleter(complete_list,this);

        complete_list_object_fuctions_exits_entries->setCaseSensitivity(Qt::CaseInsensitive);
        complete_list_object_fuctions_exits_entries->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
        ui->le_entry_action->setCompleter(complete_list_object_fuctions_exits_entries);

    }
}

void NFWizard2::on_le_exit_action_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){
        QStringList complete_list;
        for(quint16 i=0; i< hierarchy_states.size(); i++){

            if(hierarchy_states[i]->get_state_on_exit_Action().contains(arg1, Qt::CaseInsensitive)){
                complete_list.append(hierarchy_states[i]->get_state_on_exit_Action());
            }

        }

        complete_list_object_fuctions_exits_entries = new QCompleter(complete_list,this);

        complete_list_object_fuctions_exits_entries->setCaseSensitivity(Qt::CaseInsensitive);
        complete_list_object_fuctions_exits_entries->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
        ui->le_exit_action->setCompleter(complete_list_object_fuctions_exits_entries);

    }
}

void NFWizard2::on_le_super_state_name_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){
        QStringList complete_list;
        for(quint16 i=0; i< hierarchy_states.size(); i++){
            if(hierarchy_states[i]->get_state_name().contains(arg1, Qt::CaseInsensitive)){
                complete_list.append(hierarchy_states[i]->get_state_name());
            }
        }

        complete_list_object_states = new QCompleter(complete_list,this);

        complete_list_object_states->setCaseSensitivity(Qt::CaseInsensitive);
        complete_list_object_states->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
        ui->le_super_state_name->setCompleter(complete_list_object_states);
    }

}

void NFWizard2::on_le_initial_state_name_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){
        QStringList complete_list;
        int index = get_state_index_with_name(current_state);
        for(quint16 i=0; i< hierarchy_states[index]->get_direct_SubStates().size(); i++){
            if(hierarchy_states[index]->get_direct_SubStates()[i].contains(arg1, Qt::CaseInsensitive)){
                complete_list.append(hierarchy_states[index]->get_direct_SubStates()[i]);
            }
        }

        complete_list_object_states = new QCompleter(complete_list,this);

        complete_list_object_states->setCaseSensitivity(Qt::CaseInsensitive);
        complete_list_object_states->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
        ui->le_initial_state_name->setCompleter(complete_list_object_states);
    }
}

void NFWizard2::on_le_default_state_name_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){
        QStringList complete_list;
        for(quint16 i=0; i< hierarchy_states.size(); i++){
            if(hierarchy_states[i]->get_state_name().contains(arg1, Qt::CaseInsensitive)){
                complete_list.append(hierarchy_states[i]->get_state_name());
            }
        }

        complete_list_object_states = new QCompleter(complete_list,this);

        complete_list_object_states->setCaseSensitivity(Qt::CaseInsensitive);
        complete_list_object_states->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
        ui->le_default_state_name->setCompleter(complete_list_object_states);
    }
}

void NFWizard2::on_pb_load_state_machine_clicked()
{
    ui->widget_state_machine_name->show();
    isLoad = true;
}

void NFWizard2::on_pb_save_state_machine_clicked()
{
    ui->widget_state_machine_name->show();
    isLoad = false;

}

void NFWizard2::on_pb_acept_sate_machine_name_clicked()
{
    ui->widget_state_machine_name->hide();

    if(!isLoad){

        QStringList projectFolderTree;
        projectFolderTree << "HSMs";
        QFileInfo fileInfo(fileuVision);
        FolderTreeGenerator::generateFileTree(fileInfo.dir().path(), projectFolderTree);

        QFile *data_base = new QFile(fileInfo.dir().path()+QString("/HSMs/")+ui->le_state_machine_name->text() +QString(".dat"),this);

        if(data_base->open(QIODevice::WriteOnly))
        {
            qDebug()<<data_base->fileName();

            QDataStream out(data_base);
            out.setVersion(QDataStream::Qt_5_9);

            for(quint8 i=0; i< hierarchy_states.size(); i++){

                hierarchy_states[i]->write_file(out);
            }

            data_base->close();

            QMessageBox::information(this,"Information","<font color=white>Saved State Machine:  "+hierarchy_states[0]->get_state_name(),QMessageBox::Ok);
        }
    }
    else if(isLoad){

        QFile *data_base = new QFile(fileuVision_Path+QString("/HSMs/")+ui->le_state_machine_name->text() +QString(".dat"),this);

        if (!data_base->exists()) {
            qWarning() << "file: " << data_base->fileName() << " not found!";
            QMessageBox::information(this,"Information","<font color=white>Cannot Load State Machine:  "+ui->le_state_machine_name->text(),QMessageBox::Ok);
            return;
        }

        if(!ui->widget_on_state_options->isHidden()){

            ui->widget_on_state_options->hide();
        }
        for(quint16 i=0; i< hierarchy_states.size(); i++){

            hierarchy_states[i]->hide();
            hierarchy_states[i]->deleteLater();
        }
        hierarchy_states.clear();

        if(data_base->open(QIODevice::ReadOnly))
        {
            qDebug()<<data_base->fileName();

            QDataStream in(data_base);
            in.setVersion(QDataStream::Qt_5_9);

            while(!data_base->atEnd()){

                QHierarchy_State *state = new QHierarchy_State(ui->widget_states,"unknow");

                state->read_file(in);

                connect(state,SIGNAL(signal_clicked(QString)),this,SLOT(on_state_clicked(QString)));
                connect(state,SIGNAL(signal_toggled(QString)),this,SLOT(on_state_toggled(QString)));
                state->setToolTip(QString("<font color =  green >State Name : ")+state->get_state_name()
                                  +QString("<br>Super State : ")+state->get_state_parent()
                                  +QString("<br>Initial State  : "+state->get_state_initial())
                                  +QString("<br>Next State   : ")+state->get_events_list()[0].next_state);
                hierarchy_states.append(state);
            }

            data_base->close();

            QMessageBox::information(this,"Information","<font color=white>Load State Machine:  "+hierarchy_states[0]->get_state_name(),QMessageBox::Ok);
        }
        draw_super_state(hierarchy_states[0]->get_state_parent());
    }
}

void NFWizard2::on_pb_cancel_state_machine_name_clicked()
{
    ui->widget_state_machine_name->hide();
    ui->le_state_machine_name->clear();
}

void NFWizard2::on_le_state_machine_name_textChanged(const QString &arg1)
{
    QFileInfo fileInfo(fileuVision);
    QDir directory(fileInfo.dir().path()+QString("/HSMs"));
    QStringList saved_state_machines_list = directory.entryList(QStringList() << "*.dat" << "*.DAT"<<"*.txt"<<"*.TXT",QDir::Files);

    if(!arg1.isEmpty()){
        QStringList complete_list;
        for(quint16 i=0; i< saved_state_machines_list.size(); i++){
            if(saved_state_machines_list[i].contains(arg1, Qt::CaseInsensitive)){
                QString n = saved_state_machines_list[i];
                n.chop(4);
                complete_list.append(n);
            }
        }

        if(!complete_list.isEmpty()){
            complete_list_saved_states = new QCompleter(complete_list,this);

            complete_list_saved_states->setCaseSensitivity(Qt::CaseInsensitive);
            complete_list_saved_states->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
            ui->le_state_machine_name->setCompleter(complete_list_saved_states);
        }
    }
}

void NFWizard2::on_pb_add_event_action_clicked()
{
    ui->widget_add_delete_event->hide();
    ui->widget_event_options->show();
    ui->pb_add_event->show();
    ui->pb_delete_event->hide();
}

void NFWizard2::on_pb_delete_event_action_clicked()
{
    ui->widget_add_delete_event->hide();

    int index = get_state_index_with_name(current_state);

    if(index!=-1){

        if(!hierarchy_states[index]->get_events_list().isEmpty()){
            if(hierarchy_states[index]->get_events_list()[0].event == "No Event"){

                QMessageBox::warning(this, tr("NFWizard2"),tr("<font color = white >This State has no Events to erase"));
                return;
            }
        }
    }
    ui->widget_event_options->show();
    ui->pb_add_event->hide();
    ui->pb_delete_event->show();
}

void NFWizard2::on_pb_cancel_add_event_2_clicked()
{
    ui->widget_add_delete_event->hide();
}

void NFWizard2::on_pb_delete_event_clicked()
{
    ui->widget_event_options->hide();

    int index = get_state_index_with_name(current_state);

    if(index!=-1){

        if(ui->le_event_ID_name->text().isEmpty()){

            QMessageBox::warning(this, tr("NFWizard2"),tr("<font color = white >Insert Event ID name to Erase"));
            return;
        }

        for(quint16 i =0; i< hierarchy_states[index]->get_events_list().size(); i++){

            if(hierarchy_states[index]->get_events_list()[i].event == ui->le_event_ID_name->text()){

                hierarchy_states[index]->get_events_list().removeAt(i);
            }

        }
        if(hierarchy_states[index]->get_events_list().isEmpty()){

            hierarchy_states[index]->add_Event("No Event", "No Next State", "No Action");

            ui->lw_Events->clear();
            ui->lw_Next_State->clear();
            ui->lw_Actions->clear();

            ui->lw_Events->addItem(QString("No Event"));
            ui->lw_Next_State->addItem(QString("No Next State"));
            ui->lw_Actions->addItem(QString("No Action"));
        }
        else{

            QStringList temp_to_add_events;
            QStringList temp_to_add_next_state;
            QStringList temp_to_add_actions;
            ui->lw_Events->clear();
            ui->lw_Next_State->clear();
            ui->lw_Actions->clear();
            for(quint16 i =0; i< hierarchy_states[index]->get_events_list().size(); i++){
               temp_to_add_events.append( hierarchy_states[index]->get_events_list()[i].event);
               temp_to_add_next_state.append( hierarchy_states[index]->get_events_list()[i].next_state);
               temp_to_add_actions.append( hierarchy_states[index]->get_events_list()[i].state_action);
            }

            ui->lw_Events->addItems(temp_to_add_events);
            ui->lw_Next_State->addItems(temp_to_add_next_state);
            ui->lw_Actions->addItems(temp_to_add_actions);
        }
    }
}

void NFWizard2::on_selected_event(const QString &arg1){

    int index = get_state_index_with_name(current_state);

    if(index!=-1){

        for(quint16 i =0; i< hierarchy_states[index]->get_events_list().size(); i++){

            if(hierarchy_states[index]->get_events_list()[i].event == arg1){

                ui->le_next_state_name->setText(hierarchy_states[index]->get_events_list()[i].next_state);
                ui->le_action_name->setText(hierarchy_states[index]->get_events_list()[i].state_action);
            }

        }
    }
}

void NFWizard2::on_pb_load_from_Thread_clicked()
{


    if(ui->le_main_thread_name->text().isEmpty()){

        QMessageBox::information(this, "NEOWizard","<font color = white >Insert name of main thread and try again");
        ui->widget_options_thread_options->show();
        ui->widget_options_thread_options->move(500,140);
        ui->le_main_thread_name->show();
        ui->l_main_thread_name->show();
        ui->le_thread_name->hide();
        ui->l_thread_name->hide();
        ui->l_thread_priority->hide();
        ui->cb_thread_priority->hide();
        ui->l_thread_stack_size->hide();
        ui->sb_thread_stack_size->hide();
        ui->pb_add_thread->hide();
        ui->pb_acept_main_thread->show();
        return;
    }

    ui->widget_wait->show();
    ui->label_loading->setText("LOADING...");

    if(QMessageBox::information(this,"Confirmation","<font color=white >Load State Machine",QMessageBox::Ok,QMessageBox::Cancel)==QMessageBox::Ok){

        if(!ui->widget_on_state_options->isHidden()){

            ui->widget_on_state_options->hide();
        }
        load_state_machine_from_Thread(fileuVision_Path, ui->le_main_thread_name->text());
    }

    ui->widget_wait->hide();
}

int NFWizard2::load_state_machine_from_Thread(const QString path, const QString main_thread_name){


    TextFileProcessor main_FileProcessor;

    main_FileProcessor.setFilename(path+QString("/Source/")+main_thread_name+QString(".cpp"));

    QApplication::setOverrideCursor(Qt::WaitCursor);

    ////Obtiene estados********************************************************************************************************
    main_FileProcessor.setStartLine("eObject::Declare::eState");
    main_FileProcessor.setEndLine(";");

    QStringList definitions = main_FileProcessor.get_text_between();
    QStringList states_list;
    for(quint16 i=0; i< definitions.size(); i++){

        if(!((definitions[i]).isEmpty()) && definitions[i]!="End String"){
            states_list.append(definitions[i].simplified().section('>',1,1).remove(" ").remove(";"));//.remove("state"));
        }
    }

    for(quint16 i=0; i< hierarchy_states.size(); i++){  ////Borrar maquinas guardadas y vaciar lista de maquinas

        hierarchy_states[i]->hide();
        hierarchy_states[i]->deleteLater();
    }
    hierarchy_states.clear();

    for(quint16 i=0; i< states_list.size(); i++){

        if(!((definitions[i]).isEmpty())){
            add_state_in_superstate(QString("No Parent"),states_list[i], false);
        }
    }

    definitions.clear();
    states_list.clear();
    ////************************************************************************************************************************


    ////Obtiene Estado Inicial********************************************************************************************************

    main_FileProcessor.setStartLine(".setInitialState");
    main_FileProcessor.setEndLine(";");

    definitions = main_FileProcessor.get_text_between();

    for(quint16 n=0; n< definitions.size(); n++){

        if(!((definitions[n]).isEmpty())
                && definitions[n]!="End String"
                && definitions[n]!="Not Found String"
                && definitions[n]!="Not Found"
                && definitions[n]!="No File"){

            QString parent_state;
            parent_state =(definitions[n].simplified().section('(',1,1).remove(" ").remove(")").remove(";"));//.remove("state"));
            int index = get_state_index_with_name(parent_state);
            if(index!=-1){

                hierarchy_states[index]->setInitial(true);
            }
        }
    }

    definitions.clear();
    ////*************************************************************************************************************************


    ////Obtiene superEstados********************************************************************************************************

    QString parent_state;
    for(quint16 i=0; i< hierarchy_states.size(); i++){

        main_FileProcessor.setStartLine(hierarchy_states[i]->get_state_name()+QString(".setSuperstate"));
        main_FileProcessor.setEndLine(";");

        definitions = main_FileProcessor.get_text_between();

        for(quint16 n=0; n< definitions.size(); n++){

            if(!((definitions[n]).isEmpty())
                    && definitions[n]!="End String"
                    && definitions[n]!="Not Found String"
                    && definitions[n]!="Not Found"){

                parent_state =(definitions[n].simplified().section('(',1,1).remove(" ").remove(")").remove(";"));//.remove("state"));

                int index = get_state_index_with_name(parent_state);
                if(index!=-1){

                    hierarchy_states[i]->set_state_parent(parent_state);
                    hierarchy_states[index]->add_direct_sub_State(hierarchy_states[i]->get_state_name());
                }
            }
        }
    }
    definitions.clear();
    ////*************************************************************************************************************************


    ////Obtiene Estados Iniciales********************************************************************************************************
    for(quint16 i=0; i< hierarchy_states.size(); i++){

        main_FileProcessor.setStartLine(hierarchy_states[i]->get_state_name()+QString(".setInitialSubState"));
        main_FileProcessor.setEndLine(";");

        definitions = main_FileProcessor.get_text_between();

        for(quint16 n=0; n< definitions.size(); n++){

            if(!((definitions[n]).isEmpty())
                    && definitions[n]!="End String"
                    && definitions[n]!="Not Found String"
                    && definitions[n]!="Not Found"
                    && definitions[n]!="No File"){

                QString child_initial_state;
                child_initial_state =(definitions[n].simplified().section('(',1,1).remove(" ").remove(")").remove(";"));//.remove("state"));

                hierarchy_states[i]->set_state_initial(child_initial_state);

                int index = get_state_index_with_name(child_initial_state);
                if(index!=-1){

                    hierarchy_states[index]->setInitial(true);
                }
            }
        }
    }
    definitions.clear();
    ////*************************************************************************************************************************


    ////Guarda declaracion de acciones*************************************************************************************************************************

    QStringList action_list;

    main_FileProcessor.setStartLine("eObject::eState::eAction_t");
    main_FileProcessor.setEndLine(";");

    definitions = main_FileProcessor.get_text_between();

    for(quint16 i=0; i< definitions.size(); i++){

        if(!((definitions[i]).isEmpty())
                && definitions[i]!="End String"
                && definitions[i]!="Not Found String"
                && definitions[i]!="Not Found"
                && definitions[i]!="No File"){

            action_list.append(definitions[i].simplified().section(' ',1,1).remove(" ").remove(";"));//.remove("state"));
        }
    }

    definitions.clear();
    ////*************************************************************************************************************************


    ////Añade eventos, estados siguientes y acciones********************************************************************************************************

    for(quint16 i=0; i< hierarchy_states.size(); i++){

        main_FileProcessor.setStartLine(hierarchy_states[i]->get_state_name()+QString(".addEvent"));
        main_FileProcessor.setEndLine(";");

        definitions = main_FileProcessor.get_text_between();

        for(quint16 n=0; n< definitions.size(); n++){

            if(!((definitions[n]).isEmpty())
                    && definitions[n]!="End String"
                    && definitions[n]!="Not Found String"
                    && definitions[n]!="Not Found"
                    && definitions[n]!="No File"){

                QString event_struct;
                event_struct =(definitions[n].simplified().section('(',1,1));//.remove("state"));
                QStringList event_split = event_struct.split(",",QString::SkipEmptyParts);

                for(quint8 c=0; c < event_split.size(); c++){

                    event_split[c].remove(" ").remove(")").remove(";");

                }

                if(event_split.size()==2){  ////Evento y accion o estado siguiente

                    if(action_list.contains(event_split[1])){

                        hierarchy_states[i]->add_Event(event_split[0], "No Next State",event_split[1]);
                    }
                    else{
                        hierarchy_states[i]->add_Event(event_split[0], event_split[1], "No Action");
                    }
                }
                else if (event_split.size()==3){
                     ////Evento y accion y estado siguiente
                     hierarchy_states[i]->add_Event(event_split[0], event_split[1], event_split[2]);
                }
            }
        }
    }
    definitions.clear();
    ////*************************************************************************************************************************


    ////Obtiene Acciones de Entrada********************************************************************************************************
    for(quint16 i=0; i< hierarchy_states.size(); i++){

        main_FileProcessor.setStartLine(hierarchy_states[i]->get_state_name()+QString(".signalEntered.connect"));
        main_FileProcessor.setEndLine(";");

        definitions = main_FileProcessor.get_text_between();

        for(quint16 n=0; n< definitions.size(); n++){

            if(!((definitions[n]).isEmpty())
                    && definitions[n]!="End String"
                    && definitions[n]!="Not Found String"
                    && definitions[n]!="Not Found"
                    && definitions[n]!="No File"){

                QString entry_action;

                entry_action =(definitions[n].simplified().section('<',1,1).remove(" ")
                                      .remove(">").remove("(").remove(")").remove(";"));//.remove("state"));

                if(entry_action.contains("::")){

                    entry_action = entry_action.section(',',1,1);
                    entry_action = entry_action.section('&',1,1);
                }
                else{

                    entry_action.remove("&");
                }
                hierarchy_states[i]->set_state_entryAction(entry_action);

            }
        }
    }
    definitions.clear();
    ////*************************************************************************************************************************


    ////Obtiene Acciones de Salida********************************************************************************************************
    for(quint16 i=0; i< hierarchy_states.size(); i++){

        main_FileProcessor.setStartLine(hierarchy_states[i]->get_state_name()+QString(".signalExited.connect"));
        main_FileProcessor.setEndLine(";");

        definitions = main_FileProcessor.get_text_between();

        for(quint16 n=0; n< definitions.size(); n++){

            if(!((definitions[n]).isEmpty())
                    && definitions[n]!="End String"
                    && definitions[n]!="Not Found String"
                    && definitions[n]!="Not Found"
                    && definitions[n]!="No File"){

                QString exit_action;
                exit_action =(definitions[n].simplified().section('<',1,1).remove(" ")
                                      .remove(">").remove("(").remove(")").remove(";"));//.remove("state"));

                if(exit_action.contains("::")){

                    exit_action = exit_action.section(',',1,1);
                    exit_action = exit_action.section('&',1,1);
                }
                else{

                    exit_action.remove("&");
                }
                hierarchy_states[i]->set_state_exitAction(exit_action);

            }
        }
    }
    definitions.clear();
    ////*************************************************************************************************************************

    ////************************************************************************************************************************

    for(quint16 i=0; i< hierarchy_states.size();i++){
        hierarchy_states[i]->setToolTip(QString("<font color =  green >State Name : ")+hierarchy_states[i]->get_state_name()
                                                   +QString("<br>Super State : ")+hierarchy_states[i]->get_state_parent()
                                                   +QString("<br>Initial State  : "+hierarchy_states[i]->get_state_initial())
                                                   +QString("<br>Next State   : ")+hierarchy_states[i]->get_events_list()[0].next_state);
    }

    draw_super_state(QString("No Parent"), true, false);

    QApplication::restoreOverrideCursor();  

    return 1;
}


void NFWizard2::on_le_main_thread_name_textChanged(const QString &arg1)
{

    QFileInfo fileInfo(fileuVision);
    QDir directory(fileInfo.dir().path()+QString("/Source"));
    QStringList saved_thread_list = directory.entryList(QStringList() << "*.cpp" << "*.CPP",QDir::Files);

    if(!arg1.isEmpty()){
        QStringList complete_list;
        for(quint16 i=0; i< saved_thread_list.size(); i++){
            if(saved_thread_list[i].contains(arg1, Qt::CaseInsensitive)){
                QString n = saved_thread_list[i];
                n.chop(4);
                complete_list.append(n);
            }
        }

        if(!complete_list.isEmpty()){
            complete_list_saved_threads = new QCompleter(complete_list,this);

            complete_list_saved_threads->setCaseSensitivity(Qt::CaseInsensitive);
            complete_list_saved_threads->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
            ui->le_main_thread_name->setCompleter(complete_list_saved_threads);
        }
    }
}


void NFWizard2::on_pb_change_to_event_clicked()
{
    if(ui->widget_super_initial_default_state->isHidden()){

        ui->widget_super_initial_default_state->show();
        ui->widget_events->hide();
        ui->widget_state_name_entry_exit_actions->show();
        ui->pb_change_to_event->setText("Events");
    }
    else{
        ui->widget_state_name_entry_exit_actions->hide();
        ui->widget_super_initial_default_state->hide();
        ui->widget_events->show();
        ui->pb_change_to_event->setText("Back");
    }
}

void NFWizard2::on_tw_state_machine_itemClicked(QTreeWidgetItem *item, int column)
{
    //ui->statusBar->showMessage(item->text(column));

    int index = get_state_index_with_name(item->text(column));

    if(index !=-1){
        draw_super_state(hierarchy_states[index]->get_state_parent(), true, true, item->text(column));

        highlight_state(hierarchy_states[index]->get_state_name());
    }
}

void NFWizard2::highlight_state(const QString state_to_highlight){

    int index = get_state_index_with_name(state_to_highlight);
    if(index!=-1){

        for(quint16 i =0; i< hierarchy_states.size(); i++){

            hierarchy_states[i]->set_Highlight(false);
        }

        if(!hierarchy_states[index]->isHighLight()){

            hierarchy_states[index]->set_Highlight(true);
        }
    }
}

void NFWizard2::on_tw_state_machine_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    int index = get_state_index_with_name(item->text(column));

    if(index !=-1){
        //draw_super_state(hierarchy_states[index]->get_state_parent(), true, true, item->text(column));

        //highlight_state(hierarchy_states[index]->get_state_name());
        qDebug()<<"doble : "<<hierarchy_states[index]->get_state_name();

        QString state_name = hierarchy_states[index]->get_state_name();
        highlight_state(state_name);
        current_state = state_name;
        current_state_parent = ui->l_name_current_state->text();
        ui->widget_on_state_options->show();
        ui->widget_on_state_options->move(QWidget::mapFromGlobal(QCursor::pos()));
    }


}


