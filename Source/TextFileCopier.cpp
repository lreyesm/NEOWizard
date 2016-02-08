#include "TextFileCopier.h"


TextFileCopier::TextFileCopier(QObject *parent):
    TextFileParser(parent)
{

}

TextFileCopier::TextFileCopier(QString &fileName, QObject *parent):
    TextFileParser(fileName, parent)
{

}

TextFileCopier::TextCopiedData TextFileCopier::copiedData() const
{
    return copiedData_;
}

bool TextFileCopier::startCoping()
{
    bool retval = startParsing();
    if (!retval) {
        return false;
    }
    QFile file(fileName_);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        return false;
    }
    TextLinePair_t key;
    foreach (key, parsedData_.keys()) {

    }
}

