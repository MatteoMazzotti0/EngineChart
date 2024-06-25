#include "searchaddwidget.h"
#include "ui_searchaddwidget.h"
#include"mainwindow.h"
#include"../Container/container.h"
#include <QMessageBox>

std::vector<QPushButton*> SearchAddWidget::buttons;

SearchAddWidget::SearchAddWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SearchAddWidget)
{
    hasFocus=nullptr;
    ui->setupUi(this);
    ui->VLayout->setAlignment(Qt::AlignTop);
    ui->frame->setFrameStyle(QFrame::Box);
    connect(ui->SearchLine, &QLineEdit::textChanged, this, [this](){searchButton(ui->SearchLine->text());});
    connect(ui->AddButton, &QPushButton::clicked, this, &SearchAddWidget::addClicked);
    connect(ui->DeleteAllButton, &QPushButton::clicked, this, &SearchAddWidget::deleteAllClicked);
    connect(ui->DeleteButton, &QPushButton::clicked, this, &SearchAddWidget::deleteClicked);

    QRegularExpression regExp("[\\p{L}0-9]*");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regExp, this);
    ui->SearchLine->setValidator(validator);
    ui->SearchLine->setMaxLength(28);
}

void SearchAddWidget::searchButton(const QString& target)
{
    if (target.isEmpty())
    {
        for (auto it = buttons.begin(); it != buttons.end(); ++it)
        {
            (*it)->show();
        }
    }
    else
    {
        for (auto it = buttons.begin(); it != buttons.end(); ++it)
        {
            if (!(*it)->objectName().contains(target, Qt::CaseInsensitive))
            {
                (*it)->hide();
            }
            else
            {
                (*it)->show();
            }
        }
    }
}

void SearchAddWidget::addButton(AbstractSensor* sensor, SensorVisitor* visitor)
{
    sensor->setButton(visitor);
    QPushButton* returnButton = visitor->getButton();
    connect(returnButton, &QPushButton::clicked, this, [this, sensor]() { emit nameTransfer(sensor); });
    connect(returnButton, &QPushButton::clicked, this, [this, sensor]() { setFocus(sensor); });
    buttons.push_back(returnButton);
    ui->VLayout->addWidget(returnButton);
}


void SearchAddWidget::editButton(string newname, string oldname)
{
    for(auto it = buttons.begin();it!=buttons.end();it++)
    {
        if((*it)->objectName().remove("&").toStdString()==oldname)
        {
            (*it)->setObjectName(QString::fromStdString(newname));
            delete (*it)->layout()->itemAt(0)->widget();
            QLabel* textLabel = new QLabel(QString::fromStdString(newname));
            textLabel->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            (*it)->layout()->addWidget(textLabel);
            return;
        }
    }
}

SearchAddWidget::~SearchAddWidget()
{
    delete ui;
}

void SearchAddWidget::setFocus(AbstractSensor* sensorPointer)
{
    this->hasFocus=sensorPointer;
    emit focusChanged();
}

AbstractSensor* SearchAddWidget::getFocus()
{
    if(hasFocus!=nullptr)
    {
        return this->hasFocus;
    }
    return nullptr;
}

void SearchAddWidget::addClicked()
{
    emit requestAdd();
}

void SearchAddWidget::deleteAllClicked()
{
    QMessageBox::StandardButton reply; // messaggio di accertamente

    reply = QMessageBox::question(this, "Delete All", "Are you sure you want to delete all sensors?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        for (auto it = buttons.begin(); it != buttons.end(); ++it)
        {
            delete *it;
        }
        buttons.clear();

        emit deleteAllSignal();
    }
}

void SearchAddWidget::loadDeleteAll()
{
    for (auto it = buttons.begin(); it != buttons.end(); ++it)
    {
        delete *it;
    }
    buttons.clear();

    emit deleteAllSignal();
}

void SearchAddWidget::deleteClicked()
{
    if (hasFocus != nullptr)
    {
        // cerco bottone per rimuoverlo
        for (auto it = buttons.begin(); it != buttons.end(); ++it)
        {
            if ((*it)->objectName().toStdString() == hasFocus->getname())
            {
                ui->VLayout->removeWidget(*it);
                delete *it;
                buttons.erase(it);
                break;
            }
        }

        // cancello il sensore dal container
        Container::remove(hasFocus);
        hasFocus = nullptr;

        emit sensorDeleted();
    }
}

