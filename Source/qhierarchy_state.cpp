#include "qhierarchy_state.h"

QHierarchy_State::QHierarchy_State(QWidget *parent, QString state_name_ref) : QPushButton(parent)
{
    this->setObjectName(state_name_ref);
    this->setEnabled(true);
    this->setText(objectName().left(2).toUpper());
    this->move(0,0);
    this->setMinimumSize(QSize(85, 85));
    this->setMaximumSize(QSize(85, 85));
    this->setCursor(QCursor(Qt::PointingHandCursor));
    this->setStyleSheet(QLatin1String("border-image: url(:/Assets/green_2.png); font: 12pt \"Segoe UI\";"));
    this->setFixedSize(85,85);
    this->setFlat(true);

    connect(this,SIGNAL(clicked(bool)),this,SLOT(send_signal_click()));

    this->state_name = state_name_ref;
}


QHierarchy_State::~QHierarchy_State()
{
    delete this;
}

void QHierarchy_State::send_signal_click(){

    emit signal_clicked(state_name);
}
void QHierarchy_State::drag_with_mouse(){

    //emit signal_clicked(state_name);
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
const QStringList QHierarchy_State::get_next_states(){

    return next_states;
}
const QStringList QHierarchy_State::get_events(){

    return events;
}
const QStringList QHierarchy_State::get_state_actions(){

    return state_actions;
}
