/********************************************************************************
** Form generated from reading UI file 'inputdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTDIALOG_H
#define UI_INPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InputDialog
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_value;
    QLabel *label_minMax;
    QDoubleSpinBox *valueBox;
    QLabel *label_time;
    QDoubleSpinBox *timeBox;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_ok;
    QPushButton *btn_cancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *InputDialog)
    {
        if (InputDialog->objectName().isEmpty())
            InputDialog->setObjectName("InputDialog");
        InputDialog->resize(342, 210);
        gridLayout = new QGridLayout(InputDialog);
        gridLayout->setObjectName("gridLayout");
        frame = new QFrame(InputDialog);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_value = new QLabel(frame);
        label_value->setObjectName("label_value");
        label_value->setMaximumSize(QSize(35, 16777215));

        horizontalLayout_2->addWidget(label_value);

        label_minMax = new QLabel(frame);
        label_minMax->setObjectName("label_minMax");

        horizontalLayout_2->addWidget(label_minMax);


        verticalLayout->addLayout(horizontalLayout_2);

        valueBox = new QDoubleSpinBox(frame);
        valueBox->setObjectName("valueBox");

        verticalLayout->addWidget(valueBox);

        label_time = new QLabel(frame);
        label_time->setObjectName("label_time");

        verticalLayout->addWidget(label_time);

        timeBox = new QDoubleSpinBox(frame);
        timeBox->setObjectName("timeBox");

        verticalLayout->addWidget(timeBox);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setMaximumSize(QSize(16777215, 16777215));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_ok = new QPushButton(frame_2);
        btn_ok->setObjectName("btn_ok");

        horizontalLayout->addWidget(btn_ok);

        btn_cancel = new QPushButton(frame_2);
        btn_cancel->setObjectName("btn_cancel");

        horizontalLayout->addWidget(btn_cancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(frame_2);


        gridLayout->addWidget(frame, 3, 1, 1, 1);


        retranslateUi(InputDialog);

        QMetaObject::connectSlotsByName(InputDialog);
    } // setupUi

    void retranslateUi(QDialog *InputDialog)
    {
        InputDialog->setWindowTitle(QCoreApplication::translate("InputDialog", "Dialog", nullptr));
        label_value->setText(QCoreApplication::translate("InputDialog", "Value:", nullptr));
        label_minMax->setText(QCoreApplication::translate("InputDialog", "TextLabel", nullptr));
        label_time->setText(QCoreApplication::translate("InputDialog", "Time:", nullptr));
        btn_ok->setText(QCoreApplication::translate("InputDialog", "Ok", nullptr));
        btn_cancel->setText(QCoreApplication::translate("InputDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InputDialog: public Ui_InputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTDIALOG_H
