#ifndef CUBEINTERRUPTFILEPROCESSOR_H
#define CUBEINTERRUPTFILEPROCESSOR_H

#include <QtCore>

class CubeInterruptFileProcessor
{
public:
    static const QString SYSTICK_HANDLER_START_LINE;
    static const QString SYSTICK_HANDLER_END_LINE;
    static const QString SYSTICK_HANDLER_DELETED_MSSG;
    static bool processFile(const QString &fileName);
private:
    Q_DISABLE_COPY(CubeInterruptFileProcessor)
    CubeInterruptFileProcessor();
};

#endif // CUBEINTERRUPTFILEPROCESSOR_H
