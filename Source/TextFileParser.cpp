#include "TextFileParser.h"

TextFileParser::TextFileParser(QString& fileName, QObject *parent) :
    QObject(parent)
{
    parsing_ = false;
    setFileName(fileName);
}

TextFileParser::TextFileParser(QObject* parent):
    QObject(parent)
{
    parsing_ = false;
}

QString TextFileParser::getFileName() const
{
    return fileName_;
}

bool TextFileParser::setFileName(const QString& fileName)
{
    if (isParsing()) {
        return false;
    }
    bool retval = false;
    if(QFile::exists(fileName)){
        retval = true;
        fileName_ = fileName;
    }
    return retval;
}

void TextFileParser::addTextLinePair(const TextLinePair_t &tokenRef)
{
    textLinePair_.append(tokenRef);
}

void TextFileParser::addTextLinePairList(const TextLineList_t &tokenListRef)
{
    textLinePair_.append(tokenListRef);
}

void TextFileParser::clearTextLinePairList()
{
    textLinePair_.clear();
}

bool TextFileParser::isParsing() const
{
    return parsing_;
}


bool TextFileParser::startParsing()
{
    if (parsing_ || textLinePair_.isEmpty()) {
        return false;
    }
    parsing_ = true;
    QFile file(fileName_);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        return false;
    }
    QString line;
    qint64 startPosition;
    qint64 endPosition;
    foreach (const TextLinePair_t& token, textLinePair_) { // process all tokens
        startPosition = 0;
        endPosition = 0;
        file.seek(0); // start of file
        while (!file.atEnd()) {
            line = file.readLine();
            if (line.contains(token.first)) {
                startPosition = file.pos(); //WARNING: first line not included
            } else if (line.contains(token.second)) {
                endPosition = file.pos(); //WARNING: last line included
                if (startPosition < endPosition ) { // check for consistency
                    parsedData_.insert(token, TextParsedCoordenates_t(startPosition, endPosition));
                    break;
                }
            }
        }
    }
    emit parsingFinished();
    return true;
}

TextFileParser::TextParsedData_t TextFileParser::getTextParsedData() const
{
    if (isParsing()) {
        return TextParsedData_t();//empty data
    }
    return parsedData_;
}

bool TextFileParser::clearParsedData()
{
    if (isParsing()) {
        return false;
    }
    parsedData_.clear();
    return true;
}
