#include "Thread_Name.h"

using namespace eObject;

Thread_Name::Thread_Name() : eSingletonStaticBase(this),Thread_Name_Instance(Thread_Name_Run, eThread::PriorityNormal)
{
    Thread_Name_Instance.start(); ////To start executing the thread
}

void Thread_Name::Thread_Name_Run(eThread &threadInstance)
{

//    std::int32_t signal = 0;   ////variable to save the signal received

    while (true)
    {
//        threadInstance.eventWaitAny(signal);  ////Wait for any signal from any thread

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



