#ifndef TEXTFILEPARSER_H
#define TEXTFILEPARSER_H

#include <QObject>
#include <QtCore>


class TextFileParser : public QObject
{
    Q_OBJECT
public:
    //public types
    typedef QPair<QString, QString> TextLinePair_t;
    typedef QPair<quint64, quint64> TextParsedCoordenates_t;
    typedef QList<TextLinePair_t> TextLineList_t;
    typedef QMap<TextLinePair_t, TextParsedCoordenates_t> TextParsedData_t;

    explicit TextFileParser(QObject *parent = Q_NULLPTR);
    TextFileParser(QString& fileName, QObject *parent = Q_NULLPTR);

    QString getFileName() const;
    bool setFileName(const QString& filePtr);

    void addTextLinePair(const TextLinePair_t& tokenRef);
    void addTextLinePairList(const TextLineList_t& tokenListRef);
    void clearTextLinePairList();

    TextParsedData_t getTextParsedData() const;
    bool clearParsedData();
    bool isParsing() const;

signals:
    void parsingFinished();
public slots:
    bool startParsing();
protected:
    QString fileName_;
    bool parsing_;
    TextLineList_t textLinePair_;
    TextParsedData_t parsedData_;
};
#endif // TEXTFILEPARSER_H
