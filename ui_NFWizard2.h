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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
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
    QWidget *widget_buttons_quit;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_Quit;
    QPushButton *pushButton_Generate;
    QWidget *widget_help_buttons;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pb_uVision_Config;
    QPushButton *pb_Stcube_Config;
    QPushButton *pb_about_NEOW;
    QPushButton *pb_about_QT;
    QWidget *widget_generate_options;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_generate_options;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_generate_folders;
    QLabel *label_generate_options_2;
    QWidget *widget_options_thread_options;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_6;
    QLabel *l_thread_name;
    QLineEdit *le_thread_name;
    QVBoxLayout *verticalLayout_32;
    QLabel *l_main_thread_name;
    QLineEdit *le_main_thread_name;
    QVBoxLayout *verticalLayout_8;
    QLabel *l_thread_priority;
    QComboBox *cb_thread_priority;
    QVBoxLayout *verticalLayout_7;
    QLabel *l_thread_stack_size;
    QSpinBox *sb_thread_stack_size;
    QPushButton *pb_acept_main_thread;
    QPushButton *pb_add_thread;
    QWidget *widget_options_buttons;
    QVBoxLayout *verticalLayout_10;
    QPushButton *pb_configure_Main_thread;
    QPushButton *pb_configure_thread_in_main;
    QPushButton *pb_configure_thread_in_class;
    QSpacerItem *verticalSpacer;
    QPushButton *pb_configure_state_machine;
    QWidget *widget_layout_state_machine;
    QVBoxLayout *verticalLayout_11;
    QWidget *widget_back_search;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pb_back;
    QLabel *l_state_parent_tag;
    QLabel *l_name_current_state;
    QVBoxLayout *verticalLayout_31;
    QPushButton *pb_search_state;
    QLineEdit *le_state_to_search;
    QWidget *widget_states;
    QVBoxLayout *verticalLayout_12;
    QWidget *widget_state_info;
    QVBoxLayout *verticalLayout_22;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_20;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_2;
    QLineEdit *le_super_state_name;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_3;
    QLineEdit *le_initial_state_name;
    QVBoxLayout *verticalLayout_23;
    QLabel *l_Entry_Action;
    QLineEdit *le_entry_action;
    QVBoxLayout *verticalLayout_24;
    QLabel *l_Exit_Action;
    QLineEdit *le_exit_action;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_4;
    QLineEdit *le_default_state_name;
    QVBoxLayout *verticalLayout_21;
    QVBoxLayout *verticalLayout_16;
    QLabel *label;
    QLineEdit *le_current_state_name;
    QVBoxLayout *verticalLayout_13;
    QLabel *l_Events;
    QListWidget *lw_Events;
    QVBoxLayout *verticalLayout_14;
    QLabel *l_Next_State;
    QListWidget *lw_Next_State;
    QVBoxLayout *verticalLayout_15;
    QLabel *l_actions;
    QListWidget *lw_Actions;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pb_ok;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_add_gen_buttons;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pb_add_state;
    QLineEdit *le_state_name;
    QPushButton *pb_generate_state_machine;
    QWidget *widget_on_state_options;
    QVBoxLayout *verticalLayout_25;
    QPushButton *pb_open_state;
    QPushButton *pb_set_as_initial;
    QPushButton *pb_configure_state;
    QPushButton *pb_add_sub_sate;
    QPushButton *pb_eliminate_state;
    QWidget *widget_event_options;
    QVBoxLayout *verticalLayout_30;
    QVBoxLayout *verticalLayout_29;
    QVBoxLayout *verticalLayout_26;
    QLabel *l_EVENT;
    QLineEdit *le_event_ID_name;
    QVBoxLayout *verticalLayout_27;
    QLabel *l_NEXT_STATE;
    QLineEdit *le_next_state_name;
    QVBoxLayout *verticalLayout_28;
    QLabel *l_ACTION;
    QLineEdit *le_action_name;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pb_cancel_add_event;
    QPushButton *pb_add_event;
    QMenuBar *menuBar;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NFWizard2)
    {
        if (NFWizard2->objectName().isEmpty())
            NFWizard2->setObjectName(QStringLiteral("NFWizard2"));
        NFWizard2->resize(1280, 800);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NFWizard2->sizePolicy().hasHeightForWidth());
        NFWizard2->setSizePolicy(sizePolicy);
        NFWizard2->setMinimumSize(QSize(793, 389));
        NFWizard2->setMaximumSize(QSize(1280, 800));
        NFWizard2->setFocusPolicy(Qt::StrongFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Assets/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        NFWizard2->setWindowIcon(icon);
        NFWizard2->setStyleSheet(QStringLiteral("background-color: rgb(48, 60, 77);"));
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
        centralWidget->setStyleSheet(QStringLiteral(""));
        pushButton_Generate_tag = new QPushButton(centralWidget);
        pushButton_Generate_tag->setObjectName(QStringLiteral("pushButton_Generate_tag"));
        pushButton_Generate_tag->setGeometry(QRect(0, 10, 92, 24));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_Generate_tag->sizePolicy().hasHeightForWidth());
        pushButton_Generate_tag->setSizePolicy(sizePolicy1);
        pushButton_Generate_tag->setMinimumSize(QSize(0, 0));
        pushButton_Generate_tag->setMaximumSize(QSize(104, 25));
        pushButton_Generate_tag->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Generate_tag->setStyleSheet(QLatin1String("background-color: rgb(89, 99, 113);\n"
"border-image: url(:/Assets/generate_tag_on.png);\n"
""));
        pushButton_Generate_tag->setFlat(true);
        pushButton_Options_tag = new QPushButton(centralWidget);
        pushButton_Options_tag->setObjectName(QStringLiteral("pushButton_Options_tag"));
        pushButton_Options_tag->setGeometry(QRect(110, 8, 49, 19));
        pushButton_Options_tag->setMinimumSize(QSize(49, 19));
        pushButton_Options_tag->setMaximumSize(QSize(103, 25));
        pushButton_Options_tag->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Options_tag->setStyleSheet(QLatin1String("border-image: url(:/Assets/options_tag_off.png);\n"
"background-color: rgb(89, 99, 113);"));
        pushButton_Options_tag->setFlat(true);
        pushButton_Help_tag = new QPushButton(centralWidget);
        pushButton_Help_tag->setObjectName(QStringLiteral("pushButton_Help_tag"));
        pushButton_Help_tag->setGeometry(QRect(210, 8, 29, 19));
        sizePolicy1.setHeightForWidth(pushButton_Help_tag->sizePolicy().hasHeightForWidth());
        pushButton_Help_tag->setSizePolicy(sizePolicy1);
        pushButton_Help_tag->setMinimumSize(QSize(29, 19));
        pushButton_Help_tag->setMaximumSize(QSize(67, 25));
        pushButton_Help_tag->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Help_tag->setStyleSheet(QLatin1String("background-color: rgb(89, 99, 113);\n"
"border-image: url(:/Assets/help_tag_off.png);"));
        pushButton_Help_tag->setFlat(true);
        label_bar_background = new QLabel(centralWidget);
        label_bar_background->setObjectName(QStringLiteral("label_bar_background"));
        label_bar_background->setGeometry(QRect(0, 0, 793, 36));
        label_bar_background->setMinimumSize(QSize(793, 36));
        label_bar_background->setMaximumSize(QSize(793, 36));
        label_bar_background->setStyleSheet(QStringLiteral("background-image: url(:/Assets/background.png);"));
        widget_dirs = new QWidget(centralWidget);
        widget_dirs->setObjectName(QStringLiteral("widget_dirs"));
        widget_dirs->setGeometry(QRect(110, 70, 571, 181));
        verticalLayout_3 = new QVBoxLayout(widget_dirs);
        verticalLayout_3->setSpacing(25);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        label_uVision = new QLabel(widget_dirs);
        label_uVision->setObjectName(QStringLiteral("label_uVision"));
        label_uVision->setMinimumSize(QSize(127, 24));
        label_uVision->setMaximumSize(QSize(127, 24));
        label_uVision->setStyleSheet(QStringLiteral("background-image: url(:/Assets/label_uVision.png);"));

        verticalLayout_2->addWidget(label_uVision);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        lineEdit_uVisionPath = new QLineEdit(widget_dirs);
        lineEdit_uVisionPath->setObjectName(QStringLiteral("lineEdit_uVisionPath"));
        lineEdit_uVisionPath->setEnabled(true);
        lineEdit_uVisionPath->setMinimumSize(QSize(437, 26));
        lineEdit_uVisionPath->setMaximumSize(QSize(437, 26));
        lineEdit_uVisionPath->setCursor(QCursor(Qt::ForbiddenCursor));
        lineEdit_uVisionPath->setAutoFillBackground(false);
        lineEdit_uVisionPath->setStyleSheet(QLatin1String("border-image: url(:/Assets/line_edit.png);\n"
"color: rgb(150, 150, 150);\n"
"font: 11pt \"Segoe UI\";"));
        lineEdit_uVisionPath->setEchoMode(QLineEdit::Normal);
        lineEdit_uVisionPath->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEdit_uVisionPath);

        pushButton_uVisionBrowse = new QPushButton(widget_dirs);
        pushButton_uVisionBrowse->setObjectName(QStringLiteral("pushButton_uVisionBrowse"));
        pushButton_uVisionBrowse->setEnabled(true);
        pushButton_uVisionBrowse->setMinimumSize(QSize(106, 25));
        pushButton_uVisionBrowse->setMaximumSize(QSize(106, 25));
        pushButton_uVisionBrowse->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_uVisionBrowse->setStyleSheet(QStringLiteral("background-image: url(:/Assets/button_browse.png);"));
        pushButton_uVisionBrowse->setFlat(true);

        horizontalLayout_2->addWidget(pushButton_uVisionBrowse);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        label_Cube = new QLabel(widget_dirs);
        label_Cube->setObjectName(QStringLiteral("label_Cube"));
        label_Cube->setMinimumSize(QSize(231, 24));
        label_Cube->setMaximumSize(QSize(231, 24));
        label_Cube->setStyleSheet(QStringLiteral("background-image: url(:/Assets/label_cube.png);"));

        verticalLayout->addWidget(label_Cube);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        lineEdit_CubePath = new QLineEdit(widget_dirs);
        lineEdit_CubePath->setObjectName(QStringLiteral("lineEdit_CubePath"));
        lineEdit_CubePath->setEnabled(true);
        lineEdit_CubePath->setMinimumSize(QSize(437, 26));
        lineEdit_CubePath->setMaximumSize(QSize(437, 26));
        lineEdit_CubePath->setCursor(QCursor(Qt::ForbiddenCursor));
        lineEdit_CubePath->setStyleSheet(QLatin1String("border-image: url(:/Assets/line_edit.png);\n"
"font: 11pt \"Segoe UI\";\n"
"color: rgb(150, 150, 150);"));
        lineEdit_CubePath->setDragEnabled(false);
        lineEdit_CubePath->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit_CubePath);

        pushButton_CubeBrowse = new QPushButton(widget_dirs);
        pushButton_CubeBrowse->setObjectName(QStringLiteral("pushButton_CubeBrowse"));
        pushButton_CubeBrowse->setMinimumSize(QSize(106, 25));
        pushButton_CubeBrowse->setMaximumSize(QSize(106, 25));
        pushButton_CubeBrowse->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_CubeBrowse->setStyleSheet(QStringLiteral("background-image: url(:/Assets/button_browse.png);"));
        pushButton_CubeBrowse->setFlat(true);

        horizontalLayout->addWidget(pushButton_CubeBrowse);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);

        widget_buttons_quit = new QWidget(centralWidget);
        widget_buttons_quit->setObjectName(QStringLiteral("widget_buttons_quit"));
        widget_buttons_quit->setGeometry(QRect(400, 300, 271, 61));
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
        pushButton_Quit = new QPushButton(widget_buttons_quit);
        pushButton_Quit->setObjectName(QStringLiteral("pushButton_Quit"));
        pushButton_Quit->setMinimumSize(QSize(105, 29));
        pushButton_Quit->setMaximumSize(QSize(103, 27));
        pushButton_Quit->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Quit->setStyleSheet(QStringLiteral("background-image: url(:/Assets/button_quit.png);"));
        pushButton_Quit->setFlat(true);

        horizontalLayout_3->addWidget(pushButton_Quit);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        pushButton_Generate = new QPushButton(widget_buttons_quit);
        pushButton_Generate->setObjectName(QStringLiteral("pushButton_Generate"));
        pushButton_Generate->setMinimumSize(QSize(106, 29));
        pushButton_Generate->setMaximumSize(QSize(104, 27));
        pushButton_Generate->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Generate->setStyleSheet(QStringLiteral("background-image: url(:/Assets/generate_botom.png);"));
        pushButton_Generate->setFlat(true);

        horizontalLayout_4->addWidget(pushButton_Generate);

        widget_help_buttons = new QWidget(centralWidget);
        widget_help_buttons->setObjectName(QStringLiteral("widget_help_buttons"));
        widget_help_buttons->setGeometry(QRect(180, 40, 200, 141));
        widget_help_buttons->setMinimumSize(QSize(0, 0));
        widget_help_buttons->setStyleSheet(QStringLiteral("background-color: rgb(21, 172, 112);"));
        verticalLayout_5 = new QVBoxLayout(widget_help_buttons);
        verticalLayout_5->setSpacing(10);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetFixedSize);
        pb_uVision_Config = new QPushButton(widget_help_buttons);
        pb_uVision_Config->setObjectName(QStringLiteral("pb_uVision_Config"));
        pb_uVision_Config->setCursor(QCursor(Qt::PointingHandCursor));
        pb_uVision_Config->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);\n"
"background-color: rgb(21, 172, 112);"));
        pb_uVision_Config->setFlat(true);

        verticalLayout_5->addWidget(pb_uVision_Config);

        pb_Stcube_Config = new QPushButton(widget_help_buttons);
        pb_Stcube_Config->setObjectName(QStringLiteral("pb_Stcube_Config"));
        pb_Stcube_Config->setCursor(QCursor(Qt::PointingHandCursor));
        pb_Stcube_Config->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);\n"
"border-color: rgb(21, 172, 112);"));
        pb_Stcube_Config->setFlat(true);

        verticalLayout_5->addWidget(pb_Stcube_Config);

        pb_about_NEOW = new QPushButton(widget_help_buttons);
        pb_about_NEOW->setObjectName(QStringLiteral("pb_about_NEOW"));
        pb_about_NEOW->setCursor(QCursor(Qt::PointingHandCursor));
        pb_about_NEOW->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);\n"
"background-color: rgb(21, 172, 112);"));
        pb_about_NEOW->setFlat(true);

        verticalLayout_5->addWidget(pb_about_NEOW);

        pb_about_QT = new QPushButton(widget_help_buttons);
        pb_about_QT->setObjectName(QStringLiteral("pb_about_QT"));
        pb_about_QT->setCursor(QCursor(Qt::PointingHandCursor));
        pb_about_QT->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);\n"
"background-color: rgb(21, 172, 112);"));
        pb_about_QT->setFlat(true);

        verticalLayout_5->addWidget(pb_about_QT);

        widget_generate_options = new QWidget(centralWidget);
        widget_generate_options->setObjectName(QStringLiteral("widget_generate_options"));
        widget_generate_options->setGeometry(QRect(115, 240, 251, 91));
        verticalLayout_4 = new QVBoxLayout(widget_generate_options);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        label_generate_options = new QLabel(widget_generate_options);
        label_generate_options->setObjectName(QStringLiteral("label_generate_options"));
        label_generate_options->setMinimumSize(QSize(148, 23));
        label_generate_options->setMaximumSize(QSize(148, 23));
        label_generate_options->setStyleSheet(QStringLiteral("background-image: url(:/Assets/label_generate_options.png);"));

        verticalLayout_4->addWidget(label_generate_options);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetFixedSize);
        pushButton_generate_folders = new QPushButton(widget_generate_options);
        pushButton_generate_folders->setObjectName(QStringLiteral("pushButton_generate_folders"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(16);
        sizePolicy2.setVerticalStretch(16);
        sizePolicy2.setHeightForWidth(pushButton_generate_folders->sizePolicy().hasHeightForWidth());
        pushButton_generate_folders->setSizePolicy(sizePolicy2);
        pushButton_generate_folders->setMinimumSize(QSize(16, 16));
        pushButton_generate_folders->setMaximumSize(QSize(16, 16));
        pushButton_generate_folders->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_generate_folders->setStyleSheet(QStringLiteral("border-image: url(:/Assets/check_box_off.png);"));
        pushButton_generate_folders->setFlat(true);

        horizontalLayout_5->addWidget(pushButton_generate_folders);

        label_generate_options_2 = new QLabel(widget_generate_options);
        label_generate_options_2->setObjectName(QStringLiteral("label_generate_options_2"));
        label_generate_options_2->setMinimumSize(QSize(197, 24));
        label_generate_options_2->setMaximumSize(QSize(197, 24));
        label_generate_options_2->setStyleSheet(QStringLiteral("background-image: url(:/Assets/generate_folder_text.png);"));

        horizontalLayout_5->addWidget(label_generate_options_2);


        verticalLayout_4->addLayout(horizontalLayout_5);

        widget_options_thread_options = new QWidget(centralWidget);
        widget_options_thread_options->setObjectName(QStringLiteral("widget_options_thread_options"));
        widget_options_thread_options->setGeometry(QRect(670, 60, 132, 241));
        verticalLayout_9 = new QVBoxLayout(widget_options_thread_options);
        verticalLayout_9->setSpacing(20);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetFixedSize);
        l_thread_name = new QLabel(widget_options_thread_options);
        l_thread_name->setObjectName(QStringLiteral("l_thread_name"));
        l_thread_name->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);\n"
"border-color: rgb(21, 172, 112);"));

        verticalLayout_6->addWidget(l_thread_name);

        le_thread_name = new QLineEdit(widget_options_thread_options);
        le_thread_name->setObjectName(QStringLiteral("le_thread_name"));
        le_thread_name->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);\n"
"border-color: rgb(21, 172, 112);"));

        verticalLayout_6->addWidget(le_thread_name);


        verticalLayout_9->addLayout(verticalLayout_6);

        verticalLayout_32 = new QVBoxLayout();
        verticalLayout_32->setSpacing(6);
        verticalLayout_32->setObjectName(QStringLiteral("verticalLayout_32"));
        verticalLayout_32->setSizeConstraint(QLayout::SetFixedSize);
        l_main_thread_name = new QLabel(widget_options_thread_options);
        l_main_thread_name->setObjectName(QStringLiteral("l_main_thread_name"));
        l_main_thread_name->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);\n"
"border-color: rgb(21, 172, 112);"));

        verticalLayout_32->addWidget(l_main_thread_name);

        le_main_thread_name = new QLineEdit(widget_options_thread_options);
        le_main_thread_name->setObjectName(QStringLiteral("le_main_thread_name"));
        le_main_thread_name->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);\n"
"border-color: rgb(21, 172, 112);"));

        verticalLayout_32->addWidget(le_main_thread_name);


        verticalLayout_9->addLayout(verticalLayout_32);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setSizeConstraint(QLayout::SetFixedSize);
        l_thread_priority = new QLabel(widget_options_thread_options);
        l_thread_priority->setObjectName(QStringLiteral("l_thread_priority"));
        l_thread_priority->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);\n"
"border-color: rgb(21, 172, 112);"));

        verticalLayout_8->addWidget(l_thread_priority);

        cb_thread_priority = new QComboBox(widget_options_thread_options);
        cb_thread_priority->setObjectName(QStringLiteral("cb_thread_priority"));
        cb_thread_priority->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);\n"
"border-color: rgb(21, 172, 112);"));

        verticalLayout_8->addWidget(cb_thread_priority);


        verticalLayout_9->addLayout(verticalLayout_8);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setSizeConstraint(QLayout::SetFixedSize);
        l_thread_stack_size = new QLabel(widget_options_thread_options);
        l_thread_stack_size->setObjectName(QStringLiteral("l_thread_stack_size"));
        l_thread_stack_size->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);\n"
"border-color: rgb(21, 172, 112);"));

        verticalLayout_7->addWidget(l_thread_stack_size);

        sb_thread_stack_size = new QSpinBox(widget_options_thread_options);
        sb_thread_stack_size->setObjectName(QStringLiteral("sb_thread_stack_size"));
        sb_thread_stack_size->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);\n"
"border-color: rgb(21, 172, 112);"));
        sb_thread_stack_size->setMaximum(4096);

        verticalLayout_7->addWidget(sb_thread_stack_size);


        verticalLayout_9->addLayout(verticalLayout_7);

        pb_acept_main_thread = new QPushButton(widget_options_thread_options);
        pb_acept_main_thread->setObjectName(QStringLiteral("pb_acept_main_thread"));
        pb_acept_main_thread->setCursor(QCursor(Qt::PointingHandCursor));
        pb_acept_main_thread->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color:  rgb(21, 172, 112);"));
        pb_acept_main_thread->setFlat(true);

        verticalLayout_9->addWidget(pb_acept_main_thread);

        pb_add_thread = new QPushButton(widget_options_thread_options);
        pb_add_thread->setObjectName(QStringLiteral("pb_add_thread"));
        pb_add_thread->setCursor(QCursor(Qt::PointingHandCursor));
        pb_add_thread->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color:  rgb(21, 172, 112);"));
        pb_add_thread->setFlat(true);

        verticalLayout_9->addWidget(pb_add_thread);

        widget_options_buttons = new QWidget(centralWidget);
        widget_options_buttons->setObjectName(QStringLiteral("widget_options_buttons"));
        widget_options_buttons->setGeometry(QRect(10, 110, 400, 200));
        widget_options_buttons->setMinimumSize(QSize(400, 200));
        widget_options_buttons->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(21, 172, 112);"));
        verticalLayout_10 = new QVBoxLayout(widget_options_buttons);
        verticalLayout_10->setSpacing(20);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setSizeConstraint(QLayout::SetFixedSize);
        pb_configure_Main_thread = new QPushButton(widget_options_buttons);
        pb_configure_Main_thread->setObjectName(QStringLiteral("pb_configure_Main_thread"));
        pb_configure_Main_thread->setEnabled(true);
        pb_configure_Main_thread->setMinimumSize(QSize(150, 40));
        pb_configure_Main_thread->setMaximumSize(QSize(200, 50));
        pb_configure_Main_thread->setCursor(QCursor(Qt::PointingHandCursor));
        pb_configure_Main_thread->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color:  rgb(21, 172, 112);;\n"
""));
        pb_configure_Main_thread->setFlat(true);

        verticalLayout_10->addWidget(pb_configure_Main_thread);

        pb_configure_thread_in_main = new QPushButton(widget_options_buttons);
        pb_configure_thread_in_main->setObjectName(QStringLiteral("pb_configure_thread_in_main"));
        pb_configure_thread_in_main->setEnabled(true);
        pb_configure_thread_in_main->setMinimumSize(QSize(150, 40));
        pb_configure_thread_in_main->setMaximumSize(QSize(200, 50));
        pb_configure_thread_in_main->setCursor(QCursor(Qt::PointingHandCursor));
        pb_configure_thread_in_main->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color:  rgb(21, 172, 112);\n"
"border-color: rgb(21, 172, 112);"));
        pb_configure_thread_in_main->setFlat(true);

        verticalLayout_10->addWidget(pb_configure_thread_in_main);

        pb_configure_thread_in_class = new QPushButton(widget_options_buttons);
        pb_configure_thread_in_class->setObjectName(QStringLiteral("pb_configure_thread_in_class"));
        pb_configure_thread_in_class->setEnabled(true);
        pb_configure_thread_in_class->setMinimumSize(QSize(150, 40));
        pb_configure_thread_in_class->setMaximumSize(QSize(200, 50));
        pb_configure_thread_in_class->setCursor(QCursor(Qt::PointingHandCursor));
        pb_configure_thread_in_class->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(21, 172, 112);\n"
""));
        pb_configure_thread_in_class->setFlat(true);

        verticalLayout_10->addWidget(pb_configure_thread_in_class);

        verticalSpacer = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer);

        pb_configure_state_machine = new QPushButton(widget_options_buttons);
        pb_configure_state_machine->setObjectName(QStringLiteral("pb_configure_state_machine"));
        pb_configure_state_machine->setEnabled(true);
        pb_configure_state_machine->setMinimumSize(QSize(150, 40));
        pb_configure_state_machine->setMaximumSize(QSize(200, 50));
        pb_configure_state_machine->setCursor(QCursor(Qt::PointingHandCursor));
        pb_configure_state_machine->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color:  rgb(21, 172, 112);\n"
""));
        pb_configure_state_machine->setFlat(true);

        verticalLayout_10->addWidget(pb_configure_state_machine);

        widget_layout_state_machine = new QWidget(centralWidget);
        widget_layout_state_machine->setObjectName(QStringLiteral("widget_layout_state_machine"));
        widget_layout_state_machine->setGeometry(QRect(820, 40, 418, 428));
        verticalLayout_11 = new QVBoxLayout(widget_layout_state_machine);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setSizeConstraint(QLayout::SetFixedSize);
        widget_back_search = new QWidget(widget_layout_state_machine);
        widget_back_search->setObjectName(QStringLiteral("widget_back_search"));
        widget_back_search->setMinimumSize(QSize(0, 0));
        widget_back_search->setMaximumSize(QSize(400, 100));
        horizontalLayout_7 = new QHBoxLayout(widget_back_search);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setSizeConstraint(QLayout::SetFixedSize);
        pb_back = new QPushButton(widget_back_search);
        pb_back->setObjectName(QStringLiteral("pb_back"));
        pb_back->setMaximumSize(QSize(16777215, 30));
        pb_back->setCursor(QCursor(Qt::PointingHandCursor));
        pb_back->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color:  rgb(21, 172, 112);"));
        pb_back->setFlat(true);

        horizontalLayout_7->addWidget(pb_back);

        l_state_parent_tag = new QLabel(widget_back_search);
        l_state_parent_tag->setObjectName(QStringLiteral("l_state_parent_tag"));
        l_state_parent_tag->setMaximumSize(QSize(16777215, 20));
        l_state_parent_tag->setStyleSheet(QLatin1String("font: 11pt \"Segoe UI\";\n"
"color:  rgb(21, 172, 112);\n"
""));

        horizontalLayout_7->addWidget(l_state_parent_tag);

        l_name_current_state = new QLabel(widget_back_search);
        l_name_current_state->setObjectName(QStringLiteral("l_name_current_state"));
        l_name_current_state->setMinimumSize(QSize(80, 0));
        l_name_current_state->setMaximumSize(QSize(80, 20));
        l_name_current_state->setStyleSheet(QLatin1String("background-color: rgb(48, 60, 77);\n"
"font: 11pt \"Segoe UI\";\n"
"color:  rgb(21, 172, 112);"));

        horizontalLayout_7->addWidget(l_name_current_state);

        verticalLayout_31 = new QVBoxLayout();
        verticalLayout_31->setSpacing(6);
        verticalLayout_31->setObjectName(QStringLiteral("verticalLayout_31"));
        verticalLayout_31->setSizeConstraint(QLayout::SetFixedSize);
        pb_search_state = new QPushButton(widget_back_search);
        pb_search_state->setObjectName(QStringLiteral("pb_search_state"));
        pb_search_state->setMinimumSize(QSize(0, 20));
        pb_search_state->setMaximumSize(QSize(16777215, 30));
        pb_search_state->setCursor(QCursor(Qt::PointingHandCursor));
        pb_search_state->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color:  rgb(21, 172, 112);"));
        pb_search_state->setFlat(true);

        verticalLayout_31->addWidget(pb_search_state);

        le_state_to_search = new QLineEdit(widget_back_search);
        le_state_to_search->setObjectName(QStringLiteral("le_state_to_search"));
        le_state_to_search->setMinimumSize(QSize(80, 20));
        le_state_to_search->setMaximumSize(QSize(100, 30));
        le_state_to_search->setStyleSheet(QLatin1String("font: 11pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);"));

        verticalLayout_31->addWidget(le_state_to_search);


        horizontalLayout_7->addLayout(verticalLayout_31);


        verticalLayout_11->addWidget(widget_back_search);

        widget_states = new QWidget(widget_layout_state_machine);
        widget_states->setObjectName(QStringLiteral("widget_states"));
        widget_states->setEnabled(true);
        widget_states->setMinimumSize(QSize(400, 260));
        widget_states->setMaximumSize(QSize(400, 270));
        widget_states->setStyleSheet(QStringLiteral("background-color: rgb(89, 99, 113);"));
        verticalLayout_12 = new QVBoxLayout(widget_states);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        widget_state_info = new QWidget(widget_states);
        widget_state_info->setObjectName(QStringLiteral("widget_state_info"));
        verticalLayout_22 = new QVBoxLayout(widget_state_info);
        verticalLayout_22->setSpacing(6);
        verticalLayout_22->setContentsMargins(11, 11, 11, 11);
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(15);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setSpacing(5);
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        verticalLayout_20->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        verticalLayout_17->setSizeConstraint(QLayout::SetFixedSize);
        label_2 = new QLabel(widget_state_info);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 12));
        label_2->setStyleSheet(QLatin1String("font: 10pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);"));

        verticalLayout_17->addWidget(label_2);

        le_super_state_name = new QLineEdit(widget_state_info);
        le_super_state_name->setObjectName(QStringLiteral("le_super_state_name"));
        le_super_state_name->setStyleSheet(QLatin1String("font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);"));

        verticalLayout_17->addWidget(le_super_state_name);


        verticalLayout_20->addLayout(verticalLayout_17);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        verticalLayout_18->setSizeConstraint(QLayout::SetFixedSize);
        label_3 = new QLabel(widget_state_info);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 12));
        label_3->setStyleSheet(QLatin1String("font: 10pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);"));

        verticalLayout_18->addWidget(label_3);

        le_initial_state_name = new QLineEdit(widget_state_info);
        le_initial_state_name->setObjectName(QStringLiteral("le_initial_state_name"));
        le_initial_state_name->setStyleSheet(QLatin1String("font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);"));

        verticalLayout_18->addWidget(le_initial_state_name);


        verticalLayout_20->addLayout(verticalLayout_18);

        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setSpacing(6);
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        verticalLayout_23->setSizeConstraint(QLayout::SetFixedSize);
        l_Entry_Action = new QLabel(widget_state_info);
        l_Entry_Action->setObjectName(QStringLiteral("l_Entry_Action"));
        l_Entry_Action->setMinimumSize(QSize(0, 12));
        l_Entry_Action->setStyleSheet(QLatin1String("font: 10pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);"));

        verticalLayout_23->addWidget(l_Entry_Action);

        le_entry_action = new QLineEdit(widget_state_info);
        le_entry_action->setObjectName(QStringLiteral("le_entry_action"));
        le_entry_action->setStyleSheet(QLatin1String("font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);"));

        verticalLayout_23->addWidget(le_entry_action);


        verticalLayout_20->addLayout(verticalLayout_23);

        verticalLayout_24 = new QVBoxLayout();
        verticalLayout_24->setSpacing(6);
        verticalLayout_24->setObjectName(QStringLiteral("verticalLayout_24"));
        verticalLayout_24->setSizeConstraint(QLayout::SetFixedSize);
        l_Exit_Action = new QLabel(widget_state_info);
        l_Exit_Action->setObjectName(QStringLiteral("l_Exit_Action"));
        l_Exit_Action->setMinimumSize(QSize(0, 12));
        l_Exit_Action->setStyleSheet(QLatin1String("font: 10pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);"));

        verticalLayout_24->addWidget(l_Exit_Action);

        le_exit_action = new QLineEdit(widget_state_info);
        le_exit_action->setObjectName(QStringLiteral("le_exit_action"));
        le_exit_action->setStyleSheet(QLatin1String("font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);"));

        verticalLayout_24->addWidget(le_exit_action);


        verticalLayout_20->addLayout(verticalLayout_24);

        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setSpacing(6);
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        verticalLayout_19->setSizeConstraint(QLayout::SetFixedSize);
        label_4 = new QLabel(widget_state_info);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(0, 12));
        label_4->setStyleSheet(QLatin1String("font: 10pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);"));

        verticalLayout_19->addWidget(label_4);

        le_default_state_name = new QLineEdit(widget_state_info);
        le_default_state_name->setObjectName(QStringLiteral("le_default_state_name"));
        le_default_state_name->setStyleSheet(QLatin1String("font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);"));

        verticalLayout_19->addWidget(le_default_state_name);


        verticalLayout_20->addLayout(verticalLayout_19);


        horizontalLayout_8->addLayout(verticalLayout_20);

        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setSpacing(10);
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_16->setSizeConstraint(QLayout::SetFixedSize);
        label = new QLabel(widget_state_info);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 12));
        label->setStyleSheet(QLatin1String("font: 10pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);"));

        verticalLayout_16->addWidget(label);

        le_current_state_name = new QLineEdit(widget_state_info);
        le_current_state_name->setObjectName(QStringLiteral("le_current_state_name"));
        le_current_state_name->setStyleSheet(QLatin1String("font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);"));

        verticalLayout_16->addWidget(le_current_state_name);


        verticalLayout_21->addLayout(verticalLayout_16);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_13->setSizeConstraint(QLayout::SetFixedSize);
        l_Events = new QLabel(widget_state_info);
        l_Events->setObjectName(QStringLiteral("l_Events"));
        l_Events->setStyleSheet(QLatin1String("font: 10pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);"));

        verticalLayout_13->addWidget(l_Events);

        lw_Events = new QListWidget(widget_state_info);
        lw_Events->setObjectName(QStringLiteral("lw_Events"));
        lw_Events->setMaximumSize(QSize(120, 50));
        lw_Events->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        lw_Events->setStyleSheet(QLatin1String("font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);"));

        verticalLayout_13->addWidget(lw_Events);


        verticalLayout_21->addLayout(verticalLayout_13);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_14->setSizeConstraint(QLayout::SetFixedSize);
        l_Next_State = new QLabel(widget_state_info);
        l_Next_State->setObjectName(QStringLiteral("l_Next_State"));
        l_Next_State->setStyleSheet(QLatin1String("font: 10pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);"));

        verticalLayout_14->addWidget(l_Next_State);

        lw_Next_State = new QListWidget(widget_state_info);
        lw_Next_State->setObjectName(QStringLiteral("lw_Next_State"));
        lw_Next_State->setMaximumSize(QSize(120, 50));
        lw_Next_State->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        lw_Next_State->setStyleSheet(QLatin1String("font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);"));

        verticalLayout_14->addWidget(lw_Next_State);


        verticalLayout_21->addLayout(verticalLayout_14);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        verticalLayout_15->setSizeConstraint(QLayout::SetFixedSize);
        l_actions = new QLabel(widget_state_info);
        l_actions->setObjectName(QStringLiteral("l_actions"));
        l_actions->setStyleSheet(QLatin1String("font: 10pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);"));

        verticalLayout_15->addWidget(l_actions);

        lw_Actions = new QListWidget(widget_state_info);
        lw_Actions->setObjectName(QStringLiteral("lw_Actions"));
        lw_Actions->setMaximumSize(QSize(120, 50));
        lw_Actions->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        lw_Actions->setStyleSheet(QLatin1String("font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);"));

        verticalLayout_15->addWidget(lw_Actions);


        verticalLayout_21->addLayout(verticalLayout_15);


        horizontalLayout_8->addLayout(verticalLayout_21);


        verticalLayout_22->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        pb_ok = new QPushButton(widget_state_info);
        pb_ok->setObjectName(QStringLiteral("pb_ok"));
        pb_ok->setCursor(QCursor(Qt::PointingHandCursor));
        pb_ok->setStyleSheet(QLatin1String("font: 11pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);"));
        pb_ok->setFlat(true);

        horizontalLayout_9->addWidget(pb_ok);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);


        verticalLayout_22->addLayout(horizontalLayout_9);


        verticalLayout_12->addWidget(widget_state_info);


        verticalLayout_11->addWidget(widget_states);

        widget_add_gen_buttons = new QWidget(widget_layout_state_machine);
        widget_add_gen_buttons->setObjectName(QStringLiteral("widget_add_gen_buttons"));
        widget_add_gen_buttons->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color:  rgb(21, 172, 112);"));
        horizontalLayout_6 = new QHBoxLayout(widget_add_gen_buttons);
        horizontalLayout_6->setSpacing(10);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetFixedSize);
        pb_add_state = new QPushButton(widget_add_gen_buttons);
        pb_add_state->setObjectName(QStringLiteral("pb_add_state"));
        pb_add_state->setMinimumSize(QSize(120, 0));
        pb_add_state->setMaximumSize(QSize(133, 16777215));
        pb_add_state->setCursor(QCursor(Qt::PointingHandCursor));
        pb_add_state->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color:  rgb(21, 172, 112);"));
        pb_add_state->setFlat(true);

        horizontalLayout_6->addWidget(pb_add_state);

        le_state_name = new QLineEdit(widget_add_gen_buttons);
        le_state_name->setObjectName(QStringLiteral("le_state_name"));
        le_state_name->setMinimumSize(QSize(120, 0));
        le_state_name->setMaximumSize(QSize(133, 16777215));
        le_state_name->setStyleSheet(QLatin1String("font: 10pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);"));

        horizontalLayout_6->addWidget(le_state_name);

        pb_generate_state_machine = new QPushButton(widget_add_gen_buttons);
        pb_generate_state_machine->setObjectName(QStringLiteral("pb_generate_state_machine"));
        pb_generate_state_machine->setEnabled(true);
        pb_generate_state_machine->setMinimumSize(QSize(120, 0));
        pb_generate_state_machine->setMaximumSize(QSize(133, 16777215));
        pb_generate_state_machine->setCursor(QCursor(Qt::PointingHandCursor));
        pb_generate_state_machine->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color:  rgb(21, 172, 112);"));
        pb_generate_state_machine->setFlat(true);

        horizontalLayout_6->addWidget(pb_generate_state_machine);


        verticalLayout_11->addWidget(widget_add_gen_buttons);

        widget_on_state_options = new QWidget(centralWidget);
        widget_on_state_options->setObjectName(QStringLiteral("widget_on_state_options"));
        widget_on_state_options->setGeometry(QRect(705, 300, 101, 121));
        widget_on_state_options->setCursor(QCursor(Qt::ArrowCursor));
        verticalLayout_25 = new QVBoxLayout(widget_on_state_options);
        verticalLayout_25->setSpacing(6);
        verticalLayout_25->setContentsMargins(11, 11, 11, 11);
        verticalLayout_25->setObjectName(QStringLiteral("verticalLayout_25"));
        verticalLayout_25->setSizeConstraint(QLayout::SetFixedSize);
        pb_open_state = new QPushButton(widget_on_state_options);
        pb_open_state->setObjectName(QStringLiteral("pb_open_state"));
        pb_open_state->setCursor(QCursor(Qt::PointingHandCursor));
        pb_open_state->setStyleSheet(QLatin1String("font:  10pt \"Segoe UI\";\n"
"border-color: rgb(21, 172, 112);\n"
"color:  rgb(21, 172, 112);"));
        pb_open_state->setFlat(true);

        verticalLayout_25->addWidget(pb_open_state);

        pb_set_as_initial = new QPushButton(widget_on_state_options);
        pb_set_as_initial->setObjectName(QStringLiteral("pb_set_as_initial"));
        pb_set_as_initial->setCursor(QCursor(Qt::PointingHandCursor));
        pb_set_as_initial->setStyleSheet(QLatin1String("font:  10pt \"Segoe UI\";\n"
"border-color: rgb(21, 172, 112);\n"
"color:  rgb(21, 172, 112);"));
        pb_set_as_initial->setFlat(true);

        verticalLayout_25->addWidget(pb_set_as_initial);

        pb_configure_state = new QPushButton(widget_on_state_options);
        pb_configure_state->setObjectName(QStringLiteral("pb_configure_state"));
        pb_configure_state->setCursor(QCursor(Qt::PointingHandCursor));
        pb_configure_state->setStyleSheet(QLatin1String("font: 10pt \"Segoe UI\";\n"
"border-color: rgb(21, 172, 112);\n"
"color:  rgb(21, 172, 112);"));
        pb_configure_state->setFlat(true);

        verticalLayout_25->addWidget(pb_configure_state);

        pb_add_sub_sate = new QPushButton(widget_on_state_options);
        pb_add_sub_sate->setObjectName(QStringLiteral("pb_add_sub_sate"));
        pb_add_sub_sate->setCursor(QCursor(Qt::PointingHandCursor));
        pb_add_sub_sate->setStyleSheet(QLatin1String("font: 10pt \"Segoe UI\";\n"
"border-color: rgb(21, 172, 112);\n"
"color:  rgb(21, 172, 112);"));
        pb_add_sub_sate->setFlat(true);

        verticalLayout_25->addWidget(pb_add_sub_sate);

        pb_eliminate_state = new QPushButton(widget_on_state_options);
        pb_eliminate_state->setObjectName(QStringLiteral("pb_eliminate_state"));
        pb_eliminate_state->setCursor(QCursor(Qt::PointingHandCursor));
        pb_eliminate_state->setStyleSheet(QLatin1String("font: 10pt \"Segoe UI\";\n"
"border-color: rgb(21, 172, 112);\n"
"color:  rgb(21, 172, 112);"));
        pb_eliminate_state->setFlat(true);

        verticalLayout_25->addWidget(pb_eliminate_state);

        widget_event_options = new QWidget(centralWidget);
        widget_event_options->setObjectName(QStringLiteral("widget_event_options"));
        widget_event_options->setGeometry(QRect(540, 350, 187, 231));
        verticalLayout_30 = new QVBoxLayout(widget_event_options);
        verticalLayout_30->setSpacing(6);
        verticalLayout_30->setContentsMargins(11, 11, 11, 11);
        verticalLayout_30->setObjectName(QStringLiteral("verticalLayout_30"));
        verticalLayout_29 = new QVBoxLayout();
        verticalLayout_29->setSpacing(6);
        verticalLayout_29->setObjectName(QStringLiteral("verticalLayout_29"));
        verticalLayout_29->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_26 = new QVBoxLayout();
        verticalLayout_26->setSpacing(6);
        verticalLayout_26->setObjectName(QStringLiteral("verticalLayout_26"));
        verticalLayout_26->setSizeConstraint(QLayout::SetFixedSize);
        l_EVENT = new QLabel(widget_event_options);
        l_EVENT->setObjectName(QStringLiteral("l_EVENT"));
        l_EVENT->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color:  rgb(21, 172, 112);"));

        verticalLayout_26->addWidget(l_EVENT);

        le_event_ID_name = new QLineEdit(widget_event_options);
        le_event_ID_name->setObjectName(QStringLiteral("le_event_ID_name"));
        le_event_ID_name->setMaximumSize(QSize(165, 16777215));
        le_event_ID_name->setStyleSheet(QLatin1String("font: 10pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);"));

        verticalLayout_26->addWidget(le_event_ID_name);


        verticalLayout_29->addLayout(verticalLayout_26);

        verticalLayout_27 = new QVBoxLayout();
        verticalLayout_27->setSpacing(6);
        verticalLayout_27->setObjectName(QStringLiteral("verticalLayout_27"));
        verticalLayout_27->setSizeConstraint(QLayout::SetFixedSize);
        l_NEXT_STATE = new QLabel(widget_event_options);
        l_NEXT_STATE->setObjectName(QStringLiteral("l_NEXT_STATE"));
        l_NEXT_STATE->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color:  rgb(21, 172, 112);"));

        verticalLayout_27->addWidget(l_NEXT_STATE);

        le_next_state_name = new QLineEdit(widget_event_options);
        le_next_state_name->setObjectName(QStringLiteral("le_next_state_name"));
        le_next_state_name->setMaximumSize(QSize(165, 16777215));
        le_next_state_name->setStyleSheet(QLatin1String("font: 10pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);"));

        verticalLayout_27->addWidget(le_next_state_name);


        verticalLayout_29->addLayout(verticalLayout_27);

        verticalLayout_28 = new QVBoxLayout();
        verticalLayout_28->setSpacing(6);
        verticalLayout_28->setObjectName(QStringLiteral("verticalLayout_28"));
        verticalLayout_28->setSizeConstraint(QLayout::SetFixedSize);
        l_ACTION = new QLabel(widget_event_options);
        l_ACTION->setObjectName(QStringLiteral("l_ACTION"));
        l_ACTION->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color:  rgb(21, 172, 112);"));

        verticalLayout_28->addWidget(l_ACTION);

        le_action_name = new QLineEdit(widget_event_options);
        le_action_name->setObjectName(QStringLiteral("le_action_name"));
        le_action_name->setMinimumSize(QSize(165, 0));
        le_action_name->setMaximumSize(QSize(165, 16777215));
        le_action_name->setStyleSheet(QLatin1String("font: 10pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);"));

        verticalLayout_28->addWidget(le_action_name);


        verticalLayout_29->addLayout(verticalLayout_28);


        verticalLayout_30->addLayout(verticalLayout_29);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        pb_cancel_add_event = new QPushButton(widget_event_options);
        pb_cancel_add_event->setObjectName(QStringLiteral("pb_cancel_add_event"));
        pb_cancel_add_event->setCursor(QCursor(Qt::PointingHandCursor));
        pb_cancel_add_event->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color:  rgb(21, 172, 112);"));
        pb_cancel_add_event->setFlat(true);

        horizontalLayout_10->addWidget(pb_cancel_add_event);

        pb_add_event = new QPushButton(widget_event_options);
        pb_add_event->setObjectName(QStringLiteral("pb_add_event"));
        pb_add_event->setCursor(QCursor(Qt::PointingHandCursor));
        pb_add_event->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color:  rgb(21, 172, 112);"));
        pb_add_event->setFlat(true);

        horizontalLayout_10->addWidget(pb_add_event);


        verticalLayout_30->addLayout(horizontalLayout_10);

        NFWizard2->setCentralWidget(centralWidget);
        label_bar_background->raise();
        pushButton_Generate_tag->raise();
        pushButton_Options_tag->raise();
        pushButton_Help_tag->raise();
        widget_dirs->raise();
        widget_buttons_quit->raise();
        widget_help_buttons->raise();
        widget_generate_options->raise();
        widget_layout_state_machine->raise();
        widget_on_state_options->raise();
        widget_options_thread_options->raise();
        widget_event_options->raise();
        widget_options_buttons->raise();
        menuBar = new QMenuBar(NFWizard2);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 20));
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

        pb_about_QT->setDefault(false);


        QMetaObject::connectSlotsByName(NFWizard2);
    } // setupUi

    void retranslateUi(QMainWindow *NFWizard2)
    {
        NFWizard2->setWindowTitle(QApplication::translate("NFWizard2", "NEOWizard", Q_NULLPTR));
        actionUVision_Configuration->setText(QApplication::translate("NFWizard2", "uVision Configuration", Q_NULLPTR));
        actionSTM32CubeMx_Configuration->setText(QApplication::translate("NFWizard2", "STM32CubeMx Configuration", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("NFWizard2", "About NEOWizard", Q_NULLPTR));
        actionAbout_Qt->setText(QApplication::translate("NFWizard2", "About Qt", Q_NULLPTR));
        pushButton_Generate_tag->setText(QString());
        pushButton_Options_tag->setText(QString());
        pushButton_Help_tag->setText(QString());
        label_bar_background->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_uVision->setToolTip(QApplication::translate("NFWizard2", "Keil uVision project path on your PC (*.uvprojx file)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_uVision->setText(QString());
#ifndef QT_NO_TOOLTIP
        lineEdit_uVisionPath->setToolTip(QApplication::translate("NFWizard2", "Keil uVision project path on your PC", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        lineEdit_uVisionPath->setPlaceholderText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_uVisionBrowse->setToolTip(QApplication::translate("NFWizard2", "Look for uVision project path in your PC", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_uVisionBrowse->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_Cube->setToolTip(QApplication::translate("NFWizard2", "STCubeMX generated project path on your PC (*.ioc file)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_Cube->setText(QString());
#ifndef QT_NO_TOOLTIP
        lineEdit_CubePath->setToolTip(QApplication::translate("NFWizard2", "STCube generated project path on your PC", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        lineEdit_CubePath->setPlaceholderText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_CubeBrowse->setToolTip(QApplication::translate("NFWizard2", "Look for STCubeMX generated project path in your PC", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_CubeBrowse->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_Quit->setToolTip(QApplication::translate("NFWizard2", "Close application", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_Quit->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_Generate->setToolTip(QApplication::translate("NFWizard2", "Generate the files and modifies files needed to become compatible both projects", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_Generate->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_uVision_Config->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pb_uVision_Config->setText(QApplication::translate("NFWizard2", "uVision Configuration", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_Stcube_Config->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pb_Stcube_Config->setText(QApplication::translate("NFWizard2", "STM32CubeMx Configuration", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_about_NEOW->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pb_about_NEOW->setText(QApplication::translate("NFWizard2", "About NEOWizard", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_about_QT->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pb_about_QT->setText(QApplication::translate("NFWizard2", "About Qt", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_generate_options->setToolTip(QApplication::translate("NFWizard2", "Generates files needed. If they are generated already you don't need to mark this option", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_generate_options->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_generate_folders->setToolTip(QApplication::translate("NFWizard2", "Generates files needed. If they are generated already you don't need to mark this option", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_generate_folders->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_generate_options_2->setToolTip(QApplication::translate("NFWizard2", "Generates files needed. If they are generated already you don't need to mark this option", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_generate_options_2->setText(QString());
        l_thread_name->setText(QApplication::translate("NFWizard2", "New Thread Name", Q_NULLPTR));
        l_main_thread_name->setText(QApplication::translate("NFWizard2", "Main Thread Name", Q_NULLPTR));
        l_thread_priority->setText(QApplication::translate("NFWizard2", "Thread Priority", Q_NULLPTR));
        cb_thread_priority->clear();
        cb_thread_priority->insertItems(0, QStringList()
         << QApplication::translate("NFWizard2", "Idle ", Q_NULLPTR)
         << QApplication::translate("NFWizard2", "Low ", Q_NULLPTR)
         << QApplication::translate("NFWizard2", "BelowNormal ", Q_NULLPTR)
         << QApplication::translate("NFWizard2", "Normal ", Q_NULLPTR)
         << QApplication::translate("NFWizard2", "AboveNormal ", Q_NULLPTR)
         << QApplication::translate("NFWizard2", "High ", Q_NULLPTR)
         << QApplication::translate("NFWizard2", "Realtime ", Q_NULLPTR)
         << QApplication::translate("NFWizard2", "Error ", Q_NULLPTR)
        );
        l_thread_stack_size->setText(QApplication::translate("NFWizard2", "Thread Stack Size ", Q_NULLPTR));
        pb_acept_main_thread->setText(QApplication::translate("NFWizard2", "Acept", Q_NULLPTR));
        pb_add_thread->setText(QApplication::translate("NFWizard2", "Add Thread", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_configure_Main_thread->setToolTip(QApplication::translate("NFWizard2", "Look for uVision project path in your PC", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_configure_Main_thread->setText(QApplication::translate("NFWizard2", "Configure Main Thread", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_configure_thread_in_main->setToolTip(QApplication::translate("NFWizard2", "Look for uVision project path in your PC", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_configure_thread_in_main->setText(QApplication::translate("NFWizard2", "Configure Thread in Main", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_configure_thread_in_class->setToolTip(QApplication::translate("NFWizard2", "Look for uVision project path in your PC", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_configure_thread_in_class->setText(QApplication::translate("NFWizard2", "Configure a Thread", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_configure_state_machine->setToolTip(QApplication::translate("NFWizard2", "Look for uVision project path in your PC", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_configure_state_machine->setText(QApplication::translate("NFWizard2", "Configure State Machine", Q_NULLPTR));
        pb_back->setText(QApplication::translate("NFWizard2", "Back", Q_NULLPTR));
        l_state_parent_tag->setText(QApplication::translate("NFWizard2", "      Super State  :", Q_NULLPTR));
        l_name_current_state->setText(QApplication::translate("NFWizard2", "No Parent", Q_NULLPTR));
        pb_search_state->setText(QApplication::translate("NFWizard2", "Search", Q_NULLPTR));
        label_2->setText(QApplication::translate("NFWizard2", "SUPER STATE", Q_NULLPTR));
        label_3->setText(QApplication::translate("NFWizard2", "INITIAL STATE", Q_NULLPTR));
        l_Entry_Action->setText(QApplication::translate("NFWizard2", "ENTRY ACTION", Q_NULLPTR));
        l_Exit_Action->setText(QApplication::translate("NFWizard2", "EXIT ACTION", Q_NULLPTR));
        label_4->setText(QApplication::translate("NFWizard2", "DEFAULT EVENT", Q_NULLPTR));
        label->setText(QApplication::translate("NFWizard2", "STATE NAME", Q_NULLPTR));
        l_Events->setText(QApplication::translate("NFWizard2", "EVENTS", Q_NULLPTR));
        l_Next_State->setText(QApplication::translate("NFWizard2", "NEXT STATE", Q_NULLPTR));
        l_actions->setText(QApplication::translate("NFWizard2", "ACTIONS", Q_NULLPTR));
        pb_ok->setText(QApplication::translate("NFWizard2", "Apply", Q_NULLPTR));
        pb_add_state->setText(QApplication::translate("NFWizard2", "Add State", Q_NULLPTR));
        pb_generate_state_machine->setText(QApplication::translate("NFWizard2", "Generate", Q_NULLPTR));
        pb_open_state->setText(QApplication::translate("NFWizard2", "Open State", Q_NULLPTR));
        pb_set_as_initial->setText(QApplication::translate("NFWizard2", "Set as Initial", Q_NULLPTR));
        pb_configure_state->setText(QApplication::translate("NFWizard2", "Configure State", Q_NULLPTR));
        pb_add_sub_sate->setText(QApplication::translate("NFWizard2", "Add Child ", Q_NULLPTR));
        pb_eliminate_state->setText(QApplication::translate("NFWizard2", "Eliminate State", Q_NULLPTR));
        l_EVENT->setText(QApplication::translate("NFWizard2", "EVENT ID", Q_NULLPTR));
        l_NEXT_STATE->setText(QApplication::translate("NFWizard2", "NEXT STATE", Q_NULLPTR));
        l_ACTION->setText(QApplication::translate("NFWizard2", "ACTION", Q_NULLPTR));
        pb_cancel_add_event->setText(QApplication::translate("NFWizard2", "Cancel", Q_NULLPTR));
        pb_add_event->setText(QApplication::translate("NFWizard2", "Add Event", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("NFWizard2", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NFWizard2: public Ui_NFWizard2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NFWIZARD2_H
