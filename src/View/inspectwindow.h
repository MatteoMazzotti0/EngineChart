#ifndef INSPECTWINDOW_H
#define INSPECTWINDOW_H
#include "../Sensor/abstractsensor.h"
#include <QDialog>

namespace Ui
{
class InspectWindow;
}

class InspectWindow : public QDialog
{
    Q_OBJECT

  public:
    explicit InspectWindow(AbstractSensor *, QWidget *parent = nullptr);
    void refresh(const AbstractSensor *);
    ~InspectWindow();

  signals:
    void newValue();
    void deleteValue();
    void deleteAllValues();
    void requestDeleteVal(unsigned int, unsigned int);
    void updateChart();

  private slots:
    void onDeleteValue();

    void on_TimeView_currentRowChanged(int currentRow);

    void on_ValueView_currentRowChanged(int currentRow);

  private:
    Ui::InspectWindow *ui;
    int currentFocus;
    AbstractSensor *inspected;
};

#endif // INSPECTWINDOW_H
