#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include "qboxlayout.h"
#include <QWidget>

namespace Ui
{
class InfoWidget;
}

class InfoWidget : public QWidget
{
    Q_OBJECT
  signals:
    void startSim();
    void inspectSensor();
    void editSensor();

  public:
    explicit InfoWidget(QWidget *parent = nullptr);
    ~InfoWidget();
    void setName(const QString &name);
    void setType(const QString &type);
    void setDesc(const QString &);
    void clearText();
    void clearLayout();
    QVBoxLayout *getWidgetLayout();

  private:
    Ui::InfoWidget *ui;
};

#endif // INFOWIDGET_H
