#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "../Container/container.h"
#include "additem.h"
#include "chartdisplaywidget.h"
#include "infowidget.h"
#include "inputdialog.h"
#include "inspectwindow.h"
#include "searchaddwidget.h"
#include "src/View/edititem.h"
#include "src/Visitor/concretevisitor.h"
#include <QMainWindow>

class SearchAddWidget;
QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    AbstractSensor *createSensor(const std::string &, const std::string &, const std::string &);
    QJsonObject sensorToJson(AbstractSensor *);
    AbstractSensor *jsonToSensor(const QJsonObject &);
    void saveSensors(const std::vector<AbstractSensor *> &, const QString &);
    std::vector<AbstractSensor *> loadSensors(const QString &);
    AbstractSensor *getSensor(const std::string &);
    ~MainWindow();

  private slots:
    void onSetFocus(AbstractSensor *);
    void displayInfo(AbstractSensor *);
    void onRequestAdd();
    void onDeleteAll();
    void onSensorDeleted();
    void onStartSim();
    void onInspectSensor();
    void onDataAvailable(AbstractSensor *);
    void onNewValue();
    void onAddValToSensor(const double &, const double &);
    void onRequestDeleteVal(const unsigned int &, const unsigned int &);
    void onUpdateChart();
    void onEditSensor();
    void onCheckSensor();
    void onRefresh(const AbstractSensor *, const std::string &);
    void onDeleteAllValues();

    void onSaveSensors();
    void onLoadSensors();

  signals:
    void editAvailable();

  private:
    Ui::MainWindow *ui;
    static Container *storage;
    SearchAddWidget *searchWidget;
    InfoWidget *info;
    ChartDisplayWidget *chart;
    InputDialog *inputVal;
    EditItem *editItem;
    InspectWindow *inspectWnd;
    QSplitter *HSplit;
    QSplitter *VSplit;
    bool splitterStatus = false;
    static ConcreteVisitor *visitor;
    string oldSensorName; // check per edit desc senza cambiare nome al sensore

    int threshold = 110; // soglia per il rezise automatico dello splitter
};

#endif // MAINWINDOW_H
