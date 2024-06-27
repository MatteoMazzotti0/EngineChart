#include "chartdisplaywidget.h"
#include "src/Visitor/concretevisitor.h"
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
    // rimozione degli assi esistenti + reset grafico
    chartView->chart()->removeAllSeries();
    while (!chartView->chart()->axes().isEmpty())
    {
        chartView->chart()->removeAxis(chartView->chart()->axes().takeFirst());
    }

    chartView->chart()->legend()->hide();
    chartView->chart()->setTitle("Sensor values");

    ConcreteVisitor *visitor = new ConcreteVisitor();

    if (target != nullptr)
    {
        QLineSeries *series = new QLineSeries();

        // visita sensore per ottenere unità di misura
        target->accept(visitor);
        QString unitOfMeasure = QString::fromStdString(visitor->getUnitOfMeasure());

        for (int i = 0; i < target->countValues(); i++)
        {
            series->append(target->getValueAt(i).time(), target->getValueAt(i).value());
        }

        // asse X
        auto axisX = new QValueAxis;
        axisX->setTickCount(10);
        axisX->setTitleText("(s)");
        chartView->chart()->addAxis(axisX, Qt::AlignBottom);
        chartView->chart()->addSeries(series);

        // asse Y
        auto axisY = new QValueAxis;
        axisY->setTitleText("(" + unitOfMeasure + ")");
        axisY->setRange(target->getmin(), target->getmax()); // range adattivo asse Y
        axisY->setLinePenColor(series->pen().color());
        chartView->chart()->addAxis(axisY, Qt::AlignLeft);

        series->attachAxis(axisX);
        series->attachAxis(axisY);
    }

    delete visitor;
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
