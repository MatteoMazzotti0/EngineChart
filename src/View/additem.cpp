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
    QRegularExpression regExp("[\\p{L}0-9]*");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regExp, this);
    ui->NameLine->setValidator(validator);
    ui->NameLine->setMaxLength(25);
}

AddItem::~AddItem()
{
    delete ui;
}

void AddItem::on_AddButtonDiag_clicked()
{
    // check nome sensore non vuoto (gli spazi vengono rimossi)
    QString sensorName = ui->NameLine->text().trimmed();

    if (sensorName.isEmpty())
    {
        // finestra messaggio d'errore
        ErrorPopup *errorPopup = new ErrorPopup("The sensor's name cannot be empty", this);
        errorPopup->show();
    }

    else
    {
        if (ui->HumRadio->isChecked())
        {
            HumiditySensor *newsensor =
                new HumiditySensor(ui->NameLine->text().toStdString(), ui->DescLine->text().toStdString());
            emit dataAvailable(newsensor);
            close();
        }
        else if (ui->TempRadio->isChecked())
        {
            TempSensor *newsensor =
                new TempSensor(ui->NameLine->text().toStdString(), ui->DescLine->text().toStdString());
            emit dataAvailable(newsensor);
            close();
        }
        else if (ui->PressRadio->isChecked())
        {
            OilPressure *newsensor =
                new OilPressure(ui->NameLine->text().toStdString(), ui->DescLine->text().toStdString());
            emit dataAvailable(newsensor);
            close();
        }
        else if (ui->FuelRadio->isChecked())
        {
            FuelLevel *newsensor =
                new FuelLevel(ui->NameLine->text().toStdString(), ui->DescLine->text().toStdString());
            emit dataAvailable(newsensor);
            close();
        }
        else if (ui->SpeedRadio->isChecked())
        {
            VehicleSpeed *newsensor =
                new VehicleSpeed(ui->NameLine->text().toStdString(), ui->DescLine->text().toStdString());
            emit dataAvailable(newsensor);
            close();
        }

    }
}
