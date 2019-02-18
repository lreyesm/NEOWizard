#ifndef QHIERARCHY_STATE_H
#define QHIERARCHY_STATE_H

#include <QPushButton>
#include <QMouseEvent>


#define MAX_CHILD_STATES 12

class QHierarchy_State : public QPushButton
{
    Q_OBJECT

public:
    explicit QHierarchy_State(QWidget *parent = nullptr, QString state_name_ref="unknow");

    ~QHierarchy_State();

    static const quint8 MAX_SUB_STATE;

    typedef struct{

        QString event;
        QString next_state;
        QString state_action;

    }QHierarchy_State_Event_t;

    const QString get_state_name();
    const QString get_state_parent();
    const QString get_state_initial();
    const QString get_state_default();
    const QString get_state_on_entry_Action(){ return on_entry_Action;}
    const QString get_state_on_exit_Action(){ return on_exit_Action;}
    QList<QHierarchy_State_Event_t> &get_events_list();
    quint8 get_position_in_superstate(){ return (quint8)position_in_superstate;}
    const QStringList get_direct_SubStates(){ return direct_subStates;}
    quint8 get_subStates_count(){ return subState_count;}
    bool look_for_child(const QString &child_state);
    bool eliminate_child(const QString &child_state); ////Modificar esta funcion /Que hacer con estados hijos del eliminado
    bool isInitial(){ return initial;}
    bool set_Highlight(const bool highlight);

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    int hasEvent(QString event);
    const QString get_next_state_simulating(){ return next_state_simulating;}

    const QHierarchy_State_Event_t get_default_event(){return default_event;}
    const QString get_default_next_state(){ return default_event.next_state;}
    const QString get_default_action(){ return default_event.state_action;}

    bool is_equal(QHierarchy_State *state);
    bool copy(QHierarchy_State *state);
    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void set_state_name(const QString &name);
    void set_state_parent(const QString &parent);
    void set_state_initial(const QString &initial);
    void set_state_default(const QString &defaults);
    void set_state_entryAction(const QString &entryAction){ on_entry_Action = entryAction;}
    void set_state_exitAction(const QString &exitAction){ on_exit_Action = exitAction;}
    void add_Event(const QHierarchy_State_Event_t event);
    void add_Event(const QString event, const QString next_state, const QString state_action);
    void set_position_in_superstate(const int pos){ position_in_superstate = (quint8)pos;}
    void add_direct_sub_State(const QString subState){ if(subState_count < MAX_CHILD_STATES){direct_subStates.append(subState); subState_count++;}}
    void setInitial(bool ini);
    void write_file(QDataStream &out);
    void read_file(QDataStream &in);

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    void set_next_state_simulating(QString state_name){ next_state_simulating = state_name;}

    void set_default_event(const QString default_next_state, const QString default_action);
    void set_default_event(const QHierarchy_State_Event_t &event);
    void set_default_next_state(const QString default_next_state){ default_event.next_state = default_next_state;}
    void set_default_action(const QString default_action){ default_event.state_action = default_action;}

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    void set_configured(bool config);
    bool is_configured();
    bool isHighLight(){return highLight;}

signals:
    void signal_clicked(QString clicked_state_name = "unknow");
    void signal_toggled(QString toggled_state_name = "unknow");

    void signal_double_click(QString double_clicked_state_name = "unknow"); ////a partir de aqui agregar en NEOWizard original
    void signal_right_clicked(QString right_clicked_state_name = "unknow");
    void signal_left_clicked(QString left_clicked_state_name = "unknow");
    void doubleClicked();
    void rightClicked();
    void leftClicked();


public slots:
    void send_signal_click();
    void drag_with_mouse();

    void send_signal_double_click(); ////a partir de aqui agregar en NEOWizard original
    void send_signal_right_click();
    void send_signal_left_click();

protected: ////a partir de aqui agregar en NEOWizard original

    void mouseDoubleClickEvent(QMouseEvent *)
    {
        emit doubleClicked();
    }
private slots: ////a partir de aqui agregar en NEOWizard original

    void mousePressEvent(QMouseEvent *e) ///al reimplementar esta funcion deja de funcionar el evento pressed
    {
        if(e->buttons()==Qt::RightButton)
            emit rightClicked();

        if(e->buttons()==Qt::LeftButton)
            emit leftClicked();
    }

private:

    QString state_name;
    QString state_parent;
    QString state_initial;
    QString state_default;
    QString on_entry_Action;
    QString on_exit_Action;
    QList<QHierarchy_State_Event_t> events_list;
    QStringList direct_subStates;
    int position_in_superstate;
    quint8 subState_count;
    bool initial;
    bool highLight;

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    QHierarchy_State_Event_t default_event;
    /////////////////////////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    QString next_state_simulating;
    /////////////////////////////////////////////////////////////////////////////////////////////////////

    bool configured;

};


#endif // QHIERARCHY_STATE_H
