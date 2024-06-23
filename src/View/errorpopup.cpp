#include "errorpopup.h"
#include "ui_errorpopup.h"

ErrorPopup::ErrorPopup(QString message, QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::ErrorPopup)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("Error"));
    ui->label->setText(message);
    setWindowModality(Qt::ApplicationModal);
}

ErrorPopup::~ErrorPopup()
{
    delete ui;
}

void ErrorPopup::on_pushButton_clicked()
{
    close();
}

