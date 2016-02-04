#ifndef NFWIZARD2_H
#define NFWIZARD2_H

#include <QWidget>
#include <QtCore>
#include "FileParser.h"
#include "XMLKeilModify.h"

namespace Ui {
class NFWizard2;
}

class NFWizard2 : public QWidget
{
    Q_OBJECT

public:
    explicit NFWizard2(QWidget *parent = 0);
    ~NFWizard2();

private slots:
    void on_pushButton_uVisionBrowse_clicked();

    void on_pushButton_CubeBrowse_clicked();

    void on_pushButton_Generate_clicked();

    void on_cubeMainFileProcessed();

private:
    void generateProjectFileTree();
    void processMainFiles();
    void processXmlFiles();
private:
    Ui::NFWizard2 *ui;

    QString fileuVision;
    QString fileCube;
    QDir directoryuVision;
    QDir directoryCube;

    FileParserNamespace::FileParser fileParser;
    QFile fileHandler;

};

#endif // NFWIZARD2_H
