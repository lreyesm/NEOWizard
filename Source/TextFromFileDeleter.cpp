#include "TextFromFileDeleter.h"
#include <QTextDocument>
#include <QTextDocumentWriter>
#include <QTextCursor>
#include <QFile>
#include <QDebug>


QString TextFromFileDeleter::startLine() const
{
    return startLine_;
}

void TextFromFileDeleter::setStartLine(const QString &startLine)
{
    startLine_ = startLine;
}

QString TextFromFileDeleter::endLine() const
{
    return endLine_;
}

void TextFromFileDeleter::setEndLine(const QString &endLine)
{
    endLine_ = endLine;
}

QString TextFromFileDeleter::mssg() const
{
    return mssg_;
}

void TextFromFileDeleter::setMssg(const QString &mssg)
{
    mssg_ = mssg;
}

void TextFromFileDeleter::processFile()
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
    QTextCursor cursorStart = document.find(startLine());
    QTextCursor cursorEnd = document.find(endLine());
    if (!cursorStart.hasSelection() || !cursorEnd.hasSelection()) {
        qWarning() << "The text between: " << startLine() << " and " << endLine() << "found" << endLine();

        return;
    }
    if (!cursorEnd.movePosition(QTextCursor::Down, QTextCursor::KeepAnchor, 2)) { // WARNING: magic number, to select the "}"
        qWarning() << "file: " << filename() << " not found!";
        return;
    }
    cursorStart.setPosition(cursorEnd.position(),QTextCursor::KeepAnchor);
    cursorStart.removeSelectedText(); // delete the function
    cursorStart.insertText(mssg());
    QTextDocumentWriter docWriter(filename(), "plaintext");
    if (! docWriter.write(&document)) { // to select the "}"
        qWarning() << "file: " << filename() << " could not be written!";

        return;
    }
}

QString TextFromFileDeleter::filename() const
{
    return filename_;
}

void TextFromFileDeleter::setFilename(const QString &filename)
{
    filename_ = filename;
}

