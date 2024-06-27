/********************************************************************************
** Form generated from reading UI file 'errorpopup.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORPOPUP_H
#define UI_ERRORPOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ErrorPopup
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *ErrorPopup)
    {
        if (ErrorPopup->objectName().isEmpty())
            ErrorPopup->setObjectName("ErrorPopup");
        ErrorPopup->resize(400, 190);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ErrorPopup->sizePolicy().hasHeightForWidth());
        ErrorPopup->setSizePolicy(sizePolicy);
        ErrorPopup->setMinimumSize(QSize(400, 190));
        ErrorPopup->setMaximumSize(QSize(400, 190));
        pushButton = new QPushButton(ErrorPopup);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(160, 148, 80, 24));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        label = new QLabel(ErrorPopup);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 50, 300, 50));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(ErrorPopup);

        QMetaObject::connectSlotsByName(ErrorPopup);
    } // setupUi

    void retranslateUi(QDialog *ErrorPopup)
    {
        ErrorPopup->setWindowTitle(QCoreApplication::translate("ErrorPopup", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("ErrorPopup", "Okay", nullptr));
        label->setText(QCoreApplication::translate("ErrorPopup", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ErrorPopup: public Ui_ErrorPopup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORPOPUP_H
