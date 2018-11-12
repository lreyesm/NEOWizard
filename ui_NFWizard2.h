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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QLabel *label_bar_selection;
    QPushButton *pushButton_Generate_tag;
    QPushButton *pushButton_Options_tag;
    QPushButton *pushButton_Help_tag;
    QLabel *label_bar_background;
    QWidget *widget_dirs;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_uVision;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_uVisionPath;
    QPushButton *pushButton_uVisionBrowse;
    QVBoxLayout *verticalLayout;
    QLabel *label_Cube;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_CubePath;
    QPushButton *pushButton_CubeBrowse;
    QWidget *widget_generate_options;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_generate_options;
    QPushButton *pushButton_generate_folders;
    QWidget *widget_buttons_quit;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_Generate;
    QPushButton *pushButton_Quit;
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
        label_bar_selection = new QLabel(centralWidget);
        label_bar_selection->setObjectName(QStringLiteral("label_bar_selection"));
        label_bar_selection->setGeometry(QRect(0, 30, 47, 13));
        pushButton_Generate_tag = new QPushButton(centralWidget);
        pushButton_Generate_tag->setObjectName(QStringLiteral("pushButton_Generate_tag"));
        pushButton_Generate_tag->setGeometry(QRect(0, 0, 80, 21));
        pushButton_Options_tag = new QPushButton(centralWidget);
        pushButton_Options_tag->setObjectName(QStringLiteral("pushButton_Options_tag"));
        pushButton_Options_tag->setGeometry(QRect(190, 0, 80, 21));
        pushButton_Help_tag = new QPushButton(centralWidget);
        pushButton_Help_tag->setObjectName(QStringLiteral("pushButton_Help_tag"));
        pushButton_Help_tag->setGeometry(QRect(100, 0, 80, 21));
        label_bar_background = new QLabel(centralWidget);
        label_bar_background->setObjectName(QStringLiteral("label_bar_background"));
        label_bar_background->setGeometry(QRect(290, 10, 47, 13));
        widget_dirs = new QWidget(centralWidget);
        widget_dirs->setObjectName(QStringLiteral("widget_dirs"));
        widget_dirs->setGeometry(QRect(80, 50, 152, 98));
        verticalLayout_3 = new QVBoxLayout(widget_dirs);
        verticalLayout_3->setSpacing(20);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        label_uVision = new QLabel(widget_dirs);
        label_uVision->setObjectName(QStringLiteral("label_uVision"));

        verticalLayout_2->addWidget(label_uVision);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        lineEdit_uVisionPath = new QLineEdit(widget_dirs);
        lineEdit_uVisionPath->setObjectName(QStringLiteral("lineEdit_uVisionPath"));
        lineEdit_uVisionPath->setEnabled(false);
        lineEdit_uVisionPath->setAutoFillBackground(false);
        lineEdit_uVisionPath->setEchoMode(QLineEdit::Normal);
        lineEdit_uVisionPath->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEdit_uVisionPath);

        pushButton_uVisionBrowse = new QPushButton(widget_dirs);
        pushButton_uVisionBrowse->setObjectName(QStringLiteral("pushButton_uVisionBrowse"));

        horizontalLayout_2->addWidget(pushButton_uVisionBrowse);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        label_Cube = new QLabel(widget_dirs);
        label_Cube->setObjectName(QStringLiteral("label_Cube"));

        verticalLayout->addWidget(label_Cube);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        lineEdit_CubePath = new QLineEdit(widget_dirs);
        lineEdit_CubePath->setObjectName(QStringLiteral("lineEdit_CubePath"));
        lineEdit_CubePath->setEnabled(false);
        lineEdit_CubePath->setDragEnabled(false);
        lineEdit_CubePath->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit_CubePath);

        pushButton_CubeBrowse = new QPushButton(widget_dirs);
        pushButton_CubeBrowse->setObjectName(QStringLiteral("pushButton_CubeBrowse"));

        horizontalLayout->addWidget(pushButton_CubeBrowse);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);

        widget_generate_options = new QWidget(centralWidget);
        widget_generate_options->setObjectName(QStringLiteral("widget_generate_options"));
        widget_generate_options->setGeometry(QRect(90, 160, 47, 42));
        verticalLayout_4 = new QVBoxLayout(widget_generate_options);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        label_generate_options = new QLabel(widget_generate_options);
        label_generate_options->setObjectName(QStringLiteral("label_generate_options"));

        verticalLayout_4->addWidget(label_generate_options);

        pushButton_generate_folders = new QPushButton(widget_generate_options);
        pushButton_generate_folders->setObjectName(QStringLiteral("pushButton_generate_folders"));

        verticalLayout_4->addWidget(pushButton_generate_folders);

        widget_buttons_quit = new QWidget(centralWidget);
        widget_buttons_quit->setObjectName(QStringLiteral("widget_buttons_quit"));
        widget_buttons_quit->setGeometry(QRect(304, 190, 120, 25));
        horizontalLayout_4 = new QHBoxLayout(widget_buttons_quit);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        pushButton_Generate = new QPushButton(widget_buttons_quit);
        pushButton_Generate->setObjectName(QStringLiteral("pushButton_Generate"));

        horizontalLayout_3->addWidget(pushButton_Generate);

        pushButton_Quit = new QPushButton(widget_buttons_quit);
        pushButton_Quit->setObjectName(QStringLiteral("pushButton_Quit"));

        horizontalLayout_3->addWidget(pushButton_Quit);


        horizontalLayout_4->addLayout(horizontalLayout_3);

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

        QMetaObject::connectSlotsByName(NFWizard2);
    } // setupUi

    void retranslateUi(QMainWindow *NFWizard2)
    {
        NFWizard2->setWindowTitle(QApplication::translate("NFWizard2", "NEOWizard", Q_NULLPTR));
        actionUVision_Configuration->setText(QApplication::translate("NFWizard2", "uVision Configuration", Q_NULLPTR));
        actionSTM32CubeMx_Configuration->setText(QApplication::translate("NFWizard2", "STM32CubeMx Configuration", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("NFWizard2", "About NEOWizard", Q_NULLPTR));
        actionAbout_Qt->setText(QApplication::translate("NFWizard2", "About Qt", Q_NULLPTR));
        label_bar_selection->setText(QApplication::translate("NFWizard2", "TextLabel", Q_NULLPTR));
        pushButton_Generate_tag->setText(QString());
        pushButton_Options_tag->setText(QString());
        pushButton_Help_tag->setText(QString());
        label_bar_background->setText(QApplication::translate("NFWizard2", "TextLabel", Q_NULLPTR));
        label_uVision->setText(QApplication::translate("NFWizard2", "TextLabel", Q_NULLPTR));
        lineEdit_uVisionPath->setPlaceholderText(QApplication::translate("NFWizard2", "Keil uVision Project path", Q_NULLPTR));
        pushButton_uVisionBrowse->setText(QString());
        label_Cube->setText(QApplication::translate("NFWizard2", "TextLabel", Q_NULLPTR));
        lineEdit_CubePath->setPlaceholderText(QApplication::translate("NFWizard2", "STM32CubeMx Project path", Q_NULLPTR));
        pushButton_CubeBrowse->setText(QString());
        label_generate_options->setText(QApplication::translate("NFWizard2", "textLabel", Q_NULLPTR));
        pushButton_generate_folders->setText(QString());
        pushButton_Generate->setText(QString());
        pushButton_Quit->setText(QString());
        menuHelp->setTitle(QApplication::translate("NFWizard2", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NFWizard2: public Ui_NFWizard2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NFWIZARD2_H
