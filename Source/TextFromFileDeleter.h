#ifndef TEXTFROMFILEDELETER_H
#define TEXTFROMFILEDELETER_H

#include <QtCore>

class TextFromFileDeleter
{
public:
    QString startLine() const;
    void setStartLine(const QString &startLine);

    QString endLine() const;
    void setEndLine(const QString &endLine);

    QString mssg() const;
    void setMssg(const QString &mssg);


    QString filename() const;
    void setFilename(const QString &filename);

    void processFile();
private:
    QString filename_;
    QString startLine_;
    QString endLine_;
    QString mssg_;
};

#endif // TEXTFROMFILEDELETER_H
