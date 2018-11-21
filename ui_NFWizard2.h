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
    QVBoxLayout *verticalLayout_8;
    QLabel *l_thread_priority;
    QComboBox *cb_thread_priority;
    QVBoxLayout *verticalLayout_7;
    QLabel *l_thread_stack_size;
    QSpinBox *sb_thread_stack_size;
    QPushButton *pb_add_thread;
    QWidget *widget_options_buttons;
    QVBoxLayout *verticalLayout_10;
    QPushButton *pb_configure_Main_thread;
    QPushButton *pb_configure_thread;
    QPushButton *pushButton_uVisionBrowse_3;
    QMenuBar *menuBar;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NFWizard2)
    {
        if (NFWizard2->objectName().isEmpty())
            NFWizard2->setObjectName(QStringLiteral("NFWizard2"));
        NFWizard2->resize(793, 389);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NFWizard2->sizePolicy().hasHeightForWidth());
        NFWizard2->setSizePolicy(sizePolicy);
        NFWizard2->setMinimumSize(QSize(793, 389));
        NFWizard2->setMaximumSize(QSize(793, 389));
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
        widget_help_buttons->setGeometry(QRect(180, 40, 191, 141));
        widget_help_buttons->setStyleSheet(QStringLiteral("background-color: rgb(21, 172, 112);"));
        verticalLayout_5 = new QVBoxLayout(widget_help_buttons);
        verticalLayout_5->setSpacing(6);
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
        widget_options_thread_options->setGeometry(QRect(670, 60, 132, 209));
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

        pb_add_thread = new QPushButton(widget_options_thread_options);
        pb_add_thread->setObjectName(QStringLiteral("pb_add_thread"));
        pb_add_thread->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);\n"
"border-color: rgb(21, 172, 112);"));

        verticalLayout_9->addWidget(pb_add_thread);

        widget_options_buttons = new QWidget(centralWidget);
        widget_options_buttons->setObjectName(QStringLiteral("widget_options_buttons"));
        widget_options_buttons->setGeometry(QRect(10, 110, 129, 117));
        verticalLayout_10 = new QVBoxLayout(widget_options_buttons);
        verticalLayout_10->setSpacing(20);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setSizeConstraint(QLayout::SetFixedSize);
        pb_configure_Main_thread = new QPushButton(widget_options_buttons);
        pb_configure_Main_thread->setObjectName(QStringLiteral("pb_configure_Main_thread"));
        pb_configure_Main_thread->setEnabled(true);
        pb_configure_Main_thread->setMinimumSize(QSize(106, 25));
        pb_configure_Main_thread->setMaximumSize(QSize(200, 50));
        pb_configure_Main_thread->setCursor(QCursor(Qt::PointingHandCursor));
        pb_configure_Main_thread->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);\n"
"border-color: rgb(21, 172, 112);"));
        pb_configure_Main_thread->setFlat(false);

        verticalLayout_10->addWidget(pb_configure_Main_thread);

        pb_configure_thread = new QPushButton(widget_options_buttons);
        pb_configure_thread->setObjectName(QStringLiteral("pb_configure_thread"));
        pb_configure_thread->setEnabled(true);
        pb_configure_thread->setMinimumSize(QSize(106, 25));
        pb_configure_thread->setMaximumSize(QSize(200, 50));
        pb_configure_thread->setCursor(QCursor(Qt::PointingHandCursor));
        pb_configure_thread->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);\n"
"border-color: rgb(21, 172, 112);"));
        pb_configure_thread->setFlat(false);

        verticalLayout_10->addWidget(pb_configure_thread);

        pushButton_uVisionBrowse_3 = new QPushButton(widget_options_buttons);
        pushButton_uVisionBrowse_3->setObjectName(QStringLiteral("pushButton_uVisionBrowse_3"));
        pushButton_uVisionBrowse_3->setEnabled(true);
        pushButton_uVisionBrowse_3->setMinimumSize(QSize(106, 25));
        pushButton_uVisionBrowse_3->setMaximumSize(QSize(200, 50));
        pushButton_uVisionBrowse_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_uVisionBrowse_3->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 245, 242);\n"
"border-color: rgb(21, 172, 112);"));
        pushButton_uVisionBrowse_3->setFlat(false);

        verticalLayout_10->addWidget(pushButton_uVisionBrowse_3);

        NFWizard2->setCentralWidget(centralWidget);
        label_bar_background->raise();
        pushButton_Generate_tag->raise();
        pushButton_Options_tag->raise();
        pushButton_Help_tag->raise();
        widget_dirs->raise();
        widget_buttons_quit->raise();
        widget_help_buttons->raise();
        widget_generate_options->raise();
        pb_configure_thread->raise();
        pushButton_uVisionBrowse_3->raise();
        pb_configure_Main_thread->raise();
        cb_thread_priority->raise();
        sb_thread_stack_size->raise();
        le_thread_name->raise();
        l_thread_name->raise();
        l_thread_stack_size->raise();
        l_thread_priority->raise();
        menuBar = new QMenuBar(NFWizard2);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 793, 20));
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
        l_thread_name->setText(QApplication::translate("NFWizard2", "Thread Name", Q_NULLPTR));
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
        pb_add_thread->setText(QApplication::translate("NFWizard2", "Add Thread", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_configure_Main_thread->setToolTip(QApplication::translate("NFWizard2", "Look for uVision project path in your PC", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_configure_Main_thread->setText(QApplication::translate("NFWizard2", "Configure Main Thread", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_configure_thread->setToolTip(QApplication::translate("NFWizard2", "Look for uVision project path in your PC", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_configure_thread->setText(QApplication::translate("NFWizard2", "Configure a Thread", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton_uVisionBrowse_3->setToolTip(QApplication::translate("NFWizard2", "Look for uVision project path in your PC", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_uVisionBrowse_3->setText(QApplication::translate("NFWizard2", "Configure State Machine", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("NFWizard2", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NFWizard2: public Ui_NFWizard2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NFWIZARD2_H
