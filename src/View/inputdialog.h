#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>

namespace Ui
{
class InputDialog;
}

class InputDialog : public QDialog
{
    Q_OBJECT

  public:
    explicit InputDialog(QWidget *parent = nullptr, const int &min = 0, const int &max = 0);
    ~InputDialog();
    double getValue() const;
    double getTime() const;
  signals:
    void addValToSensor(const double &value, const double &time);

  private slots:
    void on_btn_cancel_clicked();

  private:
    Ui::InputDialog *ui;
};

#endif // INPUTDIALOG_H
