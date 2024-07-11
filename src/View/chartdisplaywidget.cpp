#include "chartdisplaywidget.h"
#include "src/Visitor/concretevisitor.h"
#include "ui_chartdisplaywidget.h"
#include <QLineSeries>
ChartDisplayWidget::ChartDisplayWidget(QWidget *parent) : QWidget(parent), ui(new Ui::ChartDisplayWidget)
{
    ui->setupUi(this);
    ui->frame->setFrameStyle(QFrame::Box);
    chartView = new QChartView();
    this->displayValues(nullptr, true);
    ui->horizontalLayout_2->addWidget(chartView);
}

void ChartDisplayWidget::displayValues(const AbstractSensor *target, const bool& simulationSuccess)
{
    // rimozione degli assi esistenti + reset grafico
    chartView->chart()->removeAllSeries();
    while (!chartView->chart()->axes().isEmpty())
    {
        chartView->chart()->removeAxis(chartView->chart()->axes().takeFirst());
    }

    // creazione titolo con nome e colore diverso a seconda della simulazione
    QString chartTitle = "Sensor values";
    chartView->chart()->legend()->hide();
    if (!simulationSuccess && target->countValues() > 1)
    {
        chartTitle += " - defective";
        chartView->chart()->setTitleBrush(QBrush(Qt::red));
    }
    else
    {
        chartView->chart()->setTitleBrush(QBrush(Qt::black));
    }
    chartView->chart()->setTitle(chartTitle);

    ConcreteVisitor *visitor = new ConcreteVisitor();

    if (target != nullptr)
    {
        QLineSeries *series = new QLineSeries();

        // cambio colore grafico in base alla simulazione
        if (!simulationSuccess && target->countValues() > 1)
        {
            series->setPen(QPen(Qt::red, 2));
        }
        else
        {
            series->setPen(QPen(Qt::darkBlue, 2));
        }

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
        axisX->setTitleText("(min)");
        chartView->chart()->addAxis(axisX, Qt::AlignBottom);
        chartView->chart()->addSeries(series);
        axisX->setLinePenColor(Qt::black);

        // asse Y
        auto axisY = new QValueAxis;
        axisY->setTitleText("(" + unitOfMeasure + ")");
        axisY->setRange(target->getmin(), target->getmax()); // range adattivo asse Y
        axisY->setLinePenColor(series->pen().color());
        chartView->chart()->addAxis(axisY, Qt::AlignLeft);
        axisY->setLinePenColor(Qt::black);

        series->attachAxis(axisX);
        series->attachAxis(axisY);
    }

    delete visitor;
}

void ChartDisplayWidget::resetChart()
{
    QLineSeries *values = new QLineSeries();

    // reset grafico
    chartView->chart()->removeAllSeries();
    if(!chartView->chart()->axes().empty())
    {
        chartView->chart()->removeAxis(chartView->chart()->axes().takeFirst());
    }
    if(!chartView->chart()->axes().empty())
    {
        chartView->chart()->removeAxis(chartView->chart()->axes().takeLast());

    }

    // titolo e rimozione legenda
    chartView->chart()->legend()->hide();
    chartView->chart()->setTitle("Sensor values");

    // asse X
    auto axisX = new QValueAxis;
    axisX->setTickCount(10);
    chartView->chart()->addAxis(axisX, Qt::AlignBottom);
    chartView->chart()->addSeries(values);

    // asse Y
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
