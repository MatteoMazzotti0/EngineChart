#include "errorpopup.h"
#include "ui_errorpopup.h"

ErrorPopup::ErrorPopup(QString message, QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::ErrorPopup)
{
    ui->setupUi(this);
    ui->label->setText(message);
    this->setWindowTitle(QString::fromStdString("Error"));

    setWindowModality(Qt::ApplicationModal);
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
}

ErrorPopup::~ErrorPopup()
{
    delete ui;
}

void ErrorPopup::on_pushButton_clicked()
{
    close();
}

