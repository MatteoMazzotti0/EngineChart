/********************************************************************************
** Form generated from reading UI file 'chartdisplaywidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTDISPLAYWIDGET_H
#define UI_CHARTDISPLAYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChartDisplayWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;

    void setupUi(QWidget *ChartDisplayWidget)
    {
        if (ChartDisplayWidget->objectName().isEmpty())
            ChartDisplayWidget->setObjectName("ChartDisplayWidget");
        ChartDisplayWidget->resize(938, 499);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChartDisplayWidget->sizePolicy().hasHeightForWidth());
        ChartDisplayWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(ChartDisplayWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        frame = new QFrame(ChartDisplayWidget);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");

        horizontalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout->addWidget(frame);


        retranslateUi(ChartDisplayWidget);

        QMetaObject::connectSlotsByName(ChartDisplayWidget);
    } // setupUi

    void retranslateUi(QWidget *ChartDisplayWidget)
    {
        ChartDisplayWidget->setWindowTitle(QCoreApplication::translate("ChartDisplayWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChartDisplayWidget: public Ui_ChartDisplayWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTDISPLAYWIDGET_H
