#include "mainwindow.h"
#include "../Sensor/abstractsensor.h"
#include "../View/inspectwindow.h"
#include "errorpopup.h"
#include "src/Visitor/concretevisitor.h"
#include "ui_mainwindow.h"
#include <QLineSeries>
#include <QSplitter>
#include <iostream>
using std::string;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("Engine Chart"));
    searchWidget = new SearchAddWidget(this);
    info = new InfoWidget(this);
    chart = new ChartDisplayWidget(this);

    this->setWindowIcon(QIcon(":/Icons/src/Resources/appIcon.png"));

    HSplit = new QSplitter;
    VSplit = new QSplitter;

    HSplit->setChildrenCollapsible(false);
    VSplit->setChildrenCollapsible(false);

    VSplit->setOrientation(Qt::Vertical);
    VSplit->addWidget(info);
    VSplit->addWidget(chart);

    HSplit->addWidget(searchWidget);
    HSplit->addWidget(VSplit);

    HSplit->setHandleWidth(10);
    VSplit->setHandleWidth(10);

    QList<int> sizes;
    sizes << 100 << 330;

    VSplit->setSizes(sizes);

    this->setCentralWidget(HSplit);

    connect(searchWidget, &SearchAddWidget::nameTransfer, this, &MainWindow::displayInfo);
    connect(searchWidget, &SearchAddWidget::requestAdd, this, &MainWindow::onRequestAdd);
    connect(searchWidget, &SearchAddWidget::deleteAllSignal, this, &MainWindow::onDeleteAll);
    connect(searchWidget, &SearchAddWidget::sensorDeleted, this, &MainWindow::onSensorDeleted);
    connect(searchWidget, &SearchAddWidget::focusChanged, this, &MainWindow::onUpdateChart);

    connect(info, &InfoWidget::startSim, this, &MainWindow::onStartSim);
    connect(info, &InfoWidget::inspectSensor, this, &MainWindow ::onInspectSensor);
    connect(info, &InfoWidget::editSensor, this, &MainWindow ::onEditSensor);

    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::onSaveSensors);
    connect(ui->actionLoad, &QAction::triggered, this, &MainWindow::onLoadSensors);

    // resize dello splitter automatico se viene rimpicciolito troppo
    connect(VSplit, &QSplitter::splitterMoved, this, [this](int pos) {
        if (pos < threshold)
        {
            splitterStatus = false;
            std::cout << pos << std::endl;
        }
        else
        {
            splitterStatus = true;
            std::cout << pos << std::endl;
        }
    });
}

Container *MainWindow::storage = new Container();
ConcreteVisitor *MainWindow::visitor = new ConcreteVisitor();

//  ------------------------------
//       AGGIUNTA SENSORI
//  ------------------------------

void MainWindow::onRequestAdd() // creazione finestra additem
{
    AddItem *addWindow = new AddItem();
    addWindow->show();
    connect(addWindow, &AddItem::dataAvailable, this, &MainWindow::onDataAvailable);
}

void MainWindow::onDataAvailable(AbstractSensor *sensor) // aggiunta del bottone corrispondente al sensore
{
    if (MainWindow::storage->add(sensor))
    {
        searchWidget->addButton(sensor, visitor);
    }

    else
    {
        ErrorPopup *Dialog = new ErrorPopup("Nome già in uso", this);
        Dialog->show();
    }
}

//  ------------------------------
//       ISPEZIONE SENSORI
//  ------------------------------

void MainWindow::onInspectSensor()
{
    if (searchWidget->getFocus() != nullptr)
    {
        inspectWnd = new InspectWindow(searchWidget->getFocus());
        connect(inspectWnd, &InspectWindow::newValue, this, &MainWindow::onNewValue);
        connect(inspectWnd, &InspectWindow::requestDeleteVal, this, &MainWindow::onRequestDeleteVal);
        connect(inspectWnd, &InspectWindow::updateChart, this, &MainWindow::onUpdateChart);
        connect(inspectWnd, &InspectWindow::deleteAllValues, this, &MainWindow::onDeleteAllValues);
        inspectWnd->show();
    }
}

//  ------------------------------
//       MODIFICA SENSORI
//  ------------------------------

void MainWindow::onEditSensor() // creazione finestra di edit
{
    if (searchWidget->getFocus() != nullptr)
    {
        AbstractSensor* sensor = searchWidget->getFocus();
        string oldSensorName = sensor->getname();

        editItem = new EditItem(sensor);
        editItem->show();

        connect(editItem, &EditItem::checkSensor, this, &MainWindow::onCheckSensor);
        connect(this, &MainWindow::editAvailable, editItem, &EditItem::onEditAvailable);
        connect(editItem, &EditItem::refresh, this, &MainWindow::onRefresh);
    }
}

void MainWindow::onCheckSensor() // check nome sensore non doppio o vuoto nell'editing
{
    string newName = editItem->getNewName();

    if(MainWindow::storage->check(newName, oldSensorName))
    {
        emit editAvailable();
    }
    else
    {
        ErrorPopup *errorPopup = new ErrorPopup("Nome già in uso");
        errorPopup->show();
    }
}

//  ------------------------------
//       GRAFICO E SIMULAZIONE
//  ------------------------------

void MainWindow::onStartSim() // avvia simulazione sul grafico
{

    if (searchWidget->getFocus() != nullptr)
    {
        searchWidget->getFocus()->simulation();
        chart->displayValues(searchWidget->getFocus());
    }
}

void MainWindow::onUpdateChart()
{

    if (searchWidget->getFocus() != nullptr)
    {
        chart->displayValues(searchWidget->getFocus());
    }
}

//  -----------------------------------------
//  AGGIUNTA E RIMOZIONE VALORI DI UN SENSORE
//  -----------------------------------------

void MainWindow::onNewValue() // creazione finestra per input
{
    inputVal = new InputDialog();
    connect(inputVal, &InputDialog::addValToSensor, this, &MainWindow::onAddValToSensor);
    inputVal->show();
}

void MainWindow::onAddValToSensor(const double& time, const double& val) // aggiunta valore
{
    if (searchWidget->getFocus() != nullptr)
    {
        if (searchWidget->getFocus()->insertNewVal(time, val))
        {
            inspectWnd->refresh(searchWidget->getFocus());
        }
        else
        {
            ErrorPopup *errorPopup = new ErrorPopup("Esiste già un valore in quell'istante");
            errorPopup->show();
        }
    }
}

void MainWindow::onRequestDeleteVal(const unsigned int& time, const unsigned int& val) // rimozione valore
{
    if (searchWidget->getFocus() != nullptr)
    {
        searchWidget->getFocus()->deleteVal(time, val);
    }
}

void MainWindow::onDeleteAllValues() // rimozione di tutti i valori
{
    searchWidget->getFocus()->deleteAllValues();
    inspectWnd->refresh(searchWidget->getFocus());
}

//  ------------------------------
//  DISPLAY INFO SENSORE SU WIDGET
//  ------------------------------

void MainWindow::displayInfo(AbstractSensor *sensor) // mostraggio info del sensore
{
    if (!sensor)
    {
        qDebug() << "Error: sensor is nullptr";
        return;
    }

    info->setName(QString::fromStdString(sensor->getname()));
    sensor->accept(visitor);
    info->setType(QString::fromStdString(visitor->getType()));
    info->setDesc(QString::fromStdString(sensor->getdesc()));

    info->clearLayout();

    if (splitterStatus == false)
    {
        QList<int> newSizes;
        newSizes << 100 << 330;
        VSplit->setSizes(newSizes);
    }
}

AbstractSensor *MainWindow::getSensor(const string &name)
{
    return storage->search(name);
}

//  ------------------------------
//    SALVATAGGIO E CARICAMENTO
//  ------------------------------

AbstractSensor *MainWindow::createSensor(const std::string &type, const std::string &name, const std::string &description)
{
    if (type == "Humidity")
    {
        return new HumiditySensor(name, description);
    }

    else if (type == "Temperature")
    {
        return new TempSensor(name, description);
    }

    else if (type == "Fuel Level")
    {
        return new FuelLevel(name, description);
    }

    else if (type == "Oil Pressure")
    {
        return new OilPressure(name, description);
    }

    else if (type == "Vehicle Speed") {
        return new VehicleSpeed(name, description);
    }

    return nullptr;
}

QJsonObject MainWindow::sensorToJson(AbstractSensor *sensor)
{
    QJsonObject json;
    sensor->accept(visitor);
    json["type"] = QString::fromStdString(visitor->getType());
    json["name"] = QString::fromStdString(sensor->getname());
    json["description"] = QString::fromStdString(sensor->getdesc());

    QJsonArray valuesArray;
    for (int i = 0; i < sensor->countValues(); ++i)
    {
        auto value = sensor->getValueAt(i);
        QJsonObject valueObject;
        valueObject["time"] = static_cast<double>(value.time());
        valueObject["value"] = static_cast<double>(value.value());
        valuesArray.append(valueObject);
    }

    json["values"] = valuesArray;
    return json;
}

AbstractSensor *MainWindow::jsonToSensor(const QJsonObject &json)
{
    AbstractSensor *sensor = createSensor(json["type"].toString().toStdString(), json["name"].toString().toStdString(),
                                          json["description"].toString().toStdString());

    if (!sensor)
    {
        return nullptr;
    }

    QJsonArray valuesArray = json["values"].toArray();
    for (const auto &value : valuesArray)
    {
        QJsonObject valueObject = value.toObject();
        unsigned int time = static_cast<unsigned int>(valueObject["time"].toDouble());
        unsigned int val = static_cast<unsigned int>(valueObject["value"].toDouble());
        sensor->insertNewVal(time, val);
    }

    return sensor;
}

void MainWindow::saveSensors(const std::vector<AbstractSensor *> &sensors, const QString &filename)
{
    QJsonArray jsonArray;
    for (const auto &sensor : sensors)
    {
        jsonArray.append(sensorToJson(sensor));
    }

    QJsonDocument doc(jsonArray);
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly))
    {
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
    }
}

std::vector<AbstractSensor *> MainWindow::loadSensors(const QString &filename)
{

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
    {
        return {};
    }

    searchWidget->deleteAllClicked();

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonArray jsonArray = doc.array();

    std::vector<AbstractSensor *> sensors;
    for (const auto &jsonValue : jsonArray)
    {
        AbstractSensor *sensor = jsonToSensor(jsonValue.toObject());
        if (sensor)
        {
            sensors.push_back(sensor);
            searchWidget->addButton(sensor, visitor);
        }
    }

    return sensors;
}

void MainWindow::onSaveSensors()
{
    QString fileName =
        QFileDialog::getSaveFileName(this, tr("Save Sensors"), "", tr("JSON Files (*.json);;All Files (*)"));
    if (fileName.isEmpty())
        return;

    saveSensors(Container::getSensors(), fileName);
    QMessageBox::information(this, tr("Save Sensors"), tr("Sensors saved successfully."));
}

void MainWindow::onLoadSensors()
{
    QString fileName =
        QFileDialog::getOpenFileName(this, tr("Load Sensors"), "", tr("JSON Files (*.json);;All Files (*)"));
    if (fileName.isEmpty())
        return;

    std::vector<AbstractSensor *> loadedSensors = loadSensors(fileName);
    if (loadedSensors.empty())
    {
        QMessageBox::warning(this, tr("Load Sensors"), tr("No sensors were loaded or file is invalid."));
        return;
    }

    Container::setSensors(loadedSensors);
    QMessageBox::information(this, tr("Load Sensors"), tr("Sensors loaded successfully."));
}

//  ------------------------------
//        AGGIORNAMENTO UI
//  ------------------------------

void MainWindow::onDeleteAll() // delete tutti i bottoni
{
    searchWidget->setFocus(nullptr);
    storage->deleteAll();
    info->clearText();
    info->clearLayout();
    chart->resetChart();
}

void MainWindow::onSensorDeleted() // delete bottone singolo
{
    searchWidget->setFocus(nullptr);
    info->clearText();
    info->clearLayout();
}

void MainWindow::onRefresh(const AbstractSensor *sensor, const string& oldName) // aggiornamento nome post editing
{
    info->setName(QString::fromStdString(sensor->getname()));
    info->setDesc(QString::fromStdString(sensor->getdesc()));
    searchWidget->editButton(sensor->getname(), oldName);
}

void MainWindow::onSetFocus(AbstractSensor *sensorFocus)
{
    searchWidget->setFocus(sensorFocus);
}

MainWindow::~MainWindow()
{
    delete ui;
}
