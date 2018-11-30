#ifndef MAIN_THREAD_TEMPLATE_H
#define MAIN_THREAD_TEMPLATE_H

#include <eApplicationBase.h>

using namespace eObject;

/*Definition of Events ID of State Machine*/
/*End of Definition of Events ID of State Machine*/

class Main_Thread_Template:public eObject::eApplicationBase<Main_Thread_Template>
{
public:
    /*Main thread Constructor*/
    Main_Thread_Template();

    ////Main function, this function is executed infinitely when app.exec() in main.cpp
    virtual void userLoop() E_DECLARE_OVERRIDE;

    /*User declare thread objects*/

    /*End of User declare thread objects*/


    /*Definitions of State Machine*/

    /*Definition of Action Prototypes of State Machine*/
    /*End of Definition of Action Prototypes of State Machine*/

    /*End of Definitions of State Machine*/

private:

    /*User declare thread objects functions*/

    /*End of User declare thread objects functions*/
};


#endif // MAIN_THREAD_TEMPLATE_H
