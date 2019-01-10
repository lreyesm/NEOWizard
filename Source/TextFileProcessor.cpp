#include "TextFileProcessor.h"
#include <QTextDocument>
#include <QTextDocumentWriter>
#include <QTextCursor>
#include <QFile>
#include <QDebug>
#include <QMessageBox>

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

void TextFileProcessor::processTextBlock_modified() //esta funcion es los mismo q processTextBlock pero el endline inicia busqueda desde startline,
{                                          //el otro inicia desde el principio del texto
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
    QTextCursor cursorEnd = document.find(endLine_, cursorStart);
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

const QStringList  TextFileProcessor::get_text_between(){

    QStringList found_list;

    QFile file(filename());   // almacena en file el archivo
    if (!file.exists()) {
        qWarning() << "file: " << filename() << " not found!";

        found_list.append("No File");

         return found_list;
    }
    if (!file.open(QFile::ReadOnly | QFile::Text)) { //lo abre como lectura
        qWarning() << "file: " << filename() << " could not be opened for read!";

        found_list.append("Not Read");
        return found_list;
    }

    QTextDocument document;
    document.setPlainText(file.readAll());
    file.close();
    QTextCursor cursorStart = document.find(startLine_);
    QTextCursor cursorEnd = document.find(endLine_, cursorStart);
    if (!cursorStart.hasSelection() || !cursorEnd.hasSelection()) {
        qWarning() << "The text between: " << startLine_ << " and " << endLine_ << "not found";
        found_list.append("Not Found String");
        return found_list;
    }
    cursorStart.setPosition(cursorEnd.position(),QTextCursor::KeepAnchor);

    found_list.append(cursorStart.selectedText());

    while(true){

        cursorStart = document.find(startLine_, cursorEnd);
        cursorEnd = document.find(endLine_, cursorStart);

        if (!cursorStart.hasSelection() || !cursorEnd.hasSelection()) {
            //qWarning() << "The text between: " << startLine_ << " and " << endLine_ << "not found";
            found_list.append("End String");
            return found_list;
        }
        cursorStart.setPosition(cursorEnd.position(),QTextCursor::KeepAnchor);

        found_list.append(cursorStart.selectedText());

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
            if(startLine_!= QString("void Error_Handler()") && startLine_!= QString("void SystemClock_Config(void);") && startLine_!= QString("RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSE;")){
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

int TextFileProcessor::check_if_code_exist(const QString line_code, bool case_sensitive){

    int retval = false;
    QFile file(filename());
    if (!file.exists()) {
        qWarning() << "File: " << filename() << " not found!";
        return -1;
    }
    if (!file.open(QFile::ReadWrite | QFile::Text)) {
        qWarning() << "File: " << filename() << " could not be opened for read!";

        return -2;
    }

    QString fileContent = file.readAll();

    Qt::CaseSensitivity case_sensitive_ = (case_sensitive)?Qt::CaseSensitive:Qt::CaseInsensitive;

    if(fileContent.contains(line_code, case_sensitive_)){

        retval = 1;
    }
    else{

        retval = 0;
    }

    //file.seek(0);
    //file.write(fileContent);
    file.close();

    return retval;
}

int TextFileProcessor::write_string_to_document(const QString fileContent){

    QTextDocument document;
    document.setPlainText(fileContent);

    QTextDocumentWriter docWriter(filename(), "plaintext");
    if (! docWriter.write(&document)) { // to select the "}"
        qWarning() << "file: " << filename() << " could not be written!";
        return -3;
    }
    return 1;
}
int TextFileProcessor::generate_machine_lines_in_main_thread_h(){

    QString replacement_line = "\n/*Definition of Events ID of State Machine*/\n/*End of Definition of Events ID of State Machine*/\n";
    QString replacement_line_2 = "    /*Definitions of State Machine*/\n\n    /*Definition of Action Prototypes of State Machine*/\n    /*End of Definition of Action Prototypes of State Machine*/\n\n    /*End of Definitions of State Machine*/\n\n";

    QString exist_code= replacement_line.section('/',1,1);

    if(check_if_code_exist("#include <eApplicationBase.h>", false)==1 && check_if_code_exist(exist_code, false)==0){

         QString toReplace = "#include <eApplicationBase.h>\n\n" + replacement_line;

         QFile file(filename());
         if (!file.open(QFile::ReadWrite | QFile::Text)) {
             qWarning() << "File: " << filename() << " could not be opened for read!";

             return -2;
         }

         QString fileContent = file.readAll();

         file.close();

         fileContent.replace("#include <eApplicationBase.h>", toReplace);

         int retval = write_string_to_document(fileContent);
         if(retval != 1){
             return retval;
         }
    }
    else{
        if(check_if_code_exist("#include \"eApplicationBase.h\"", false)==1 && check_if_code_exist(replacement_line.section('/',1,1), false)==0){

            QString toReplace = "#include \"eApplicationBase.h\"\n\n" + replacement_line;

            QFile file(filename());
            if (!file.open(QFile::ReadWrite | QFile::Text)) {
                qWarning() << "File: " << filename() << " could not be opened for read!";

                return -2;
            }

            QString fileContent = file.readAll();

            file.close();

            fileContent.replace("#include \"eApplicationBase.h\"", toReplace);

            int retval = write_string_to_document(fileContent);
            if(retval != 1){
                return retval;
            }
        }
        else{

            if(check_if_code_exist("#include <eApplicationBase.h>", false)==0){

                QFile file(filename());
                if (!file.open(QFile::ReadWrite | QFile::Text)) {
                    qWarning() << "File: " << filename() << " could not be opened for read!";

                    return -2;
                }

                QString fileContent = file.readAll();

                fileContent = "#include <eApplicationBase.h>\n\n" + replacement_line + fileContent;

                file.close();

                int retval = write_string_to_document(fileContent);
                if(retval != 1){
                    return retval;
                }
                return 1;
            }
        }
    }
    if(check_if_code_exist("private:", true)==1){

        QString toReplace = replacement_line_2 + "private:\n";

        QFile file(filename());
        if (!file.open(QFile::ReadWrite | QFile::Text)) {
            qWarning() << "File: " << filename() << " could not be opened for read!";

            return -2;
        }

        QString fileContent = file.readAll();

        file.close();

        fileContent.replace("private:", toReplace);

        int retval = write_string_to_document(fileContent);

        if(retval != 1){
            return retval;
        }
    }
    else{
        if(check_if_code_exist("private", true)==1){ ////private con espacios entre los :
           return -4;
        }
        return 0;
    }
    return 1;
}

int TextFileProcessor::generate_machine_lines_in_main_thread_cpp(const QString main_thread_name){


    QString replacement_line = QString("/* USER CODE BEGIN Includes */")+
            QString("\n/* USER CODE BEGIN END Includes */")+

            QString("\n\n/*Definition of Entry Functions Prototypes of State Machine*/")+
            QString("\n/*End of Definition of Entry Functions Prototypes of State Machine*/")+

            QString("\n\n/*Definition of Exit Functions Prototypes of State Machine*/")+
            QString("\n/*End of Definition of Exit Functions Prototypes of State Machine*/");

    QString replacement_line_2 = QString("\n\n    /*State Machine Generated Code*/")+
            QString("\n\n    /*Name of State Machine controller*/")+
            QString("\n    /*End of Name of State Machine controller*/")+

            QString("\n\n    /*Definition of all eState from State Machine*/")+
            QString("\n    /*End of Definition of all eState from State Machine*/")+

            QString("\n\n    /*Definition of all eAction from State Machine*/")+
            QString("\n    /*End of Definition of all eAction from State Machine*/")+

            QString("\n\n    /*Definition of all SuperStates from State Machine*/")+
            QString("\n    /*End of Definition of all SuperStates from State Machine*/")+

            QString("\n\n    /*Definition of the Inicial State of State Machine*/")+
            QString("\n    /*End of Definition of the Inicial State of State Machine*/")+

            QString("\n\n    /*Definition of all Inicial States from State Machine*/")+
            QString("\n    /*End of Definition of all Inicial States from State Machine*/")+

            QString("\n\n    /*Adding all Events from State Machine*/")+
            QString("\n    /*End of Adding all Events from State Machine*/")+

            QString("\n\n    /*Definition of all Default Events from State Machine*/")+
            QString("\n    /*End of Definition of all Default Events from State Machine*/")+

            QString("\n\n    /*Definition of all Entry Actions from State Machine*/")+
            QString("\n    /*End of Definition of all Entry Actions from State Machine*/")+

            QString("\n\n    /*Definition of all Exit Actions from State Machine*/")+
            QString("\n    /*End of Definition of all Exit Actions from State Machine*/")+

            QString("\n\n    /*Start of State Machine*/")+
            QString("\n    /*End of Start of State Machine*/")+

            QString("\n\n    /*End of State Machine Generated Code*/");

    QString replacement_line_3 = QString("\n/*Implementation of Action Prototypes of State Machine*/")+
            QString("\n /*End of Implementation of Action Prototypes of State Machine*/")+

            QString("\n\n/*Implementation of Entry Functions of State Machine*/")+
            QString("\n /*End of Implementation Entry Functions of State Machine*/")+

            QString("\n\n/*Implementation of Exit Functions of State Machine*/")+
            QString("\n/*End of Implementation Exit Functions of State Machine*/\n\n");

    if(check_if_code_exist("/*Implementation of Action Prototypes of State Machine*/", false)!=1 && check_if_code_exist(replacement_line_3.section('/',1,1), false)==0){


         QFile file(filename());
         if (!file.open(QFile::ReadWrite | QFile::Text)) {
             qWarning() << "File: " << filename() << " could not be opened for read!";

             return -2;
         }

         QString fileContent = file.readAll() + replacement_line_3;

         file.close();

         int retval = write_string_to_document(fileContent);
         if(retval != 1){
             return retval;
         }
    }

    if(check_if_code_exist("#include \""+main_thread_name+".h\"", false)==1 && check_if_code_exist(replacement_line.section('/',1,1), false)==0){

         QString toReplace = "#include \""+main_thread_name+".h\"\n\n" + replacement_line;

         QFile file(filename());
         if (!file.open(QFile::ReadWrite | QFile::Text)) {
             qWarning() << "File: " << filename() << " could not be opened for read!";

             return -2;
         }

         QString fileContent = file.readAll();

         file.close();

         fileContent.replace("#include \""+main_thread_name+".h\"", toReplace);

         int retval = write_string_to_document(fileContent);
         if(retval != 1){
             return retval;
         }
    }
    else{
        if(check_if_code_exist("#include <"+main_thread_name+".h>", false)==1 && check_if_code_exist(replacement_line.section('/',1,1), false)==0){

            QString toReplace = "#include <"+main_thread_name+".h>\n\n" + replacement_line;

            QFile file(filename());
            if (!file.open(QFile::ReadWrite | QFile::Text)) {
                qWarning() << "File: " << filename() << " could not be opened for read!";

                return -2;
            }

            QString fileContent = file.readAll();

            file.close();

            fileContent.replace("#include \"eApplicationBase.h\"", toReplace);

            int retval = write_string_to_document(fileContent);
            if(retval != 1){
                return retval;
            }
        }
        else{
            return 0;
        }
    }
    if(check_if_code_exist("::userLoop(){", true)==1 && check_if_code_exist(replacement_line_2.section('/',1,1), false)==0){

        QString toReplace = "::userLoop(){" + replacement_line_2;

        QFile file(filename());
        if (!file.open(QFile::ReadWrite | QFile::Text)) {
            qWarning() << "File: " << filename() << " could not be opened for read!";

            return -2;
        }

        QString fileContent = file.readAll();

        file.close();

        fileContent.replace("::userLoop(){", toReplace);

        int retval = write_string_to_document(fileContent);

        if(retval != 1){
            return retval;
        }
    }
    else{
        if(check_if_code_exist("::userLoop()\n", true)==1 && check_if_code_exist(replacement_line_2.section('/',1,1), false)==0){
            QString toReplace = "::userLoop(){" + replacement_line_2;

            QFile file(filename());
            if (!file.open(QFile::ReadWrite | QFile::Text)) {
                qWarning() << "File: " << filename() << " could not be opened for read!";

                return -2;
            }

            QString fileContent = file.readAll();

            file.close();

            fileContent.replace("::userLoop()\n{", toReplace);

            int retval = write_string_to_document(fileContent);

            if(retval != 1){
                return retval;
            }
        }
        else{
            return 0;
        }
    }
    return 1;
}

int TextFileProcessor::generate_code_in_main_thread_h(){

    QString replacement_line = "    /*User declare thread objects*/\n    /*End of User declare thread objects*/\n\nprivate:\n\n    /*User declare thread objects functions*/\n    /*End of User declare thread objects functions*/";

    if(check_if_code_exist("private:", true)==1){

         QFile file(filename());
         if (!file.open(QFile::ReadWrite | QFile::Text)) {
             qWarning() << "File: " << filename() << " could not be opened for read!";

             return -2;
         }
         QString fileContent = file.readAll();
         file.close();

         fileContent.replace("private:", replacement_line);

         return write_string_to_document(fileContent);
    }
    else{
        if(check_if_code_exist("private", true)==1){ ////private con espacios entre los :
           return -4;
        }
        return 0;
    }
    return 1;
}

int TextFileProcessor::generate_code_in_main_thread_cpp(const QString main_thread_name){

    QFile file(filename());
    if (!file.open(QFile::ReadWrite | QFile::Text)) {
        qWarning() << "File: " << filename() << " could not be opened for read!";

        return -2;
    }
    QString replacement_line = main_thread_name+"::"+main_thread_name+"(),";
    QString add_line = QString("\n\n/*Threads Functions Implementation Generated Code*/\n/*End of Threads Functions Implementation Generated Code*/\n");
    if(check_if_code_exist(main_thread_name+"::"+main_thread_name+"():",true)==1){

         QString fileContent = file.readAll()+add_line;
         file.close();

         fileContent.replace(main_thread_name+"::"+main_thread_name+"():", replacement_line);

         return write_string_to_document(fileContent);
    }
    else{
        if(check_if_code_exist(main_thread_name+"::"+main_thread_name+"()",true)==1){

            QString fileContent = file.readAll()+add_line;
            file.close();

//            replacement_line = main_thread_name+"::"+main_thread_name+"()";
//            fileContent.replace(main_thread_name+"::"+main_thread_name+"()", replacement_line);

            return write_string_to_document(fileContent);
            return 1;
        }
        return 0;

    }
    return 1;
}

int TextFileProcessor::add_code_to_end_of_file(const QString main_thread_name){

    QFile file(filename());
    if (!file.open(QFile::ReadWrite | QFile::Text)) {
        qWarning() << "File: " << filename() << " could not be opened for read!";

        return -2;
    }

    QString fileContent = file.readAll()+replacementStr_;
    file.close();

    return write_string_to_document(fileContent);

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

