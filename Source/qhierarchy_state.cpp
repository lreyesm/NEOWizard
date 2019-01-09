#include "qhierarchy_state.h"


const quint8 QHierarchy_State::MAX_SUB_STATE = MAX_CHILD_STATES;

QHierarchy_State::QHierarchy_State(QWidget *parent, QString state_name_ref) : QPushButton(parent)
{
    this->setObjectName(state_name_ref);
    this->state_name = state_name_ref;
    subState_count = 0;
    this->setEnabled(true);
    QString n = objectName().toUpper();
    n.remove("state",Qt::CaseInsensitive);
    this->setText(n.left(3));
    this->move(0,0);
    this->setCursor(QCursor(Qt::PointingHandCursor));
    this->setStyleSheet(QLatin1String("color: rgb(255, 245, 242); background-image: url(:/icons/state.png); font: 10pt \"Segoe UI\";"));
    this->setFixedSize(66,66);
    this->setFlat(true);

    connect(this,SIGNAL(doubleClicked()),this,SLOT(send_signal_double_click()));  ////a partir de aqui agregar en NEOWizard original
    connect(this,SIGNAL(rightClicked()),this,SLOT(send_signal_right_click()));  ////a partir de aqui agregar en NEOWizard original
    connect(this,SIGNAL(leftClicked()),this,SLOT(send_signal_left_click()));  ////a partir de aqui agregar en NEOWizard original

    state_parent = "No Parent";
    state_default = "No Default";
    state_initial = "No Initial";
    on_entry_Action = "No Entry Action";
    on_exit_Action = "No Exit Action";
    add_Event("No Event", "No Next State", "No Action");
    position_in_superstate = -1;

    highLight = false;
    initial=false;
    configured=false;
}


QHierarchy_State::~QHierarchy_State()
{
    this->deleteLater();
}

bool QHierarchy_State::set_Highlight(const bool highlight){

    if(highlight){

        highLight = true;
        if(initial){
            this->setStyleSheet(QLatin1String("color: rgb(255, 245, 242); background-image: url(:/icons/state_init_highlight.png); font: 10pt \"Segoe UI\";"));
        }
        else{
            this->setStyleSheet(QLatin1String("color: rgb(255, 245, 242); background-image: url(:/icons/state_highlight.png); font: 10pt \"Segoe UI\";"));
        }
        return true;
    }
    else{

        highLight = false;
        if(initial){
            this->setStyleSheet(QLatin1String("color: rgb(255, 245, 242); background-image: url(:/icons/state_init.png); font: 10pt \"Segoe UI\";"));
        }
        else{
            this->setStyleSheet(QLatin1String("color: rgb(255, 245, 242); background-image: url(:/icons/state.png); font: 10pt \"Segoe UI\";"));
        }
        return false;
    }
}

void QHierarchy_State::write_file(QDataStream &out){


    out<<this->state_name;
    out<<this->state_parent;
    out<<this->state_initial;
    out<<this->state_default;
    out<<this->on_entry_Action;
    out<<this->on_exit_Action;
    out<<(quint8)(this->events_list.size());
    for(quint8 i=0; i< events_list.size();i++){

        out<<this->events_list[i].event;
        out<<this->events_list[i].next_state;
        out<<this->events_list[i].state_action;
    }
    out<<this->direct_subStates;
    out<<this->position_in_superstate;
    out<<this->subState_count;
    out<<this->initial;
    out<<this->configured;
    QString n= QString("End of State\n");
    out<<n;

}
//-----------------------------------------------------------------------------------------------------------------------


//Esta funcion me lee desde un dataStream los datos de bebe guardados en un archivo--------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void QHierarchy_State::read_file(QDataStream &in){

    in>>this->state_name;
    in>>this->state_parent;
    in>>this->state_initial;
    in>>this->state_default;
    in>>this->on_entry_Action;
    in>>this->on_exit_Action;

    quint8 size_events_list=0;
    in>>size_events_list;

    for(quint8 i=0; i< size_events_list;i++){
        this->add_Event("No Event1", "No Next State1", "No Action1");
    }
    for(quint8 i=0; i< size_events_list;i++){

        in>>this->events_list[i].event;
        in>>this->events_list[i].next_state;
        in>>this->events_list[i].state_action;
    }
    in>>this->direct_subStates;
    in>>this->position_in_superstate;
    in>>this->subState_count;
    in>>this->initial;
    in>>this->configured;
    QString string_end;
    in>>string_end;

    this->setObjectName(state_name);
    QString n = objectName().toUpper();
    n.remove("state",Qt::CaseInsensitive);
    this->setText(n.left(3));
    this->setInitial(initial);
}

void QHierarchy_State::setInitial(bool ini){

    if(ini){
        this->setStyleSheet(QLatin1String("color: rgb(255, 245, 242); background-image: url(:/icons/state_init.png); font: 10pt \"Segoe UI\";"));
    }
    else{
        this->setStyleSheet(QLatin1String("color: rgb(255, 245, 242); background-image: url(:/icons/state.png); font: 10pt \"Segoe UI\";"));
    }
    initial = ini;
}

void QHierarchy_State::set_configured(bool config){

    configured = config;
}

bool QHierarchy_State::is_configured(){

    return configured;
}

////Funciones slots q emiten las señales del boton*****************************************************************************************************************************
void QHierarchy_State::send_signal_click(){

    emit signal_clicked(state_name);
}

void QHierarchy_State::send_signal_double_click(){  ////a partir de aqui agregar en NEOWizard original

    emit signal_double_click(state_name);
}

void QHierarchy_State::send_signal_right_click(){  ////a partir de aqui agregar en NEOWizard original

    emit signal_right_clicked(state_name);
}

void QHierarchy_State::send_signal_left_click(){  ////a partir de aqui agregar en NEOWizard original

    emit signal_left_clicked(state_name);
}

void QHierarchy_State::drag_with_mouse(){

    emit signal_toggled(state_name);
}
////*****************************************************************************************************************************************************************************

const QString QHierarchy_State::get_state_name(){

    return state_name;
}
const QString QHierarchy_State::get_state_parent(){

    return state_parent;
}
const QString QHierarchy_State::get_state_initial(){

    return state_initial;
}
const QString QHierarchy_State::get_state_default(){

    return state_default;
}

QList<QHierarchy_State::QHierarchy_State_Event_t>& QHierarchy_State::get_events_list(){

    return events_list;
}

//const QStringList QHierarchy_State::get_next_states(){

//    return next_states;
//}
//const QStringList QHierarchy_State::get_events(){

//    return events;
//}
//const QStringList QHierarchy_State::get_state_actions(){

//    return state_actions;
//}

void QHierarchy_State::set_state_name(const QString &name){

    setObjectName(name);
    this->setText(name.toUpper().left(3));
    state_name = name;
}

void QHierarchy_State::set_state_parent(const QString &parent){

    state_parent = parent;
}

void QHierarchy_State::set_state_initial(const QString &initial){

    state_initial = initial;
}

void QHierarchy_State::set_state_default(const QString &defaults){

    state_default = defaults;
}

void QHierarchy_State::add_Event(const QHierarchy_State_Event_t event){

    if(!events_list.isEmpty()){
        if(events_list[0].event == "No Event" && events_list[0].event == "No Next State" && events_list[0].event == "No Action"){

            events_list.clear();
        }
    }
    events_list.append(event);
}

void QHierarchy_State::add_Event(const QString event, const QString next_state, const QString state_action){

    if(!events_list.isEmpty()){
        if(events_list[0].event == "No Event" && events_list[0].next_state == "No Next State" && events_list[0].state_action == "No Action"){

            events_list.clear();
        }
    }
    QHierarchy_State_Event_t event_t;
    event_t.event = event;
    event_t.next_state = next_state;
    event_t.state_action = state_action;

    events_list.append(event_t);
}
//void QHierarchy_State::add_state_event(const QString event){

//    events.append(event);
//}

//void QHierarchy_State::add_state_action(const QString action){

//    state_actions.append(action);
//}

//void QHierarchy_State::add_next_state(const QString next){

//    next_states.append(next);
//}

bool QHierarchy_State::look_for_child(const QString &child_state){

    if(direct_subStates.contains(child_state)){
        return true;
    }

    else{
        return false;
    }
}

bool QHierarchy_State::eliminate_child(const QString &child_state){ ////Modificar esta funcion /Que hacer con estados hijos del eliminado

    if(!direct_subStates.contains(child_state)){
        return false;
    }
    else{
        subState_count--;
        return direct_subStates.removeOne(child_state);
    }
}


