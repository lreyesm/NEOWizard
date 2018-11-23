#ifndef QHIERARCHY_STATE_H
#define QHIERARCHY_STATE_H

#include <QPushButton>

class QHierarchy_State : public QPushButton
{
    Q_OBJECT

public:
    explicit QHierarchy_State(QWidget *parent = nullptr);

signals:

public slots:

private:

    QString state_name;
};

#endif // QHIERARCHY_STATE_H
