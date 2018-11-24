#include "qhierarchy_state.h"

QHierarchy_State::QHierarchy_State(QWidget *parent, QString state_name_ref) : QPushButton(parent)
{
    this->setObjectName(state_name_ref);
    this->state_name = state_name_ref;

    this->setEnabled(true);
    this->setText(objectName().left(3).toUpper());
    this->move(0,0);
    this->setMinimumSize(QSize(85, 85));
    this->setMaximumSize(QSize(85, 85));
    this->setCursor(QCursor(Qt::PointingHandCursor));
    this->setStyleSheet(QLatin1String("color: rgb(255, 245, 242); border-image: url(:/Assets/green_2.png); font: 12pt \"Segoe UI\";"));
    this->setFixedSize(85,85);
    this->setFlat(true);

    connect(this,SIGNAL(clicked(bool)),this,SLOT(send_signal_click()));
    connect(this,SIGNAL(pressed()),this,SLOT(drag_with_mouse()));

    state_parent = "No Parent";
    state_default = "No Default";
    state_initial = "No Initial";
    on_entry_Action = "No Entry Action";
    on_exit_Action = "No Exit Action";

    configured=false;
}

void QHierarchy_State::set_configured(bool config){

    configured = config;
}

bool QHierarchy_State::is_configured(){

    return configured;
}

QHierarchy_State::~QHierarchy_State()
{
    delete this;
}

void QHierarchy_State::send_signal_click(){

    emit signal_clicked(state_name);
}
void QHierarchy_State::drag_with_mouse(){

    emit signal_toggled(state_name);
}

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

QList<QHierarchy_State::QHierarchy_State_Event_t> QHierarchy_State::get_events_list(){

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

void QHierarchy_State::set_state_name(const QString name){

    state_name = name;
}

void QHierarchy_State::set_state_parent(const QString parent){

    state_parent = parent;
}

void QHierarchy_State::set_state_initial(const QString initial){

    state_initial = initial;
}

void QHierarchy_State::set_state_default(const QString defaults){

    state_default = defaults;
}

void QHierarchy_State::add_Event(const QHierarchy_State_Event_t event){

    events_list.append(event);
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
