/********************************************************************************
** Form generated from reading UI file 'additem.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDITEM_H
#define UI_ADDITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddItem
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *NameLabel;
    QLineEdit *NameLine;
    QHBoxLayout *horizontalLayout;
    QLabel *TypeLabel;
    QRadioButton *SpeedRadio;
    QRadioButton *HumRadio;
    QRadioButton *TempRadio;
    QRadioButton *PressRadio;
    QRadioButton *FuelRadio;
    QHBoxLayout *horizontalLayout_3;
    QLabel *DescLabel;
    QLineEdit *DescLine;
    QPushButton *AddButtonDiag;

    void setupUi(QDialog *AddItem)
    {
        if (AddItem->objectName().isEmpty())
            AddItem->setObjectName("AddItem");
        AddItem->resize(466, 200);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddItem->sizePolicy().hasHeightForWidth());
        AddItem->setSizePolicy(sizePolicy);
        AddItem->setMaximumSize(QSize(466, 200));
        horizontalLayout_4 = new QHBoxLayout(AddItem);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        NameLabel = new QLabel(AddItem);
        NameLabel->setObjectName("NameLabel");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(NameLabel->sizePolicy().hasHeightForWidth());
        NameLabel->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(NameLabel);

        NameLine = new QLineEdit(AddItem);
        NameLine->setObjectName("NameLine");
        NameLine->setMinimumSize(QSize(0, 0));
        NameLine->setFrame(false);

        horizontalLayout_2->addWidget(NameLine);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        TypeLabel = new QLabel(AddItem);
        TypeLabel->setObjectName("TypeLabel");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(TypeLabel->sizePolicy().hasHeightForWidth());
        TypeLabel->setSizePolicy(sizePolicy2);
        TypeLabel->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(TypeLabel);

        SpeedRadio = new QRadioButton(AddItem);
        SpeedRadio->setObjectName("SpeedRadio");

        horizontalLayout->addWidget(SpeedRadio);

        HumRadio = new QRadioButton(AddItem);
        HumRadio->setObjectName("HumRadio");

        horizontalLayout->addWidget(HumRadio);

        TempRadio = new QRadioButton(AddItem);
        TempRadio->setObjectName("TempRadio");

        horizontalLayout->addWidget(TempRadio);

        PressRadio = new QRadioButton(AddItem);
        PressRadio->setObjectName("PressRadio");

        horizontalLayout->addWidget(PressRadio);

        FuelRadio = new QRadioButton(AddItem);
        FuelRadio->setObjectName("FuelRadio");

        horizontalLayout->addWidget(FuelRadio);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        DescLabel = new QLabel(AddItem);
        DescLabel->setObjectName("DescLabel");

        horizontalLayout_3->addWidget(DescLabel);

        DescLine = new QLineEdit(AddItem);
        DescLine->setObjectName("DescLine");
        DescLine->setAutoFillBackground(true);
        DescLine->setFrame(false);

        horizontalLayout_3->addWidget(DescLine);


        verticalLayout->addLayout(horizontalLayout_3);

        AddButtonDiag = new QPushButton(AddItem);
        AddButtonDiag->setObjectName("AddButtonDiag");

        verticalLayout->addWidget(AddButtonDiag);


        horizontalLayout_4->addLayout(verticalLayout);


        retranslateUi(AddItem);

        QMetaObject::connectSlotsByName(AddItem);
    } // setupUi

    void retranslateUi(QDialog *AddItem)
    {
        AddItem->setWindowTitle(QCoreApplication::translate("AddItem", "Dialog", nullptr));
        NameLabel->setText(QCoreApplication::translate("AddItem", "Name:", nullptr));
        TypeLabel->setText(QCoreApplication::translate("AddItem", "Type:", nullptr));
        SpeedRadio->setText(QCoreApplication::translate("AddItem", "Speed", nullptr));
        HumRadio->setText(QCoreApplication::translate("AddItem", "Humidity", nullptr));
        TempRadio->setText(QCoreApplication::translate("AddItem", "Temperature", nullptr));
        PressRadio->setText(QCoreApplication::translate("AddItem", "Oil Pressure", nullptr));
        FuelRadio->setText(QCoreApplication::translate("AddItem", "Fuel Level", nullptr));
        DescLabel->setText(QCoreApplication::translate("AddItem", "Description:", nullptr));
        AddButtonDiag->setText(QCoreApplication::translate("AddItem", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddItem: public Ui_AddItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDITEM_H
