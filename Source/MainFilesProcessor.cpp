#include "MainFilesProcessor.h"



const QString MainFilesProcessor::INCLUDES_START_LINE = "/* Includes ------------------------------------------------------------------*/";
const QString MainFilesProcessor::INCLUDES_END_LINE = "/* USER CODE BEGIN Includes */";
const QString MainFilesProcessor::PERIP_CONFIG_START_LINE = "  /* Initialize all configured peripherals */";
const QString MainFilesProcessor::PERIP_CONFIG_END_LINE = "  /* USER CODE BEGIN 2 */";
///*const*/ QString MainFilesProcessor::SYSCLOCK_CONFIG_START_LINE_STCUBEMX_VERSION_4_20 = "/** System Clock Configuration";
///*const*/ QString MainFilesProcessor::SYSCLOCK_CONFIG_START_LINE_STCUBEMX_VERSION_4_26 = "  * @brief System Clock Configuration";
QString MainFilesProcessor::SYSCLOCK_CONFIG_START_LINE = "  * @brief System Clock Configuration";
const QString MainFilesProcessor::SYSCLOCK_CONFIG_END_LINE = "/* USER CODE BEGIN 4 */";


bool MainFilesProcessor::processFiles(const QString& cubemaincFileName, const QString& maincppFileName)
{
    QFile file(cubemaincFileName);  //comprueba q existe el archivo main.c generado por STCubeMx
    if (!file.exists()) {
        qDebug() << "file: " << file.fileName() << " not found!";
        return false;
    }
    if (!file.open(QFile::ReadOnly | QFile::Text)) {  // abre el main.c generado por STCubeMX como lectura
        qDebug() << "file: " << file.fileName() << " could not be opened for read!";
        return false;
    }
    QTextDocument cubeMainDoc;  //variable para guardar texto del main.c
    cubeMainDoc.setPlainText(file.readAll());  // guarda el contenido del main.c en cubeMainDoc
    file.close();

    file.setFileName(maincppFileName);   // pone en file la direccion de archivo keil
    if (!file.open(QFile::ReadOnly | QFile::Text)) {  // lo abre como lectura
        qDebug() << "file: " << file.fileName() << " could not be opened for read!";
        return false;
    }
    QTextDocument maincppDoc;  //variable para guardar contenido de plantilla main.cpp
    maincppDoc.setPlainText(file.readAll()); // guarda el contenido da main.cpp en mainCppDoc
    file.close();

    /********************** STM32CubeMx main.c file processing**********************************/
    QTextCursor cursorIncludesStart = cubeMainDoc.find(INCLUDES_START_LINE); // estos cursores son para seleccionar el codigo
    QTextCursor cursorIncludesEnd = cubeMainDoc.find(INCLUDES_END_LINE);     // de los "includes" generados por el STCubeMx

    if (cursorIncludesStart.hasSelection() && cursorIncludesEnd.hasSelection()) {
         // guarda los "includes"
        cursorIncludesStart.setPosition(cursorIncludesEnd.position(),QTextCursor::KeepAnchor);
    }else {
        qDebug() << " Include Section not found on "  << cubemaincFileName;
    }

    // estos cursores son para guardar el contenido del codigo de inicializacion de perifericas genereado por STCubeMx
    QTextCursor cursorPeriphConfigStart = cubeMainDoc.find(PERIP_CONFIG_START_LINE);
    QTextCursor cursorPeriphConfigEnd = cubeMainDoc.find(PERIP_CONFIG_END_LINE);

    if (cursorPeriphConfigStart.hasSelection() && cursorPeriphConfigEnd.hasSelection()) {
        // guarda inicializacion de perifericos (funciones MX_XX_Init) generadas por el STCubeMx
        cursorPeriphConfigStart.setPosition(cursorPeriphConfigEnd.position(),QTextCursor::KeepAnchor);
    }else {
        qDebug() << " Initialize configured peripherals Section not found on "  << cubemaincFileName;
    }

    // cursores para guardar configuracion de relojes del sistema generado por STCubeMX
    QTextCursor cursorSysClockConfigStart = cubeMainDoc.find(SYSCLOCK_CONFIG_START_LINE);
    QTextCursor cursorSysClockConfigEnd = cubeMainDoc.find(SYSCLOCK_CONFIG_END_LINE);

    if (cursorSysClockConfigStart.hasSelection() && cursorSysClockConfigEnd.hasSelection()) {
        //guarda configuracion de relojes del sistema  e implementacion de funciones MX_XX_Init generados por STCubeMX
        cursorSysClockConfigStart.setPosition(cursorSysClockConfigEnd.position(),QTextCursor::KeepAnchor);
    }else {
        qDebug() << " System Clock Configuration Section not found on "  << cubemaincFileName;
    }

    /********************** end processing STM32CubeMx main.c file **********************************/

    /********************** main.cpp file processing**********************************/
    // Selecciona el texto de "includes" en el main.cpp
    QTextCursor maincppCursorStart = maincppDoc.find(INCLUDES_START_LINE);
    QTextCursor maincppCursorEnd = maincppDoc.find(INCLUDES_END_LINE);

    // Remplaza el texto de "includes" del main.cpp por el de main.c generado en STCubeMX
    if (maincppCursorStart.hasSelection() && maincppCursorEnd.hasSelection()) {
        maincppCursorStart.setPosition(maincppCursorEnd.position(),QTextCursor::KeepAnchor);
        maincppCursorStart.insertText(cursorIncludesStart.selectedText()); // insert the copied include lines
    }else {
        qDebug() << " Include Section not found on "  << maincppFileName;
    }
    maincppCursorStart.clearSelection();
    maincppCursorEnd.clearSelection();

    // Selecciona el texto de config de perifericos (funciones MX_XX_Init) en el main.cpp
    maincppCursorStart = maincppDoc.find(PERIP_CONFIG_START_LINE);
    maincppCursorEnd = maincppDoc.find(PERIP_CONFIG_END_LINE);

    // Remplaza el texto de config de perifericos del main.cpp por el de main.c generado en STCubeMX
    if (maincppCursorStart.hasSelection() && maincppCursorEnd.hasSelection()) {
        maincppCursorStart.setPosition(maincppCursorEnd.position(),QTextCursor::KeepAnchor);
        maincppCursorStart.insertText(cursorPeriphConfigStart.selectedText()); // insert the copied peripheral config lines
    }else {
        qDebug() << " Initialize configured peripherals Section not found on "  << maincppFileName;
    }

    maincppCursorStart.clearSelection();
    maincppCursorEnd.clearSelection();

    // Selecciona el texto de config de relojes e implementacion de MX_XX_Init en el main.cpp
    maincppCursorStart = maincppDoc.find(SYSCLOCK_CONFIG_START_LINE);
    maincppCursorEnd = maincppDoc.find(SYSCLOCK_CONFIG_END_LINE);

    // Remplaza el texto de config de relojes e implementacion de MX_XX_Init del main.cpp por el de main.c generado en STCubeMX
    if (maincppCursorStart.hasSelection() && maincppCursorEnd.hasSelection()) {
        maincppCursorStart.setPosition(maincppCursorEnd.position(),QTextCursor::KeepAnchor);
        maincppCursorStart.insertText(cursorSysClockConfigStart.selectedText()); // insert the copied peripheral config lines
    }else {
        qDebug() << " System Clock Configuration Section not found on "  << maincppFileName;
    }
    /********************** end processing main.cpp file **********************************/


    // Escribe las modificaciones anteriores del texto en el archivo main.cpp original
    QTextDocumentWriter docWriter(maincppFileName, "plaintext");
    if (! docWriter.write(&maincppDoc)) { // to select the "}"
        qDebug() << "file: " << maincppFileName << " could not be written!";
        return false;
    }
    return true;

}
