#ifndef MAIN_THREAD_TEMPLATE_H
#define MAIN_THREAD_TEMPLATE_H

#include <eApplicationBase.h>

using namespace eObject;


class Main_Thread_Template:public eObject::eApplicationBase<Main_Thread_Template>
{
public:
    /*Main thread Constructor*/
    Main_Thread_Template();

    ////Main function, this function is executed infinitely when app.exec() in main.cpp
    virtual void userLoop() E_DECLARE_OVERRIDE;

private:
    /*User declare thread objects*/

    /*End of User declare thread objects*/
};


#endif // MAIN_THREAD_TEMPLATE_H
