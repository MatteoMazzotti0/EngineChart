#include "infowidget.h"
#include "ui_infowidget.h"
#include <QFrame>
#include <QVBoxLayout>

InfoWidget::InfoWidget(QWidget *parent) : QWidget(parent), ui(new Ui::InfoWidget)
{
    ui->setupUi(this);
    ui->frame->setFrameStyle(QFrame::Box);

    ui->NameDisplay->setAttribute(Qt::WA_TranslucentBackground);
    ui->TypeDisplay->setAttribute(Qt::WA_TranslucentBackground);
    ui->DescDisplay->setAttribute(Qt::WA_TranslucentBackground);
    ui->MaxDisplay->setAttribute(Qt::WA_TranslucentBackground);
    ui->MinDisplay->setAttribute(Qt::WA_TranslucentBackground);

    ui->NameDisplay->setStyleSheet("QTextEdit { background: transparent; }");
    ui->TypeDisplay->setStyleSheet("QTextEdit { background: transparent; }");
    ui->DescDisplay->setStyleSheet("QTextEdit { background: transparent; }");
    ui->MaxDisplay->setStyleSheet("QTextEdit { background: transparent; }");
    ui->MinDisplay->setStyleSheet("QTextEdit { background: transparent; }");

    connect(ui->btn_inspect, &QPushButton::clicked, this, [this]() { emit inspectSensor(); });
    connect(ui->btn_edit, &QPushButton::clicked, this, [this]() { emit editSensor(); });
    connect(ui->btn_simulation, &QPushButton::clicked, this, [this]() { emit startSim(); });
}

void InfoWidget::clearText()
{
    ui->NameDisplay->clear();
    ui->TypeDisplay->clear();
    ui->DescDisplay->clear();
    ui->MaxDisplay->clear();
    ui->MinDisplay->clear();
}

void InfoWidget::setName(const QString &name)
{
    ui->NameDisplay->setText(name);
}

void InfoWidget::setType(const QString &type)
{
    ui->TypeDisplay->setText(type);
}

void InfoWidget::setDesc(const QString &desc)
{
    ui->DescDisplay->setText(desc);
}

void InfoWidget::setMinMax(const QString &min, const QString &max, const QString &unit)
{
    ui->MinDisplay->setText(min+unit);
    ui->MaxDisplay->setText(max+unit);

}
InfoWidget::~InfoWidget()
{
    delete ui;
}

QVBoxLayout *InfoWidget::getWidgetLayout()
{
    return ui->widgetLayout;
}

void InfoWidget::clearLayout()
{
    QLayoutItem *item;
    while ((item = ui->widgetLayout->takeAt(0)) != nullptr)
    {
        delete item->widget();
        delete item;
    }
}
