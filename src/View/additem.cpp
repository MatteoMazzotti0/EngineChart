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

void AddItem::on_SpeedRadio_toggled(bool checked)
{
    if(checked){
        // aggiornamento placeholder con fefault values
        ui->MinLine->setPlaceholderText("0");
        ui->MaxLine->setPlaceholderText("220");

        // check per valori non negativi del min
        if(ui->MinLine->text().toInt() < 0)
        {
            ui->MinLine->setText("0");
        }

        // check min oltre il massimo consentito
        if(ui->MinLine->text().toInt() > 99)
        {
            ui->MinLine->setText("549");
        }

        // check max non oltre il limite massimo
        if(ui->MaxLine->text().toInt() > 550)
        {
            ui->MaxLine->setText("550");
        }

        // check che max > min
        if(ui->MinLine->text().toInt() > ui->MaxLine->text().toInt())
        {
            ui->MaxLine->setText(QString::number(ui->MinLine->text().toInt() + 1));
        }

        // set validators per valori di velocità consoni
        QIntValidator *speedMin = new QIntValidator(0, 549, this);
        ui->MinLine->setValidator(speedMin);

        QIntValidator *speedMax = new QIntValidator(ui->MinLine->text().toInt(), 550, this);
        ui->MaxLine->setValidator(speedMax);
    }
}


void AddItem::on_HumRadio_toggled(bool checked)
{
    if(checked){
        ui->MinLine->setPlaceholderText("20");
        ui->MaxLine->setPlaceholderText("80");

        // check per valori non negativi del min
        if(ui->MinLine->text().toInt() < 0)
        {
            ui->MinLine->setText("0");
        }

        // check min oltre il massimo consentito
        if(ui->MinLine->text().toInt() > 99)
        {
            ui->MinLine->setText("99");
        }

        // check max non oltre il limite massimo
        if(ui->MaxLine->text().toInt() > 100)
        {
            ui->MaxLine->setText("100");
        }

        // check che max > min
        if(ui->MinLine->text().toInt() > ui->MaxLine->text().toInt())
        {
            ui->MaxLine->setText(QString::number(ui->MinLine->text().toInt() + 1));
        }

        // set validators per valori di umidità consoni
        QIntValidator *humidityMin = new QIntValidator(0, 99, this);
        ui->MinLine->setValidator(humidityMin);

        QIntValidator *himidityMax = new QIntValidator(ui->MinLine->text().toInt(), 100, this);
        ui->MaxLine->setValidator(himidityMax);
    }
}


void AddItem::on_TempRadio_toggled(bool checked)
{
    if(checked){
        ui->MinLine->setPlaceholderText("-10");
        ui->MaxLine->setPlaceholderText("120");

        // check per min non oltre il minimo consentito
        if(ui->MinLine->text().toInt() < -20)
        {
            ui->MinLine->setText("-20");
        }

        // check min oltre il massimo consentito
        if(ui->MinLine->text().toInt() > 199)
        {
            ui->MinLine->setText("199");
        }

        // check max non oltre il limite massimo
        if(ui->MaxLine->text().toInt() > 200)
        {
            ui->MaxLine->setText("200");
        }

        // check che max > min
        if(ui->MinLine->text().toInt() > ui->MaxLine->text().toInt())
        {
            ui->MaxLine->setText(QString::number(ui->MinLine->text().toInt() + 1));
        }

        // set validators per valori di temperatura consoni (i motori delle auto da F1 possono raggiungere i 200°C)
        QIntValidator *tempMin = new QIntValidator(-20, 199, this);
        ui->MinLine->setValidator(tempMin);

        QIntValidator *tempMax = new QIntValidator(ui->MinLine->text().toInt(), 200, this);
        ui->MaxLine->setValidator(tempMax);
    }
}


void AddItem::on_PressRadio_toggled(bool checked)
{
    if(checked){
        ui->MinLine->setPlaceholderText("10");
        ui->MaxLine->setPlaceholderText("90");

        // check per valori non negativi del min
        if(ui->MinLine->text().toInt() < 0)
        {
            ui->MinLine->setText("0");
        }

        // check min oltre il massimo consentito
        if(ui->MinLine->text().toInt() > 99)
        {
            ui->MinLine->setText("99");
        }

        // check max non oltre il limite massimo
        if(ui->MaxLine->text().toInt() > 100)
        {
            ui->MaxLine->setText("100");
        }

        // check che max > min
        if(ui->MinLine->text().toInt() > ui->MaxLine->text().toInt())
        {
            ui->MaxLine->setText(QString::number(ui->MinLine->text().toInt() + 1));
        }

        // set validators per valori di pressione consoni
        QIntValidator *psiMin = new QIntValidator(0, 99, this);
        ui->MinLine->setValidator(psiMin);

        QIntValidator *psiMax = new QIntValidator(ui->MinLine->text().toInt(), 100, this);
        ui->MaxLine->setValidator(psiMax);
    }
}


void AddItem::on_FuelRadio_toggled(bool checked)
{
    if(checked){
        ui->MinLine->setPlaceholderText("0");
        ui->MaxLine->setPlaceholderText("90");

        // check per valori non negativi del min
        if(ui->MinLine->text().toInt() < 0)
        {
            ui->MinLine->setText("0");
        }

        // check min oltre il massimo consentito
        if(ui->MinLine->text().toInt() > 169)
        {
            ui->MinLine->setText("169");
        }

        // check max non oltre il limite massimo
        if(ui->MaxLine->text().toInt() > 170)
        {
            ui->MaxLine->setText("170");
        }

        // check che max > min
        if(ui->MinLine->text().toInt() > ui->MaxLine->text().toInt())
        {
            ui->MaxLine->setText(QString::number(ui->MinLine->text().toInt() + 1));
        }

        // set validators per valori di capienza consoni
        QIntValidator *tankMin = new QIntValidator(0, 169, this);
        ui->MinLine->setValidator(tankMin);

        QIntValidator *tankMax = new QIntValidator(ui->MinLine->text().toInt(), 170, this);
        ui->MaxLine->setValidator(tankMax);
    }

}

