#include "inputdialog.h"
#include "ui_inputdialog.h"

InputDialog::InputDialog(QWidget *parent) : QDialog(parent), ui(new Ui::InputDialog)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/Icons/src/Resources/appIcon.png"));
    this->setWindowTitle(QString::fromStdString("Insert value"));

    ui->timeBox->setMinimum(0);
    ui->timeBox->setSingleStep(1);
    ui->timeBox->setValue(0);

    ui->valueBox->setMinimum(-100);
    ui->valueBox->setMaximum(100);
    ui->valueBox->setSingleStep(1);
    ui->valueBox->setValue(0);

    connect(ui->btn_ok, &QPushButton::clicked, this, [this]() {
        emit addValToSensor(ui->timeBox->value(), ui->valueBox->value());
        close();
    });
}

InputDialog::~InputDialog()
{
    delete ui;
}

double InputDialog::getTime() const
{
    return ui->timeBox->value();
}

double InputDialog::getValue() const
{
    return ui->valueBox->value();
}

void InputDialog::on_btn_cancel_clicked()
{
    close();
}
