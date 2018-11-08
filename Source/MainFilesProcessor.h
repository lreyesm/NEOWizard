#ifndef MAINFILESPROCESSOR_H
#define MAINFILESPROCESSOR_H

#include <QtCore>

class MainFilesProcessor
{
public:

    static const QString INCLUDES_START_LINE;
    static const QString INCLUDES_END_LINE;
    static const QString PERIP_CONFIG_START_LINE;
    static const QString PERIP_CONFIG_END_LINE;
    static const QString SYSCLOCK_CONFIG_START_LINE_STCUBEMX_VERSION_4_20;
    static const QString SYSCLOCK_CONFIG_START_LINE_STCUBEMX_VERSION_4_26;
    static const QString SYSCLOCK_CONFIG_END_LINE;

    static bool processFiles(const QString &cubemaincFileName, const QString &maincppFileName);

private:

    Q_DISABLE_COPY(MainFilesProcessor)
    MainFilesProcessor();
};

#endif // MAINFILESPROCESSOR_H
