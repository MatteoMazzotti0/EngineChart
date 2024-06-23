#include "chartdisplaywidget.h"
#include "ui_chartdisplaywidget.h"
#include <QLineSeries>
ChartDisplayWidget::ChartDisplayWidget(QWidget *parent) : QWidget(parent), ui(new Ui::ChartDisplayWidget)
{
    ui->setupUi(this);
    ui->frame->setFrameStyle(QFrame::Box);
    chartView = new QChartView();
    this->displayValues(nullptr);
    ui->horizontalLayout_2->addWidget(chartView);
}

void ChartDisplayWidget::displayValues(const AbstractSensor *target)
{
    //Reset grafico
    chartView->chart()->removeAllSeries();

    if(!chartView->chart()->axes().empty())
    {
        chartView->chart()->removeAxis(chartView->chart()->axes().takeFirst());
    }
    if(!chartView->chart()->axes().empty())
    {
        chartView->chart()->removeAxis(chartView->chart()->axes().takeLast());

    }
    //Titolo e rimozione legenda
    chartView->chart()->legend()->hide();
    chartView->chart()->setTitle("Sensor values");

    //Setting dei valori
    QLineSeries *values = new QLineSeries();
    if(target!=nullptr)
    {
        for (int i = 0; i < target->countValues(); i++)
        {
            values->append(target->getValueAt(i).time(), target->getValueAt(i).value());
        }
    }

    //Creazione assi
    auto axisX = new QValueAxis;
    axisX->setTickCount(10);
    chartView->chart()->addAxis(axisX, Qt::AlignBottom);
    chartView->chart()->addSeries(values);
    auto axisY = new QValueAxis;
    axisY->setLinePenColor(values->pen().color());
    chartView->chart()->addAxis(axisY, Qt::AlignLeft);
    values->attachAxis(axisX);
    values->attachAxis(axisY);
}

void ChartDisplayWidget::resetChart()
{
    QLineSeries *values = new QLineSeries();

    //Reset grafico
    chartView->chart()->removeAllSeries();
    if(!chartView->chart()->axes().empty())
    {
        chartView->chart()->removeAxis(chartView->chart()->axes().takeFirst());
    }
    if(!chartView->chart()->axes().empty())
    {
        chartView->chart()->removeAxis(chartView->chart()->axes().takeLast());

    }

    //Titolo e rimozione legenda
    chartView->chart()->legend()->hide();
    chartView->chart()->setTitle("Sensor values");

    //Creazione assi
    auto axisX = new QValueAxis;
    axisX->setTickCount(10);
    chartView->chart()->addAxis(axisX, Qt::AlignBottom);
    chartView->chart()->addSeries(values);
    auto axisY = new QValueAxis;
    axisY->setLinePenColor(values->pen().color());
    chartView->chart()->addAxis(axisY, Qt::AlignLeft);
    values->attachAxis(axisX);
    values->attachAxis(axisY);
}
ChartDisplayWidget::~ChartDisplayWidget()
{
    delete ui;
}
