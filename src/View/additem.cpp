#include "additem.h"
#include "../Sensor/fuellevel.h"
#include "../Sensor/humidity.h"
#include "../Sensor/oilpressure.h"
#include "../Sensor/temperature.h"
#include "../Sensor/speed.h"
#include "errorpopup.h"
#include "ui_additem.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

AddItem::AddItem(QWidget *parent) : QDialog(parent), ui(new Ui::AddItem)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/Icons/src/Resources/appIcon.png"));
    this->setWindowTitle(QString::fromStdString("Add new sensor"));
    ui->NameLine->setFocus();

    // validator caratteri nome
    QRegularExpression regExpName("[\\p{L}0-9]*");
    QRegularExpressionValidator *validatorName = new QRegularExpressionValidator(regExpName, this);

    // validator caratteri min
    QRegularExpression regExpMin("^-?[0-9]*$");
    QRegularExpressionValidator *validatorMin = new QRegularExpressionValidator(regExpMin, this);

    // validator caratteri max
    QRegularExpression regExpMax("^[0-9]*$");
    QRegularExpressionValidator *validatorMax = new QRegularExpressionValidator(regExpMax, this);

    ui->NameLine->setValidator(validatorName);
    ui->NameLine->setMaxLength(25);
    ui->MinLine->setValidator(validatorMin);
    ui->MinLine->setMaxLength(3);
    ui->MaxLine->setValidator(validatorMax);
    ui->MaxLine->setMaxLength(3);

}

AddItem::~AddItem()
{
    delete ui;
}

void AddItem::on_AddButtonDiag_clicked()
{
    // check nome sensore non vuoto (gli spazi vengono rimossi)
    QString sensorName = ui->NameLine->text().trimmed();
    QString sensorMin = ui->MinLine->text().trimmed();
    QString sensorMax = ui->MaxLine->text().trimmed();

    if (sensorName.isEmpty())
    {
        // finestra messaggio d'errore
        ErrorPopup *errorPopup = new ErrorPopup("The sensor's name cannot be empty", this);
        errorPopup->show();
    }

    else
    {
        // mette valore di default in caso min e max vuoti
        if(sensorMin.isEmpty())
        {
            sensorMin = ui->MinLine->placeholderText();
        }

        if(sensorMax.isEmpty())
        {
            sensorMax = ui->MaxLine->placeholderText();
        }

        if (ui->HumRadio->isChecked())
        {
            HumiditySensor *newsensor =
                new HumiditySensor(ui->NameLine->text().toStdString(), ui->DescLine->text().toStdString(), sensorMin.toInt(), sensorMax.toInt());
            emit dataAvailable(newsensor);
            close();
        }
        else if (ui->TempRadio->isChecked())
        {
            TempSensor *newsensor =
                new TempSensor(ui->NameLine->text().toStdString(), ui->DescLine->text().toStdString(), sensorMin.toInt(), sensorMax.toInt());
            emit dataAvailable(newsensor);
            close();
        }
        else if (ui->PressRadio->isChecked())
        {
            OilPressure *newsensor =
                new OilPressure(ui->NameLine->text().toStdString(), ui->DescLine->text().toStdString(), sensorMin.toInt(), sensorMax.toInt());
            emit dataAvailable(newsensor);
            close();
        }
        else if (ui->FuelRadio->isChecked())
        {
            FuelLevel *newsensor =
                new FuelLevel(ui->NameLine->text().toStdString(), ui->DescLine->text().toStdString(), sensorMin.toInt(), sensorMax.toInt());
            emit dataAvailable(newsensor);
            close();
        }
        else if (ui->SpeedRadio->isChecked())
        {
            VehicleSpeed *newsensor =
                new VehicleSpeed(ui->NameLine->text().toStdString(), ui->DescLine->text().toStdString(), sensorMin.toInt(), sensorMax.toInt());
            emit dataAvailable(newsensor);
            close();
        }

    }
}

void AddItem::adjustValues(int minRange, int maxRange)
{
    disconnect(ui->MinLine, &QLineEdit::textChanged, this, nullptr);
    disconnect(ui->MaxLine, &QLineEdit::textChanged, this, nullptr);

    int minVal = ui->MinLine->text().toInt();
    int maxVal = ui->MaxLine->text().toInt();

    // check minVal nei limiti
    if (minVal < minRange)
    {
        minVal = minRange;
        ui->MinLine->setText(QString::number(minVal));
    }
    else if (minVal > maxRange - 1)
    {
        minVal = maxRange - 1;
        ui->MinLine->setText(QString::number(minVal));
    }

    // check maxVal nei limiti
    if (maxVal > maxRange)
    {
        maxVal = maxRange;
        ui->MaxLine->setText(QString::number(maxVal));
    }

    // check maxVal > minVal
    if (!ui->MaxLine->text().isEmpty() && maxVal <= minVal)
    {
        maxVal = minVal + 1;
        ui->MaxLine->setText(QString::number(maxVal));
    }
    // update validator
    QIntValidator *maxValidator = new QIntValidator(minVal, maxRange, this);
    ui->MaxLine->setValidator(maxValidator);

    connect(ui->MinLine, &QLineEdit::textChanged, this, [=] { adjustValues(minRange, maxRange); });
    connect(ui->MaxLine, &QLineEdit::textChanged, this, [=] { adjustValues(minRange, maxRange); });

}

void AddItem::setValueRange(int minRange, int maxRange)
{
    // imposta validators
    QIntValidator *minValidator = new QIntValidator(minRange, maxRange - 1, this);
    ui->MinLine->setValidator(minValidator);

    QIntValidator *maxValidator = new QIntValidator(minRange, maxRange, this);
    ui->MaxLine->setValidator(maxValidator);

    // check min e max limiti consentiti
    adjustValues(minRange, maxRange);

    connect(ui->MinLine, &QLineEdit::textChanged, this, [=] { adjustValues(minRange, maxRange); });
    connect(ui->MaxLine, &QLineEdit::textChanged, this, [=] { adjustValues(minRange, maxRange); });
}

void AddItem::on_SpeedRadio_toggled(bool checked)
{
    if(checked){
        // imposta placeholders
        ui->MinLine->setPlaceholderText("0");
        ui->MaxLine->setPlaceholderText("220");
        setValueRange(0, 550);
    }
}


void AddItem::on_HumRadio_toggled(bool checked)
{
    if(checked){
        ui->MinLine->setPlaceholderText("20");
        ui->MaxLine->setPlaceholderText("80");
        setValueRange(0, 100);
    }
}


void AddItem::on_TempRadio_toggled(bool checked)
{
    if(checked){
        ui->MinLine->setPlaceholderText("0");
        ui->MaxLine->setPlaceholderText("120");
        setValueRange(-30, 200);
    }
}


void AddItem::on_PressRadio_toggled(bool checked)
{
    if(checked){
        ui->MinLine->setPlaceholderText("10");
        ui->MaxLine->setPlaceholderText("90");
        setValueRange(0, 100);
    }
}


void AddItem::on_FuelRadio_toggled(bool checked)
{
    if(checked){
        ui->MinLine->setPlaceholderText("0");
        ui->MaxLine->setPlaceholderText("90");
        setValueRange(0, 170);
    }

}

