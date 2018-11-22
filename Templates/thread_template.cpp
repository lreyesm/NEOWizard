#include "Thread_Name.h"

using namespace eObject;

Thread_Name::Thread_Name() : eSingletonStaticBase(this),Thread_Name_Instance(Thread_Name_Run, eThread::PriorityNormal)
{
    Thread_Name.start();
}

void Thread_Name::Thread_Name_Run(eThread &threadInstance)
{

//    std::int32_t signal = 0;

    while (true)
    {
//        threadInstance.eventWaitAny(signal);

//        switch (signal) {

//        case SIGNAL_0:

//            break;

//        case SIGNAL_N:

//            break;

//        default:
//            break;
//        }
    }
}



