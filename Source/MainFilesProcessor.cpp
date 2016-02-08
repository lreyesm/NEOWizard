#include "MainFilesProcessor.h"

#include <QTextDocument>
#include <QTextDocumentWriter>
#include <QTextCursor>
#include <QFile>
#include <QDebug>

const QString MainFilesProcessor::INCLUDES_START_LINE = "/* Includes ------------------------------------------------------------------*/";
const QString MainFilesProcessor::INCLUDES_END_LINE = "/* USER CODE BEGIN Includes */";
const QString MainFilesProcessor::PERIP_CONFIG_START_LINE = "  /* Initialize all configured peripherals */";
const QString MainFilesProcessor::PERIP_CONFIG_END_LINE = "  /* USER CODE BEGIN 2 */";
const QString MainFilesProcessor::SYSCLOCK_CONFIG_START_LINE = "/** System Clock Configuration";
const QString MainFilesProcessor::SYSCLOCK_CONFIG_END_LINE = "/* USER CODE BEGIN 4 */";


bool MainFilesProcessor::processFiles(const QString& cubemaincFileName, const QString& maincppFileName)
{
    QFile file(cubemaincFileName);
    if (!file.exists()) {
        qDebug() << "file: " << file.fileName() << " not found!";
        return false;
    }
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "file: " << file.fileName() << " could not be opened for read!";
        return false;
    }
    QTextDocument cubeMainDoc;
    cubeMainDoc.setPlainText(file.readAll());
    file.close();

    file.setFileName(maincppFileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "file: " << file.fileName() << " could not be opened for read!";
        return false;
    }
    QTextDocument maincppDoc;
    maincppDoc.setPlainText(file.readAll());
    file.close();

    /********************** STM32CubeMx main.c file processing**********************************/
    QTextCursor cursorIncludesStart = cubeMainDoc.find(INCLUDES_START_LINE);
    QTextCursor cursorIncludesEnd = cubeMainDoc.find(INCLUDES_END_LINE);

    if (cursorIncludesStart.hasSelection() && cursorIncludesEnd.hasSelection()) {
        cursorIncludesStart.setPosition(cursorIncludesEnd.position(),QTextCursor::KeepAnchor);
    }else {
        qDebug() << " Include Section not found on "  << cubemaincFileName;
    }

    QTextCursor cursorPeriphConfigStart = cubeMainDoc.find(PERIP_CONFIG_START_LINE);
    QTextCursor cursorPeriphConfigEnd = cubeMainDoc.find(PERIP_CONFIG_END_LINE);

    if (cursorPeriphConfigStart.hasSelection() && cursorPeriphConfigEnd.hasSelection()) {
        cursorPeriphConfigStart.setPosition(cursorPeriphConfigEnd.position(),QTextCursor::KeepAnchor);
    }else {
        qDebug() << " Initialize configured peripherals Section not found on "  << cubemaincFileName;
    }

    QTextCursor cursorSysClockConfigStart = cubeMainDoc.find(SYSCLOCK_CONFIG_START_LINE);
    QTextCursor cursorSysClockConfigEnd = cubeMainDoc.find(SYSCLOCK_CONFIG_END_LINE);

    if (cursorSysClockConfigStart.hasSelection() && cursorSysClockConfigEnd.hasSelection()) {
        cursorSysClockConfigStart.setPosition(cursorSysClockConfigEnd.position(),QTextCursor::KeepAnchor);
    }else {
        qDebug() << " System Clock Configuration Section not found on "  << cubemaincFileName;
    }

    /********************** end processing STM32CubeMx main.c file **********************************/

    /********************** main.cpp file processing**********************************/
    QTextCursor maincppCursorStart = maincppDoc.find(INCLUDES_START_LINE);
    QTextCursor maincppCursorEnd = maincppDoc.find(INCLUDES_END_LINE);

    if (maincppCursorStart.hasSelection() && maincppCursorEnd.hasSelection()) {
        maincppCursorStart.setPosition(maincppCursorEnd.position(),QTextCursor::KeepAnchor);
        maincppCursorStart.insertText(cursorIncludesStart.selectedText()); // insert the copied include lines
    }else {
        qDebug() << " Include Section not found on "  << maincppFileName;
    }
    maincppCursorStart.clearSelection();
    maincppCursorEnd.clearSelection();
    maincppCursorStart = maincppDoc.find(PERIP_CONFIG_START_LINE);
    maincppCursorEnd = maincppDoc.find(PERIP_CONFIG_END_LINE);

    if (maincppCursorStart.hasSelection() && maincppCursorEnd.hasSelection()) {
        maincppCursorStart.setPosition(maincppCursorEnd.position(),QTextCursor::KeepAnchor);
        maincppCursorStart.insertText(cursorPeriphConfigStart.selectedText()); // insert the copied peripheral config lines
    }else {
        qDebug() << " Initialize configured peripherals Section not found on "  << maincppFileName;
    }

    maincppCursorStart.clearSelection();
    maincppCursorEnd.clearSelection();
    maincppCursorStart = maincppDoc.find(SYSCLOCK_CONFIG_START_LINE);
    maincppCursorEnd = maincppDoc.find(SYSCLOCK_CONFIG_END_LINE);

    if (maincppCursorStart.hasSelection() && maincppCursorEnd.hasSelection()) {
        maincppCursorStart.setPosition(maincppCursorEnd.position(),QTextCursor::KeepAnchor);
        maincppCursorStart.insertText(cursorSysClockConfigStart.selectedText()); // insert the copied peripheral config lines
    }else {
        qDebug() << " System Clock Configuration Section not found on "  << maincppFileName;
    }
    /********************** end processing main.cpp file **********************************/


    QTextDocumentWriter docWriter(maincppFileName, "plaintext");
    if (! docWriter.write(&maincppDoc)) { // to select the "}"
        qDebug() << "file: " << maincppFileName << " could not be written!";
        return false;
    }
    return true;

}
