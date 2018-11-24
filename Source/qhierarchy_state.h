#ifndef QHIERARCHY_STATE_H
#define QHIERARCHY_STATE_H

#include <QPushButton>

class QHierarchy_State : public QPushButton
{
    Q_OBJECT

public:
    explicit QHierarchy_State(QWidget *parent = nullptr, QString state_name_ref="unknow");

    ~QHierarchy_State();

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
    QList<QHierarchy_State_Event_t> get_events_list();
//    const QStringList get_events();
//    const QStringList get_next_states();
//    const QStringList get_state_actions();

    void set_state_name(const QString name);
    void set_state_parent(const QString parent);
    void set_state_initial(const QString initial);
    void set_state_default(const QString defaults);
    void set_state_entryAction(const QString entryAction){ on_entry_Action = entryAction;}
    void set_state_exitAction(const QString exitAction){ on_exit_Action = exitAction;;}
    void add_Event(const QHierarchy_State_Event_t event);
//    void add_state_event(const QString event);
//    void add_next_state(const QString next);
//    void add_state_action(const QString action);

    void set_configured(bool config);
    bool is_configured();

signals:
    void signal_clicked(QString clicked_state_name = "unknow");
    void signal_toggled(QString toggled_state_name = "unknow");

public slots:
    void send_signal_click();
    void drag_with_mouse();

private:

    QString state_name;
    QString state_parent;
    QString state_initial;
    QString state_default;
    QString on_entry_Action;
    QString on_exit_Action;
    QList<QHierarchy_State_Event_t> events_list;

//    QStringList events;
//    QStringList next_states;
//    QStringList state_actions;

    bool configured;

};

#endif // QHIERARCHY_STATE_H
