#ifndef THREAD_NAME_H
#define THREAD_NAME_H

#include "eThread.h"
#include "eSingletonStaticBase.h"


class Thread_Name : public eObject::eSingletonStaticBase<Thread_Name>
{
public:
    Thread_Name();

    eObject::eThread& getThreadInstance(void) __attribute__((always_inline));

private:

    eObject::eThread Thread_Name_object;

    static void Thread_Name_Run(eObject::eThread &threadInstance);
};

inline eObject::eThread& Thread_Name::getThreadInstance(void)
{
    return this->Thread_Name_object;
}

#endif // THREAD_NAME_H
