/********************************************************************************
** Form generated from reading UI file 'inspectwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSPECTWINDOW_H
#define UI_INSPECTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InspectWindow
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_newValue;
    QPushButton *btn_delete;
    QPushButton *btn_deleteAll;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QListWidget *TimeView;
    QListWidget *ValueView;

    void setupUi(QDialog *InspectWindow)
    {
        if (InspectWindow->objectName().isEmpty())
            InspectWindow->setObjectName("InspectWindow");
        InspectWindow->resize(445, 539);
        verticalLayout = new QVBoxLayout(InspectWindow);
        verticalLayout->setObjectName("verticalLayout");
        frame = new QFrame(InspectWindow);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btn_newValue = new QPushButton(frame);
        btn_newValue->setObjectName("btn_newValue");

        horizontalLayout->addWidget(btn_newValue);

        btn_delete = new QPushButton(frame);
        btn_delete->setObjectName("btn_delete");

        horizontalLayout->addWidget(btn_delete);

        btn_deleteAll = new QPushButton(frame);
        btn_deleteAll->setObjectName("btn_deleteAll");

        horizontalLayout->addWidget(btn_deleteAll);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(label);

        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(label_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 2);

        TimeView = new QListWidget(frame);
        TimeView->setObjectName("TimeView");
        TimeView->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);

        gridLayout->addWidget(TimeView, 2, 0, 1, 1);

        ValueView = new QListWidget(frame);
        ValueView->setObjectName("ValueView");

        gridLayout->addWidget(ValueView, 2, 1, 1, 1);


        verticalLayout->addWidget(frame);


        retranslateUi(InspectWindow);

        QMetaObject::connectSlotsByName(InspectWindow);
    } // setupUi

    void retranslateUi(QDialog *InspectWindow)
    {
        InspectWindow->setWindowTitle(QCoreApplication::translate("InspectWindow", "Dialog", nullptr));
        btn_newValue->setText(QCoreApplication::translate("InspectWindow", "New Value", nullptr));
        btn_delete->setText(QCoreApplication::translate("InspectWindow", "Delete Value", nullptr));
        btn_deleteAll->setText(QCoreApplication::translate("InspectWindow", "Delete all", nullptr));
        label->setText(QCoreApplication::translate("InspectWindow", "Time", nullptr));
        label_2->setText(QCoreApplication::translate("InspectWindow", "Value", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InspectWindow: public Ui_InspectWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSPECTWINDOW_H
