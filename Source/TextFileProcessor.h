#ifndef TEXTFROMFILEDELETER_H
#define TEXTFROMFILEDELETER_H

#include <QtCore>

class TextFileProcessor
{
public:
    QString startLine() const;
    void setStartLine(const QString &value);

    QString endLine() const;
    void setEndLine(const QString &endLine);

    QString replacementString() const;
    void setReplacementString(const QString &value);


    QString filename() const;
    void setFilename(const QString &filename);

    void processTextBlock();
    void processMethod();
    int check_if_code_exist(const QString line_code, bool case_sensitive);
    int generate_code_in_main_thread_h();
    int generate_code_in_main_thread_cpp(const QString main_thread_name);
    int generate_machine_lines_in_main_thread_h();
    int generate_machine_lines_in_main_thread_cpp(const QString main_thread_name);
    void replace_all_lines_code_instances();
    int write_string_to_document(const QString fileContent);
    const QStringList get_text_between();
    void processTextBlock_modified();
private:
    QString filename_;
    QString startLine_;
    QString endLine_;
    QString replacementStr_;
};

#endif // TEXTFROMFILEDELETER_H
