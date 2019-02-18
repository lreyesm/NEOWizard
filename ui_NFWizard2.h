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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeWidget>
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
    QWidget *widget_generate_screen;
    QPushButton *pushButton_Generate;
    QPushButton *pushButton_Quit;
    QLineEdit *lineEdit_CubePath;
    QPushButton *pushButton_CubeBrowse;
    QPushButton *pushButton_uVisionBrowse;
    QLineEdit *lineEdit_uVisionPath;
    QLabel *label_Cube;
    QLabel *label_uVision;
    QPushButton *pushButton_generate_folders;
    QLabel *label_generate_options;
    QPushButton *pb_generate_project_folders;
    QWidget *widget_options_screen_native;
    QPushButton *pb_configure_thread_in_class;
    QPushButton *pb_configure_Main_thread;
    QPushButton *pb_configure_in_Main_thread;
    QPushButton *pb_configure_state_machine;
    QWidget *widget_options_thread_options;
    QPushButton *pb_add_thread;
    QLabel *l_main_thread_name;
    QLineEdit *le_main_thread_name;
    QLabel *l_thread_name;
    QLineEdit *le_thread_name;
    QLabel *l_thread_priority;
    QComboBox *cb_thread_priority;
    QSpinBox *sb_thread_stack_size;
    QLabel *l_thread_stack_size;
    QWidget *widget_configure_in_main_thread;
    QPushButton *pb_configure_thread_in_main;
    QPushButton *pb_configure_Mail;
    QPushButton *pb_configure_Timer;
    QPushButton *pb_configure_semaphore;
    QPushButton *pb_configure_memoryPool;
    QPushButton *pb_configure_mutex;
    QPushButton *pb_configure_messQueue;
    QPushButton *pb_configure_serialPort;
    QWidget *widget_timer_parameters;
    QVBoxLayout *verticalLayout_39;
    QVBoxLayout *verticalLayout_47;
    QLabel *l_EVENT_13;
    QLineEdit *le_timer_name;
    QComboBox *cb_timer_mode;
    QVBoxLayout *verticalLayout_37;
    QLabel *l_EVENT_3;
    QSpinBox *sb_timer_interval;
    QVBoxLayout *verticalLayout_36;
    QLabel *l_EVENT_4;
    QLineEdit *le_timer_function;
    QPushButton *pb_add_Timer;
    QWidget *widget_mailBox_parameters;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_40;
    QLabel *l_EVENT_5;
    QLineEdit *le_mailBox_name;
    QVBoxLayout *verticalLayout_41;
    QLabel *l_EVENT_9;
    QLineEdit *le_mail_data_type;
    QVBoxLayout *verticalLayout_4;
    QLabel *l_EVENT_7;
    QSpinBox *sb_mailBox_size;
    QVBoxLayout *verticalLayout_3;
    QLabel *l_EVENT_6;
    QSpinBox *sb_mailBox_buffer_size;
    QPushButton *pb_add_MailBox;
    QWidget *widget_memory_pool_parameters;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_42;
    QLabel *l_EVENT_10;
    QLineEdit *le_memory_pool_name;
    QVBoxLayout *verticalLayout_7;
    QLabel *l_EVENT_11;
    QSpinBox *sb_memory_pool_size;
    QVBoxLayout *verticalLayout_44;
    QLabel *l_memPool_data_type;
    QLineEdit *le_memPool_data_type;
    QCheckBox *cb_memoryPool_buffer;
    QVBoxLayout *verticalLayout_45;
    QLabel *l_memPool_buffer_type;
    QLineEdit *le_memPool_buffer_Type;
    QVBoxLayout *verticalLayout_8;
    QLabel *l_memPool_buffer_size;
    QSpinBox *sb_memory_pool_buffer_size;
    QPushButton *pb_add_memPool;
    QWidget *widget_semaphore_parameters;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_38;
    QLabel *l_EVENT_2;
    QLineEdit *le_semaphore_name;
    QVBoxLayout *verticalLayout_46;
    QLabel *l_EVENT_12;
    QSpinBox *sb_semaphore_res_size;
    QPushButton *pb_add_Semaphore;
    QWidget *widget_mutex_parameters;
    QVBoxLayout *verticalLayout_13;
    QVBoxLayout *verticalLayout_11;
    QLabel *l_EVENT_14;
    QLineEdit *le_Mutex_name;
    QPushButton *pb_add_Mutex;
    QWidget *widget_messQueue_parameters;
    QVBoxLayout *verticalLayout_30;
    QVBoxLayout *verticalLayout_43;
    QLabel *l_EVENT_8;
    QLineEdit *le_messQueue_name;
    QVBoxLayout *verticalLayout_48;
    QLabel *l_EVENT_15;
    QSpinBox *sb_messQueue_size;
    QPushButton *pb_add_messQueue;
    QWidget *widget_serialPort_parameters;
    QVBoxLayout *verticalLayout_16;
    QVBoxLayout *verticalLayout_49;
    QLabel *l_EVENT_16;
    QLineEdit *le_serialport_name;
    QVBoxLayout *verticalLayout_50;
    QLabel *l_EVENT_17;
    QSpinBox *sb_serialport_usart_number;
    QPushButton *pb_add_SerialPort;
    QWidget *widget_state_machine_screen;
    QPushButton *pb_load_from_Thread;
    QPushButton *pb_save_state_machine;
    QPushButton *pb_load_state_machine;
    QWidget *widget_layout_state_machine;
    QVBoxLayout *verticalLayout;
    QWidget *widget_states;
    QVBoxLayout *verticalLayout_12;
    QWidget *widget_state_info;
    QVBoxLayout *verticalLayout_22;
    QHBoxLayout *horizontalLayout_8;
    QWidget *widget_super_initial_default_state;
    QVBoxLayout *verticalLayout_20;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_2;
    QLineEdit *le_super_state_name;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_3;
    QLineEdit *le_initial_state_name;
    QWidget *widget_state_name_default_event;
    QVBoxLayout *verticalLayout_19;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_10;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *le_current_state_name;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_16;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_5;
    QLineEdit *le_default_state_name;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_6;
    QLineEdit *le_default_action_name;
    QWidget *widget_events;
    QHBoxLayout *horizontalLayout_12;
    QTableView *tableView_events;
    QWidget *widget_state_name_entry_exit_actions;
    QVBoxLayout *verticalLayout_21;
    QVBoxLayout *verticalLayout_23;
    QLabel *l_Entry_Action;
    QLineEdit *le_entry_action;
    QVBoxLayout *verticalLayout_24;
    QLabel *l_Exit_Action;
    QLineEdit *le_exit_action;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pb_change_to_event;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pb_ok;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pb_generate_state_machine;
    QLineEdit *le_state_name;
    QLabel *l_name_current_state;
    QLabel *l_state_parent_tag;
    QPushButton *pb_back;
    QPushButton *pb_search_state;
    QLineEdit *le_state_to_search;
    QTreeWidget *tw_state_machine;
    QPushButton *pb_back_from_state_machine;
    QPushButton *pb_add_state;
    QWidget *widget_on_state_options;
    QVBoxLayout *verticalLayout_25;
    QPushButton *pb_open_state;
    QPushButton *pb_set_as_initial;
    QPushButton *pb_configure_state;
    QPushButton *pb_add_sub_sate;
    QPushButton *pb_eliminate_state;
    QPushButton *pb_cancel_state_options;
    QPushButton *pb_warning_state_machine;
    QWidget *widget_add_delete_event;
    QVBoxLayout *verticalLayout_35;
    QPushButton *pb_add_event_action;
    QPushButton *pb_delete_event_action;
    QPushButton *pb_cancel_add_event_2;
    QPushButton *pb_Simulate_HSM;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_acept_main_thread;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_wait;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_loading;
    QWidget *widget_win_buttons;
    QPushButton *pb_close_window;
    QPushButton *pb_max_window;
    QPushButton *pushButton_Generate_tag;
    QPushButton *pb_min_window_;
    QPushButton *pushButton_Help_tag;
    QPushButton *pushButton_Options_tag;
    QLabel *label_bar_background;
    QWidget *l_background_blur;
    QWidget *widget_state_machine_name;
    QLabel *l_state_machine_name;
    QLineEdit *le_state_machine_name;
    QPushButton *pb_acept_sate_machine_name;
    QPushButton *pb_cancel_state_machine_name;
    QWidget *widget_main_thread_name;
    QLabel *l_main_thrad_name;
    QLineEdit *le_main_thread_name_to_load;
    QPushButton *pb_acept_main_thread_name;
    QPushButton *pb_cancel_main_thrad_name;
    QWidget *widget_event_options;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pb_cancel_add_event;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pb_add_event;
    QPushButton *pb_delete_event;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_26;
    QLabel *l_EVENT;
    QLineEdit *le_event_ID_name;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_27;
    QLabel *l_NEXT_STATE;
    QLineEdit *le_next_state_name;
    QWidget *layoutWidget_5;
    QVBoxLayout *verticalLayout_28;
    QLabel *l_ACTION;
    QLineEdit *le_action_name;
    QWidget *widget_simulate_HSM;
    QPushButton *pb_back_from_HSM_simulate;
    QWidget *layoutWidget_6;
    QVBoxLayout *verticalLayout_32;
    QLabel *l_EVENT_18;
    QLineEdit *le_simulated_event_ID_name;
    QWidget *layoutWidget_7;
    QVBoxLayout *verticalLayout_33;
    QLabel *l_NEXT_STATE_2;
    QLineEdit *le_simulated_next_state_name;
    QWidget *layoutWidget_8;
    QVBoxLayout *verticalLayout_34;
    QLabel *l_ACTION_2;
    QLineEdit *le_simulated_action_name;
    QPushButton *pb_simulate_dispatch;
    QListWidget *lw_simulated_events;
    QLabel *l_EVENT_19;
    QLabel *l_EVENT_20;
    QLabel *l_current_state_simulated;
    QWidget *widget_help_screen;
    QPushButton *pb_Stcube_Config;
    QPushButton *pb_about_NEOW;
    QPushButton *pb_about_QT;
    QPushButton *pb_uVision_Config;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_31;
    QWidget *widget_examples;
    QVBoxLayout *verticalLayout_29;
    QPushButton *pb_thread_example;
    QPushButton *pb_timer_example;
    QPushButton *pb_mail_example;
    QPushButton *pb_memoryPool_example;
    QPushButton *pb_semaphore_example;
    QPushButton *pb_mutex_example;
    QPushButton *pb_messQueue_example;
    QPushButton *pb_serialPort_example;
    QWidget *widget_win_options;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pb_minimize_option;
    QPushButton *pb_maximize_option;
    QPushButton *pb_cancel_option;
    QPushButton *pb_close_option;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NFWizard2)
    {
        if (NFWizard2->objectName().isEmpty())
            NFWizard2->setObjectName(QStringLiteral("NFWizard2"));
        NFWizard2->resize(8000, 768);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NFWizard2->sizePolicy().hasHeightForWidth());
        NFWizard2->setSizePolicy(sizePolicy);
        NFWizard2->setMinimumSize(QSize(793, 389));
        NFWizard2->setMaximumSize(QSize(16777215, 16777215));
        NFWizard2->setFocusPolicy(Qt::StrongFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Assets/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        NFWizard2->setWindowIcon(icon);
        NFWizard2->setStyleSheet(QStringLiteral(""));
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
        widget_generate_screen = new QWidget(centralWidget);
        widget_generate_screen->setObjectName(QStringLiteral("widget_generate_screen"));
        widget_generate_screen->setGeometry(QRect(0, 0, 1366, 768));
        widget_generate_screen->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen1/background.png);"));
        pushButton_Generate = new QPushButton(widget_generate_screen);
        pushButton_Generate->setObjectName(QStringLiteral("pushButton_Generate"));
        pushButton_Generate->setGeometry(QRect(900, 621, 136, 35));
        pushButton_Generate->setMinimumSize(QSize(106, 29));
        pushButton_Generate->setMaximumSize(QSize(200, 200));
        pushButton_Generate->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Generate->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen1/generate_botom.png);"));
        pushButton_Generate->setFlat(true);
        pushButton_Quit = new QPushButton(widget_generate_screen);
        pushButton_Quit->setObjectName(QStringLiteral("pushButton_Quit"));
        pushButton_Quit->setGeometry(QRect(730, 621, 140, 37));
        pushButton_Quit->setMinimumSize(QSize(105, 29));
        pushButton_Quit->setMaximumSize(QSize(200, 200));
        pushButton_Quit->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Quit->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen1/quit_botom_2.png);"));
        pushButton_Quit->setFlat(true);
        lineEdit_CubePath = new QLineEdit(widget_generate_screen);
        lineEdit_CubePath->setObjectName(QStringLiteral("lineEdit_CubePath"));
        lineEdit_CubePath->setEnabled(true);
        lineEdit_CubePath->setGeometry(QRect(330, 401, 595, 35));
        lineEdit_CubePath->setMinimumSize(QSize(437, 26));
        lineEdit_CubePath->setMaximumSize(QSize(600, 36));
        lineEdit_CubePath->setCursor(QCursor(Qt::ForbiddenCursor));
        lineEdit_CubePath->setStyleSheet(QLatin1String("border-image: url(:/icons/screen1/label_screen_1.png);\n"
"color: rgb(150, 150, 150);\n"
"font: 14pt \"Segoe UI\";"));
        lineEdit_CubePath->setDragEnabled(false);
        lineEdit_CubePath->setReadOnly(true);
        pushButton_CubeBrowse = new QPushButton(widget_generate_screen);
        pushButton_CubeBrowse->setObjectName(QStringLiteral("pushButton_CubeBrowse"));
        pushButton_CubeBrowse->setGeometry(QRect(923, 400, 116, 37));
        pushButton_CubeBrowse->setMinimumSize(QSize(106, 25));
        pushButton_CubeBrowse->setMaximumSize(QSize(200, 200));
        pushButton_CubeBrowse->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_CubeBrowse->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen1/browse_botom.png);"));
        pushButton_CubeBrowse->setFlat(true);
        pushButton_uVisionBrowse = new QPushButton(widget_generate_screen);
        pushButton_uVisionBrowse->setObjectName(QStringLiteral("pushButton_uVisionBrowse"));
        pushButton_uVisionBrowse->setEnabled(true);
        pushButton_uVisionBrowse->setGeometry(QRect(920, 289, 116, 37));
        pushButton_uVisionBrowse->setMinimumSize(QSize(106, 25));
        pushButton_uVisionBrowse->setMaximumSize(QSize(200, 200));
        pushButton_uVisionBrowse->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_uVisionBrowse->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen1/browse_botom.png);"));
        pushButton_uVisionBrowse->setFlat(true);
        lineEdit_uVisionPath = new QLineEdit(widget_generate_screen);
        lineEdit_uVisionPath->setObjectName(QStringLiteral("lineEdit_uVisionPath"));
        lineEdit_uVisionPath->setEnabled(true);
        lineEdit_uVisionPath->setGeometry(QRect(329, 290, 595, 35));
        lineEdit_uVisionPath->setMinimumSize(QSize(437, 26));
        lineEdit_uVisionPath->setMaximumSize(QSize(600, 200));
        lineEdit_uVisionPath->setCursor(QCursor(Qt::ForbiddenCursor));
        lineEdit_uVisionPath->setAutoFillBackground(false);
        lineEdit_uVisionPath->setStyleSheet(QLatin1String("border-image: url(:/icons/screen1/label_screen_1.png);\n"
"color: rgb(150, 150, 150);\n"
"font: 14pt \"Segoe UI\";"));
        lineEdit_uVisionPath->setEchoMode(QLineEdit::Normal);
        lineEdit_uVisionPath->setReadOnly(true);
        label_Cube = new QLabel(widget_generate_screen);
        label_Cube->setObjectName(QStringLiteral("label_Cube"));
        label_Cube->setGeometry(QRect(329, 360, 316, 31));
        label_Cube->setMinimumSize(QSize(231, 24));
        label_Cube->setMaximumSize(QSize(600, 40));
        label_Cube->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen1/STM32Cube MX Project path_text.png);"));
        label_uVision = new QLabel(widget_generate_screen);
        label_uVision->setObjectName(QStringLiteral("label_uVision"));
        label_uVision->setGeometry(QRect(329, 250, 164, 31));
        label_uVision->setMinimumSize(QSize(127, 24));
        label_uVision->setMaximumSize(QSize(600, 50));
        label_uVision->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen1/uVision_Projects_text.png);"));
        pushButton_generate_folders = new QPushButton(widget_generate_screen);
        pushButton_generate_folders->setObjectName(QStringLiteral("pushButton_generate_folders"));
        pushButton_generate_folders->setGeometry(QRect(370, 553, 22, 22));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(16);
        sizePolicy1.setVerticalStretch(16);
        sizePolicy1.setHeightForWidth(pushButton_generate_folders->sizePolicy().hasHeightForWidth());
        pushButton_generate_folders->setSizePolicy(sizePolicy1);
        pushButton_generate_folders->setMinimumSize(QSize(16, 16));
        pushButton_generate_folders->setMaximumSize(QSize(40, 40));
        pushButton_generate_folders->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_generate_folders->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen1/check_box.png);"));
        pushButton_generate_folders->setFlat(true);
        label_generate_options = new QLabel(widget_generate_screen);
        label_generate_options->setObjectName(QStringLiteral("label_generate_options"));
        label_generate_options->setGeometry(QRect(369, 510, 200, 31));
        label_generate_options->setMinimumSize(QSize(148, 23));
        label_generate_options->setMaximumSize(QSize(300, 200));
        label_generate_options->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen1/Generation_options_text.png);"));
        pb_generate_project_folders = new QPushButton(widget_generate_screen);
        pb_generate_project_folders->setObjectName(QStringLiteral("pb_generate_project_folders"));
        pb_generate_project_folders->setGeometry(QRect(410, 550, 265, 31));
        pb_generate_project_folders->setMinimumSize(QSize(105, 29));
        pb_generate_project_folders->setMaximumSize(QSize(500, 200));
        pb_generate_project_folders->setCursor(QCursor(Qt::PointingHandCursor));
        pb_generate_project_folders->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen1/generation_project_text.png);"));
        pb_generate_project_folders->setFlat(true);
        pushButton_Generate->raise();
        pushButton_Quit->raise();
        lineEdit_CubePath->raise();
        pushButton_CubeBrowse->raise();
        lineEdit_uVisionPath->raise();
        label_Cube->raise();
        label_uVision->raise();
        pushButton_generate_folders->raise();
        label_generate_options->raise();
        pushButton_uVisionBrowse->raise();
        pb_generate_project_folders->raise();
        widget_options_screen_native = new QWidget(centralWidget);
        widget_options_screen_native->setObjectName(QStringLiteral("widget_options_screen_native"));
        widget_options_screen_native->setGeometry(QRect(2560, 0, 1366, 768));
        widget_options_screen_native->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen1/background.png);"));
        pb_configure_thread_in_class = new QPushButton(widget_options_screen_native);
        pb_configure_thread_in_class->setObjectName(QStringLiteral("pb_configure_thread_in_class"));
        pb_configure_thread_in_class->setEnabled(true);
        pb_configure_thread_in_class->setGeometry(QRect(315, 405, 263, 31));
        pb_configure_thread_in_class->setMinimumSize(QSize(0, 0));
        pb_configure_thread_in_class->setMaximumSize(QSize(500, 50));
        pb_configure_thread_in_class->setCursor(QCursor(Qt::PointingHandCursor));
        pb_configure_thread_in_class->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen5/Configure a thread_off.png);"));
        pb_configure_thread_in_class->setFlat(true);
        pb_configure_Main_thread = new QPushButton(widget_options_screen_native);
        pb_configure_Main_thread->setObjectName(QStringLiteral("pb_configure_Main_thread"));
        pb_configure_Main_thread->setEnabled(true);
        pb_configure_Main_thread->setGeometry(QRect(270, 250, 308, 31));
        pb_configure_Main_thread->setMinimumSize(QSize(0, 0));
        pb_configure_Main_thread->setMaximumSize(QSize(500, 50));
        pb_configure_Main_thread->setCursor(QCursor(Qt::PointingHandCursor));
        pb_configure_Main_thread->setStyleSheet(QLatin1String("background-image: url(:/icons/screen6/Configure main thread_off.png);\n"
"\n"
""));
        pb_configure_Main_thread->setFlat(true);
        pb_configure_in_Main_thread = new QPushButton(widget_options_screen_native);
        pb_configure_in_Main_thread->setObjectName(QStringLiteral("pb_configure_in_Main_thread"));
        pb_configure_in_Main_thread->setEnabled(true);
        pb_configure_in_Main_thread->setGeometry(QRect(245, 330, 333, 31));
        pb_configure_in_Main_thread->setMinimumSize(QSize(0, 0));
        pb_configure_in_Main_thread->setMaximumSize(QSize(500, 50));
        pb_configure_in_Main_thread->setCursor(QCursor(Qt::PointingHandCursor));
        pb_configure_in_Main_thread->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen5/Configure thread in main_off.png);"));
        pb_configure_in_Main_thread->setFlat(true);
        pb_configure_state_machine = new QPushButton(widget_options_screen_native);
        pb_configure_state_machine->setObjectName(QStringLiteral("pb_configure_state_machine"));
        pb_configure_state_machine->setEnabled(true);
        pb_configure_state_machine->setGeometry(QRect(220, 510, 366, 65));
        pb_configure_state_machine->setMinimumSize(QSize(150, 40));
        pb_configure_state_machine->setMaximumSize(QSize(500, 200));
        pb_configure_state_machine->setCursor(QCursor(Qt::PointingHandCursor));
        pb_configure_state_machine->setStyleSheet(QLatin1String("background-image: url(:/icons/screen5/CONFIGURE STATE MACHINE_botom.png);\n"
""));
        pb_configure_state_machine->setFlat(true);
        widget_options_thread_options = new QWidget(widget_options_screen_native);
        widget_options_thread_options->setObjectName(QStringLiteral("widget_options_thread_options"));
        widget_options_thread_options->setGeometry(QRect(630, 160, 661, 458));
        widget_options_thread_options->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/fondo_blanco.png);"));
        pb_add_thread = new QPushButton(widget_options_thread_options);
        pb_add_thread->setObjectName(QStringLiteral("pb_add_thread"));
        pb_add_thread->setGeometry(QRect(289, 352, 214, 47));
        pb_add_thread->setMinimumSize(QSize(214, 47));
        pb_add_thread->setMaximumSize(QSize(214, 47));
        pb_add_thread->setCursor(QCursor(Qt::PointingHandCursor));
        pb_add_thread->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen6/add_botom.png);"));
        pb_add_thread->setFlat(true);
        l_main_thread_name = new QLabel(widget_options_thread_options);
        l_main_thread_name->setObjectName(QStringLiteral("l_main_thread_name"));
        l_main_thread_name->setGeometry(QRect(30, 85, 203, 33));
        l_main_thread_name->setMinimumSize(QSize(203, 33));
        l_main_thread_name->setMaximumSize(QSize(203, 33));
        l_main_thread_name->setStyleSheet(QLatin1String("font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        le_main_thread_name = new QLineEdit(widget_options_thread_options);
        le_main_thread_name->setObjectName(QStringLiteral("le_main_thread_name"));
        le_main_thread_name->setGeometry(QRect(288, 85, 214, 41));
        le_main_thread_name->setMinimumSize(QSize(214, 41));
        le_main_thread_name->setMaximumSize(QSize(214, 41));
        le_main_thread_name->setStyleSheet(QLatin1String("border-image: url(:/icons/screen6/label_1.png);\n"
"font: 75 16pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        le_main_thread_name->setAlignment(Qt::AlignCenter);
        l_thread_name = new QLabel(widget_options_thread_options);
        l_thread_name->setObjectName(QStringLiteral("l_thread_name"));
        l_thread_name->setGeometry(QRect(36, 159, 199, 31));
        l_thread_name->setStyleSheet(QLatin1String("font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        le_thread_name = new QLineEdit(widget_options_thread_options);
        le_thread_name->setObjectName(QStringLiteral("le_thread_name"));
        le_thread_name->setGeometry(QRect(288, 157, 214, 41));
        le_thread_name->setMinimumSize(QSize(214, 41));
        le_thread_name->setMaximumSize(QSize(214, 41));
        le_thread_name->setStyleSheet(QLatin1String("border-image: url(:/icons/screen6/label_1.png);\n"
"font: 75 16pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        le_thread_name->setAlignment(Qt::AlignCenter);
        l_thread_priority = new QLabel(widget_options_thread_options);
        l_thread_priority->setObjectName(QStringLiteral("l_thread_priority"));
        l_thread_priority->setGeometry(QRect(70, 287, 164, 33));
        l_thread_priority->setMinimumSize(QSize(164, 33));
        l_thread_priority->setMaximumSize(QSize(164, 33));
        l_thread_priority->setStyleSheet(QLatin1String("font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        cb_thread_priority = new QComboBox(widget_options_thread_options);
        cb_thread_priority->setObjectName(QStringLiteral("cb_thread_priority"));
        cb_thread_priority->setGeometry(QRect(290, 290, 211, 31));
        cb_thread_priority->setStyleSheet(QLatin1String("\n"
"border-image: url(:/icons/screen5/label_2.png);\n"
"font: 75 16pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
"\n"
""));
        sb_thread_stack_size = new QSpinBox(widget_options_thread_options);
        sb_thread_stack_size->setObjectName(QStringLiteral("sb_thread_stack_size"));
        sb_thread_stack_size->setGeometry(QRect(290, 232, 211, 29));
        sb_thread_stack_size->setStyleSheet(QLatin1String("\n"
"border-image: url(:/icons/screen5/label_2.png);\n"
"font: 75 14pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        sb_thread_stack_size->setAlignment(Qt::AlignCenter);
        sb_thread_stack_size->setMaximum(4096);
        sb_thread_stack_size->setSingleStep(10);
        l_thread_stack_size = new QLabel(widget_options_thread_options);
        l_thread_stack_size->setObjectName(QStringLiteral("l_thread_stack_size"));
        l_thread_stack_size->setGeometry(QRect(46, 227, 189, 33));
        l_thread_stack_size->setMinimumSize(QSize(189, 33));
        l_thread_stack_size->setMaximumSize(QSize(189, 33));
        l_thread_stack_size->setStyleSheet(QLatin1String("font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        l_thread_priority->raise();
        cb_thread_priority->raise();
        sb_thread_stack_size->raise();
        l_thread_stack_size->raise();
        l_main_thread_name->raise();
        le_main_thread_name->raise();
        l_thread_name->raise();
        le_thread_name->raise();
        pb_add_thread->raise();
        widget_configure_in_main_thread = new QWidget(widget_options_screen_native);
        widget_configure_in_main_thread->setObjectName(QStringLiteral("widget_configure_in_main_thread"));
        widget_configure_in_main_thread->setGeometry(QRect(680, 220, 671, 501));
        widget_configure_in_main_thread->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/fondo_transparente.png);"));
        pb_configure_thread_in_main = new QPushButton(widget_configure_in_main_thread);
        pb_configure_thread_in_main->setObjectName(QStringLiteral("pb_configure_thread_in_main"));
        pb_configure_thread_in_main->setEnabled(true);
        pb_configure_thread_in_main->setGeometry(QRect(80, 20, 150, 40));
        pb_configure_thread_in_main->setMinimumSize(QSize(150, 40));
        pb_configure_thread_in_main->setMaximumSize(QSize(200, 50));
        pb_configure_thread_in_main->setCursor(QCursor(Qt::PointingHandCursor));
        pb_configure_thread_in_main->setStyleSheet(QLatin1String("background-image: url(:/icons/screen8/fondo_transparente.png);\n"
"font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_configure_thread_in_main->setFlat(true);
        pb_configure_Mail = new QPushButton(widget_configure_in_main_thread);
        pb_configure_Mail->setObjectName(QStringLiteral("pb_configure_Mail"));
        pb_configure_Mail->setEnabled(true);
        pb_configure_Mail->setGeometry(QRect(96, 140, 150, 41));
        pb_configure_Mail->setMinimumSize(QSize(150, 40));
        pb_configure_Mail->setMaximumSize(QSize(200, 50));
        pb_configure_Mail->setCursor(QCursor(Qt::PointingHandCursor));
        pb_configure_Mail->setStyleSheet(QLatin1String("background-image: url(:/icons/screen8/fondo_transparente.png);\n"
"font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_configure_Mail->setFlat(true);
        pb_configure_Timer = new QPushButton(widget_configure_in_main_thread);
        pb_configure_Timer->setObjectName(QStringLiteral("pb_configure_Timer"));
        pb_configure_Timer->setEnabled(true);
        pb_configure_Timer->setGeometry(QRect(90, 80, 150, 40));
        pb_configure_Timer->setMinimumSize(QSize(150, 40));
        pb_configure_Timer->setMaximumSize(QSize(200, 50));
        pb_configure_Timer->setCursor(QCursor(Qt::PointingHandCursor));
        pb_configure_Timer->setStyleSheet(QLatin1String("background-image: url(:/icons/screen8/fondo_transparente.png);\n"
"font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_configure_Timer->setFlat(true);
        pb_configure_semaphore = new QPushButton(widget_configure_in_main_thread);
        pb_configure_semaphore->setObjectName(QStringLiteral("pb_configure_semaphore"));
        pb_configure_semaphore->setEnabled(true);
        pb_configure_semaphore->setGeometry(QRect(33, 260, 200, 40));
        pb_configure_semaphore->setMinimumSize(QSize(150, 40));
        pb_configure_semaphore->setMaximumSize(QSize(200, 50));
        pb_configure_semaphore->setCursor(QCursor(Qt::PointingHandCursor));
        pb_configure_semaphore->setStyleSheet(QLatin1String("background-image: url(:/icons/screen8/fondo_transparente.png);\n"
"font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_configure_semaphore->setFlat(true);
        pb_configure_memoryPool = new QPushButton(widget_configure_in_main_thread);
        pb_configure_memoryPool->setObjectName(QStringLiteral("pb_configure_memoryPool"));
        pb_configure_memoryPool->setEnabled(true);
        pb_configure_memoryPool->setGeometry(QRect(28, 200, 191, 40));
        pb_configure_memoryPool->setMinimumSize(QSize(150, 40));
        pb_configure_memoryPool->setMaximumSize(QSize(200, 50));
        pb_configure_memoryPool->setCursor(QCursor(Qt::PointingHandCursor));
        pb_configure_memoryPool->setStyleSheet(QLatin1String("background-image: url(:/icons/screen8/fondo_transparente.png);\n"
"font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_configure_memoryPool->setFlat(true);
        pb_configure_mutex = new QPushButton(widget_configure_in_main_thread);
        pb_configure_mutex->setObjectName(QStringLiteral("pb_configure_mutex"));
        pb_configure_mutex->setEnabled(true);
        pb_configure_mutex->setGeometry(QRect(58, 320, 200, 40));
        pb_configure_mutex->setMinimumSize(QSize(150, 40));
        pb_configure_mutex->setMaximumSize(QSize(200, 50));
        pb_configure_mutex->setCursor(QCursor(Qt::PointingHandCursor));
        pb_configure_mutex->setStyleSheet(QLatin1String("background-image: url(:/icons/screen8/fondo_transparente.png);\n"
"font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_configure_mutex->setFlat(true);
        pb_configure_messQueue = new QPushButton(widget_configure_in_main_thread);
        pb_configure_messQueue->setObjectName(QStringLiteral("pb_configure_messQueue"));
        pb_configure_messQueue->setEnabled(true);
        pb_configure_messQueue->setGeometry(QRect(0, 380, 220, 40));
        pb_configure_messQueue->setMinimumSize(QSize(150, 40));
        pb_configure_messQueue->setMaximumSize(QSize(220, 50));
        pb_configure_messQueue->setCursor(QCursor(Qt::PointingHandCursor));
        pb_configure_messQueue->setStyleSheet(QLatin1String("background-image: url(:/icons/screen8/fondo_transparente.png);\n"
"font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_configure_messQueue->setFlat(true);
        pb_configure_serialPort = new QPushButton(widget_configure_in_main_thread);
        pb_configure_serialPort->setObjectName(QStringLiteral("pb_configure_serialPort"));
        pb_configure_serialPort->setEnabled(true);
        pb_configure_serialPort->setGeometry(QRect(34, 440, 220, 40));
        pb_configure_serialPort->setMinimumSize(QSize(150, 40));
        pb_configure_serialPort->setMaximumSize(QSize(220, 50));
        pb_configure_serialPort->setCursor(QCursor(Qt::PointingHandCursor));
        pb_configure_serialPort->setStyleSheet(QLatin1String("background-image: url(:/icons/screen8/fondo_transparente.png);\n"
"font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_configure_serialPort->setFlat(true);
        widget_timer_parameters = new QWidget(widget_options_screen_native);
        widget_timer_parameters->setObjectName(QStringLiteral("widget_timer_parameters"));
        widget_timer_parameters->setGeometry(QRect(30, 10, 251, 381));
        widget_timer_parameters->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/fondo_transparente.png);"));
        verticalLayout_39 = new QVBoxLayout(widget_timer_parameters);
        verticalLayout_39->setSpacing(30);
        verticalLayout_39->setContentsMargins(11, 11, 11, 11);
        verticalLayout_39->setObjectName(QStringLiteral("verticalLayout_39"));
        verticalLayout_39->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_47 = new QVBoxLayout();
        verticalLayout_47->setSpacing(6);
        verticalLayout_47->setObjectName(QStringLiteral("verticalLayout_47"));
        verticalLayout_47->setSizeConstraint(QLayout::SetFixedSize);
        l_EVENT_13 = new QLabel(widget_timer_parameters);
        l_EVENT_13->setObjectName(QStringLiteral("l_EVENT_13"));
        l_EVENT_13->setStyleSheet(QLatin1String("font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        l_EVENT_13->setAlignment(Qt::AlignCenter);

        verticalLayout_47->addWidget(l_EVENT_13);

        le_timer_name = new QLineEdit(widget_timer_parameters);
        le_timer_name->setObjectName(QStringLiteral("le_timer_name"));
        le_timer_name->setMinimumSize(QSize(214, 41));
        le_timer_name->setStyleSheet(QLatin1String("border-image: url(:/icons/screen6/label_1.png);\n"
"font: 75 16pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));

        verticalLayout_47->addWidget(le_timer_name);


        verticalLayout_39->addLayout(verticalLayout_47);

        cb_timer_mode = new QComboBox(widget_timer_parameters);
        cb_timer_mode->setObjectName(QStringLiteral("cb_timer_mode"));
        cb_timer_mode->setMinimumSize(QSize(0, 31));
        cb_timer_mode->setLayoutDirection(Qt::LeftToRight);
        cb_timer_mode->setStyleSheet(QLatin1String("\n"
"border-image: url(:/icons/screen5/label_2.png);\n"
"font: 75 14pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));

        verticalLayout_39->addWidget(cb_timer_mode);

        verticalLayout_37 = new QVBoxLayout();
        verticalLayout_37->setSpacing(6);
        verticalLayout_37->setObjectName(QStringLiteral("verticalLayout_37"));
        verticalLayout_37->setSizeConstraint(QLayout::SetFixedSize);
        l_EVENT_3 = new QLabel(widget_timer_parameters);
        l_EVENT_3->setObjectName(QStringLiteral("l_EVENT_3"));
        l_EVENT_3->setStyleSheet(QLatin1String("font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        l_EVENT_3->setAlignment(Qt::AlignCenter);

        verticalLayout_37->addWidget(l_EVENT_3);

        sb_timer_interval = new QSpinBox(widget_timer_parameters);
        sb_timer_interval->setObjectName(QStringLiteral("sb_timer_interval"));
        sb_timer_interval->setMinimumSize(QSize(0, 25));
        sb_timer_interval->setStyleSheet(QLatin1String("font: 14pt \"Segoe UI\";\n"
"border-image: url(:/icons/screen5/label_2.png);\n"
"color: rgb(8, 113, 104);\n"
""));
        sb_timer_interval->setAlignment(Qt::AlignCenter);
        sb_timer_interval->setMaximum(100000);
        sb_timer_interval->setSingleStep(10);
        sb_timer_interval->setValue(100);

        verticalLayout_37->addWidget(sb_timer_interval);


        verticalLayout_39->addLayout(verticalLayout_37);

        verticalLayout_36 = new QVBoxLayout();
        verticalLayout_36->setSpacing(6);
        verticalLayout_36->setObjectName(QStringLiteral("verticalLayout_36"));
        verticalLayout_36->setSizeConstraint(QLayout::SetFixedSize);
        l_EVENT_4 = new QLabel(widget_timer_parameters);
        l_EVENT_4->setObjectName(QStringLiteral("l_EVENT_4"));
        l_EVENT_4->setStyleSheet(QLatin1String("font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        l_EVENT_4->setAlignment(Qt::AlignCenter);

        verticalLayout_36->addWidget(l_EVENT_4);

        le_timer_function = new QLineEdit(widget_timer_parameters);
        le_timer_function->setObjectName(QStringLiteral("le_timer_function"));
        le_timer_function->setMinimumSize(QSize(214, 41));
        le_timer_function->setStyleSheet(QLatin1String("border-image: url(:/icons/screen6/label_1.png);\n"
"font: 75 16pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));

        verticalLayout_36->addWidget(le_timer_function);


        verticalLayout_39->addLayout(verticalLayout_36);

        pb_add_Timer = new QPushButton(widget_timer_parameters);
        pb_add_Timer->setObjectName(QStringLiteral("pb_add_Timer"));
        pb_add_Timer->setEnabled(true);
        pb_add_Timer->setMinimumSize(QSize(150, 40));
        pb_add_Timer->setMaximumSize(QSize(16777215, 50));
        pb_add_Timer->setCursor(QCursor(Qt::PointingHandCursor));
        pb_add_Timer->setStyleSheet(QLatin1String("font: 63 18pt \"Segoe UI Semibold\";\n"
"color:  rgb(8, 113, 104);"));
        pb_add_Timer->setFlat(true);

        verticalLayout_39->addWidget(pb_add_Timer);

        widget_mailBox_parameters = new QWidget(widget_options_screen_native);
        widget_mailBox_parameters->setObjectName(QStringLiteral("widget_mailBox_parameters"));
        widget_mailBox_parameters->setGeometry(QRect(310, 0, 234, 401));
        widget_mailBox_parameters->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/fondo_transparente.png);"));
        verticalLayout_6 = new QVBoxLayout(widget_mailBox_parameters);
        verticalLayout_6->setSpacing(30);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_40 = new QVBoxLayout();
        verticalLayout_40->setSpacing(6);
        verticalLayout_40->setObjectName(QStringLiteral("verticalLayout_40"));
        verticalLayout_40->setSizeConstraint(QLayout::SetFixedSize);
        l_EVENT_5 = new QLabel(widget_mailBox_parameters);
        l_EVENT_5->setObjectName(QStringLiteral("l_EVENT_5"));
        l_EVENT_5->setStyleSheet(QLatin1String("font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        l_EVENT_5->setAlignment(Qt::AlignCenter);

        verticalLayout_40->addWidget(l_EVENT_5);

        le_mailBox_name = new QLineEdit(widget_mailBox_parameters);
        le_mailBox_name->setObjectName(QStringLiteral("le_mailBox_name"));
        le_mailBox_name->setMinimumSize(QSize(214, 41));
        le_mailBox_name->setStyleSheet(QLatin1String("border-image: url(:/icons/screen6/label_1.png);\n"
"font: 75 16pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));

        verticalLayout_40->addWidget(le_mailBox_name);


        verticalLayout_6->addLayout(verticalLayout_40);

        verticalLayout_41 = new QVBoxLayout();
        verticalLayout_41->setSpacing(6);
        verticalLayout_41->setObjectName(QStringLiteral("verticalLayout_41"));
        verticalLayout_41->setSizeConstraint(QLayout::SetFixedSize);
        l_EVENT_9 = new QLabel(widget_mailBox_parameters);
        l_EVENT_9->setObjectName(QStringLiteral("l_EVENT_9"));
        l_EVENT_9->setStyleSheet(QLatin1String("font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        l_EVENT_9->setAlignment(Qt::AlignCenter);

        verticalLayout_41->addWidget(l_EVENT_9);

        le_mail_data_type = new QLineEdit(widget_mailBox_parameters);
        le_mail_data_type->setObjectName(QStringLiteral("le_mail_data_type"));
        le_mail_data_type->setMinimumSize(QSize(214, 41));
        le_mail_data_type->setStyleSheet(QLatin1String("border-image: url(:/icons/screen6/label_1.png);\n"
"font: 75 16pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));

        verticalLayout_41->addWidget(le_mail_data_type);


        verticalLayout_6->addLayout(verticalLayout_41);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        l_EVENT_7 = new QLabel(widget_mailBox_parameters);
        l_EVENT_7->setObjectName(QStringLiteral("l_EVENT_7"));
        l_EVENT_7->setStyleSheet(QLatin1String("font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        l_EVENT_7->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(l_EVENT_7);

        sb_mailBox_size = new QSpinBox(widget_mailBox_parameters);
        sb_mailBox_size->setObjectName(QStringLiteral("sb_mailBox_size"));
        sb_mailBox_size->setMinimumSize(QSize(0, 25));
        sb_mailBox_size->setStyleSheet(QLatin1String("\n"
"border-image: url(:/icons/screen5/label_2.png);\n"
"font: 75 14pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        sb_mailBox_size->setAlignment(Qt::AlignCenter);
        sb_mailBox_size->setMaximum(100000);
        sb_mailBox_size->setSingleStep(1);
        sb_mailBox_size->setValue(1);

        verticalLayout_4->addWidget(sb_mailBox_size);


        verticalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        l_EVENT_6 = new QLabel(widget_mailBox_parameters);
        l_EVENT_6->setObjectName(QStringLiteral("l_EVENT_6"));
        l_EVENT_6->setStyleSheet(QLatin1String("font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        l_EVENT_6->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(l_EVENT_6);

        sb_mailBox_buffer_size = new QSpinBox(widget_mailBox_parameters);
        sb_mailBox_buffer_size->setObjectName(QStringLiteral("sb_mailBox_buffer_size"));
        sb_mailBox_buffer_size->setMinimumSize(QSize(0, 25));
        sb_mailBox_buffer_size->setStyleSheet(QLatin1String("\n"
"border-image: url(:/icons/screen5/label_2.png);\n"
"font: 75 14pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        sb_mailBox_buffer_size->setAlignment(Qt::AlignCenter);
        sb_mailBox_buffer_size->setMaximum(100000);
        sb_mailBox_buffer_size->setSingleStep(1);
        sb_mailBox_buffer_size->setValue(1);

        verticalLayout_3->addWidget(sb_mailBox_buffer_size);


        verticalLayout_6->addLayout(verticalLayout_3);

        pb_add_MailBox = new QPushButton(widget_mailBox_parameters);
        pb_add_MailBox->setObjectName(QStringLiteral("pb_add_MailBox"));
        pb_add_MailBox->setEnabled(true);
        pb_add_MailBox->setMinimumSize(QSize(150, 40));
        pb_add_MailBox->setMaximumSize(QSize(16777215, 50));
        pb_add_MailBox->setCursor(QCursor(Qt::PointingHandCursor));
        pb_add_MailBox->setStyleSheet(QLatin1String("font: 63 18pt \"Segoe UI Semibold\";\n"
"color:  rgb(8, 113, 104);"));
        pb_add_MailBox->setFlat(true);

        verticalLayout_6->addWidget(pb_add_MailBox);

        widget_memory_pool_parameters = new QWidget(widget_options_screen_native);
        widget_memory_pool_parameters->setObjectName(QStringLiteral("widget_memory_pool_parameters"));
        widget_memory_pool_parameters->setGeometry(QRect(1130, 220, 271, 491));
        widget_memory_pool_parameters->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/fondo_transparente.png);"));
        verticalLayout_9 = new QVBoxLayout(widget_memory_pool_parameters);
        verticalLayout_9->setSpacing(30);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_42 = new QVBoxLayout();
        verticalLayout_42->setSpacing(6);
        verticalLayout_42->setObjectName(QStringLiteral("verticalLayout_42"));
        verticalLayout_42->setSizeConstraint(QLayout::SetFixedSize);
        l_EVENT_10 = new QLabel(widget_memory_pool_parameters);
        l_EVENT_10->setObjectName(QStringLiteral("l_EVENT_10"));
        l_EVENT_10->setStyleSheet(QLatin1String("font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        l_EVENT_10->setAlignment(Qt::AlignCenter);

        verticalLayout_42->addWidget(l_EVENT_10);

        le_memory_pool_name = new QLineEdit(widget_memory_pool_parameters);
        le_memory_pool_name->setObjectName(QStringLiteral("le_memory_pool_name"));
        le_memory_pool_name->setMinimumSize(QSize(214, 41));
        le_memory_pool_name->setStyleSheet(QLatin1String("border-image: url(:/icons/screen6/label_1.png);\n"
"font: 75 16pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));

        verticalLayout_42->addWidget(le_memory_pool_name);


        verticalLayout_9->addLayout(verticalLayout_42);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setSizeConstraint(QLayout::SetFixedSize);
        l_EVENT_11 = new QLabel(widget_memory_pool_parameters);
        l_EVENT_11->setObjectName(QStringLiteral("l_EVENT_11"));
        l_EVENT_11->setStyleSheet(QLatin1String("font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        l_EVENT_11->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(l_EVENT_11);

        sb_memory_pool_size = new QSpinBox(widget_memory_pool_parameters);
        sb_memory_pool_size->setObjectName(QStringLiteral("sb_memory_pool_size"));
        sb_memory_pool_size->setMinimumSize(QSize(0, 25));
        sb_memory_pool_size->setStyleSheet(QLatin1String("\n"
"border-image: url(:/icons/screen5/label_2.png);\n"
"font: 75 14pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        sb_memory_pool_size->setAlignment(Qt::AlignCenter);
        sb_memory_pool_size->setMinimum(1);
        sb_memory_pool_size->setMaximum(100000);
        sb_memory_pool_size->setSingleStep(1);
        sb_memory_pool_size->setValue(1);

        verticalLayout_7->addWidget(sb_memory_pool_size);


        verticalLayout_9->addLayout(verticalLayout_7);

        verticalLayout_44 = new QVBoxLayout();
        verticalLayout_44->setSpacing(6);
        verticalLayout_44->setObjectName(QStringLiteral("verticalLayout_44"));
        verticalLayout_44->setSizeConstraint(QLayout::SetFixedSize);
        l_memPool_data_type = new QLabel(widget_memory_pool_parameters);
        l_memPool_data_type->setObjectName(QStringLiteral("l_memPool_data_type"));
        l_memPool_data_type->setStyleSheet(QLatin1String("font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        l_memPool_data_type->setAlignment(Qt::AlignCenter);

        verticalLayout_44->addWidget(l_memPool_data_type);

        le_memPool_data_type = new QLineEdit(widget_memory_pool_parameters);
        le_memPool_data_type->setObjectName(QStringLiteral("le_memPool_data_type"));
        le_memPool_data_type->setMinimumSize(QSize(214, 41));
        le_memPool_data_type->setStyleSheet(QLatin1String("border-image: url(:/icons/screen6/label_1.png);\n"
"font: 75 16pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));

        verticalLayout_44->addWidget(le_memPool_data_type);


        verticalLayout_9->addLayout(verticalLayout_44);

        cb_memoryPool_buffer = new QCheckBox(widget_memory_pool_parameters);
        cb_memoryPool_buffer->setObjectName(QStringLiteral("cb_memoryPool_buffer"));
        cb_memoryPool_buffer->setStyleSheet(QLatin1String("font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
"\n"
""));

        verticalLayout_9->addWidget(cb_memoryPool_buffer);

        verticalLayout_45 = new QVBoxLayout();
        verticalLayout_45->setSpacing(6);
        verticalLayout_45->setObjectName(QStringLiteral("verticalLayout_45"));
        verticalLayout_45->setSizeConstraint(QLayout::SetFixedSize);
        l_memPool_buffer_type = new QLabel(widget_memory_pool_parameters);
        l_memPool_buffer_type->setObjectName(QStringLiteral("l_memPool_buffer_type"));
        l_memPool_buffer_type->setStyleSheet(QLatin1String("font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        l_memPool_buffer_type->setAlignment(Qt::AlignCenter);

        verticalLayout_45->addWidget(l_memPool_buffer_type);

        le_memPool_buffer_Type = new QLineEdit(widget_memory_pool_parameters);
        le_memPool_buffer_Type->setObjectName(QStringLiteral("le_memPool_buffer_Type"));
        le_memPool_buffer_Type->setMinimumSize(QSize(214, 41));
        le_memPool_buffer_Type->setStyleSheet(QLatin1String("border-image: url(:/icons/screen6/label_1.png);\n"
"font: 75 16pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));

        verticalLayout_45->addWidget(le_memPool_buffer_Type);


        verticalLayout_9->addLayout(verticalLayout_45);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setSizeConstraint(QLayout::SetFixedSize);
        l_memPool_buffer_size = new QLabel(widget_memory_pool_parameters);
        l_memPool_buffer_size->setObjectName(QStringLiteral("l_memPool_buffer_size"));
        l_memPool_buffer_size->setStyleSheet(QLatin1String("font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        l_memPool_buffer_size->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(l_memPool_buffer_size);

        sb_memory_pool_buffer_size = new QSpinBox(widget_memory_pool_parameters);
        sb_memory_pool_buffer_size->setObjectName(QStringLiteral("sb_memory_pool_buffer_size"));
        sb_memory_pool_buffer_size->setMinimumSize(QSize(0, 25));
        sb_memory_pool_buffer_size->setStyleSheet(QLatin1String("\n"
"border-image: url(:/icons/screen5/label_2.png);\n"
"font: 75 14pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        sb_memory_pool_buffer_size->setAlignment(Qt::AlignCenter);
        sb_memory_pool_buffer_size->setMinimum(1);
        sb_memory_pool_buffer_size->setMaximum(100000);
        sb_memory_pool_buffer_size->setSingleStep(1);
        sb_memory_pool_buffer_size->setValue(1);

        verticalLayout_8->addWidget(sb_memory_pool_buffer_size);


        verticalLayout_9->addLayout(verticalLayout_8);

        pb_add_memPool = new QPushButton(widget_memory_pool_parameters);
        pb_add_memPool->setObjectName(QStringLiteral("pb_add_memPool"));
        pb_add_memPool->setEnabled(true);
        pb_add_memPool->setMinimumSize(QSize(150, 40));
        pb_add_memPool->setMaximumSize(QSize(16777215, 50));
        pb_add_memPool->setCursor(QCursor(Qt::PointingHandCursor));
        pb_add_memPool->setStyleSheet(QLatin1String("font: 63 18pt \"Segoe UI Semibold\";\n"
"color:  rgb(8, 113, 104);"));
        pb_add_memPool->setFlat(true);

        verticalLayout_9->addWidget(pb_add_memPool);

        widget_semaphore_parameters = new QWidget(widget_options_screen_native);
        widget_semaphore_parameters->setObjectName(QStringLiteral("widget_semaphore_parameters"));
        widget_semaphore_parameters->setGeometry(QRect(10, 450, 283, 271));
        widget_semaphore_parameters->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/fondo_transparente.png);"));
        verticalLayout_10 = new QVBoxLayout(widget_semaphore_parameters);
        verticalLayout_10->setSpacing(30);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_38 = new QVBoxLayout();
        verticalLayout_38->setSpacing(6);
        verticalLayout_38->setObjectName(QStringLiteral("verticalLayout_38"));
        verticalLayout_38->setSizeConstraint(QLayout::SetFixedSize);
        l_EVENT_2 = new QLabel(widget_semaphore_parameters);
        l_EVENT_2->setObjectName(QStringLiteral("l_EVENT_2"));
        l_EVENT_2->setStyleSheet(QLatin1String("font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        l_EVENT_2->setAlignment(Qt::AlignCenter);

        verticalLayout_38->addWidget(l_EVENT_2);

        le_semaphore_name = new QLineEdit(widget_semaphore_parameters);
        le_semaphore_name->setObjectName(QStringLiteral("le_semaphore_name"));
        le_semaphore_name->setMinimumSize(QSize(214, 41));
        le_semaphore_name->setStyleSheet(QLatin1String("border-image: url(:/icons/screen6/label_1.png);\n"
"font: 75 16pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));

        verticalLayout_38->addWidget(le_semaphore_name);


        verticalLayout_10->addLayout(verticalLayout_38);

        verticalLayout_46 = new QVBoxLayout();
        verticalLayout_46->setSpacing(6);
        verticalLayout_46->setObjectName(QStringLiteral("verticalLayout_46"));
        verticalLayout_46->setSizeConstraint(QLayout::SetFixedSize);
        l_EVENT_12 = new QLabel(widget_semaphore_parameters);
        l_EVENT_12->setObjectName(QStringLiteral("l_EVENT_12"));
        l_EVENT_12->setStyleSheet(QLatin1String("font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        l_EVENT_12->setAlignment(Qt::AlignCenter);

        verticalLayout_46->addWidget(l_EVENT_12);

        sb_semaphore_res_size = new QSpinBox(widget_semaphore_parameters);
        sb_semaphore_res_size->setObjectName(QStringLiteral("sb_semaphore_res_size"));
        sb_semaphore_res_size->setMinimumSize(QSize(0, 25));
        sb_semaphore_res_size->setStyleSheet(QLatin1String("\n"
"border-image: url(:/icons/screen5/label_2.png);\n"
"font: 75 14pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        sb_semaphore_res_size->setAlignment(Qt::AlignCenter);
        sb_semaphore_res_size->setMinimum(1);
        sb_semaphore_res_size->setMaximum(100000);
        sb_semaphore_res_size->setSingleStep(1);
        sb_semaphore_res_size->setValue(1);

        verticalLayout_46->addWidget(sb_semaphore_res_size);


        verticalLayout_10->addLayout(verticalLayout_46);

        pb_add_Semaphore = new QPushButton(widget_semaphore_parameters);
        pb_add_Semaphore->setObjectName(QStringLiteral("pb_add_Semaphore"));
        pb_add_Semaphore->setEnabled(true);
        pb_add_Semaphore->setMinimumSize(QSize(150, 40));
        pb_add_Semaphore->setMaximumSize(QSize(16777215, 50));
        pb_add_Semaphore->setCursor(QCursor(Qt::PointingHandCursor));
        pb_add_Semaphore->setStyleSheet(QLatin1String("font: 63 18pt \"Segoe UI Semibold\";\n"
"color:  rgb(8, 113, 104);"));
        pb_add_Semaphore->setFlat(true);

        verticalLayout_10->addWidget(pb_add_Semaphore);

        pb_add_Semaphore->raise();
        widget_mutex_parameters = new QWidget(widget_options_screen_native);
        widget_mutex_parameters->setObjectName(QStringLiteral("widget_mutex_parameters"));
        widget_mutex_parameters->setGeometry(QRect(330, 560, 234, 171));
        widget_mutex_parameters->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/fondo_transparente.png);"));
        verticalLayout_13 = new QVBoxLayout(widget_mutex_parameters);
        verticalLayout_13->setSpacing(50);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        l_EVENT_14 = new QLabel(widget_mutex_parameters);
        l_EVENT_14->setObjectName(QStringLiteral("l_EVENT_14"));
        l_EVENT_14->setStyleSheet(QLatin1String("font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        l_EVENT_14->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(l_EVENT_14);

        le_Mutex_name = new QLineEdit(widget_mutex_parameters);
        le_Mutex_name->setObjectName(QStringLiteral("le_Mutex_name"));
        le_Mutex_name->setMinimumSize(QSize(214, 41));
        le_Mutex_name->setStyleSheet(QLatin1String("border-image: url(:/icons/screen6/label_1.png);\n"
"font: 15pt \"Myriad Web\";\n"
"color:  rgb(8, 113, 104);\n"
""));

        verticalLayout_11->addWidget(le_Mutex_name);


        verticalLayout_13->addLayout(verticalLayout_11);

        pb_add_Mutex = new QPushButton(widget_mutex_parameters);
        pb_add_Mutex->setObjectName(QStringLiteral("pb_add_Mutex"));
        pb_add_Mutex->setEnabled(true);
        pb_add_Mutex->setMinimumSize(QSize(150, 40));
        pb_add_Mutex->setMaximumSize(QSize(11111111, 50));
        pb_add_Mutex->setCursor(QCursor(Qt::PointingHandCursor));
        pb_add_Mutex->setStyleSheet(QLatin1String("font: 63 18pt \"Segoe UI Semibold\";\n"
"color:  rgb(8, 113, 104);"));
        pb_add_Mutex->setFlat(true);

        verticalLayout_13->addWidget(pb_add_Mutex);

        pb_add_Mutex->raise();
        widget_messQueue_parameters = new QWidget(widget_options_screen_native);
        widget_messQueue_parameters->setObjectName(QStringLiteral("widget_messQueue_parameters"));
        widget_messQueue_parameters->setGeometry(QRect(590, 10, 283, 271));
        widget_messQueue_parameters->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/fondo_transparente.png);"));
        verticalLayout_30 = new QVBoxLayout(widget_messQueue_parameters);
        verticalLayout_30->setSpacing(30);
        verticalLayout_30->setContentsMargins(11, 11, 11, 11);
        verticalLayout_30->setObjectName(QStringLiteral("verticalLayout_30"));
        verticalLayout_43 = new QVBoxLayout();
        verticalLayout_43->setSpacing(6);
        verticalLayout_43->setObjectName(QStringLiteral("verticalLayout_43"));
        verticalLayout_43->setSizeConstraint(QLayout::SetFixedSize);
        l_EVENT_8 = new QLabel(widget_messQueue_parameters);
        l_EVENT_8->setObjectName(QStringLiteral("l_EVENT_8"));
        l_EVENT_8->setStyleSheet(QLatin1String("font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        l_EVENT_8->setAlignment(Qt::AlignCenter);

        verticalLayout_43->addWidget(l_EVENT_8);

        le_messQueue_name = new QLineEdit(widget_messQueue_parameters);
        le_messQueue_name->setObjectName(QStringLiteral("le_messQueue_name"));
        le_messQueue_name->setMinimumSize(QSize(214, 41));
        le_messQueue_name->setStyleSheet(QLatin1String("border-image: url(:/icons/screen6/label_1.png);\n"
"font: 75 16pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));

        verticalLayout_43->addWidget(le_messQueue_name);


        verticalLayout_30->addLayout(verticalLayout_43);

        verticalLayout_48 = new QVBoxLayout();
        verticalLayout_48->setSpacing(6);
        verticalLayout_48->setObjectName(QStringLiteral("verticalLayout_48"));
        verticalLayout_48->setSizeConstraint(QLayout::SetFixedSize);
        l_EVENT_15 = new QLabel(widget_messQueue_parameters);
        l_EVENT_15->setObjectName(QStringLiteral("l_EVENT_15"));
        l_EVENT_15->setStyleSheet(QLatin1String("font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        l_EVENT_15->setAlignment(Qt::AlignCenter);

        verticalLayout_48->addWidget(l_EVENT_15);

        sb_messQueue_size = new QSpinBox(widget_messQueue_parameters);
        sb_messQueue_size->setObjectName(QStringLiteral("sb_messQueue_size"));
        sb_messQueue_size->setMinimumSize(QSize(0, 25));
        sb_messQueue_size->setStyleSheet(QLatin1String("\n"
"border-image: url(:/icons/screen5/label_2.png);\n"
"font: 75 14pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        sb_messQueue_size->setAlignment(Qt::AlignCenter);
        sb_messQueue_size->setMinimum(1);
        sb_messQueue_size->setMaximum(100000);
        sb_messQueue_size->setSingleStep(1);
        sb_messQueue_size->setValue(1);

        verticalLayout_48->addWidget(sb_messQueue_size);


        verticalLayout_30->addLayout(verticalLayout_48);

        pb_add_messQueue = new QPushButton(widget_messQueue_parameters);
        pb_add_messQueue->setObjectName(QStringLiteral("pb_add_messQueue"));
        pb_add_messQueue->setEnabled(true);
        pb_add_messQueue->setMinimumSize(QSize(150, 40));
        pb_add_messQueue->setMaximumSize(QSize(16777215, 50));
        pb_add_messQueue->setCursor(QCursor(Qt::PointingHandCursor));
        pb_add_messQueue->setStyleSheet(QLatin1String("font: 63 18pt \"Segoe UI Semibold\";\n"
"color:  rgb(8, 113, 104);"));
        pb_add_messQueue->setFlat(true);

        verticalLayout_30->addWidget(pb_add_messQueue);

        pb_add_messQueue->raise();
        widget_serialPort_parameters = new QWidget(widget_options_screen_native);
        widget_serialPort_parameters->setObjectName(QStringLiteral("widget_serialPort_parameters"));
        widget_serialPort_parameters->setGeometry(QRect(980, 10, 283, 271));
        widget_serialPort_parameters->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/fondo_transparente.png);"));
        verticalLayout_16 = new QVBoxLayout(widget_serialPort_parameters);
        verticalLayout_16->setSpacing(30);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_49 = new QVBoxLayout();
        verticalLayout_49->setSpacing(6);
        verticalLayout_49->setObjectName(QStringLiteral("verticalLayout_49"));
        verticalLayout_49->setSizeConstraint(QLayout::SetFixedSize);
        l_EVENT_16 = new QLabel(widget_serialPort_parameters);
        l_EVENT_16->setObjectName(QStringLiteral("l_EVENT_16"));
        l_EVENT_16->setStyleSheet(QLatin1String("font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        l_EVENT_16->setAlignment(Qt::AlignCenter);

        verticalLayout_49->addWidget(l_EVENT_16);

        le_serialport_name = new QLineEdit(widget_serialPort_parameters);
        le_serialport_name->setObjectName(QStringLiteral("le_serialport_name"));
        le_serialport_name->setMinimumSize(QSize(214, 41));
        le_serialport_name->setStyleSheet(QLatin1String("border-image: url(:/icons/screen6/label_1.png);\n"
"font: 75 16pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));

        verticalLayout_49->addWidget(le_serialport_name);


        verticalLayout_16->addLayout(verticalLayout_49);

        verticalLayout_50 = new QVBoxLayout();
        verticalLayout_50->setSpacing(6);
        verticalLayout_50->setObjectName(QStringLiteral("verticalLayout_50"));
        verticalLayout_50->setSizeConstraint(QLayout::SetFixedSize);
        l_EVENT_17 = new QLabel(widget_serialPort_parameters);
        l_EVENT_17->setObjectName(QStringLiteral("l_EVENT_17"));
        l_EVENT_17->setStyleSheet(QLatin1String("font: 75 18pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        l_EVENT_17->setAlignment(Qt::AlignCenter);

        verticalLayout_50->addWidget(l_EVENT_17);

        sb_serialport_usart_number = new QSpinBox(widget_serialPort_parameters);
        sb_serialport_usart_number->setObjectName(QStringLiteral("sb_serialport_usart_number"));
        sb_serialport_usart_number->setMinimumSize(QSize(0, 25));
        sb_serialport_usart_number->setStyleSheet(QLatin1String("\n"
"border-image: url(:/icons/screen5/label_2.png);\n"
"font: 75 14pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        sb_serialport_usart_number->setAlignment(Qt::AlignCenter);
        sb_serialport_usart_number->setMinimum(1);
        sb_serialport_usart_number->setMaximum(100000);
        sb_serialport_usart_number->setSingleStep(1);
        sb_serialport_usart_number->setValue(1);

        verticalLayout_50->addWidget(sb_serialport_usart_number);


        verticalLayout_16->addLayout(verticalLayout_50);

        pb_add_SerialPort = new QPushButton(widget_serialPort_parameters);
        pb_add_SerialPort->setObjectName(QStringLiteral("pb_add_SerialPort"));
        pb_add_SerialPort->setEnabled(true);
        pb_add_SerialPort->setMinimumSize(QSize(150, 40));
        pb_add_SerialPort->setMaximumSize(QSize(16777215, 50));
        pb_add_SerialPort->setCursor(QCursor(Qt::PointingHandCursor));
        pb_add_SerialPort->setStyleSheet(QLatin1String("font: 63 18pt \"Segoe UI Semibold\";\n"
"color:  rgb(8, 113, 104);"));
        pb_add_SerialPort->setFlat(true);

        verticalLayout_16->addWidget(pb_add_SerialPort);

        pb_add_SerialPort->raise();
        pb_configure_thread_in_class->raise();
        pb_configure_Main_thread->raise();
        pb_configure_in_Main_thread->raise();
        pb_configure_state_machine->raise();
        widget_options_thread_options->raise();
        widget_timer_parameters->raise();
        widget_mailBox_parameters->raise();
        widget_memory_pool_parameters->raise();
        widget_semaphore_parameters->raise();
        widget_mutex_parameters->raise();
        widget_configure_in_main_thread->raise();
        widget_messQueue_parameters->raise();
        widget_serialPort_parameters->raise();
        widget_state_machine_screen = new QWidget(centralWidget);
        widget_state_machine_screen->setObjectName(QStringLiteral("widget_state_machine_screen"));
        widget_state_machine_screen->setGeometry(QRect(3930, 0, 1366, 768));
        widget_state_machine_screen->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen1/background.png);"));
        pb_load_from_Thread = new QPushButton(widget_state_machine_screen);
        pb_load_from_Thread->setObjectName(QStringLiteral("pb_load_from_Thread"));
        pb_load_from_Thread->setEnabled(true);
        pb_load_from_Thread->setGeometry(QRect(30, 328, 294, 46));
        pb_load_from_Thread->setMinimumSize(QSize(150, 40));
        pb_load_from_Thread->setMaximumSize(QSize(16777215, 16777215));
        pb_load_from_Thread->setCursor(QCursor(Qt::PointingHandCursor));
        pb_load_from_Thread->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/Load from Main Thread_botom.png);"));
        pb_load_from_Thread->setFlat(true);
        pb_save_state_machine = new QPushButton(widget_state_machine_screen);
        pb_save_state_machine->setObjectName(QStringLiteral("pb_save_state_machine"));
        pb_save_state_machine->setEnabled(true);
        pb_save_state_machine->setGeometry(QRect(30, 450, 294, 46));
        pb_save_state_machine->setMinimumSize(QSize(150, 40));
        pb_save_state_machine->setMaximumSize(QSize(1111111, 16777215));
        pb_save_state_machine->setCursor(QCursor(Qt::PointingHandCursor));
        pb_save_state_machine->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/Save State Machine_botom.png);"));
        pb_save_state_machine->setFlat(true);
        pb_load_state_machine = new QPushButton(widget_state_machine_screen);
        pb_load_state_machine->setObjectName(QStringLiteral("pb_load_state_machine"));
        pb_load_state_machine->setEnabled(true);
        pb_load_state_machine->setGeometry(QRect(30, 390, 294, 46));
        pb_load_state_machine->setMinimumSize(QSize(150, 40));
        pb_load_state_machine->setMaximumSize(QSize(16777215, 16777215));
        pb_load_state_machine->setCursor(QCursor(Qt::PointingHandCursor));
        pb_load_state_machine->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/Load from State Machine_botom.png);"));
        pb_load_state_machine->setFlat(true);
        widget_layout_state_machine = new QWidget(widget_state_machine_screen);
        widget_layout_state_machine->setObjectName(QStringLiteral("widget_layout_state_machine"));
        widget_layout_state_machine->setGeometry(QRect(340, 270, 745, 290));
        widget_layout_state_machine->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/window.png);"));
        verticalLayout = new QVBoxLayout(widget_layout_state_machine);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget_states = new QWidget(widget_layout_state_machine);
        widget_states->setObjectName(QStringLiteral("widget_states"));
        widget_states->setEnabled(true);
        widget_states->setMinimumSize(QSize(724, 270));
        widget_states->setMaximumSize(QSize(16777215, 16777215));
        widget_states->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/fondo_transparente.png);"));
        verticalLayout_12 = new QVBoxLayout(widget_states);
        verticalLayout_12->setSpacing(1);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        widget_state_info = new QWidget(widget_states);
        widget_state_info->setObjectName(QStringLiteral("widget_state_info"));
        verticalLayout_22 = new QVBoxLayout(widget_state_info);
        verticalLayout_22->setSpacing(0);
        verticalLayout_22->setContentsMargins(11, 11, 11, 11);
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        verticalLayout_22->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(70);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setSizeConstraint(QLayout::SetFixedSize);
        widget_super_initial_default_state = new QWidget(widget_state_info);
        widget_super_initial_default_state->setObjectName(QStringLiteral("widget_super_initial_default_state"));
        verticalLayout_20 = new QVBoxLayout(widget_super_initial_default_state);
        verticalLayout_20->setSpacing(15);
        verticalLayout_20->setContentsMargins(11, 11, 11, 11);
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        verticalLayout_20->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        verticalLayout_17->setSizeConstraint(QLayout::SetFixedSize);
        label_2 = new QLabel(widget_super_initial_default_state);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 12));
        label_2->setStyleSheet(QLatin1String("font: 75 14pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));

        verticalLayout_17->addWidget(label_2);

        le_super_state_name = new QLineEdit(widget_super_initial_default_state);
        le_super_state_name->setObjectName(QStringLiteral("le_super_state_name"));
        le_super_state_name->setMaximumSize(QSize(120, 120));
        le_super_state_name->setStyleSheet(QLatin1String("border-image: url(:/icons/screen2/label_1.png);\n"
"font: 11pt \"Segoe UI\";\n"
"color:  rgb(8, 113, 104);"));

        verticalLayout_17->addWidget(le_super_state_name);


        verticalLayout_20->addLayout(verticalLayout_17);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        verticalLayout_18->setSizeConstraint(QLayout::SetFixedSize);
        label_3 = new QLabel(widget_super_initial_default_state);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 12));
        label_3->setStyleSheet(QLatin1String("font: 75 14pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));

        verticalLayout_18->addWidget(label_3);

        le_initial_state_name = new QLineEdit(widget_super_initial_default_state);
        le_initial_state_name->setObjectName(QStringLiteral("le_initial_state_name"));
        le_initial_state_name->setMaximumSize(QSize(120, 1200));
        le_initial_state_name->setStyleSheet(QLatin1String("font: 11pt \"Segoe UI\";\n"
"color:  rgb(8, 113, 104);\n"
"border-image: url(:/icons/screen2/label_1.png);"));

        verticalLayout_18->addWidget(le_initial_state_name);


        verticalLayout_20->addLayout(verticalLayout_18);


        horizontalLayout_8->addWidget(widget_super_initial_default_state);

        widget_state_name_default_event = new QWidget(widget_state_info);
        widget_state_name_default_event->setObjectName(QStringLiteral("widget_state_name_default_event"));
        verticalLayout_19 = new QVBoxLayout(widget_state_name_default_event);
        verticalLayout_19->setSpacing(6);
        verticalLayout_19->setContentsMargins(11, 11, 11, 11);
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        verticalLayout_19->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(widget_state_name_default_event);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 19));
        label->setStyleSheet(QLatin1String("font: 75 14pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));

        verticalLayout_2->addWidget(label);

        le_current_state_name = new QLineEdit(widget_state_name_default_event);
        le_current_state_name->setObjectName(QStringLiteral("le_current_state_name"));
        le_current_state_name->setMaximumSize(QSize(120, 34));
        le_current_state_name->setStyleSheet(QLatin1String("border-image: url(:/icons/screen2/label_1.png);\n"
"font: 11pt \"Segoe UI\";\n"
"color:  rgb(8, 113, 104);"));

        verticalLayout_2->addWidget(le_current_state_name);


        horizontalLayout_4->addLayout(verticalLayout_2);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);


        verticalLayout_19->addLayout(horizontalLayout_4);

        label_4 = new QLabel(widget_state_name_default_event);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(0, 12));
        label_4->setStyleSheet(QLatin1String("font: 75 14pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_19->addWidget(label_4);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(1);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_16->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        verticalLayout_15->setSizeConstraint(QLayout::SetFixedSize);
        label_5 = new QLabel(widget_state_name_default_event);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(0, 12));
        label_5->setStyleSheet(QLatin1String("font: 75 14pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_15->addWidget(label_5);

        le_default_state_name = new QLineEdit(widget_state_name_default_event);
        le_default_state_name->setObjectName(QStringLiteral("le_default_state_name"));
        le_default_state_name->setMaximumSize(QSize(100, 100));
        le_default_state_name->setStyleSheet(QLatin1String("font: 11pt \"Segoe UI\";\n"
"color:  rgb(8, 113, 104);\n"
"border-image: url(:/icons/screen2/label_1.png);"));

        verticalLayout_15->addWidget(le_default_state_name);


        horizontalLayout_16->addLayout(verticalLayout_15);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_14->setSizeConstraint(QLayout::SetFixedSize);
        label_6 = new QLabel(widget_state_name_default_event);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(0, 12));
        label_6->setStyleSheet(QLatin1String("font: 75 14pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_14->addWidget(label_6);

        le_default_action_name = new QLineEdit(widget_state_name_default_event);
        le_default_action_name->setObjectName(QStringLiteral("le_default_action_name"));
        le_default_action_name->setMaximumSize(QSize(100, 100));
        le_default_action_name->setStyleSheet(QLatin1String("font: 11pt \"Segoe UI\";\n"
"color:  rgb(8, 113, 104);\n"
"border-image: url(:/icons/screen2/label_1.png);"));

        verticalLayout_14->addWidget(le_default_action_name);


        horizontalLayout_16->addLayout(verticalLayout_14);


        verticalLayout_19->addLayout(horizontalLayout_16);


        horizontalLayout_8->addWidget(widget_state_name_default_event);

        widget_events = new QWidget(widget_state_info);
        widget_events->setObjectName(QStringLiteral("widget_events"));
        widget_events->setMaximumSize(QSize(16777215, 170));
        horizontalLayout_12 = new QHBoxLayout(widget_events);
        horizontalLayout_12->setSpacing(1);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setSizeConstraint(QLayout::SetFixedSize);
        tableView_events = new QTableView(widget_events);
        tableView_events->setObjectName(QStringLiteral("tableView_events"));
        tableView_events->setMinimumSize(QSize(654, 150));
        tableView_events->setMaximumSize(QSize(16777215, 16777215));
        tableView_events->setStyleSheet(QLatin1String("font: 11pt \"Segoe UI\";\n"
"background-image: url(:/icons/screen8/fondo_blanco.png);\n"
"color:  rgb(8, 113, 104);"));
        tableView_events->setFrameShape(QFrame::Box);
        tableView_events->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableView_events->setTextElideMode(Qt::ElideMiddle);
        tableView_events->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tableView_events->setSortingEnabled(true);
        tableView_events->horizontalHeader()->setDefaultSectionSize(205);
        tableView_events->horizontalHeader()->setMinimumSectionSize(100);

        horizontalLayout_12->addWidget(tableView_events);


        horizontalLayout_8->addWidget(widget_events);

        widget_state_name_entry_exit_actions = new QWidget(widget_state_info);
        widget_state_name_entry_exit_actions->setObjectName(QStringLiteral("widget_state_name_entry_exit_actions"));
        verticalLayout_21 = new QVBoxLayout(widget_state_name_entry_exit_actions);
        verticalLayout_21->setSpacing(15);
        verticalLayout_21->setContentsMargins(11, 11, 11, 11);
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        verticalLayout_21->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setSpacing(8);
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        verticalLayout_23->setSizeConstraint(QLayout::SetFixedSize);
        l_Entry_Action = new QLabel(widget_state_name_entry_exit_actions);
        l_Entry_Action->setObjectName(QStringLiteral("l_Entry_Action"));
        l_Entry_Action->setMinimumSize(QSize(0, 20));
        l_Entry_Action->setStyleSheet(QLatin1String("font: 75 14pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));

        verticalLayout_23->addWidget(l_Entry_Action);

        le_entry_action = new QLineEdit(widget_state_name_entry_exit_actions);
        le_entry_action->setObjectName(QStringLiteral("le_entry_action"));
        le_entry_action->setMaximumSize(QSize(120, 120));
        le_entry_action->setStyleSheet(QLatin1String("font: 11pt \"Segoe UI\";\n"
"color:  rgb(8, 113, 104);\n"
"border-image: url(:/icons/screen2/label_1.png);"));

        verticalLayout_23->addWidget(le_entry_action);

        verticalLayout_24 = new QVBoxLayout();
        verticalLayout_24->setSpacing(6);
        verticalLayout_24->setObjectName(QStringLiteral("verticalLayout_24"));
        verticalLayout_24->setSizeConstraint(QLayout::SetFixedSize);
        l_Exit_Action = new QLabel(widget_state_name_entry_exit_actions);
        l_Exit_Action->setObjectName(QStringLiteral("l_Exit_Action"));
        l_Exit_Action->setMinimumSize(QSize(0, 20));
        l_Exit_Action->setStyleSheet(QLatin1String("font: 75 14pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));

        verticalLayout_24->addWidget(l_Exit_Action);

        le_exit_action = new QLineEdit(widget_state_name_entry_exit_actions);
        le_exit_action->setObjectName(QStringLiteral("le_exit_action"));
        le_exit_action->setMaximumSize(QSize(120, 107));
        le_exit_action->setStyleSheet(QLatin1String("font: 11pt \"Segoe UI\";\n"
"color:  rgb(8, 113, 104);\n"
"border-image: url(:/icons/screen2/label_1.png);"));

        verticalLayout_24->addWidget(le_exit_action);


        verticalLayout_23->addLayout(verticalLayout_24);


        verticalLayout_21->addLayout(verticalLayout_23);


        horizontalLayout_8->addWidget(widget_state_name_entry_exit_actions);


        verticalLayout_22->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);

        pb_change_to_event = new QPushButton(widget_state_info);
        pb_change_to_event->setObjectName(QStringLiteral("pb_change_to_event"));
        pb_change_to_event->setMinimumSize(QSize(73, 20));
        pb_change_to_event->setCursor(QCursor(Qt::PointingHandCursor));
        pb_change_to_event->setStyleSheet(QLatin1String("font: 75 14pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_change_to_event->setFlat(true);

        horizontalLayout_9->addWidget(pb_change_to_event);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        pb_ok = new QPushButton(widget_state_info);
        pb_ok->setObjectName(QStringLiteral("pb_ok"));
        pb_ok->setCursor(QCursor(Qt::PointingHandCursor));
        pb_ok->setStyleSheet(QLatin1String("font: 75 14pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_ok->setFlat(true);

        horizontalLayout_9->addWidget(pb_ok);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);


        verticalLayout_22->addLayout(horizontalLayout_9);


        verticalLayout_12->addWidget(widget_state_info);


        verticalLayout->addWidget(widget_states);

        pb_generate_state_machine = new QPushButton(widget_state_machine_screen);
        pb_generate_state_machine->setObjectName(QStringLiteral("pb_generate_state_machine"));
        pb_generate_state_machine->setEnabled(true);
        pb_generate_state_machine->setGeometry(QRect(900, 580, 97, 29));
        pb_generate_state_machine->setMinimumSize(QSize(0, 0));
        pb_generate_state_machine->setMaximumSize(QSize(133, 16777215));
        pb_generate_state_machine->setCursor(QCursor(Qt::PointingHandCursor));
        pb_generate_state_machine->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/generate_botom.png);"));
        pb_generate_state_machine->setFlat(true);
        le_state_name = new QLineEdit(widget_state_machine_screen);
        le_state_name->setObjectName(QStringLiteral("le_state_name"));
        le_state_name->setGeometry(QRect(600, 580, 232, 34));
        le_state_name->setMinimumSize(QSize(0, 0));
        le_state_name->setMaximumSize(QSize(16777215, 16777215));
        le_state_name->setStyleSheet(QLatin1String("border-image: url(:/icons/screen8/label.png);\n"
"font: 15pt \"Myriad Web\";\n"
"color:  rgb(8, 113, 104);\n"
""));
        l_name_current_state = new QLabel(widget_state_machine_screen);
        l_name_current_state->setObjectName(QStringLiteral("l_name_current_state"));
        l_name_current_state->setGeometry(QRect(720, 210, 171, 41));
        l_name_current_state->setMinimumSize(QSize(80, 0));
        l_name_current_state->setMaximumSize(QSize(16777215, 16777215));
        l_name_current_state->setStyleSheet(QLatin1String("font: 63 16pt \"Segoe UI Semibold\";\n"
"color:  rgb(8, 113, 104);\n"
"\n"
"background-image: url(:/icons/screen8/fondo_blanco.png);"));
        l_state_parent_tag = new QLabel(widget_state_machine_screen);
        l_state_parent_tag->setObjectName(QStringLiteral("l_state_parent_tag"));
        l_state_parent_tag->setGeometry(QRect(580, 210, 131, 40));
        l_state_parent_tag->setMaximumSize(QSize(16777215, 40));
        l_state_parent_tag->setStyleSheet(QLatin1String("background-image: url(:/icons/screen8/fondo_blanco.png);\n"
"font: 63 16pt \"Segoe UI Semibold\";\n"
"color:  rgb(8, 113, 104);\n"
"\n"
""));
        pb_back = new QPushButton(widget_state_machine_screen);
        pb_back->setObjectName(QStringLiteral("pb_back"));
        pb_back->setGeometry(QRect(340, 220, 28, 25));
        pb_back->setMaximumSize(QSize(16777215, 30));
        pb_back->setCursor(QCursor(Qt::PointingHandCursor));
        pb_back->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/back_icon_botom.png);"));
        pb_back->setFlat(true);
        pb_search_state = new QPushButton(widget_state_machine_screen);
        pb_search_state->setObjectName(QStringLiteral("pb_search_state"));
        pb_search_state->setGeometry(QRect(1040, 220, 27, 28));
        pb_search_state->setMinimumSize(QSize(0, 20));
        pb_search_state->setMaximumSize(QSize(16777215, 30));
        pb_search_state->setCursor(QCursor(Qt::PointingHandCursor));
        pb_search_state->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/search_icon_botom.png);"));
        pb_search_state->setFlat(true);
        le_state_to_search = new QLineEdit(widget_state_machine_screen);
        le_state_to_search->setObjectName(QStringLiteral("le_state_to_search"));
        le_state_to_search->setGeometry(QRect(860, 210, 171, 41));
        le_state_to_search->setMinimumSize(QSize(135, 20));
        le_state_to_search->setMaximumSize(QSize(16777215, 1111111));
        le_state_to_search->setStyleSheet(QLatin1String("border-image: url(:/icons/screen8/label.png);\n"
"font: 63 16pt \"Segoe UI Semibold\";\n"
"color:  rgb(8, 113, 104);\n"
""));
        tw_state_machine = new QTreeWidget(widget_state_machine_screen);
        tw_state_machine->setObjectName(QStringLiteral("tw_state_machine"));
        tw_state_machine->setGeometry(QRect(1100, 270, 219, 291));
        tw_state_machine->setMaximumSize(QSize(16777215, 16777215));
        tw_state_machine->setStyleSheet(QLatin1String("font: 75 13pt \"Segoe UI\";\n"
"background-image: url(:/icons/screen8/state machine_box.png);\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_back_from_state_machine = new QPushButton(widget_state_machine_screen);
        pb_back_from_state_machine->setObjectName(QStringLiteral("pb_back_from_state_machine"));
        pb_back_from_state_machine->setEnabled(true);
        pb_back_from_state_machine->setGeometry(QRect(150, 280, 51, 31));
        pb_back_from_state_machine->setMinimumSize(QSize(0, 0));
        pb_back_from_state_machine->setMaximumSize(QSize(1111111, 16777215));
        pb_back_from_state_machine->setCursor(QCursor(Qt::PointingHandCursor));
        pb_back_from_state_machine->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/back_botom.png);"));
        pb_back_from_state_machine->setFlat(true);
        pb_add_state = new QPushButton(widget_state_machine_screen);
        pb_add_state->setObjectName(QStringLiteral("pb_add_state"));
        pb_add_state->setGeometry(QRect(430, 580, 102, 29));
        pb_add_state->setMinimumSize(QSize(0, 0));
        pb_add_state->setMaximumSize(QSize(133, 16777215));
        pb_add_state->setCursor(QCursor(Qt::PointingHandCursor));
        pb_add_state->setStyleSheet(QLatin1String("font: 75 18pt \"Myriad Web\";\n"
"color:  rgb(8, 113, 104);\n"
"background-image: url(:/icons/screen8/add_state_button.png);"));
        pb_add_state->setFlat(true);
        widget_on_state_options = new QWidget(widget_state_machine_screen);
        widget_on_state_options->setObjectName(QStringLiteral("widget_on_state_options"));
        widget_on_state_options->setGeometry(QRect(110, 550, 131, 191));
        widget_on_state_options->setCursor(QCursor(Qt::ArrowCursor));
        widget_on_state_options->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/fondo_blanco.png);"));
        verticalLayout_25 = new QVBoxLayout(widget_on_state_options);
        verticalLayout_25->setSpacing(6);
        verticalLayout_25->setContentsMargins(11, 11, 11, 11);
        verticalLayout_25->setObjectName(QStringLiteral("verticalLayout_25"));
        verticalLayout_25->setSizeConstraint(QLayout::SetFixedSize);
        pb_open_state = new QPushButton(widget_on_state_options);
        pb_open_state->setObjectName(QStringLiteral("pb_open_state"));
        pb_open_state->setCursor(QCursor(Qt::PointingHandCursor));
        pb_open_state->setStyleSheet(QLatin1String("font: 75 12pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_open_state->setFlat(true);

        verticalLayout_25->addWidget(pb_open_state);

        pb_set_as_initial = new QPushButton(widget_on_state_options);
        pb_set_as_initial->setObjectName(QStringLiteral("pb_set_as_initial"));
        pb_set_as_initial->setCursor(QCursor(Qt::PointingHandCursor));
        pb_set_as_initial->setStyleSheet(QLatin1String("font: 75 12pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_set_as_initial->setFlat(true);

        verticalLayout_25->addWidget(pb_set_as_initial);

        pb_configure_state = new QPushButton(widget_on_state_options);
        pb_configure_state->setObjectName(QStringLiteral("pb_configure_state"));
        pb_configure_state->setCursor(QCursor(Qt::PointingHandCursor));
        pb_configure_state->setStyleSheet(QLatin1String("font: 75 12pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_configure_state->setFlat(true);

        verticalLayout_25->addWidget(pb_configure_state);

        pb_add_sub_sate = new QPushButton(widget_on_state_options);
        pb_add_sub_sate->setObjectName(QStringLiteral("pb_add_sub_sate"));
        pb_add_sub_sate->setCursor(QCursor(Qt::PointingHandCursor));
        pb_add_sub_sate->setStyleSheet(QLatin1String("font: 75 12pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_add_sub_sate->setFlat(true);

        verticalLayout_25->addWidget(pb_add_sub_sate);

        pb_eliminate_state = new QPushButton(widget_on_state_options);
        pb_eliminate_state->setObjectName(QStringLiteral("pb_eliminate_state"));
        pb_eliminate_state->setCursor(QCursor(Qt::PointingHandCursor));
        pb_eliminate_state->setStyleSheet(QLatin1String("font: 75 12pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_eliminate_state->setFlat(true);

        verticalLayout_25->addWidget(pb_eliminate_state);

        pb_cancel_state_options = new QPushButton(widget_on_state_options);
        pb_cancel_state_options->setObjectName(QStringLiteral("pb_cancel_state_options"));
        pb_cancel_state_options->setCursor(QCursor(Qt::PointingHandCursor));
        pb_cancel_state_options->setStyleSheet(QLatin1String("font: 75 12pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_cancel_state_options->setFlat(true);

        verticalLayout_25->addWidget(pb_cancel_state_options);

        pb_warning_state_machine = new QPushButton(widget_state_machine_screen);
        pb_warning_state_machine->setObjectName(QStringLiteral("pb_warning_state_machine"));
        pb_warning_state_machine->setGeometry(QRect(450, 640, 46, 42));
        pb_warning_state_machine->setStyleSheet(QLatin1String("background-image: url(:/icons/screen8/warning.png);\n"
"font: 75 12pt \"Segoe UI\";"));
        pb_warning_state_machine->setFlat(true);
        widget_add_delete_event = new QWidget(widget_state_machine_screen);
        widget_add_delete_event->setObjectName(QStringLiteral("widget_add_delete_event"));
        widget_add_delete_event->setGeometry(QRect(280, 610, 121, 121));
        widget_add_delete_event->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/fondo_blanco.png);"));
        verticalLayout_35 = new QVBoxLayout(widget_add_delete_event);
        verticalLayout_35->setSpacing(6);
        verticalLayout_35->setContentsMargins(11, 11, 11, 11);
        verticalLayout_35->setObjectName(QStringLiteral("verticalLayout_35"));
        verticalLayout_35->setSizeConstraint(QLayout::SetFixedSize);
        pb_add_event_action = new QPushButton(widget_add_delete_event);
        pb_add_event_action->setObjectName(QStringLiteral("pb_add_event_action"));
        pb_add_event_action->setCursor(QCursor(Qt::PointingHandCursor));
        pb_add_event_action->setStyleSheet(QLatin1String("font: 75 14pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_add_event_action->setFlat(true);

        verticalLayout_35->addWidget(pb_add_event_action);

        pb_delete_event_action = new QPushButton(widget_add_delete_event);
        pb_delete_event_action->setObjectName(QStringLiteral("pb_delete_event_action"));
        pb_delete_event_action->setCursor(QCursor(Qt::PointingHandCursor));
        pb_delete_event_action->setStyleSheet(QLatin1String("font: 75 14pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_delete_event_action->setFlat(true);

        verticalLayout_35->addWidget(pb_delete_event_action);

        pb_cancel_add_event_2 = new QPushButton(widget_add_delete_event);
        pb_cancel_add_event_2->setObjectName(QStringLiteral("pb_cancel_add_event_2"));
        pb_cancel_add_event_2->setCursor(QCursor(Qt::PointingHandCursor));
        pb_cancel_add_event_2->setStyleSheet(QLatin1String("font: 75 14pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_cancel_add_event_2->setFlat(true);

        verticalLayout_35->addWidget(pb_cancel_add_event_2);

        pb_Simulate_HSM = new QPushButton(widget_state_machine_screen);
        pb_Simulate_HSM->setObjectName(QStringLiteral("pb_Simulate_HSM"));
        pb_Simulate_HSM->setGeometry(QRect(130, 520, 102, 29));
        pb_Simulate_HSM->setMinimumSize(QSize(0, 0));
        pb_Simulate_HSM->setMaximumSize(QSize(133, 16777215));
        pb_Simulate_HSM->setCursor(QCursor(Qt::PointingHandCursor));
        pb_Simulate_HSM->setStyleSheet(QLatin1String("font: 75 18pt \"Myriad Web\";\n"
"background-image: url(:/icons/screen8/fondo_transparente.png);\n"
"color:  rgb(8, 113, 104);\n"
""));
        pb_Simulate_HSM->setFlat(true);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(2370, 100, 147, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pb_acept_main_thread = new QPushButton(layoutWidget);
        pb_acept_main_thread->setObjectName(QStringLiteral("pb_acept_main_thread"));
        pb_acept_main_thread->setMinimumSize(QSize(53, 28));
        pb_acept_main_thread->setMaximumSize(QSize(53, 28));
        pb_acept_main_thread->setCursor(QCursor(Qt::PointingHandCursor));
        pb_acept_main_thread->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/acept_botom.png);"));
        pb_acept_main_thread->setFlat(true);

        horizontalLayout->addWidget(pb_acept_main_thread);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        widget_wait = new QWidget(centralWidget);
        widget_wait->setObjectName(QStringLiteral("widget_wait"));
        widget_wait->setGeometry(QRect(2370, 160, 144, 31));
        horizontalLayout_15 = new QHBoxLayout(widget_wait);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_15->setSizeConstraint(QLayout::SetFixedSize);
        label_loading = new QLabel(widget_wait);
        label_loading->setObjectName(QStringLiteral("label_loading"));
        label_loading->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color:  rgb(21, 172, 112);"));
        label_loading->setAlignment(Qt::AlignCenter);

        horizontalLayout_15->addWidget(label_loading);

        widget_win_buttons = new QWidget(centralWidget);
        widget_win_buttons->setObjectName(QStringLiteral("widget_win_buttons"));
        widget_win_buttons->setGeometry(QRect(0, 0, 1366, 180));
        pb_close_window = new QPushButton(widget_win_buttons);
        pb_close_window->setObjectName(QStringLiteral("pb_close_window"));
        pb_close_window->setGeometry(QRect(1280, 20, 51, 40));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pb_close_window->sizePolicy().hasHeightForWidth());
        pb_close_window->setSizePolicy(sizePolicy2);
        pb_close_window->setMinimumSize(QSize(29, 19));
        pb_close_window->setMaximumSize(QSize(67, 40));
        pb_close_window->setCursor(QCursor(Qt::PointingHandCursor));
        pb_close_window->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/screen8/quit_botom.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_close_window->setIcon(icon1);
        pb_close_window->setIconSize(QSize(40, 40));
        pb_close_window->setFlat(true);
        pb_max_window = new QPushButton(widget_win_buttons);
        pb_max_window->setObjectName(QStringLiteral("pb_max_window"));
        pb_max_window->setGeometry(QRect(1210, 21, 51, 40));
        sizePolicy2.setHeightForWidth(pb_max_window->sizePolicy().hasHeightForWidth());
        pb_max_window->setSizePolicy(sizePolicy2);
        pb_max_window->setMinimumSize(QSize(29, 19));
        pb_max_window->setMaximumSize(QSize(67, 40));
        pb_max_window->setCursor(QCursor(Qt::PointingHandCursor));
        pb_max_window->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/screen8/max_botom.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_max_window->setIcon(icon2);
        pb_max_window->setIconSize(QSize(40, 40));
        pb_max_window->setFlat(true);
        pushButton_Generate_tag = new QPushButton(widget_win_buttons);
        pushButton_Generate_tag->setObjectName(QStringLiteral("pushButton_Generate_tag"));
        pushButton_Generate_tag->setGeometry(QRect(710, 122, 91, 24));
        sizePolicy2.setHeightForWidth(pushButton_Generate_tag->sizePolicy().hasHeightForWidth());
        pushButton_Generate_tag->setSizePolicy(sizePolicy2);
        pushButton_Generate_tag->setMinimumSize(QSize(0, 0));
        pushButton_Generate_tag->setMaximumSize(QSize(104, 25));
        pushButton_Generate_tag->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Generate_tag->setStyleSheet(QLatin1String("background-image: url(:/icons/screen1/generate_botom_off.png);\n"
""));
        pushButton_Generate_tag->setFlat(true);
        pb_min_window_ = new QPushButton(widget_win_buttons);
        pb_min_window_->setObjectName(QStringLiteral("pb_min_window_"));
        pb_min_window_->setGeometry(QRect(1140, 21, 51, 40));
        sizePolicy2.setHeightForWidth(pb_min_window_->sizePolicy().hasHeightForWidth());
        pb_min_window_->setSizePolicy(sizePolicy2);
        pb_min_window_->setMinimumSize(QSize(29, 19));
        pb_min_window_->setMaximumSize(QSize(67, 40));
        pb_min_window_->setCursor(QCursor(Qt::PointingHandCursor));
        pb_min_window_->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/screen8/min_botom.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_min_window_->setIcon(icon3);
        pb_min_window_->setIconSize(QSize(40, 40));
        pb_min_window_->setFlat(true);
        pushButton_Help_tag = new QPushButton(widget_win_buttons);
        pushButton_Help_tag->setObjectName(QStringLiteral("pushButton_Help_tag"));
        pushButton_Help_tag->setGeometry(QRect(1060, 122, 47, 25));
        sizePolicy2.setHeightForWidth(pushButton_Help_tag->sizePolicy().hasHeightForWidth());
        pushButton_Help_tag->setSizePolicy(sizePolicy2);
        pushButton_Help_tag->setMinimumSize(QSize(29, 19));
        pushButton_Help_tag->setMaximumSize(QSize(67, 25));
        pushButton_Help_tag->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Help_tag->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen1/help_botom_off.png);"));
        pushButton_Help_tag->setFlat(true);
        pushButton_Options_tag = new QPushButton(widget_win_buttons);
        pushButton_Options_tag->setObjectName(QStringLiteral("pushButton_Options_tag"));
        pushButton_Options_tag->setGeometry(QRect(900, 122, 85, 25));
        pushButton_Options_tag->setMinimumSize(QSize(49, 19));
        pushButton_Options_tag->setMaximumSize(QSize(103, 25));
        pushButton_Options_tag->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Options_tag->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen1/options_botom_off.png);"));
        pushButton_Options_tag->setFlat(true);
        label_bar_background = new QLabel(widget_win_buttons);
        label_bar_background->setObjectName(QStringLiteral("label_bar_background"));
        label_bar_background->setGeometry(QRect(328, 102, 251, 51));
        label_bar_background->setMinimumSize(QSize(0, 0));
        label_bar_background->setMaximumSize(QSize(500, 200));
        label_bar_background->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen1/neowizard_logo.png);"));
        l_background_blur = new QWidget(centralWidget);
        l_background_blur->setObjectName(QStringLiteral("l_background_blur"));
        l_background_blur->setGeometry(QRect(5310, -10, 1366, 768));
        l_background_blur->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/backgroud_blur.png);"));
        widget_state_machine_name = new QWidget(l_background_blur);
        widget_state_machine_name->setObjectName(QStringLiteral("widget_state_machine_name"));
        widget_state_machine_name->setGeometry(QRect(590, 0, 348, 155));
        widget_state_machine_name->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/rectangulo_central_blanco.png);"));
        l_state_machine_name = new QLabel(widget_state_machine_name);
        l_state_machine_name->setObjectName(QStringLiteral("l_state_machine_name"));
        l_state_machine_name->setGeometry(QRect(80, 30, 189, 21));
        l_state_machine_name->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"background-image: url(:/icons/screen8/State machine name_text.png);\n"
"color:  rgb(21, 172, 112);"));
        le_state_machine_name = new QLineEdit(widget_state_machine_name);
        le_state_machine_name->setObjectName(QStringLiteral("le_state_machine_name"));
        le_state_machine_name->setGeometry(QRect(60, 60, 232, 34));
        le_state_machine_name->setMaximumSize(QSize(234, 16777215));
        le_state_machine_name->setStyleSheet(QLatin1String("font: 15pt \"Myriad Web\";\n"
"color:  rgb(8, 113, 104);\n"
"border-image: url(:/icons/screen8/label.png);\n"
""));
        le_state_machine_name->setAlignment(Qt::AlignCenter);
        pb_acept_sate_machine_name = new QPushButton(widget_state_machine_name);
        pb_acept_sate_machine_name->setObjectName(QStringLiteral("pb_acept_sate_machine_name"));
        pb_acept_sate_machine_name->setGeometry(QRect(240, 100, 54, 29));
        pb_acept_sate_machine_name->setCursor(QCursor(Qt::PointingHandCursor));
        pb_acept_sate_machine_name->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"background-image: url(:/icons/screen8/acept_botom.png);\n"
"color:  rgb(21, 172, 112);"));
        pb_acept_sate_machine_name->setFlat(true);
        pb_cancel_state_machine_name = new QPushButton(widget_state_machine_name);
        pb_cancel_state_machine_name->setObjectName(QStringLiteral("pb_cancel_state_machine_name"));
        pb_cancel_state_machine_name->setGeometry(QRect(60, 100, 61, 29));
        pb_cancel_state_machine_name->setCursor(QCursor(Qt::PointingHandCursor));
        pb_cancel_state_machine_name->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"background-image: url(:/icons/screen8/cancel_botom.png);\n"
"color:  rgb(21, 172, 112);"));
        pb_cancel_state_machine_name->setFlat(true);
        widget_main_thread_name = new QWidget(l_background_blur);
        widget_main_thread_name->setObjectName(QStringLiteral("widget_main_thread_name"));
        widget_main_thread_name->setGeometry(QRect(540, 590, 348, 155));
        widget_main_thread_name->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/rectangulo_central_blanco.png);"));
        l_main_thrad_name = new QLabel(widget_main_thread_name);
        l_main_thrad_name->setObjectName(QStringLiteral("l_main_thrad_name"));
        l_main_thrad_name->setGeometry(QRect(90, 30, 189, 21));
        l_main_thrad_name->setStyleSheet(QLatin1String("font: 15pt \"Segoe UI\";\n"
"color: rgb(128, 128, 128);"));
        le_main_thread_name_to_load = new QLineEdit(widget_main_thread_name);
        le_main_thread_name_to_load->setObjectName(QStringLiteral("le_main_thread_name_to_load"));
        le_main_thread_name_to_load->setGeometry(QRect(60, 60, 232, 34));
        le_main_thread_name_to_load->setMaximumSize(QSize(234, 16777215));
        le_main_thread_name_to_load->setStyleSheet(QLatin1String("font: 15pt \"Myriad Web\";\n"
"color:  rgb(8, 113, 104);\n"
"border-image: url(:/icons/screen8/label.png);\n"
""));
        le_main_thread_name_to_load->setAlignment(Qt::AlignCenter);
        pb_acept_main_thread_name = new QPushButton(widget_main_thread_name);
        pb_acept_main_thread_name->setObjectName(QStringLiteral("pb_acept_main_thread_name"));
        pb_acept_main_thread_name->setGeometry(QRect(240, 100, 54, 29));
        pb_acept_main_thread_name->setCursor(QCursor(Qt::PointingHandCursor));
        pb_acept_main_thread_name->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"background-image: url(:/icons/screen8/acept_botom.png);\n"
"color:  rgb(21, 172, 112);"));
        pb_acept_main_thread_name->setFlat(true);
        pb_cancel_main_thrad_name = new QPushButton(widget_main_thread_name);
        pb_cancel_main_thrad_name->setObjectName(QStringLiteral("pb_cancel_main_thrad_name"));
        pb_cancel_main_thrad_name->setGeometry(QRect(60, 100, 61, 29));
        pb_cancel_main_thrad_name->setCursor(QCursor(Qt::PointingHandCursor));
        pb_cancel_main_thrad_name->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"background-image: url(:/icons/screen8/cancel_botom.png);\n"
"color:  rgb(21, 172, 112);"));
        pb_cancel_main_thrad_name->setFlat(true);
        widget_event_options = new QWidget(l_background_blur);
        widget_event_options->setObjectName(QStringLiteral("widget_event_options"));
        widget_event_options->setGeometry(QRect(-20, -50, 401, 400));
        widget_event_options->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/square_blanco.png);"));
        layoutWidget_2 = new QWidget(widget_event_options);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(88, 290, 282, 33));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        pb_cancel_add_event = new QPushButton(layoutWidget_2);
        pb_cancel_add_event->setObjectName(QStringLiteral("pb_cancel_add_event"));
        pb_cancel_add_event->setMinimumSize(QSize(61, 29));
        pb_cancel_add_event->setMaximumSize(QSize(61, 29));
        pb_cancel_add_event->setCursor(QCursor(Qt::PointingHandCursor));
        pb_cancel_add_event->setStyleSheet(QLatin1String("font: 14pt \"Myriad Web\";\n"
"color:  rgb(8, 113, 104);"));
        pb_cancel_add_event->setFlat(true);

        horizontalLayout_10->addWidget(pb_cancel_add_event);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_6);

        pb_add_event = new QPushButton(layoutWidget_2);
        pb_add_event->setObjectName(QStringLiteral("pb_add_event"));
        pb_add_event->setCursor(QCursor(Qt::PointingHandCursor));
        pb_add_event->setStyleSheet(QLatin1String("font: 14pt \"Myriad Web\";\n"
"color:  rgb(8, 113, 104);"));
        pb_add_event->setFlat(true);

        horizontalLayout_10->addWidget(pb_add_event);

        pb_delete_event = new QPushButton(layoutWidget_2);
        pb_delete_event->setObjectName(QStringLiteral("pb_delete_event"));
        pb_delete_event->setCursor(QCursor(Qt::PointingHandCursor));
        pb_delete_event->setStyleSheet(QLatin1String("font: 14pt \"Myriad Web\";\n"
"color:  rgb(8, 113, 104);"));
        pb_delete_event->setFlat(true);

        horizontalLayout_10->addWidget(pb_delete_event);

        layoutWidget_3 = new QWidget(widget_event_options);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(80, 80, 234, 63));
        verticalLayout_26 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_26->setSpacing(6);
        verticalLayout_26->setContentsMargins(11, 11, 11, 11);
        verticalLayout_26->setObjectName(QStringLiteral("verticalLayout_26"));
        verticalLayout_26->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_26->setContentsMargins(0, 0, 0, 0);
        l_EVENT = new QLabel(layoutWidget_3);
        l_EVENT->setObjectName(QStringLiteral("l_EVENT"));
        l_EVENT->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(128, 128, 128);"));
        l_EVENT->setAlignment(Qt::AlignCenter);

        verticalLayout_26->addWidget(l_EVENT);

        le_event_ID_name = new QLineEdit(layoutWidget_3);
        le_event_ID_name->setObjectName(QStringLiteral("le_event_ID_name"));
        le_event_ID_name->setMinimumSize(QSize(232, 34));
        le_event_ID_name->setMaximumSize(QSize(232, 16777215));
        le_event_ID_name->setStyleSheet(QLatin1String("font: 15pt \"Myriad Web\";\n"
"color:  rgb(8, 113, 104);\n"
"border-image: url(:/icons/screen8/label.png);\n"
""));
        le_event_ID_name->setAlignment(Qt::AlignCenter);

        verticalLayout_26->addWidget(le_event_ID_name);

        layoutWidget_4 = new QWidget(widget_event_options);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(80, 150, 234, 63));
        verticalLayout_27 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_27->setSpacing(6);
        verticalLayout_27->setContentsMargins(11, 11, 11, 11);
        verticalLayout_27->setObjectName(QStringLiteral("verticalLayout_27"));
        verticalLayout_27->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_27->setContentsMargins(0, 0, 0, 0);
        l_NEXT_STATE = new QLabel(layoutWidget_4);
        l_NEXT_STATE->setObjectName(QStringLiteral("l_NEXT_STATE"));
        l_NEXT_STATE->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(128, 128, 128);"));
        l_NEXT_STATE->setAlignment(Qt::AlignCenter);

        verticalLayout_27->addWidget(l_NEXT_STATE);

        le_next_state_name = new QLineEdit(layoutWidget_4);
        le_next_state_name->setObjectName(QStringLiteral("le_next_state_name"));
        le_next_state_name->setMinimumSize(QSize(232, 34));
        le_next_state_name->setMaximumSize(QSize(232, 16777215));
        le_next_state_name->setStyleSheet(QLatin1String("font: 15pt \"Myriad Web\";\n"
"color:  rgb(8, 113, 104);\n"
"border-image: url(:/icons/screen8/label.png);\n"
""));
        le_next_state_name->setAlignment(Qt::AlignCenter);

        verticalLayout_27->addWidget(le_next_state_name);

        layoutWidget_5 = new QWidget(widget_event_options);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(80, 220, 234, 63));
        verticalLayout_28 = new QVBoxLayout(layoutWidget_5);
        verticalLayout_28->setSpacing(6);
        verticalLayout_28->setContentsMargins(11, 11, 11, 11);
        verticalLayout_28->setObjectName(QStringLiteral("verticalLayout_28"));
        verticalLayout_28->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_28->setContentsMargins(0, 0, 0, 0);
        l_ACTION = new QLabel(layoutWidget_5);
        l_ACTION->setObjectName(QStringLiteral("l_ACTION"));
        l_ACTION->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(128, 128, 128);"));
        l_ACTION->setAlignment(Qt::AlignCenter);

        verticalLayout_28->addWidget(l_ACTION);

        le_action_name = new QLineEdit(layoutWidget_5);
        le_action_name->setObjectName(QStringLiteral("le_action_name"));
        le_action_name->setMinimumSize(QSize(232, 34));
        le_action_name->setMaximumSize(QSize(232, 34));
        le_action_name->setStyleSheet(QLatin1String("font: 15pt \"Myriad Web\";\n"
"color:  rgb(8, 113, 104);\n"
"border-image: url(:/icons/screen8/label.png);\n"
""));
        le_action_name->setAlignment(Qt::AlignCenter);

        verticalLayout_28->addWidget(le_action_name);

        widget_simulate_HSM = new QWidget(l_background_blur);
        widget_simulate_HSM->setObjectName(QStringLiteral("widget_simulate_HSM"));
        widget_simulate_HSM->setGeometry(QRect(310, 230, 743, 288));
        widget_simulate_HSM->setStyleSheet(QLatin1String("background-image: url(:/icons/screen8/window.png);\n"
"background-image: url(:/icons/screen3/window.png);"));
        pb_back_from_HSM_simulate = new QPushButton(widget_simulate_HSM);
        pb_back_from_HSM_simulate->setObjectName(QStringLiteral("pb_back_from_HSM_simulate"));
        pb_back_from_HSM_simulate->setGeometry(QRect(20, 10, 91, 51));
        pb_back_from_HSM_simulate->setCursor(QCursor(Qt::PointingHandCursor));
        pb_back_from_HSM_simulate->setStyleSheet(QLatin1String("font: 14pt \"Myriad Web\";\n"
"color:  rgb(8, 113, 104);\n"
""));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/screen8/back_icon_botom.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_back_from_HSM_simulate->setIcon(icon4);
        pb_back_from_HSM_simulate->setIconSize(QSize(100, 100));
        pb_back_from_HSM_simulate->setFlat(true);
        layoutWidget_6 = new QWidget(widget_simulate_HSM);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(480, 30, 234, 63));
        verticalLayout_32 = new QVBoxLayout(layoutWidget_6);
        verticalLayout_32->setSpacing(6);
        verticalLayout_32->setContentsMargins(11, 11, 11, 11);
        verticalLayout_32->setObjectName(QStringLiteral("verticalLayout_32"));
        verticalLayout_32->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_32->setContentsMargins(0, 0, 0, 0);
        l_EVENT_18 = new QLabel(layoutWidget_6);
        l_EVENT_18->setObjectName(QStringLiteral("l_EVENT_18"));
        l_EVENT_18->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(128, 128, 128);"));
        l_EVENT_18->setAlignment(Qt::AlignCenter);

        verticalLayout_32->addWidget(l_EVENT_18);

        le_simulated_event_ID_name = new QLineEdit(layoutWidget_6);
        le_simulated_event_ID_name->setObjectName(QStringLiteral("le_simulated_event_ID_name"));
        le_simulated_event_ID_name->setMinimumSize(QSize(232, 34));
        le_simulated_event_ID_name->setMaximumSize(QSize(232, 16777215));
        le_simulated_event_ID_name->setStyleSheet(QLatin1String("font: 15pt \"Myriad Web\";\n"
"color:  rgb(8, 113, 104);\n"
"border-image: url(:/icons/screen8/label.png);\n"
""));
        le_simulated_event_ID_name->setAlignment(Qt::AlignCenter);

        verticalLayout_32->addWidget(le_simulated_event_ID_name);

        layoutWidget_7 = new QWidget(widget_simulate_HSM);
        layoutWidget_7->setObjectName(QStringLiteral("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(480, 110, 234, 63));
        verticalLayout_33 = new QVBoxLayout(layoutWidget_7);
        verticalLayout_33->setSpacing(6);
        verticalLayout_33->setContentsMargins(11, 11, 11, 11);
        verticalLayout_33->setObjectName(QStringLiteral("verticalLayout_33"));
        verticalLayout_33->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_33->setContentsMargins(0, 0, 0, 0);
        l_NEXT_STATE_2 = new QLabel(layoutWidget_7);
        l_NEXT_STATE_2->setObjectName(QStringLiteral("l_NEXT_STATE_2"));
        l_NEXT_STATE_2->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(128, 128, 128);"));
        l_NEXT_STATE_2->setAlignment(Qt::AlignCenter);

        verticalLayout_33->addWidget(l_NEXT_STATE_2);

        le_simulated_next_state_name = new QLineEdit(layoutWidget_7);
        le_simulated_next_state_name->setObjectName(QStringLiteral("le_simulated_next_state_name"));
        le_simulated_next_state_name->setMinimumSize(QSize(232, 34));
        le_simulated_next_state_name->setMaximumSize(QSize(232, 16777215));
        le_simulated_next_state_name->setStyleSheet(QLatin1String("font: 15pt \"Myriad Web\";\n"
"color:  rgb(8, 113, 104);\n"
"border-image: url(:/icons/screen8/label.png);\n"
""));
        le_simulated_next_state_name->setAlignment(Qt::AlignCenter);

        verticalLayout_33->addWidget(le_simulated_next_state_name);

        layoutWidget_8 = new QWidget(widget_simulate_HSM);
        layoutWidget_8->setObjectName(QStringLiteral("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(480, 190, 234, 63));
        verticalLayout_34 = new QVBoxLayout(layoutWidget_8);
        verticalLayout_34->setSpacing(6);
        verticalLayout_34->setContentsMargins(11, 11, 11, 11);
        verticalLayout_34->setObjectName(QStringLiteral("verticalLayout_34"));
        verticalLayout_34->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_34->setContentsMargins(0, 0, 0, 0);
        l_ACTION_2 = new QLabel(layoutWidget_8);
        l_ACTION_2->setObjectName(QStringLiteral("l_ACTION_2"));
        l_ACTION_2->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(128, 128, 128);"));
        l_ACTION_2->setAlignment(Qt::AlignCenter);

        verticalLayout_34->addWidget(l_ACTION_2);

        le_simulated_action_name = new QLineEdit(layoutWidget_8);
        le_simulated_action_name->setObjectName(QStringLiteral("le_simulated_action_name"));
        le_simulated_action_name->setMinimumSize(QSize(232, 34));
        le_simulated_action_name->setMaximumSize(QSize(232, 34));
        le_simulated_action_name->setStyleSheet(QLatin1String("font: 15pt \"Myriad Web\";\n"
"color:  rgb(8, 113, 104);\n"
"border-image: url(:/icons/screen8/label.png);\n"
""));
        le_simulated_action_name->setAlignment(Qt::AlignCenter);

        verticalLayout_34->addWidget(le_simulated_action_name);

        pb_simulate_dispatch = new QPushButton(widget_simulate_HSM);
        pb_simulate_dispatch->setObjectName(QStringLiteral("pb_simulate_dispatch"));
        pb_simulate_dispatch->setGeometry(QRect(315, 220, 107, 31));
        pb_simulate_dispatch->setCursor(QCursor(Qt::PointingHandCursor));
        pb_simulate_dispatch->setStyleSheet(QLatin1String("font: 14pt \"Myriad Web\";\n"
"color:  rgb(8, 113, 104);"));
        pb_simulate_dispatch->setFlat(true);
        lw_simulated_events = new QListWidget(widget_simulate_HSM);
        lw_simulated_events->setObjectName(QStringLiteral("lw_simulated_events"));
        lw_simulated_events->setGeometry(QRect(30, 111, 231, 141));
        l_EVENT_19 = new QLabel(widget_simulate_HSM);
        l_EVENT_19->setObjectName(QStringLiteral("l_EVENT_19"));
        l_EVENT_19->setGeometry(QRect(30, 70, 232, 21));
        l_EVENT_19->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(128, 128, 128);"));
        l_EVENT_19->setAlignment(Qt::AlignCenter);
        l_EVENT_20 = new QLabel(widget_simulate_HSM);
        l_EVENT_20->setObjectName(QStringLiteral("l_EVENT_20"));
        l_EVENT_20->setGeometry(QRect(280, 40, 181, 21));
        l_EVENT_20->setStyleSheet(QLatin1String("font: 12pt \"Segoe UI\";\n"
"color: rgb(128, 128, 128);"));
        l_EVENT_20->setAlignment(Qt::AlignCenter);
        l_current_state_simulated = new QLabel(widget_simulate_HSM);
        l_current_state_simulated->setObjectName(QStringLiteral("l_current_state_simulated"));
        l_current_state_simulated->setGeometry(QRect(280, 70, 181, 21));
        l_current_state_simulated->setStyleSheet(QLatin1String("font: 14pt \"Myriad Web\";\n"
"color:  rgb(8, 113, 104);"));
        l_current_state_simulated->setAlignment(Qt::AlignCenter);
        widget_help_screen = new QWidget(centralWidget);
        widget_help_screen->setObjectName(QStringLiteral("widget_help_screen"));
        widget_help_screen->setGeometry(QRect(6680, 0, 1366, 768));
        widget_help_screen->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/background.png);"));
        pb_Stcube_Config = new QPushButton(widget_help_screen);
        pb_Stcube_Config->setObjectName(QStringLiteral("pb_Stcube_Config"));
        pb_Stcube_Config->setGeometry(QRect(177, 290, 433, 53));
        pb_Stcube_Config->setCursor(QCursor(Qt::PointingHandCursor));
        pb_Stcube_Config->setStyleSheet(QLatin1String("background-image: url(:/icons/screen8/fondo_transparente.png);\n"
"font: 63 20pt \"Segoe UI Semibold\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_Stcube_Config->setFlat(true);
        pb_about_NEOW = new QPushButton(widget_help_screen);
        pb_about_NEOW->setObjectName(QStringLiteral("pb_about_NEOW"));
        pb_about_NEOW->setGeometry(QRect(246, 360, 433, 53));
        pb_about_NEOW->setCursor(QCursor(Qt::PointingHandCursor));
        pb_about_NEOW->setStyleSheet(QLatin1String("background-image: url(:/icons/screen8/fondo_transparente.png);\n"
"font: 63 20pt \"Segoe UI Semibold\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_about_NEOW->setFlat(true);
        pb_about_QT = new QPushButton(widget_help_screen);
        pb_about_QT->setObjectName(QStringLiteral("pb_about_QT"));
        pb_about_QT->setGeometry(QRect(300, 430, 433, 53));
        pb_about_QT->setCursor(QCursor(Qt::PointingHandCursor));
        pb_about_QT->setStyleSheet(QLatin1String("background-image: url(:/icons/screen8/fondo_transparente.png);\n"
"font: 63 20pt \"Segoe UI Semibold\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_about_QT->setFlat(true);
        pb_uVision_Config = new QPushButton(widget_help_screen);
        pb_uVision_Config->setObjectName(QStringLiteral("pb_uVision_Config"));
        pb_uVision_Config->setGeometry(QRect(225, 220, 433, 53));
        pb_uVision_Config->setCursor(QCursor(Qt::PointingHandCursor));
        pb_uVision_Config->setStyleSheet(QLatin1String("background-image: url(:/icons/screen8/fondo_transparente.png);\n"
"font: 63 20pt \"Segoe UI Semibold\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_uVision_Config->setFlat(true);
        groupBox = new QGroupBox(widget_help_screen);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(800, 230, 231, 484));
        groupBox->setStyleSheet(QLatin1String("background-image: url(:/icons/screen8/fondo_transparente.png);\n"
"font: 63 20pt \"Segoe UI Semibold\";\n"
"color: rgb(8, 113, 104);\n"
""));
        verticalLayout_31 = new QVBoxLayout(groupBox);
        verticalLayout_31->setSpacing(6);
        verticalLayout_31->setContentsMargins(11, 11, 11, 11);
        verticalLayout_31->setObjectName(QStringLiteral("verticalLayout_31"));
        widget_examples = new QWidget(groupBox);
        widget_examples->setObjectName(QStringLiteral("widget_examples"));
        widget_examples->setStyleSheet(QStringLiteral("background-image: url(:/icons/screen8/fondo_transparente.png);"));
        verticalLayout_29 = new QVBoxLayout(widget_examples);
        verticalLayout_29->setSpacing(6);
        verticalLayout_29->setContentsMargins(11, 11, 11, 11);
        verticalLayout_29->setObjectName(QStringLiteral("verticalLayout_29"));
        verticalLayout_29->setSizeConstraint(QLayout::SetFixedSize);
        pb_thread_example = new QPushButton(widget_examples);
        pb_thread_example->setObjectName(QStringLiteral("pb_thread_example"));
        pb_thread_example->setEnabled(true);
        pb_thread_example->setMinimumSize(QSize(150, 40));
        pb_thread_example->setMaximumSize(QSize(200, 50));
        pb_thread_example->setCursor(QCursor(Qt::PointingHandCursor));
        pb_thread_example->setStyleSheet(QLatin1String("background-image: url(:/icons/screen8/fondo_transparente.png);\n"
"font: 75 20pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_thread_example->setFlat(true);

        verticalLayout_29->addWidget(pb_thread_example);

        pb_timer_example = new QPushButton(widget_examples);
        pb_timer_example->setObjectName(QStringLiteral("pb_timer_example"));
        pb_timer_example->setEnabled(true);
        pb_timer_example->setMinimumSize(QSize(150, 40));
        pb_timer_example->setMaximumSize(QSize(200, 50));
        pb_timer_example->setCursor(QCursor(Qt::PointingHandCursor));
        pb_timer_example->setStyleSheet(QLatin1String("background-image: url(:/icons/screen8/fondo_transparente.png);\n"
"font: 75 20pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_timer_example->setFlat(true);

        verticalLayout_29->addWidget(pb_timer_example);

        pb_mail_example = new QPushButton(widget_examples);
        pb_mail_example->setObjectName(QStringLiteral("pb_mail_example"));
        pb_mail_example->setEnabled(true);
        pb_mail_example->setMinimumSize(QSize(150, 40));
        pb_mail_example->setMaximumSize(QSize(200, 50));
        pb_mail_example->setCursor(QCursor(Qt::PointingHandCursor));
        pb_mail_example->setStyleSheet(QLatin1String("background-image: url(:/icons/screen8/fondo_transparente.png);\n"
"font: 75 20pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_mail_example->setFlat(true);

        verticalLayout_29->addWidget(pb_mail_example);

        pb_memoryPool_example = new QPushButton(widget_examples);
        pb_memoryPool_example->setObjectName(QStringLiteral("pb_memoryPool_example"));
        pb_memoryPool_example->setEnabled(true);
        pb_memoryPool_example->setMinimumSize(QSize(150, 40));
        pb_memoryPool_example->setMaximumSize(QSize(200, 50));
        pb_memoryPool_example->setCursor(QCursor(Qt::PointingHandCursor));
        pb_memoryPool_example->setStyleSheet(QLatin1String("background-image: url(:/icons/screen8/fondo_transparente.png);\n"
"font: 75 20pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_memoryPool_example->setFlat(true);

        verticalLayout_29->addWidget(pb_memoryPool_example);

        pb_semaphore_example = new QPushButton(widget_examples);
        pb_semaphore_example->setObjectName(QStringLiteral("pb_semaphore_example"));
        pb_semaphore_example->setEnabled(true);
        pb_semaphore_example->setMinimumSize(QSize(150, 40));
        pb_semaphore_example->setMaximumSize(QSize(200, 50));
        pb_semaphore_example->setCursor(QCursor(Qt::PointingHandCursor));
        pb_semaphore_example->setStyleSheet(QLatin1String("background-image: url(:/icons/screen8/fondo_transparente.png);\n"
"font: 75 20pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_semaphore_example->setFlat(true);

        verticalLayout_29->addWidget(pb_semaphore_example);

        pb_mutex_example = new QPushButton(widget_examples);
        pb_mutex_example->setObjectName(QStringLiteral("pb_mutex_example"));
        pb_mutex_example->setEnabled(true);
        pb_mutex_example->setMinimumSize(QSize(150, 40));
        pb_mutex_example->setMaximumSize(QSize(200, 50));
        pb_mutex_example->setCursor(QCursor(Qt::PointingHandCursor));
        pb_mutex_example->setStyleSheet(QLatin1String("background-image: url(:/icons/screen8/fondo_transparente.png);\n"
"font: 75 20pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_mutex_example->setFlat(true);

        verticalLayout_29->addWidget(pb_mutex_example);

        pb_messQueue_example = new QPushButton(widget_examples);
        pb_messQueue_example->setObjectName(QStringLiteral("pb_messQueue_example"));
        pb_messQueue_example->setEnabled(true);
        pb_messQueue_example->setMinimumSize(QSize(150, 40));
        pb_messQueue_example->setMaximumSize(QSize(220, 50));
        pb_messQueue_example->setCursor(QCursor(Qt::PointingHandCursor));
        pb_messQueue_example->setStyleSheet(QLatin1String("background-image: url(:/icons/screen8/fondo_transparente.png);\n"
"font: 75 20pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_messQueue_example->setFlat(true);

        verticalLayout_29->addWidget(pb_messQueue_example);

        pb_serialPort_example = new QPushButton(widget_examples);
        pb_serialPort_example->setObjectName(QStringLiteral("pb_serialPort_example"));
        pb_serialPort_example->setEnabled(true);
        pb_serialPort_example->setMinimumSize(QSize(150, 40));
        pb_serialPort_example->setMaximumSize(QSize(220, 50));
        pb_serialPort_example->setCursor(QCursor(Qt::PointingHandCursor));
        pb_serialPort_example->setStyleSheet(QLatin1String("background-image: url(:/icons/screen8/fondo_transparente.png);\n"
"font: 75 20pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_serialPort_example->setFlat(true);

        verticalLayout_29->addWidget(pb_serialPort_example);


        verticalLayout_31->addWidget(widget_examples);

        widget_win_options = new QWidget(centralWidget);
        widget_win_options->setObjectName(QStringLiteral("widget_win_options"));
        widget_win_options->setGeometry(QRect(2420, 230, 111, 152));
        widget_win_options->setStyleSheet(QStringLiteral("background-color: rgb(250, 250, 250);"));
        verticalLayout_5 = new QVBoxLayout(widget_win_options);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        pb_minimize_option = new QPushButton(widget_win_options);
        pb_minimize_option->setObjectName(QStringLiteral("pb_minimize_option"));
        pb_minimize_option->setCursor(QCursor(Qt::PointingHandCursor));
        pb_minimize_option->setStyleSheet(QLatin1String("font: 75 12pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_minimize_option->setFlat(true);

        verticalLayout_5->addWidget(pb_minimize_option);

        pb_maximize_option = new QPushButton(widget_win_options);
        pb_maximize_option->setObjectName(QStringLiteral("pb_maximize_option"));
        pb_maximize_option->setCursor(QCursor(Qt::PointingHandCursor));
        pb_maximize_option->setStyleSheet(QLatin1String("font: 75 12pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_maximize_option->setFlat(true);

        verticalLayout_5->addWidget(pb_maximize_option);

        pb_cancel_option = new QPushButton(widget_win_options);
        pb_cancel_option->setObjectName(QStringLiteral("pb_cancel_option"));
        pb_cancel_option->setCursor(QCursor(Qt::PointingHandCursor));
        pb_cancel_option->setStyleSheet(QLatin1String("font: 75 12pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_cancel_option->setFlat(true);

        verticalLayout_5->addWidget(pb_cancel_option);

        pb_close_option = new QPushButton(widget_win_options);
        pb_close_option->setObjectName(QStringLiteral("pb_close_option"));
        pb_close_option->setCursor(QCursor(Qt::PointingHandCursor));
        pb_close_option->setStyleSheet(QLatin1String("font: 75 12pt \"Segoe UI\";\n"
"color: rgb(8, 113, 104);\n"
""));
        pb_close_option->setFlat(true);

        verticalLayout_5->addWidget(pb_close_option);

        NFWizard2->setCentralWidget(centralWidget);
        widget_help_screen->raise();
        widget_state_machine_screen->raise();
        widget_options_screen_native->raise();
        widget_generate_screen->raise();
        layoutWidget->raise();
        widget_wait->raise();
        l_background_blur->raise();
        widget_win_buttons->raise();
        widget_win_options->raise();
        statusBar = new QStatusBar(NFWizard2);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        NFWizard2->setStatusBar(statusBar);

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
#ifndef QT_NO_TOOLTIP
        pushButton_Generate->setToolTip(QApplication::translate("NFWizard2", "Generate the files and modifies files needed to become compatible both projects", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_Generate->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_Quit->setToolTip(QApplication::translate("NFWizard2", "Close application", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_Quit->setText(QString());
#ifndef QT_NO_TOOLTIP
        lineEdit_CubePath->setToolTip(QApplication::translate("NFWizard2", "STCube generated project path on your PC", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        lineEdit_CubePath->setPlaceholderText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_CubeBrowse->setToolTip(QApplication::translate("NFWizard2", "Look for STCubeMX generated project path in your PC", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_CubeBrowse->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_uVisionBrowse->setToolTip(QApplication::translate("NFWizard2", "Look for uVision project path in your PC", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_uVisionBrowse->setText(QString());
#ifndef QT_NO_TOOLTIP
        lineEdit_uVisionPath->setToolTip(QApplication::translate("NFWizard2", "Keil uVision project path on your PC", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        lineEdit_uVisionPath->setPlaceholderText(QString());
#ifndef QT_NO_TOOLTIP
        label_Cube->setToolTip(QApplication::translate("NFWizard2", "STCubeMX generated project path on your PC (*.ioc file)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_Cube->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_uVision->setToolTip(QApplication::translate("NFWizard2", "Keil uVision project path on your PC (*.uvprojx file)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_uVision->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_generate_folders->setToolTip(QApplication::translate("NFWizard2", "Generates files needed. If they are generated already you don't need to mark this option", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_generate_folders->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_generate_options->setToolTip(QApplication::translate("NFWizard2", "Generates files needed. If they are generated already you don't need to mark this option", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_generate_options->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_generate_project_folders->setToolTip(QApplication::translate("NFWizard2", "Close application", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_generate_project_folders->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_configure_thread_in_class->setToolTip(QApplication::translate("NFWizard2", "Configure a Thread inside a Class you can name", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_configure_thread_in_class->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_configure_Main_thread->setToolTip(QApplication::translate("NFWizard2", "Configure a Main Thread and execute it in main.cpp", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_configure_Main_thread->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_configure_in_Main_thread->setToolTip(QApplication::translate("NFWizard2", "Configure a Main Thread and execute it in main.cpp", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_configure_in_Main_thread->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_configure_state_machine->setToolTip(QApplication::translate("NFWizard2", "Configure a state machine and then generate the code in your Main Thread", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_configure_state_machine->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_add_thread->setToolTip(QApplication::translate("NFWizard2", "Add the Thread configured", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_add_thread->setText(QString());
        l_main_thread_name->setText(QApplication::translate("NFWizard2", "Main Thread Name", Q_NULLPTR));
        l_thread_name->setText(QApplication::translate("NFWizard2", "New Thread Name", Q_NULLPTR));
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
        l_thread_stack_size->setText(QApplication::translate("NFWizard2", "Thread Stack Size", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_configure_thread_in_main->setToolTip(QApplication::translate("NFWizard2", "Configure a Thread inside the Main Thread, you can execute it whenever you desire", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_configure_thread_in_main->setText(QApplication::translate("NFWizard2", " Thread     >", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_configure_Mail->setToolTip(QApplication::translate("NFWizard2", "Configure a Main Thread and execute it in main.cpp", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_configure_Mail->setText(QApplication::translate("NFWizard2", "Mail     >", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_configure_Timer->setToolTip(QApplication::translate("NFWizard2", "Configure a Main Thread and execute it in main.cpp", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_configure_Timer->setText(QApplication::translate("NFWizard2", "Timer     >", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_configure_semaphore->setToolTip(QApplication::translate("NFWizard2", "Configure a Main Thread and execute it in main.cpp", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_configure_semaphore->setText(QApplication::translate("NFWizard2", "Semaphore     >", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_configure_memoryPool->setToolTip(QApplication::translate("NFWizard2", "Configure a Main Thread and execute it in main.cpp", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_configure_memoryPool->setText(QApplication::translate("NFWizard2", "Memory Pool     >", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_configure_mutex->setToolTip(QApplication::translate("NFWizard2", "Configure a Main Thread and execute it in main.cpp", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_configure_mutex->setText(QApplication::translate("NFWizard2", "Mutex     >", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_configure_messQueue->setToolTip(QApplication::translate("NFWizard2", "Configure a Main Thread and execute it in main.cpp", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_configure_messQueue->setText(QApplication::translate("NFWizard2", "Message Queue    >", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_configure_serialPort->setToolTip(QApplication::translate("NFWizard2", "Configure a Main Thread and execute it in main.cpp", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_configure_serialPort->setText(QApplication::translate("NFWizard2", "Serial Port   >", Q_NULLPTR));
        l_EVENT_13->setText(QApplication::translate("NFWizard2", "Timer Name", Q_NULLPTR));
        cb_timer_mode->clear();
        cb_timer_mode->insertItems(0, QStringList()
         << QApplication::translate("NFWizard2", "Periodic", Q_NULLPTR)
         << QApplication::translate("NFWizard2", "NonStaticMethod", Q_NULLPTR)
         << QApplication::translate("NFWizard2", "SingleShot", Q_NULLPTR)
        );
        l_EVENT_3->setText(QApplication::translate("NFWizard2", "Timer Interval  (ms)", Q_NULLPTR));
        l_EVENT_4->setText(QApplication::translate("NFWizard2", "TimeOut  Function", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_add_Timer->setToolTip(QApplication::translate("NFWizard2", "Configure a Main Thread and execute it in main.cpp", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_add_Timer->setText(QApplication::translate("NFWizard2", "Add Timer", Q_NULLPTR));
        l_EVENT_5->setText(QApplication::translate("NFWizard2", "MailBox Name", Q_NULLPTR));
        l_EVENT_9->setText(QApplication::translate("NFWizard2", "Mail Data Type", Q_NULLPTR));
        l_EVENT_7->setText(QApplication::translate("NFWizard2", "MailBox Size", Q_NULLPTR));
        l_EVENT_6->setText(QApplication::translate("NFWizard2", "Mail Buffer Size", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_add_MailBox->setToolTip(QApplication::translate("NFWizard2", "Configure a Main Thread and execute it in main.cpp", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_add_MailBox->setText(QApplication::translate("NFWizard2", "Add MailBox", Q_NULLPTR));
        l_EVENT_10->setText(QApplication::translate("NFWizard2", "Memory Pool  Name", Q_NULLPTR));
        l_EVENT_11->setText(QApplication::translate("NFWizard2", "Memory Pool  Size", Q_NULLPTR));
        l_memPool_data_type->setText(QApplication::translate("NFWizard2", "Memory Pool Data Type", Q_NULLPTR));
        cb_memoryPool_buffer->setText(QApplication::translate("NFWizard2", "Memory Pool Buffer", Q_NULLPTR));
        l_memPool_buffer_type->setText(QApplication::translate("NFWizard2", "Buffer Data Type", Q_NULLPTR));
        l_memPool_buffer_size->setText(QApplication::translate("NFWizard2", "Buffer Size", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_add_memPool->setToolTip(QApplication::translate("NFWizard2", "Configure a Main Thread and execute it in main.cpp", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_add_memPool->setText(QApplication::translate("NFWizard2", "Add Memory Pool", Q_NULLPTR));
        l_EVENT_2->setText(QApplication::translate("NFWizard2", "Semaphore Name", Q_NULLPTR));
        l_EVENT_12->setText(QApplication::translate("NFWizard2", "Semaphore Resource Size", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_add_Semaphore->setToolTip(QApplication::translate("NFWizard2", "Configure a Main Thread and execute it in main.cpp", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_add_Semaphore->setText(QApplication::translate("NFWizard2", "Add Semaphore", Q_NULLPTR));
        l_EVENT_14->setText(QApplication::translate("NFWizard2", "Mutex  Name", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_add_Mutex->setToolTip(QApplication::translate("NFWizard2", "Configure a Main Thread and execute it in main.cpp", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_add_Mutex->setText(QApplication::translate("NFWizard2", "Add Mutex", Q_NULLPTR));
        l_EVENT_8->setText(QApplication::translate("NFWizard2", "Message Queue Name", Q_NULLPTR));
        l_EVENT_15->setText(QApplication::translate("NFWizard2", "Message Queue Size", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_add_messQueue->setToolTip(QApplication::translate("NFWizard2", "Configure a Main Thread and execute it in main.cpp", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_add_messQueue->setText(QApplication::translate("NFWizard2", "Add Message Queue", Q_NULLPTR));
        l_EVENT_16->setText(QApplication::translate("NFWizard2", "SerialPort variable Name", Q_NULLPTR));
        l_EVENT_17->setText(QApplication::translate("NFWizard2", "USART Number", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_add_SerialPort->setToolTip(QApplication::translate("NFWizard2", "Configure a Main Thread and execute it in main.cpp", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_add_SerialPort->setText(QApplication::translate("NFWizard2", "Add SerialPort", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_load_from_Thread->setToolTip(QApplication::translate("NFWizard2", "Load a State Machine saved in folder HSMs into your uVision project path", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_load_from_Thread->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_save_state_machine->setToolTip(QApplication::translate("NFWizard2", "Save the State Machine configured in folder HSMs into your uVision project path", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_save_state_machine->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_load_state_machine->setToolTip(QApplication::translate("NFWizard2", "Load a State Machine saved in folder HSMs into your uVision project path", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_load_state_machine->setText(QString());
        label_2->setText(QApplication::translate("NFWizard2", "SUPER STATE", Q_NULLPTR));
        label_3->setText(QApplication::translate("NFWizard2", "INITIAL STATE", Q_NULLPTR));
        label->setText(QApplication::translate("NFWizard2", "STATE NAME", Q_NULLPTR));
        label_4->setText(QApplication::translate("NFWizard2", "DEFAULT EVENT", Q_NULLPTR));
        label_5->setText(QApplication::translate("NFWizard2", "Next State", Q_NULLPTR));
        label_6->setText(QApplication::translate("NFWizard2", "Action", Q_NULLPTR));
        l_Entry_Action->setText(QApplication::translate("NFWizard2", "ENTRY ACTION", Q_NULLPTR));
        l_Exit_Action->setText(QApplication::translate("NFWizard2", "EXIT ACTION", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_change_to_event->setToolTip(QApplication::translate("NFWizard2", "Apply changes to the State properties", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_change_to_event->setText(QApplication::translate("NFWizard2", "EVENTS", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_ok->setToolTip(QApplication::translate("NFWizard2", "Apply changes to the State properties", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_ok->setText(QApplication::translate("NFWizard2", "APPLY", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_generate_state_machine->setToolTip(QApplication::translate("NFWizard2", "Generate the code for the State Machine configured or loaded inside your Main Thread", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_generate_state_machine->setText(QString());
        l_name_current_state->setText(QApplication::translate("NFWizard2", "No Parent", Q_NULLPTR));
        l_state_parent_tag->setText(QApplication::translate("NFWizard2", "Super State  :", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_back->setToolTip(QApplication::translate("NFWizard2", "Go back to previous parent", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_back->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_search_state->setToolTip(QApplication::translate("NFWizard2", "Search for a State of the State Machine configured", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_search_state->setText(QString());
        QTreeWidgetItem *___qtreewidgetitem = tw_state_machine->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("NFWizard2", "State Machine", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_back_from_state_machine->setToolTip(QApplication::translate("NFWizard2", "Save the State Machine configured in folder HSMs into your uVision project path", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_back_from_state_machine->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_add_state->setToolTip(QApplication::translate("NFWizard2", "Add a new State in the current Super State", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_add_state->setText(QString());
        pb_open_state->setText(QApplication::translate("NFWizard2", "Open State", Q_NULLPTR));
        pb_set_as_initial->setText(QApplication::translate("NFWizard2", "Set as Initial", Q_NULLPTR));
        pb_configure_state->setText(QApplication::translate("NFWizard2", "Configure State", Q_NULLPTR));
        pb_add_sub_sate->setText(QApplication::translate("NFWizard2", "Add Child ", Q_NULLPTR));
        pb_eliminate_state->setText(QApplication::translate("NFWizard2", "Eliminate State", Q_NULLPTR));
        pb_cancel_state_options->setText(QApplication::translate("NFWizard2", "Cancel", Q_NULLPTR));
        pb_warning_state_machine->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_add_event_action->setToolTip(QApplication::translate("NFWizard2", "Add the event configured", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_add_event_action->setText(QApplication::translate("NFWizard2", "Add Event", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_delete_event_action->setToolTip(QApplication::translate("NFWizard2", "Add the event configured", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_delete_event_action->setText(QApplication::translate("NFWizard2", "Erase Event", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_cancel_add_event_2->setToolTip(QApplication::translate("NFWizard2", "Cancel the adding of the event", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_cancel_add_event_2->setText(QApplication::translate("NFWizard2", "Cancel", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_Simulate_HSM->setToolTip(QApplication::translate("NFWizard2", "Add a new State in the current Super State", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_Simulate_HSM->setText(QApplication::translate("NFWizard2", "Simulate", Q_NULLPTR));
        pb_acept_main_thread->setText(QString());
        label_loading->setText(QApplication::translate("NFWizard2", "LOADING...", Q_NULLPTR));
        pb_close_window->setText(QString());
        pb_max_window->setText(QString());
        pushButton_Generate_tag->setText(QString());
        pb_min_window_->setText(QString());
        pushButton_Help_tag->setText(QString());
        pushButton_Options_tag->setText(QString());
        label_bar_background->setText(QString());
        l_state_machine_name->setText(QString());
        pb_acept_sate_machine_name->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_cancel_state_machine_name->setToolTip(QApplication::translate("NFWizard2", "Cancel the name configured", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_cancel_state_machine_name->setText(QString());
        l_main_thrad_name->setText(QApplication::translate("NFWizard2", "Main Thread Name", Q_NULLPTR));
        pb_acept_main_thread_name->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_cancel_main_thrad_name->setToolTip(QApplication::translate("NFWizard2", "Cancel the name configured", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_cancel_main_thrad_name->setText(QString());
#ifndef QT_NO_TOOLTIP
        pb_cancel_add_event->setToolTip(QApplication::translate("NFWizard2", "Cancel the adding of the event", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_cancel_add_event->setText(QApplication::translate("NFWizard2", "Cancel", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_add_event->setToolTip(QApplication::translate("NFWizard2", "Add the event configured", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_add_event->setText(QApplication::translate("NFWizard2", "Add Event", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_delete_event->setToolTip(QApplication::translate("NFWizard2", "Add the event configured", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_delete_event->setText(QApplication::translate("NFWizard2", "Erase Event", Q_NULLPTR));
        l_EVENT->setText(QApplication::translate("NFWizard2", "EVENT ID", Q_NULLPTR));
        l_NEXT_STATE->setText(QApplication::translate("NFWizard2", "NEXT STATE", Q_NULLPTR));
        l_ACTION->setText(QApplication::translate("NFWizard2", "ACTION", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_back_from_HSM_simulate->setToolTip(QApplication::translate("NFWizard2", "Add the event configured", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_back_from_HSM_simulate->setText(QString());
        l_EVENT_18->setText(QApplication::translate("NFWizard2", "EVENT ID", Q_NULLPTR));
        l_NEXT_STATE_2->setText(QApplication::translate("NFWizard2", "NEXT STATE", Q_NULLPTR));
        l_ACTION_2->setText(QApplication::translate("NFWizard2", "ACTION", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_simulate_dispatch->setToolTip(QApplication::translate("NFWizard2", "Add the event configured", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_simulate_dispatch->setText(QApplication::translate("NFWizard2", "Start", Q_NULLPTR));
        l_EVENT_19->setText(QApplication::translate("NFWizard2", "CURRENT STATE EVENTS", Q_NULLPTR));
        l_EVENT_20->setText(QApplication::translate("NFWizard2", "CURRENT STATE", Q_NULLPTR));
        l_current_state_simulated->setText(QApplication::translate("NFWizard2", "State", Q_NULLPTR));
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
        pb_uVision_Config->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pb_uVision_Config->setText(QApplication::translate("NFWizard2", "uVision Configuration", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("NFWizard2", "Examples", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_thread_example->setToolTip(QApplication::translate("NFWizard2", "Configure a Thread inside the Main Thread, you can execute it whenever you desire", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_thread_example->setText(QApplication::translate("NFWizard2", " Thread", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_timer_example->setToolTip(QApplication::translate("NFWizard2", "Configure a Main Thread and execute it in main.cpp", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_timer_example->setText(QApplication::translate("NFWizard2", "Timer", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_mail_example->setToolTip(QApplication::translate("NFWizard2", "Configure a Main Thread and execute it in main.cpp", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_mail_example->setText(QApplication::translate("NFWizard2", "Mail", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_memoryPool_example->setToolTip(QApplication::translate("NFWizard2", "Configure a Main Thread and execute it in main.cpp", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_memoryPool_example->setText(QApplication::translate("NFWizard2", "Memory Pool", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_semaphore_example->setToolTip(QApplication::translate("NFWizard2", "Configure a Main Thread and execute it in main.cpp", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_semaphore_example->setText(QApplication::translate("NFWizard2", "Semaphore", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_mutex_example->setToolTip(QApplication::translate("NFWizard2", "Configure a Main Thread and execute it in main.cpp", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_mutex_example->setText(QApplication::translate("NFWizard2", "Mutex", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_messQueue_example->setToolTip(QApplication::translate("NFWizard2", "Configure a Main Thread and execute it in main.cpp", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_messQueue_example->setText(QApplication::translate("NFWizard2", "Message Queue", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_serialPort_example->setToolTip(QApplication::translate("NFWizard2", "Configure a Main Thread and execute it in main.cpp", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_serialPort_example->setText(QApplication::translate("NFWizard2", "Serial Port", Q_NULLPTR));
        pb_minimize_option->setText(QApplication::translate("NFWizard2", "Minimize", Q_NULLPTR));
        pb_maximize_option->setText(QApplication::translate("NFWizard2", "Maximize", Q_NULLPTR));
        pb_cancel_option->setText(QApplication::translate("NFWizard2", "Close", Q_NULLPTR));
        pb_close_option->setText(QApplication::translate("NFWizard2", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NFWizard2: public Ui_NFWizard2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NFWIZARD2_H
