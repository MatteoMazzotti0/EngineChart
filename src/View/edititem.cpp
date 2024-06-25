#include "edititem.h"
#include "qregularexpression.h"
#include "qvalidator.h"
#include "src/View/errorpopup.h"
#include "ui_edititem.h"

EditItem::EditItem(AbstractSensor *sensor, QWidget *parent) : QDialog(parent), ui(new Ui::EditItem), sensor(sensor)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/Icons/src/Resources/appIcon.png"));
    this->setWindowTitle(QString::fromStdString("Edit sensor"));

    ui->newName->setText(QString::fromStdString(sensor->getname()));
    ui->newDesc->setText(QString::fromStdString(sensor->getdesc()));

    QRegularExpression regExp("[a-zA-Z0-9]*");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regExp, this);
    ui->newName->setValidator(validator);
    ui->newName->setMaxLength(25);

    connect(ui->btn_ok, &QPushButton::clicked, this, &EditItem::onOkClicked);
    connect(ui->btn_cancel, &QPushButton::clicked, this, &EditItem::onCancelClicked);
    connect(this,&EditItem::nameNotChanged,this,&EditItem::onEditAvailable);
}

EditItem::~EditItem()
{
    delete ui;
}

void EditItem::onOkClicked()
{
    // check nome sensore non vuoto (gli spazi vengono rimossi)
    if (QString(ui->newName->text().trimmed()).isEmpty())
    {
        // finestra messaggio d'errore
        ErrorPopup *errorPopup = new ErrorPopup("Il campo nome non può essere vuoto");
        errorPopup->show();
    }
    else if(ui->newName->text().toStdString()==sensor->getname())
    {
        emit nameNotChanged();
    }
    else
    {
        emit checkSensor();
    }
}

string EditItem::getNewName() const
{
    return ui->newName->text().trimmed().toStdString();
}

void EditItem::onEditAvailable()
{
    string oldName = sensor->getname();

    sensor->setname(QString(ui->newName->text()).toStdString());
    sensor->setdesc(QString(ui->newDesc->text()).toStdString());
    emit refresh(sensor, oldName);
    close();
}

void EditItem::onCancelClicked()
{
    close();
}
