#include "CubeInterruptFileProcessor.h"
#include <QTextDocument>
#include <QTextDocumentWriter>
#include <QTextCursor>
#include <QFile>
#include <QDebug>

const QString CubeInterruptFileProcessor::SYSTICK_HANDLER_START_LINE = "void SysTick_Handler(void)";
const QString CubeInterruptFileProcessor::SYSTICK_HANDLER_END_LINE = "/* USER CODE END SysTick_IRQn 1 */";
const QString CubeInterruptFileProcessor::SYSTICK_HANDLER_DELETED_MSSG = "\n/* Deleted by NFWizard 2 */\n\n";

bool CubeInterruptFileProcessor::processFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.exists()) {
        qDebug() << "file: " << fileName << " not found!";
        return false;
    }
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "file: " << fileName << " could not be opened for read!";
        return false;
    }
    QTextDocument document;
    document.setPlainText(file.readAll());
    file.close();
    QTextCursor cursorStart = document.find(SYSTICK_HANDLER_START_LINE);
    QTextCursor cursorEnd = document.find(SYSTICK_HANDLER_END_LINE);
    if (!cursorStart.hasSelection() || !cursorEnd.hasSelection()) {
        qDebug() << " No systick handler function found";
        return true;
    }
    if (!cursorEnd.movePosition(QTextCursor::Down, QTextCursor::KeepAnchor, 2)) { // WARNING: magic number, to select the "}"
        qDebug() << "file: " << fileName << " not found!";
        return false;
    }
    cursorStart.setPosition(cursorEnd.position(),QTextCursor::KeepAnchor);
    cursorStart.removeSelectedText(); // delete the function
    cursorStart.insertText(SYSTICK_HANDLER_DELETED_MSSG);
    QTextDocumentWriter docWriter(fileName, "plaintext");
    if (! docWriter.write(&document)) { // to select the "}"
        qDebug() << "file: " << fileName << " could not be written!";
        return false;
    }
   return true;
}


