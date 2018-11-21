#ifndef NFWIZARD2_H
#define NFWIZARD2_H

#include <QMainWindow>
#include <QtCore>
#include "DialogConfigurationHelp.h"

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

    void on_pb_configure_thread_clicked();

    void on_pb_add_thread_clicked();

private:
    void generateProjectFileTree();
    void generateTemplates(const QString& projectRootRef);
    void processInterrupFile();
    void processMainFiles();
    void processXmlFiles();
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


private:
    Ui::NFWizard2 *ui;
    DialogConfigurationHelp *dialogConfigHelp;

    QString fileuVision;
    QString fileuVision_Path;
    QString fileCube;
    QString lastPath;
    QString cubeVersion;

    bool generate_project_folders;
};

#endif // NFWIZARD2_H
