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

private:
    void generateProjectFileTree();
    void generateTemplates(const QString& projectRootRef);
    void processInterrupFile();
    void processMainFiles();
    void processXmlFiles();
    void processHalConfigFile();
    void saveSettings();
    void loadSettings();
private:
    Ui::NFWizard2 *ui;
    DialogConfigurationHelp *dialogConfigHelp;

    QString fileuVision;
    QString fileuVision_Path;
    QString fileCube;
    QString lastPath;
};

#endif // NFWIZARD2_H
