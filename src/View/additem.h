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
    void adjustValues(int minRange, int maxRange);
    void setValueRange(int minRange, int maxRange);

    ~AddItem();

private slots:
    void on_AddButtonDiag_clicked();
    void on_SpeedRadio_toggled(bool checked);
    void on_HumRadio_toggled(bool checked);
    void on_TempRadio_toggled(bool checked);
    void on_PressRadio_toggled(bool checked);
    void on_FuelRadio_toggled(bool checked);

signals:
    void dataAvailable(AbstractSensor* sensor);

private:
    Ui::AddItem *ui;
};

#endif // ADDITEM_H
