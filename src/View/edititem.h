#ifndef EDITITEM_H
#define EDITITEM_H

#include "../Sensor/abstractsensor.h"
#include <QDialog>
#include <QPushButton>

namespace Ui
{
class EditItem;
}

class EditItem : public QDialog
{
    Q_OBJECT

  public:
    explicit EditItem(AbstractSensor *sensor, QWidget *parent = nullptr);
    ~EditItem();
    string getNewName() const;

  private:
    Ui::EditItem *ui;
    AbstractSensor *sensor;

  private slots:
    void onOkClicked();
    void onCancelClicked();

  public slots:
    void onEditAvailable();

  signals:
    void refresh(AbstractSensor *, string oldName);
    void checkSensor();
    void nameNotChanged();
};

#endif // EDITITEM_H
