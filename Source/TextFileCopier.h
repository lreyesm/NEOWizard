#ifndef TEXTFILECOPIER_H
#define TEXTFILECOPIER_H
#include "TextFileParser.h"


class TextFileCopier : public TextFileParser
{
public:
    typedef QMap<TextLinePair_t, QString> TextCopiedData;

    explicit TextFileCopier(QObject *parent = Q_NULLPTR);
    TextFileCopier(QString& fileName, QObject *parent = Q_NULLPTR);

    TextCopiedData copiedData() const;
signals:
    void copingFinished();

public slots:
    bool startCoping();

protected:
    TextCopiedData copiedData_;
};

#endif // TEXTFILECOPIER_H
