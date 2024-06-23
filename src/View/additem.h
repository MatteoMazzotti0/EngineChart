#ifndef ADDITEM_H
#define ADDITEM_H
#include <QDialog>
#include<QPushButton>
#include"../Sensor/abstractsensor.h"

namespace Ui {
class AddItem;
}

class AddItem : public QDialog
{
    Q_OBJECT

public:
    explicit AddItem(QWidget *parent = nullptr);
    ~AddItem();

private slots:
    void on_AddButtonDiag_clicked();

signals:
    void dataAvailable(AbstractSensor* sensor);

private:
    Ui::AddItem *ui;
};

#endif // ADDITEM_H
