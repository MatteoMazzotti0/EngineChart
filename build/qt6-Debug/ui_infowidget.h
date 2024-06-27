/********************************************************************************
** Form generated from reading UI file 'infowidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOWIDGET_H
#define UI_INFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QHBoxLayout *buttonLayout;
    QPushButton *btn_simulation;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_inspect;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_edit;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QTextEdit *DescDisplay;
    QHBoxLayout *horizontalLayout;
    QLabel *NameLabel;
    QTextEdit *NameDisplay;
    QVBoxLayout *widgetLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *TypeLabel;
    QTextEdit *TypeDisplay;
    QFrame *minMaxLayout;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *MinLabel;
    QLineEdit *MinDisplay;
    QHBoxLayout *horizontalLayout_5;
    QLabel *MaxLabel;
    QLineEdit *MaxDisplay;

    void setupUi(QWidget *InfoWidget)
    {
        if (InfoWidget->objectName().isEmpty())
            InfoWidget->setObjectName("InfoWidget");
        InfoWidget->setWindowModality(Qt::WindowModality::ApplicationModal);
        InfoWidget->resize(656, 496);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InfoWidget->sizePolicy().hasHeightForWidth());
        InfoWidget->setSizePolicy(sizePolicy);
        InfoWidget->setMinimumSize(QSize(450, 137));
        InfoWidget->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_2 = new QVBoxLayout(InfoWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        frame = new QFrame(InfoWidget);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(0, 120));
        frame->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        frame->setFrameShape(QFrame::Shape::Box);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName("gridLayout_2");
        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        btn_simulation = new QPushButton(frame);
        btn_simulation->setObjectName("btn_simulation");
        btn_simulation->setMinimumSize(QSize(85, 20));
        btn_simulation->setMaximumSize(QSize(16777215, 16777215));

        buttonLayout->addWidget(btn_simulation);

        horizontalSpacer = new QSpacerItem(15, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        buttonLayout->addItem(horizontalSpacer);

        btn_inspect = new QPushButton(frame);
        btn_inspect->setObjectName("btn_inspect");
        btn_inspect->setMinimumSize(QSize(85, 20));
        btn_inspect->setMaximumSize(QSize(16777215, 16777215));

        buttonLayout->addWidget(btn_inspect);

        horizontalSpacer_3 = new QSpacerItem(15, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        buttonLayout->addItem(horizontalSpacer_3);

        btn_edit = new QPushButton(frame);
        btn_edit->setObjectName("btn_edit");
        btn_edit->setMinimumSize(QSize(85, 20));

        buttonLayout->addWidget(btn_edit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonLayout->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(buttonLayout, 5, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(frame);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 27));
        label->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        label->setMargin(4);

        horizontalLayout_3->addWidget(label);

        DescDisplay = new QTextEdit(frame);
        DescDisplay->setObjectName("DescDisplay");
        sizePolicy.setHeightForWidth(DescDisplay->sizePolicy().hasHeightForWidth());
        DescDisplay->setSizePolicy(sizePolicy);
        DescDisplay->setMinimumSize(QSize(0, 27));
        DescDisplay->setMaximumSize(QSize(16777215, 16777215));
        DescDisplay->setFrameShape(QFrame::Shape::NoFrame);
        DescDisplay->setFrameShadow(QFrame::Shadow::Plain);
        DescDisplay->setLineWidth(0);
        DescDisplay->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        DescDisplay->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        DescDisplay->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
        DescDisplay->setLineWrapMode(QTextEdit::LineWrapMode::WidgetWidth);
        DescDisplay->setReadOnly(true);

        horizontalLayout_3->addWidget(DescDisplay);


        gridLayout_2->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        NameLabel = new QLabel(frame);
        NameLabel->setObjectName("NameLabel");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(NameLabel->sizePolicy().hasHeightForWidth());
        NameLabel->setSizePolicy(sizePolicy2);
        NameLabel->setMinimumSize(QSize(0, 27));
        NameLabel->setMaximumSize(QSize(16777215, 27));
        NameLabel->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        NameLabel->setMargin(3);

        horizontalLayout->addWidget(NameLabel);

        NameDisplay = new QTextEdit(frame);
        NameDisplay->setObjectName("NameDisplay");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(NameDisplay->sizePolicy().hasHeightForWidth());
        NameDisplay->setSizePolicy(sizePolicy3);
        NameDisplay->setMinimumSize(QSize(0, 27));
        NameDisplay->setMaximumSize(QSize(16777215, 27));
        NameDisplay->setFrameShape(QFrame::Shape::NoFrame);
        NameDisplay->setFrameShadow(QFrame::Shadow::Sunken);
        NameDisplay->setLineWidth(0);
        NameDisplay->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        NameDisplay->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        NameDisplay->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
        NameDisplay->setLineWrapMode(QTextEdit::LineWrapMode::WidgetWidth);
        NameDisplay->setReadOnly(true);

        horizontalLayout->addWidget(NameDisplay);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        widgetLayout = new QVBoxLayout();
        widgetLayout->setObjectName("widgetLayout");
        widgetLayout->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);

        gridLayout_2->addLayout(widgetLayout, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        TypeLabel = new QLabel(frame);
        TypeLabel->setObjectName("TypeLabel");
        sizePolicy2.setHeightForWidth(TypeLabel->sizePolicy().hasHeightForWidth());
        TypeLabel->setSizePolicy(sizePolicy2);
        TypeLabel->setMinimumSize(QSize(0, 27));
        TypeLabel->setMaximumSize(QSize(16777215, 27));
        TypeLabel->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        TypeLabel->setMargin(3);

        horizontalLayout_2->addWidget(TypeLabel);

        TypeDisplay = new QTextEdit(frame);
        TypeDisplay->setObjectName("TypeDisplay");
        sizePolicy3.setHeightForWidth(TypeDisplay->sizePolicy().hasHeightForWidth());
        TypeDisplay->setSizePolicy(sizePolicy3);
        TypeDisplay->setMinimumSize(QSize(0, 27));
        TypeDisplay->setMaximumSize(QSize(16777215, 27));
        TypeDisplay->setFrameShape(QFrame::Shape::NoFrame);
        TypeDisplay->setFrameShadow(QFrame::Shadow::Plain);
        TypeDisplay->setLineWidth(0);
        TypeDisplay->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        TypeDisplay->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        TypeDisplay->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContentsOnFirstShow);
        TypeDisplay->setReadOnly(true);

        horizontalLayout_2->addWidget(TypeDisplay);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        minMaxLayout = new QFrame(frame);
        minMaxLayout->setObjectName("minMaxLayout");
        minMaxLayout->setFrameShape(QFrame::Shape::NoFrame);
        minMaxLayout->setFrameShadow(QFrame::Shadow::Raised);
        minMaxLayout->setLineWidth(0);
        horizontalLayout_7 = new QHBoxLayout(minMaxLayout);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(3, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        MinLabel = new QLabel(minMaxLayout);
        MinLabel->setObjectName("MinLabel");

        horizontalLayout_6->addWidget(MinLabel);

        MinDisplay = new QLineEdit(minMaxLayout);
        MinDisplay->setObjectName("MinDisplay");
        MinDisplay->setMaximumSize(QSize(30, 16777215));
        MinDisplay->setFrame(false);
        MinDisplay->setReadOnly(true);

        horizontalLayout_6->addWidget(MinDisplay);


        horizontalLayout_7->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        MaxLabel = new QLabel(minMaxLayout);
        MaxLabel->setObjectName("MaxLabel");

        horizontalLayout_5->addWidget(MaxLabel);

        MaxDisplay = new QLineEdit(minMaxLayout);
        MaxDisplay->setObjectName("MaxDisplay");
        MaxDisplay->setMaximumSize(QSize(30, 16777215));
        MaxDisplay->setFrame(false);
        MaxDisplay->setReadOnly(true);

        horizontalLayout_5->addWidget(MaxDisplay);


        horizontalLayout_7->addLayout(horizontalLayout_5);


        gridLayout_2->addWidget(minMaxLayout, 2, 0, 1, 1, Qt::AlignmentFlag::AlignLeft);


        verticalLayout_2->addWidget(frame);


        retranslateUi(InfoWidget);

        QMetaObject::connectSlotsByName(InfoWidget);
    } // setupUi

    void retranslateUi(QWidget *InfoWidget)
    {
        InfoWidget->setWindowTitle(QCoreApplication::translate("InfoWidget", "Dialog", nullptr));
        btn_simulation->setText(QCoreApplication::translate("InfoWidget", "Simulation", nullptr));
        btn_inspect->setText(QCoreApplication::translate("InfoWidget", "Inspect Sensor", nullptr));
        btn_edit->setText(QCoreApplication::translate("InfoWidget", "Edit Sensor", nullptr));
        label->setText(QCoreApplication::translate("InfoWidget", "Description:", nullptr));
#if QT_CONFIG(accessibility)
        DescDisplay->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        NameLabel->setText(QCoreApplication::translate("InfoWidget", "Name:", nullptr));
        NameDisplay->setHtml(QCoreApplication::translate("InfoWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        TypeLabel->setText(QCoreApplication::translate("InfoWidget", "Type:", nullptr));
        MinLabel->setText(QCoreApplication::translate("InfoWidget", "Min:", nullptr));
        MaxLabel->setText(QCoreApplication::translate("InfoWidget", "Max:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoWidget: public Ui_InfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOWIDGET_H
