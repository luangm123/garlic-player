#include "configdialog.h"

ConfigDialog::ConfigDialog(QWidget *parent, TConfiguration *Config) :  QDialog(parent), ui(new Ui::ConfigDialog)
{
    ui->setupUi(this);
    MyConfiguration = Config;
    ui->lineEditPlayerName->setText(MyConfiguration->getPlayerName());
    ui->lineEditContentUrl->setText(MyConfiguration->getIndexUri());
#if !defined  Q_OS_ANDROID
    // cause in Android it shows fullscreen and not as dialog
    setWindowFlags(Qt::WindowStaysOnTopHint);
#endif
}

ConfigDialog::~ConfigDialog()
{
    delete ui;
}

void ConfigDialog::accept()
{
    MyConfiguration->setPlayerName(ui->lineEditPlayerName->text());
    MyConfiguration->determineIndexUri(ui->lineEditContentUrl->text());
    QDialog::accept();
}
