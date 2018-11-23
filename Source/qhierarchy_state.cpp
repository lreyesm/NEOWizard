#include "qhierarchy_state.h"

QHierarchy_State::QHierarchy_State(QWidget *parent) : QPushButton(parent)
{
    this->setObjectName(QStringLiteral("pb_State"));
    this->setEnabled(true);
    this->setText("State_x");
    this->move(0,0);
    this->setMinimumSize(QSize(150, 40));
    this->setMaximumSize(QSize(200, 50));
    this->setCursor(QCursor(Qt::PointingHandCursor));
    this->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"border-color: rgb(21, 172, 112);\n"
"color: rgb(255, 245, 242);\n"
""));
    this->setFlat(false);
    connect(this,SIGNAL(clicked(bool)),this,SLOT(hide()));
}
