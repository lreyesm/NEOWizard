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
        qWarning() << "The text between: " << startLine_ << " and " << endLine_ << "not found";
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

void TextFileProcessor::replace_all_lines_code_instances(){



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

     while(true){

        QTextCursor cursorStart = document.find(startLine_);
        QTextCursor cursorEnd = document.find(endLine_);

        if (!cursorStart.hasSelection() || !cursorEnd.hasSelection()) {
            //QTextCursor cursorReplacement = document.find(replacementStr_);
            QTextCursor cursorReplacement = document.find(QString("/*Start of replaced code of NEOWizard*/"));
            if(cursorReplacement.hasSelection() ){
                qWarning() <<"Function  "<< startLine_ <<"  Already deleted by NEOWizard ";

            }
            else{
            qWarning() << "The text between: " << startLine_ << " and " << endLine_ << "not found";
            return;
            }
        }
        if (!cursorEnd.movePosition(QTextCursor::Down, QTextCursor::KeepAnchor, 2)) { // WARNING: magic number, to select the "}"
            if(startLine_!= QString("_Error_Handler(__FILE__, __LINE__);")){
                qWarning() << "file: " << filename() << " not found!";
            }
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
        //QTextCursor cursorReplacement = document.find(replacementStr_);
        QTextCursor cursorReplacement = document.find(QString("/* Deleted by NEOWizard */"));
        QTextCursor cursorReplacement_2 = document.find(QString("/* Deleted by NFWizard 2 */")); ////para el caso de proyectos ya generados con NFWizard
        if(cursorReplacement.hasSelection() || cursorReplacement_2.hasSelection()){
            qWarning() <<"Function  "<< startLine_ <<"  Already deleted by NEOWizard ";
            return;
        }
        else{
        qWarning() << "The text between: " << startLine_ << " and " << endLine_ << "not found";
        return;
        }
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

