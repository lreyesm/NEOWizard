/********************************************************************************
** Form generated from reading UI file 'DialogConfigurationHelp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCONFIGURATIONHELP_H
#define UI_DIALOGCONFIGURATIONHELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogConfigurationHelp
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_HelpTextHolder;
    QLabel *label_HelpContentHolder;

    void setupUi(QDialog *DialogConfigurationHelp)
    {
        if (DialogConfigurationHelp->objectName().isEmpty())
            DialogConfigurationHelp->setObjectName(QStringLiteral("DialogConfigurationHelp"));
        DialogConfigurationHelp->setWindowModality(Qt::WindowModal);
        DialogConfigurationHelp->resize(400, 300);
        verticalLayout = new QVBoxLayout(DialogConfigurationHelp);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_HelpTextHolder = new QLabel(DialogConfigurationHelp);
        label_HelpTextHolder->setObjectName(QStringLiteral("label_HelpTextHolder"));

        verticalLayout->addWidget(label_HelpTextHolder);

        label_HelpContentHolder = new QLabel(DialogConfigurationHelp);
        label_HelpContentHolder->setObjectName(QStringLiteral("label_HelpContentHolder"));

        verticalLayout->addWidget(label_HelpContentHolder);


        retranslateUi(DialogConfigurationHelp);

        QMetaObject::connectSlotsByName(DialogConfigurationHelp);
    } // setupUi

    void retranslateUi(QDialog *DialogConfigurationHelp)
    {
        DialogConfigurationHelp->setWindowTitle(QApplication::translate("DialogConfigurationHelp", "Dialog", Q_NULLPTR));
        label_HelpTextHolder->setText(QApplication::translate("DialogConfigurationHelp", "TextLabel", Q_NULLPTR));
        label_HelpContentHolder->setText(QApplication::translate("DialogConfigurationHelp", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogConfigurationHelp: public Ui_DialogConfigurationHelp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONFIGURATIONHELP_H
