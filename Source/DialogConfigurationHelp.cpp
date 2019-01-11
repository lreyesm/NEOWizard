#include "DialogConfigurationHelp.h"
#include "ui_DialogConfigurationHelp.h"

DialogConfigurationHelp::DialogConfigurationHelp(QWidget *parent) :   //Clase encargada de generar ventanas Dialagos
    QDialog(parent),
    ui(new Ui::DialogConfigurationHelp)
{
    ui->setupUi(this);
    ui->label_HelpTextHolder->setStyleSheet(QStringLiteral("font: 75 24pt \"Segoe UI\"; color: rgb(8, 113, 104"));
}

DialogConfigurationHelp::~DialogConfigurationHelp()
{
    delete ui;
}

void DialogConfigurationHelp::setHelpImage(const QString& imageName)
{
    if (!QFile::exists(imageName)) {
        qDebug() << "help image " << imageName <<" not found";
        return;
    }
    ui->label_HelpContentHolder->setPixmap(QPixmap(imageName));
}

void DialogConfigurationHelp::setHelpText(const QString& text)
{
    ui->label_HelpTextHolder->setText(text);


}
