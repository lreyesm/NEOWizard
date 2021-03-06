#ifndef NFWIZARD2_H
#define NFWIZARD2_H

#include <QMainWindow>
#include <QtCore>
#include "DialogConfigurationHelp.h"
#include "qhierarchy_state.h"
#include <QCompleter>
#include <QTreeWidgetItem>
#include <QTimer>
#include <QStandardItemModel>
#include <QMouseEvent>
#include <QListWidgetItem>

#define EHSM_MAX_NEST_STATES 16

namespace Ui {
class NFWizard2;
}

class NFWizard2 : public QMainWindow
{
    Q_OBJECT

    struct FunctionDelimiters{
        QString startLine;
        QString endLine;
        QString mssg;
    };
    enum{Main_Thead,Thread_in_Main,Thread_in_Class};

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    enum EventHandlerType{
        EventIgnored, //The event does nothing
        TriggerAction, //The event trigered an action
        TriggerTransition, //The event triggered a transition
        TriggerActionAndTransition, //The event triggered a action and a transition
        TriggerActionMantainState,
        DoNothingEventIgnored
    };


    QString currentState_simulated;
    QString initialState_simulated;
    //QString nextStatePtr_;

    int handleEvent(int state_index, QString event_ID_name);
    int handleDefaultEvent(int state_index, QString event_ID_name);
    void dispatch(QString event_ID_name);

    QString State_Machine_name;
    /////////////////////////////////////////////////////////////////////////////////////////////////////

public:
    explicit NFWizard2(QWidget *parent = 0);
    ~NFWizard2();

private slots:

    void mousePressEvent(QMouseEvent *e) ///al reimplementar esta funcion deja de funcionar el evento pressed
    {
        emit mouse_pressed();
    }

    void mouseDoubleClickEvent(QMouseEvent *e){

        emit mouse_DoubleClick();
    }
    void mouseReleaseEvent(QMouseEvent *e) ///al reimplementar esta funcion deja de funcionar el evento pressed
    {
        emit mouse_Release();
    }

    void on_pushButton_uVisionBrowse_clicked();

    void on_pushButton_CubeBrowse_clicked();

    void on_pushButton_Generate_clicked();

    void on_actionAbout_Qt_triggered();

    void on_actionAbout_triggered();
    void on_actionUVision_Configuration_triggered();

    void on_actionSTM32CubeMx_Configuration_triggered();

    ////funcion slot de combobox de seleccion version cube
    //void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_generate_folders_clicked();

    void on_pushButton_Quit_clicked();

    void on_pushButton_Help_tag_clicked();

    void on_pushButton_Options_tag_clicked();

    void on_pushButton_Generate_tag_clicked();

    void on_pb_uVision_Config_clicked();

    void on_pb_Stcube_Config_clicked();

    void on_pb_about_NEOW_clicked();

    void on_pb_about_QT_clicked();

    void on_pb_add_thread_clicked();

    void on_pb_configure_thread_in_class_clicked();

    void on_pb_configure_thread_in_main_clicked();

    void on_pb_configure_Main_thread_clicked();

    void on_pb_configure_state_machine_clicked();

    void on_pb_add_state_clicked();

    void on_state_double_click(QString state_name);
    void on_state_right_clicked(QString state_name);
    void on_state_left_clicked(QString state_name);

    void on_pb_generate_state_machine_clicked();

    void on_pb_back_clicked();

    void on_pb_ok_clicked();

    void on_pb_open_state_clicked();

    void on_pb_configure_state_clicked();

    void on_pb_add_sub_sate_clicked();

    void on_pb_eliminate_state_clicked();

    void on_pb_search_state_clicked();

    void on_pb_add_event_clicked();

    void on_pb_cancel_add_event_clicked();

    void on_le_state_to_search_textChanged(const QString &arg1);

    void on_selected_state_in_search(const QString &state);

    void on_pb_set_as_initial_clicked();

    void on_pb_acept_main_thread_clicked();

    void on_le_event_ID_name_textChanged(const QString &arg1);

    void on_le_next_state_name_textChanged(const QString &arg1);

    void on_le_action_name_textChanged(const QString &arg1);

    void on_le_entry_action_textChanged(const QString &arg1);

    void on_le_exit_action_textChanged(const QString &arg1);

    void on_le_super_state_name_textChanged(const QString &arg1);

    void on_le_initial_state_name_textChanged(const QString &arg1);

    void on_le_default_state_name_textChanged(const QString &arg1);

    void on_pb_load_state_machine_clicked();

    void on_pb_save_state_machine_clicked();

    void on_pb_acept_sate_machine_name_clicked();

    void on_pb_cancel_state_machine_name_clicked();

    void check_for_warnings();

    void on_le_state_machine_name_textChanged(const QString &arg1);

    void on_pb_add_event_action_clicked();

    void on_pb_delete_event_action_clicked();

    void on_pb_delete_event_clicked();

    void on_pb_cancel_add_event_2_clicked();

    void on_selected_event(const QString &arg1);

    void on_selected_simulated_event(const QString &arg1);

    void on_pb_load_from_Thread_clicked();

    void on_le_main_thread_name_textChanged(const QString &arg1);

    void on_pb_change_to_event_clicked();

    void on_tw_state_machine_itemClicked(QTreeWidgetItem *item, int column);

    void on_tw_state_machine_itemPressed(QTreeWidgetItem *item, int column);

    void on_tw_state_machine_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_tableView_events_pressed(const QModelIndex &index);

    void on_pb_cancel_state_options_clicked();

    void on_pb_generate_project_folders_clicked();

    void on_pb_configure_Timer_clicked();

    void on_pb_configure_in_Main_thread_clicked();

    void on_pb_add_Timer_clicked();

    void on_pb_back_from_state_machine_clicked();

    void on_pb_acept_main_thread_name_clicked();

    void on_pb_cancel_main_thrad_name_clicked();

    void on_le_main_thread_name_to_load_textChanged(const QString &arg1);

    void on_pb_close_window_clicked();

    void on_pb_max_window_clicked();

    void on_pb_min_window__clicked();

    void on_pb_configure_Mail_clicked();

    void on_pb_add_MailBox_clicked();

    void on_cb_memoryPool_buffer_clicked();

    void on_pb_configure_memoryPool_clicked();

    void on_pb_add_memPool_clicked();

    void on_pb_configure_semaphore_clicked();


    void on_pb_add_Semaphore_clicked();

    void on_pb_configure_mutex_clicked();

    void on_pb_thread_example_clicked();

    void on_pb_timer_example_clicked();

    void on_pb_mail_example_clicked();

    void on_pb_memoryPool_example_clicked();

    void on_pb_semaphore_example_clicked();

    void on_pb_mutex_example_clicked();

    void on_pb_messQueue_example_clicked();

    void on_pb_configure_messQueue_clicked();

    void on_pb_add_messQueue_clicked();

    void on_pb_add_Mutex_clicked();

    void on_start_moving_screen_timeout();

    void on_pb_minimize_option_clicked();

    void on_pb_maximize_option_clicked();

    void on_pb_cancel_option_clicked();

    void on_pb_close_option_clicked();

    void on_drag_screen();
    void on_drag_screen_released();
    void on_mouse_DoubleClick();


    void on_pb_configure_serialPort_clicked();

    void on_pb_add_SerialPort_clicked();

    void on_pb_serialPort_example_clicked();

    void on_pb_Simulate_HSM_clicked();

    void on_pb_back_from_HSM_simulate_clicked();

    void on_le_simulated_event_ID_name_textChanged(const QString &arg1);

    void on_pb_simulate_dispatch_clicked();

    void on_lw_simulated_events_itemClicked(QListWidgetItem *item);

    void on_pb_acept_sate_machine_function_name_clicked();

    void on_pb_cancel_state_machine_function_name_clicked();


    void on_pb_configure_filter_clicked();

    void on_pb_add_Filter_clicked();

    void on_lw_coeficients_pressed(const QModelIndex &index);

    void on_lw_coeficients_doubleClicked(const QModelIndex &index);

    void on_pb_add_coefficient_ok_clicked();

    void on_pb_cancel_adding_coefficient_clicked();

    void on_pb_change_coefficient_clicked();

    void on_pb_delete_coefficient_clicked();

    void on_pb_add_coefficient_clicked();

    void on_pb_load_coefficient_clicked();
    
    void on_pb_add_coefficient_cancel_clicked();

signals:

    check_warnings();
    void mouse_pressed();
    void mouse_Release();
    void mouse_DoubleClick();

private:
    bool start_simulating();
    void generateProjectFileTree();
    void generateTemplates(const QString& projectRootRef);
    int generateTemplates_for_Thread(const QString& projectRootRef, const QString thread_name);
    void processInterrupFile();
    void processMainFiles();
    void processMainFile_add_Main_Thread_Exec(const QString thread_name, const QString main_cpp_dir);
    void process_Main_Thread_Files(const QString thread_name);
    void process_Thread_in_Main_h_File(const QString thread_name, const QString main_thread_name);
    void process_Thread_in_Main_cpp_File(const QString thread_name, const QString main_thread_name, const QString thread_priority);
    void process_Thread_Files(const QString thread_name);
    void processXmlFiles();
    void processXmlFiles_for_Threads(const QString thread_name);
    void processHalConfigFile();
    void saveSettings();
    void loadSettings();
    void checkCubeVersion();
    void processMain_H_file(const QString& main_h_path);
    void processMain_cpp_Error_function(const QString& main_cpp_path);
    void processMain_cpp_Clock_error_code(const QString &main_cpp_path);
    void windows_widget_position();
    void hide_all_objects();
    void show_help();
    void show_generate();
    void show_options();
    void set_points();
    void clean_widget_state_machine();
    int draw_super_state(const QString& superState, const bool update_tree = true, const bool expand = false, const QString item_name = "Empty");
    int get_state_index_with_name(const QString& state_name);
    QList<quint16> get_state_indexes_with_parent(const QString &superState);
    bool add_state_in_superstate(const QString& superState, const QString& state_name, const bool show);
    void clear_line_edits_and_list_widgets();
    bool eliminate_State(const QString& superState);
    void generate_code_for_state_machine(const QString main_thread_name);
    void generate_definition_for_State_Machine_actions(const QString main_thread_name, const QString action);
    void generate_definition_for_State_Machine_events(const QString main_thread_name, const QString event_id, bool define_enum, bool last_event);
    void generate_definition_for_State_Machine_entries_funtions(const QString main_thread_name, const QString class_name);
    void generate_definition_for_State_Machine_exits_funtions(const QString main_thread_name, const QString exitAction);
    int get_child_initial_index(const QString &superState);
    int check_if_compatible(const QString path, const QString main_thread_name, const QString header_source_quest, const QString line_code);
    int generate_guide_code_Main_Thread_h(const QString path, const QString main_thread_name);
    int generate_guide_code_Main_Thread_cpp(const QString path, const QString main_thread_name);
    int generate_labels_for_state_machine(const QString path, const QString main_thread_name, const QString function_name);
    int load_state_machine_from_Thread(const QString path, const QString main_thread_name);
    void show_update_tree_view(const bool expand = false, const QString item_name_parent = "Empty", const QString item_name = "Empty");
    void highlight_state(const QString state_to_highlight);
    void update_table_view_events();

    void configure_timer_in_main_thread(const QString path, const QString main_thread_name);
    void add_MailBox_configuration(const QString fileuVision_Path, const QString main_thread_name);
    void add_memPool_configuration(const QString fileuVision_Path, const QString main_thread_name);

    void add_Semaphore_Configuration(const QString fileuVision_Path, const QString main_thread_name);
    void add_mutex_Configuration(const QString fileuVision_Path, const QString main_thread_name);
    void add_messageQueue_configuration(const QString fileuVision_Path, const QString main_thread_name);
    void add_SerialPort_Configuration(const QString fileuVision_Path, const QString main_thread_name);
    void add_Filter_Configuration(const QString fileuVision_Path, const QString main_thread_name);

private:
    enum{Generate_Screen,Options_Screen,State_Machine_Screen,Help_Screen};
    Ui::NFWizard2 *ui;
    DialogConfigurationHelp *dialogConfigHelp;

    QString fileuVision;
    QString fileuVision_Path;
    QString fileCube;
    QString lastPath;
    QString cubeVersion;

    bool generate_project_folders;
    int add_thread_state;  ////enum del tipo de hilo a agregar
    QList<QHierarchy_State*> hierarchy_states;
    QList<QPoint> points[13];////almacena los QPoints de estados a dibujar
    QString current_state; ////estado marcado
    QString current_state_parent;////los hijos de este superestado son los dibujados
    int current_positions_minus_one; ////Cantidad -1 de estados a dibujar
    QCompleter *complete_list_object_states;
    QCompleter *complete_list_object_actions;
    QCompleter *complete_list_object_events;
    QCompleter *complete_list_object_simulated_events;
    QCompleter *complete_list_object_fuctions_exits_entries;
    QCompleter *complete_list_saved_states;
    QCompleter *complete_list_saved_threads;
    bool isLoad;
    bool busy;
    QStandardItemModel *model;

    QPoint current_win_Pos;
    quint8 current_screen;
    bool load_from_thread = false;

    QTimer start_moving_screen;
    int init_pos_x;
    int init_pos_y;
    bool first_move;

    QHierarchy_State* simulated_state;

    bool modify_coefficient;
    bool modify_coefficient_index;

};

#endif // NFWIZARD2_H
