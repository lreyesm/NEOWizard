#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <QObject>
#include <QtCore>

namespace FileParserNamespace {


typedef QPair<QString, QString> TokenTuple_t;
typedef QList<TokenTuple_t> TokenTupleList_t;
typedef QMap<TokenTuple_t, QString> ParsedData;

class FileParser : public QObject
{
    Q_OBJECT
public:
    explicit FileParser(QObject *parent = Q_NULLPTR);
    FileParser(QString& fileName, QObject *parent = Q_NULLPTR);

    QString getFileName() const;
    bool setFileName(const QString& filePtr);

    void addTokenTuple(const TokenTuple_t& tokenRef);
    void addTokenTupleList(const TokenTupleList_t& tokenListRef);
    void clearTokenTupleList();
    bool isParsing() const;

    ParsedData getParsedData() const;
    bool clearParsedData();

signals:
    void parsingFinished(ParsedData parsedData_);

public slots:
    bool startParsing();

private slots:
    void onParsingFinished();
private:
    ParsedData parseFile();

    QFile file_;
    bool parsing_;
    TokenTupleList_t tokenList_;

    ParsedData parsedData_;
    QFuture<ParsedData> future_;
    QFutureWatcher<ParsedData> watcher_;
};
}
#endif // FILEPARSER_H
