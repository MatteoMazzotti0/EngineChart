#include "inspectwindow.h"
#include "qscrollbar.h"
#include "ui_inspectwindow.h"
#include <QInputDialog>

InspectWindow::InspectWindow(AbstractSensor *target, QWidget *parent)
    : QDialog(parent), ui(new Ui::InspectWindow), inspected(target)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/Icons/src/Resources/appIcon.png"));
    this->setWindowTitle(QString::fromStdString("Inspect values"));

    for (int i = 0; i < target->countValues(); i++)
    {
        ui->ValueView->addItem(QString::number(target->getValueAt(i).value()));
        ui->TimeView->addItem(QString::number(target->getValueAt(i).time()));
    }

    connect(ui->btn_newValue, &QPushButton::clicked, this, [this]() { emit newValue(); });
    connect(ui->btn_delete, &QPushButton::clicked, this, [this]() { emit deleteValue(); });
    connect(ui->btn_deleteAll, &QPushButton::clicked, this, [this]() { emit deleteAllValues(); });
    connect(this, &QDialog::finished, this, [this]() {
        emit updateChart();
        close();
    });
    connect(this, &InspectWindow::deleteValue, this, &InspectWindow::onDeleteValue);

    connect(this->ui->ValueView->verticalScrollBar(), &QScrollBar::valueChanged,
            this->ui->TimeView->verticalScrollBar(), &QScrollBar::setValue);
    connect(this->ui->TimeView->verticalScrollBar(), &QScrollBar::valueChanged,
            this->ui->ValueView->verticalScrollBar(), &QScrollBar::setValue);
}

void InspectWindow::refresh(const AbstractSensor *target)
{
    ui->ValueView->clear();
    ui->TimeView->clear();
    for (int i = 0; i < target->countValues(); i++)
    {
        ui->ValueView->addItem(QString::number(target->getValueAt(i).value()));
        ui->TimeView->addItem(QString::number(target->getValueAt(i).time()));
    }
}

InspectWindow::~InspectWindow()
{
    delete ui;
}

void InspectWindow::onDeleteValue()
{
    if ((ui->TimeView->count() != 0 && ui->ValueView->count() != 0) && (ui->TimeView->currentItem()!=nullptr) && ui->ValueView->currentItem()!=nullptr)
    {
        emit requestDeleteVal(ui->TimeView->item(currentFocus)->text().toInt(),
                              ui->ValueView->item(currentFocus)->text().toInt());
        ui->TimeView->setCurrentRow(currentFocus - 1);
        ui->ValueView->setCurrentRow(currentFocus - 1);
        refresh(inspected);
    }
}

void InspectWindow::on_TimeView_currentRowChanged(const int& currentRow)
{
    if (currentRow != -1)
    {
        currentFocus = currentRow;
        ui->ValueView->setCurrentRow(currentFocus);
    }
}

void InspectWindow::on_ValueView_currentRowChanged(const int& currentRow)
{
    if (currentRow != -1)
    {
        currentFocus = currentRow;
        ui->TimeView->setCurrentRow(currentFocus);
    }
}
