#include "FileParser.h"
#include <QtConcurrent>

using namespace FileParserNamespace;

FileParser::FileParser(QString& fileName, QObject *parent) :
    QObject(parent)
{
    parsing_ = false;
    setFileName(fileName);
}

FileParser::FileParser(QObject* parent):
    QObject(parent)
{
    parsing_ = false;
}

QString FileParser::getFileName() const
{
    return file_.fileName();
}

bool FileParser::setFileName(const QString& fileName)
{
    if (isParsing()) {
        return false;
    }
    bool retval = false;
    if(QFile::exists(fileName)){
        retval = true;
        file_.setFileName(fileName);
    }
    return retval;
}

void FileParser::addTokenTuple(const TokenTuple_t &tokenRef)
{
    tokenList_.append(tokenRef);
}

void FileParser::addTokenTupleList(const TokenTupleList_t &tokenListRef)
{
    tokenList_.append(tokenListRef);
}

void FileParser::clearTokenTupleList()
{
    tokenList_.clear();
}

bool FileParser::isParsing() const
{
    return parsing_;
}


bool FileParser::startParsing()
{
    if (parsing_ || tokenList_.isEmpty()) {
        return false;
    }
    QObject::connect(&watcher_, SIGNAL(finished()), this, SLOT(onParsingFinished()));
    parsing_ = true;
    future_ = QtConcurrent::run(this, &FileParser::parseFile);
    watcher_.setFuture(future_);
    return true;

}

void FileParser::onParsingFinished()
{
    parsedData_ = watcher_.result();
    parsing_ = false;
    emit parsingFinished();
}

ParsedData FileParser::parseFile()
{
    ParsedData parsedData;
    if (file_.isOpen()) {
        file_.close(); // to be sure that will be open in TextMode
    }
    if (!file_.open(QFile::ReadOnly | QFile::Text)) {
        return parsedData;
    }
    QString line;
    QString currentDataParsed;
    qint64 startPosition;
    qint64 endPosition;
    foreach (const TokenTuple_t& token, tokenList_) { // process all tokens
        startPosition = 0;
        endPosition = 0;
        file_.seek(0); // start of file
        currentDataParsed.clear(); // empty line
        while (!file_.atEnd()) {
            line = file_.readLine();
            if (line.contains(token.first)) {
                startPosition = file_.pos();
            } else if (line.contains(token.second)) {
                endPosition = file_.pos();
                if (startPosition < endPosition ) { // check for consistency
                    if(file_.seek(startPosition)){ // rewind and start coping
                        while (file_.pos() < endPosition) {
                            currentDataParsed.append(file_.readLine()); // append parsed lines
                        }
                        break;
                    }
                }
            }
        }
        parsedData.insert(token, currentDataParsed);
    }
    return parsedData;
}

ParsedData FileParser::getParsedData() const
{
    if (isParsing()) {
        return ParsedData();//empty data
    }
    return parsedData_;
}

bool FileParser::clearParsedData()
{
    if (isParsing()) {
        return false;
    }
    parsedData_.clear();
    return true;
}
