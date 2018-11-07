#ifndef DIALOGCONFIGURATIONHELP_H
#define DIALOGCONFIGURATIONHELP_H

#include <QDialog>
#include <QtCore>

namespace Ui {
class DialogConfigurationHelp;
}

class DialogConfigurationHelp : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConfigurationHelp(QWidget *parent = 0);
    ~DialogConfigurationHelp();
    void setHelpImage(const QString &imageName);
    void setHelpText(const QString &text);

private:
    Ui::DialogConfigurationHelp *ui;
};

#endif // DIALOGCONFIGURATIONHELP_H
