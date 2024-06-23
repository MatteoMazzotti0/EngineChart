#ifndef CHARTDISPLAYWIDGET_H
#define CHARTDISPLAYWIDGET_H

#include <QWidget>
#include <QtCharts>
#include <QChartView>
#include"../Sensor/abstractsensor.h"

namespace Ui {
class ChartDisplayWidget;
}

class ChartDisplayWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChartDisplayWidget(QWidget *parent = nullptr);
    void displayValues(const AbstractSensor*);
    void resetChart();
    ~ChartDisplayWidget();
private:
    Ui::ChartDisplayWidget *ui;
    QChartView* chartView;

};

#endif // CHARTDISPLAYWIDGET_H
