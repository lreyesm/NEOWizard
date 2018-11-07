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
private:
    QString filename_;
    QString startLine_;
    QString endLine_;
    QString replacementStr_;
};

#endif // TEXTFROMFILEDELETER_H
