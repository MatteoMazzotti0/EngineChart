#ifndef SEARCHADDWIDGET_H
#define SEARCHADDWIDGET_H
#include <QWidget>
#include<QPushButton>
#include<vector>
#include"../Container/container.h"
#include "../Visitor/sensorvisitor.h"

using std::vector;

namespace Ui {
class SearchAddWidget;
}

class SearchAddWidget : public QWidget
{
    Q_OBJECT
private:
    AbstractSensor* hasFocus;
public:
    explicit SearchAddWidget(QWidget *parent = nullptr);
    void addButton(AbstractSensor*, SensorVisitor*);
    void editButton(const string&,const string&);
    void reloadUI();
    void setFocus(AbstractSensor*);
    void update(const AbstractSensor*, const string&);
    void loadDeleteAll();
    AbstractSensor* getFocus();
    ~SearchAddWidget();
signals:
    void nameTransfer(AbstractSensor *);
    void requestAdd();
    void deleteAllSignal();
    void sensorDeleted();
    void focusChanged();

private slots:
    void addClicked();
    void searchButton(const QString& target);
    void deleteClicked();

public slots:
    void deleteAllClicked();

private:
    Ui::SearchAddWidget *ui;
    static vector<QPushButton*> buttons;

};

#endif // SEARCHADDWIDGET_H
