#include "concretevisitor.h"
#include "QIcon"
#include "qboxlayout.h"
#include "qlabel.h"
#include "qlineedit.h"

ConcreteVisitor::ConcreteVisitor(){}

ConcreteVisitor::~ConcreteVisitor(){}

void ConcreteVisitor::visit([[maybe_unused]]const HumiditySensor *sensor)
{
    this->type = "Humidity";
    setUnitMeasure(sensor);
}

void ConcreteVisitor::visit([[maybe_unused]] const TempSensor *sensor)
{
    this->type = "Temperature";
    setUnitMeasure(sensor);
}

void ConcreteVisitor::visit([[maybe_unused]] const OilPressure *sensor)
{
    this->type = "Oil Pressure";
    setUnitMeasure(sensor);
}

void ConcreteVisitor::visit([[maybe_unused]] const FuelLevel *sensor)
{
    this->type = "Fuel Level";
    setUnitMeasure(sensor);
}

void ConcreteVisitor::visit([[maybe_unused]] const VehicleSpeed *sensor)
{
    this->type = "Vehicle Speed";
    setUnitMeasure(sensor);
}


void ConcreteVisitor::setButtonFor(const TempSensor *sensor)
{
    QPushButton *newButton = new QPushButton();
    newButton->setObjectName(QString::fromStdString(sensor->getname()));
    newButton->setFixedSize(QSize(225, 40));
    newButton->setIcon(QIcon(":/Icons/src/Resources/temperature.png"));
    newButton->setStyleSheet("text-align:left;");
    newButton->setLayout(new QGridLayout);

    QLabel *textLabel = new QLabel(QString::fromStdString(sensor->getname()));
    textLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    newButton->layout()->addWidget(textLabel);

    this->button = newButton;
}

void ConcreteVisitor::setButtonFor(const HumiditySensor *sensor)
{
    QPushButton *newButton = new QPushButton();
    newButton->setObjectName(QString::fromStdString(sensor->getname()));
    newButton->setFixedSize(QSize(225, 40));
    newButton->setIcon(QIcon(":/Icons/src/Resources/humidity.png"));
    newButton->setStyleSheet("text-align:left;");
    newButton->setLayout(new QGridLayout);

    QLabel *textLabel = new QLabel(QString::fromStdString(sensor->getname()));
    textLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    newButton->layout()->addWidget(textLabel);
    this->button = newButton;
}

void ConcreteVisitor::setButtonFor(const OilPressure *sensor)
{
    QPushButton *newButton = new QPushButton();
    newButton->setObjectName(QString::fromStdString(sensor->getname()));
    newButton->setFixedSize(QSize(225, 40));
    newButton->setIcon(QIcon(":/Icons/src/Resources/oilpressure.png"));
    newButton->setStyleSheet("text-align:left;");
    newButton->setLayout(new QGridLayout);

    QLabel *textLabel = new QLabel(QString::fromStdString(sensor->getname()));
    textLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    newButton->layout()->addWidget(textLabel);
    this->button = newButton;
}

void ConcreteVisitor::setButtonFor(const FuelLevel *sensor)
{
    QPushButton *newButton = new QPushButton();
    newButton->setObjectName(QString::fromStdString(sensor->getname()));
    newButton->setFixedSize(QSize(225, 40));
    newButton->setIcon(QIcon(":/Icons/src/Resources/fuel.png"));
    newButton->setStyleSheet("text-align:left;");
    newButton->setLayout(new QGridLayout);

    QLabel *textLabel = new QLabel(QString::fromStdString(sensor->getname()));
    textLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    newButton->layout()->addWidget(textLabel);
    this->button = newButton;
}

void ConcreteVisitor::setButtonFor(const VehicleSpeed *sensor)
{
    QPushButton *newButton = new QPushButton();
    newButton->setObjectName(QString::fromStdString(sensor->getname()));
    newButton->setFixedSize(QSize(225, 40));
    newButton->setIcon(QIcon(":/Icons/src/Resources/speed.png"));
    newButton->setStyleSheet("text-align:left;");
    newButton->setLayout(new QGridLayout);

    QLabel *textLabel = new QLabel(QString::fromStdString(sensor->getname()));
    textLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    newButton->layout()->addWidget(textLabel);

    this->button = newButton;
}

void ConcreteVisitor::setUnitMeasure([[maybe_unused]]const HumiditySensor *sensor)
{
    this->measureUnit = "%";
}

void ConcreteVisitor::setUnitMeasure([[maybe_unused]]const TempSensor *sensor)
{
    this->measureUnit = "°C";
}

void ConcreteVisitor::setUnitMeasure([[maybe_unused]]const OilPressure *sensor)
{
    this->measureUnit = "bar";
}

void ConcreteVisitor::setUnitMeasure([[maybe_unused]]const FuelLevel *sensor)
{
    this->measureUnit = "L";
}

void ConcreteVisitor::setUnitMeasure([[maybe_unused]]const VehicleSpeed *sensor)
{
    this->measureUnit = "Km/h";
}


QPushButton *ConcreteVisitor::getButton() const
{
    return this->button;
}

string ConcreteVisitor::getType() const
{
    return this->type;
}

string ConcreteVisitor::getUnitOfMeasure() const
{
    return this->measureUnit;
}
