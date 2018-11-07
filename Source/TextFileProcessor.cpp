#include "TextFileProcessor.h"
#include <QTextDocument>
#include <QTextDocumentWriter>
#include <QTextCursor>
#include <QFile>
#include <QDebug>


QString TextFileProcessor::startLine() const
{
    return startLine_;
}

void TextFileProcessor::setStartLine(const QString &value)
{
    startLine_ = value;
}

QString TextFileProcessor::endLine() const
{
    return endLine_;
}

void TextFileProcessor::setEndLine(const QString &endLine)
{
    endLine_ = endLine;
}

QString TextFileProcessor::replacementString() const
{
    return replacementStr_;
}

void TextFileProcessor::setReplacementString(const QString &value)
{
    replacementStr_ = value;
}

void TextFileProcessor::processTextBlock() //esta funcion es muy parecida a processMethod
{                                          //la diferencia es la inclucion de un if
    QFile file(filename());   // almacena en file el archivo
    if (!file.exists()) {
        qWarning() << "file: " << filename() << " not found!";

        return;
    }
    if (!file.open(QFile::ReadOnly | QFile::Text)) { //lo abre como lectura
        qWarning() << "file: " << filename() << " could not be opened for read!";

        return;
    }
    QTextDocument document;
    document.setPlainText(file.readAll());
    file.close();
    QTextCursor cursorStart = document.find(startLine_);
    QTextCursor cursorEnd = document.find(endLine_);
    if (!cursorStart.hasSelection() || !cursorEnd.hasSelection()) {
        qWarning() << "The text between: " << startLine_ << " and " << endLine_ << "not found" << endLine();
        return;
    }
    cursorStart.setPosition(cursorEnd.position(),QTextCursor::KeepAnchor);
    cursorStart.removeSelectedText(); // delete the function
    cursorStart.insertText(replacementString());
    QTextDocumentWriter docWriter(filename(), "plaintext");
    if (! docWriter.write(&document)) { // to select the "}"
        qWarning() << "file: " << filename() << " could not be written!";
        return;
    }
}

void TextFileProcessor::processMethod()
{
    QFile file(filename());
    if (!file.exists()) {
        qWarning() << "file: " << filename() << " not found!";

        return;
    }
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qWarning() << "file: " << filename() << " could not be opened for read!";

        return;
    }
    QTextDocument document;
    document.setPlainText(file.readAll());
    file.close();
    QTextCursor cursorStart = document.find(startLine_);
    QTextCursor cursorEnd = document.find(endLine_);
    if (!cursorStart.hasSelection() || !cursorEnd.hasSelection()) {
        qWarning() << "The text between: " << startLine_ << " and " << endLine_ << "not found" << endLine();
        return;
    }
    if (!cursorEnd.movePosition(QTextCursor::Down, QTextCursor::KeepAnchor, 2)) { // WARNING: magic number, to select the "}"
        qWarning() << "file: " << filename() << " not found!";
        return;
    }
    cursorStart.setPosition(cursorEnd.position(),QTextCursor::KeepAnchor);
    cursorStart.removeSelectedText(); // delete the function
    cursorStart.insertText(replacementString());
    QTextDocumentWriter docWriter(filename(), "plaintext");
    if (! docWriter.write(&document)) { // to select the "}"
        qWarning() << "file: " << filename() << " could not be written!";
        return;
    }
}

QString TextFileProcessor::filename() const
{
    return filename_;
}

void TextFileProcessor::setFilename(const QString &filename)
{
    filename_ = filename;
}
