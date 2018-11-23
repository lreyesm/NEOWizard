#ifndef QHIERARCHY_STATE_H
#define QHIERARCHY_STATE_H

#include <QPushButton>

class QHierarchy_State : public QPushButton
{
    Q_OBJECT

public:
    explicit QHierarchy_State(QWidget *parent = nullptr, QString state_name_ref="unknow");

    ~QHierarchy_State();

    const QString get_state_name();
    const QString get_state_parent();
    const QString get_state_initial();
    const QString get_state_default();
    const QStringList get_events();
    const QStringList get_next_states();
    const QStringList get_state_actions();

    void set_state_name(const QString name);
    void set_state_parent(const QString parent);
    void set_state_initial(const QString initial);
    void set_state_default(const QString defaults);

signals:
    void signal_clicked(QString clicked_state_name = "unknow");

public slots:
    void send_signal_click();
    void drag_with_mouse();

private:

    QString state_name;
    QString state_parent;
    QString state_initial;
    QString state_default;

    QStringList events;
    QStringList next_states;
    QStringList state_actions;

};

#endif // QHIERARCHY_STATE_H
