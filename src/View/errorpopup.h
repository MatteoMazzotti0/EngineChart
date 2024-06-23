#ifndef ERRORPOPUP_H
#define ERRORPOPUP_H

#include <QDialog>

namespace Ui {
class ErrorPopup;
}

class ErrorPopup : public QDialog
{
    Q_OBJECT

public:
    explicit ErrorPopup(QString message = "", QWidget *parent = nullptr);
    ~ErrorPopup();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ErrorPopup *ui;
};

#endif // ERRORPOPUP_H
