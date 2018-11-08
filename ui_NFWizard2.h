/********************************************************************************
** Form generated from reading UI file 'NFWizard2.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NFWIZARD2_H
#define UI_NFWIZARD2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NFWizard2
{
public:
    QAction *actionUVision_Configuration;
    QAction *actionSTM32CubeMx_Configuration;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_uVision;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_uVisionPath;
    QPushButton *pushButton_uVisionBrowse;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QGroupBox *groupBox_STM32CubeMx;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_CubePath;
    QPushButton *pushButton_CubeBrowse;
    QGroupBox *groupBox_options;
    QGridLayout *gridLayout;
    QCheckBox *checkBox_FolderStruct;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Generate;
    QPushButton *pushButton_Quit;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NFWizard2)
    {
        if (NFWizard2->objectName().isEmpty())
            NFWizard2->setObjectName(QStringLiteral("NFWizard2"));
        NFWizard2->resize(640, 315);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NFWizard2->sizePolicy().hasHeightForWidth());
        NFWizard2->setSizePolicy(sizePolicy);
        NFWizard2->setMinimumSize(QSize(640, 315));
        NFWizard2->setMaximumSize(QSize(1024, 315));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Assets/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        NFWizard2->setWindowIcon(icon);
        actionUVision_Configuration = new QAction(NFWizard2);
        actionUVision_Configuration->setObjectName(QStringLiteral("actionUVision_Configuration"));
        actionSTM32CubeMx_Configuration = new QAction(NFWizard2);
        actionSTM32CubeMx_Configuration->setObjectName(QStringLiteral("actionSTM32CubeMx_Configuration"));
        actionAbout = new QAction(NFWizard2);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAbout_Qt = new QAction(NFWizard2);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        centralWidget = new QWidget(NFWizard2);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox_uVision = new QGroupBox(centralWidget);
        groupBox_uVision->setObjectName(QStringLiteral("groupBox_uVision"));
        horizontalLayout = new QHBoxLayout(groupBox_uVision);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit_uVisionPath = new QLineEdit(groupBox_uVision);
        lineEdit_uVisionPath->setObjectName(QStringLiteral("lineEdit_uVisionPath"));
        lineEdit_uVisionPath->setEnabled(false);
        lineEdit_uVisionPath->setAutoFillBackground(false);
        lineEdit_uVisionPath->setEchoMode(QLineEdit::Normal);
        lineEdit_uVisionPath->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit_uVisionPath);

        pushButton_uVisionBrowse = new QPushButton(groupBox_uVision);
        pushButton_uVisionBrowse->setObjectName(QStringLiteral("pushButton_uVisionBrowse"));

        horizontalLayout->addWidget(pushButton_uVisionBrowse);


        verticalLayout_2->addWidget(groupBox_uVision);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        groupBox_STM32CubeMx = new QGroupBox(centralWidget);
        groupBox_STM32CubeMx->setObjectName(QStringLiteral("groupBox_STM32CubeMx"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_STM32CubeMx);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEdit_CubePath = new QLineEdit(groupBox_STM32CubeMx);
        lineEdit_CubePath->setObjectName(QStringLiteral("lineEdit_CubePath"));
        lineEdit_CubePath->setEnabled(false);
        lineEdit_CubePath->setDragEnabled(false);
        lineEdit_CubePath->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEdit_CubePath);

        pushButton_CubeBrowse = new QPushButton(groupBox_STM32CubeMx);
        pushButton_CubeBrowse->setObjectName(QStringLiteral("pushButton_CubeBrowse"));

        horizontalLayout_3->addWidget(pushButton_CubeBrowse);


        verticalLayout->addWidget(groupBox_STM32CubeMx);


        verticalLayout_2->addLayout(verticalLayout);

        groupBox_options = new QGroupBox(centralWidget);
        groupBox_options->setObjectName(QStringLiteral("groupBox_options"));
        gridLayout = new QGridLayout(groupBox_options);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        checkBox_FolderStruct = new QCheckBox(groupBox_options);
        checkBox_FolderStruct->setObjectName(QStringLiteral("checkBox_FolderStruct"));
        checkBox_FolderStruct->setChecked(false);

        gridLayout->addWidget(checkBox_FolderStruct, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_options);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_Generate = new QPushButton(centralWidget);
        pushButton_Generate->setObjectName(QStringLiteral("pushButton_Generate"));

        horizontalLayout_2->addWidget(pushButton_Generate);

        pushButton_Quit = new QPushButton(centralWidget);
        pushButton_Quit->setObjectName(QStringLiteral("pushButton_Quit"));

        horizontalLayout_2->addWidget(pushButton_Quit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        NFWizard2->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(NFWizard2);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 20));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        NFWizard2->setMenuBar(menuBar);
        mainToolBar = new QToolBar(NFWizard2);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        NFWizard2->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(NFWizard2);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        NFWizard2->setStatusBar(statusBar);

        menuBar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionUVision_Configuration);
        menuHelp->addAction(actionSTM32CubeMx_Configuration);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAbout_Qt);

        retranslateUi(NFWizard2);
        QObject::connect(pushButton_Quit, SIGNAL(clicked()), NFWizard2, SLOT(close()));

        QMetaObject::connectSlotsByName(NFWizard2);
    } // setupUi

    void retranslateUi(QMainWindow *NFWizard2)
    {
        NFWizard2->setWindowTitle(QApplication::translate("NFWizard2", "NEOWizard", Q_NULLPTR));
        actionUVision_Configuration->setText(QApplication::translate("NFWizard2", "uVision Configuration", Q_NULLPTR));
        actionSTM32CubeMx_Configuration->setText(QApplication::translate("NFWizard2", "STM32CubeMx Configuration", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("NFWizard2", "About NEOWizard", Q_NULLPTR));
        actionAbout_Qt->setText(QApplication::translate("NFWizard2", "About Qt", Q_NULLPTR));
        groupBox_uVision->setTitle(QApplication::translate("NFWizard2", "uVision Project", Q_NULLPTR));
        lineEdit_uVisionPath->setPlaceholderText(QApplication::translate("NFWizard2", "Keil uVision Project path", Q_NULLPTR));
        pushButton_uVisionBrowse->setText(QApplication::translate("NFWizard2", "Browse", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("NFWizard2", "Used STM32CubeMx Version 4.26 (for ARM Cortex M7)", Q_NULLPTR)
         << QApplication::translate("NFWizard2", "Used STM32CubeMx Version 4.20 or previous previous (for ARM Cortex M4)", Q_NULLPTR)
        );
        groupBox_STM32CubeMx->setTitle(QApplication::translate("NFWizard2", "STM32CubeMx Project", Q_NULLPTR));
        lineEdit_CubePath->setPlaceholderText(QApplication::translate("NFWizard2", "STM32CubeMx Project path", Q_NULLPTR));
        pushButton_CubeBrowse->setText(QApplication::translate("NFWizard2", "Browse", Q_NULLPTR));
        groupBox_options->setTitle(QApplication::translate("NFWizard2", "Generation Options", Q_NULLPTR));
        checkBox_FolderStruct->setText(QApplication::translate("NFWizard2", "Generate Project Folders", Q_NULLPTR));
        pushButton_Generate->setText(QApplication::translate("NFWizard2", "Generate Project", Q_NULLPTR));
        pushButton_Quit->setText(QApplication::translate("NFWizard2", "Quit", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("NFWizard2", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NFWizard2: public Ui_NFWizard2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NFWIZARD2_H
