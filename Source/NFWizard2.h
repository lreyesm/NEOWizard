#ifndef NFWIZARD2_H
#define NFWIZARD2_H

#include <QMainWindow>
#include <QtCore>
#include "DialogConfigurationHelp.h"
#include <qhierarchy_state.h>

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
public:
    explicit NFWizard2(QWidget *parent = 0);
    ~NFWizard2();

private slots:
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

    void on_state_clicked(QString state_name);

private:
    void generateProjectFileTree();
    void generateTemplates(const QString& projectRootRef);
    void generateTemplates_for_Thread(const QString& projectRootRef, const QString thread_name);
    void processInterrupFile();
    void processMainFiles();
    void processMainFile_add_Main_Thread_Exec(const QString thread_name, const QString main_cpp_dir);
    void process_Main_Thread_Files(const QString thread_name);
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


private:
    Ui::NFWizard2 *ui;
    DialogConfigurationHelp *dialogConfigHelp;

    QString fileuVision;
    QString fileuVision_Path;
    QString fileCube;
    QString lastPath;
    QString cubeVersion;

    bool generate_project_folders;
    int add_thread_state;
    QList<QHierarchy_State*> hierarchy_states;
    QList<QPoint> points[8];

};

#endif // NFWIZARD2_H
