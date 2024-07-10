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
    QRegularExpression regExpName("[\\p{L}0-9]*");
    QRegularExpressionValidator *validatorName = new QRegularExpressionValidator(regExpName, this);
    QRegularExpression regExpMinMax("^-?[0-9]*$");
    QRegularExpressionValidator *validatorMinMax = new QRegularExpressionValidator(regExpMinMax, this);
    ui->NameLine->setValidator(validatorName);
    ui->NameLine->setMaxLength(25);
    ui->MinLine->setValidator(validatorMinMax);
    ui->MaxLine->setValidator(validatorMinMax);
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

void AddItem::on_SpeedRadio_toggled(bool checked)
{
    if(checked){
        ui->MinLine->setPlaceholderText("0");
        ui->MaxLine->setPlaceholderText("220");
    }
}


void AddItem::on_HumRadio_toggled(bool checked)
{
    if(checked){
        ui->MinLine->setPlaceholderText("20");
        ui->MaxLine->setPlaceholderText("80");
    }
}


void AddItem::on_TempRadio_toggled(bool checked)
{
    if(checked){
        ui->MinLine->setPlaceholderText("-10");
        ui->MaxLine->setPlaceholderText("120");
    }
}


void AddItem::on_PressRadio_toggled(bool checked)
{
    if(checked){
        ui->MinLine->setPlaceholderText("10");
        ui->MaxLine->setPlaceholderText("90");
    }
}


void AddItem::on_FuelRadio_toggled(bool checked)
{
    if(checked){
        ui->MinLine->setPlaceholderText("0");
        ui->MaxLine->setPlaceholderText("90");
    }
}

