/********************************************************************************
** Form generated from reading UI file 'edititem.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITITEM_H
#define UI_EDITITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EditItem
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *Tip;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelName;
    QLineEdit *newName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelDesc;
    QLineEdit *newDesc;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_ok;
    QPushButton *btn_cancel;

    void setupUi(QDialog *EditItem)
    {
        if (EditItem->objectName().isEmpty())
            EditItem->setObjectName("EditItem");
        EditItem->resize(400, 154);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EditItem->sizePolicy().hasHeightForWidth());
        EditItem->setSizePolicy(sizePolicy);
        EditItem->setMaximumSize(QSize(400, 200));
        verticalLayout = new QVBoxLayout(EditItem);
        verticalLayout->setObjectName("verticalLayout");
        Tip = new QLabel(EditItem);
        Tip->setObjectName("Tip");
        Tip->setMaximumSize(QSize(600, 40));
        Tip->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(Tip);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        labelName = new QLabel(EditItem);
        labelName->setObjectName("labelName");

        horizontalLayout_2->addWidget(labelName);

        newName = new QLineEdit(EditItem);
        newName->setObjectName("newName");
        newName->setMinimumSize(QSize(0, 0));

        horizontalLayout_2->addWidget(newName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        labelDesc = new QLabel(EditItem);
        labelDesc->setObjectName("labelDesc");

        horizontalLayout_3->addWidget(labelDesc);

        newDesc = new QLineEdit(EditItem);
        newDesc->setObjectName("newDesc");

        horizontalLayout_3->addWidget(newDesc);


        verticalLayout->addLayout(horizontalLayout_3);

        frame = new QFrame(EditItem);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName("horizontalLayout");
        btn_ok = new QPushButton(frame);
        btn_ok->setObjectName("btn_ok");

        horizontalLayout->addWidget(btn_ok);

        btn_cancel = new QPushButton(frame);
        btn_cancel->setObjectName("btn_cancel");

        horizontalLayout->addWidget(btn_cancel);


        verticalLayout->addWidget(frame);


        retranslateUi(EditItem);

        QMetaObject::connectSlotsByName(EditItem);
    } // setupUi

    void retranslateUi(QDialog *EditItem)
    {
        EditItem->setWindowTitle(QCoreApplication::translate("EditItem", "Dialog", nullptr));
        Tip->setText(QCoreApplication::translate("EditItem", "Sensor Informations", nullptr));
        labelName->setText(QCoreApplication::translate("EditItem", "Name:", nullptr));
        labelDesc->setText(QCoreApplication::translate("EditItem", "Description:", nullptr));
        btn_ok->setText(QCoreApplication::translate("EditItem", "Ok", nullptr));
        btn_cancel->setText(QCoreApplication::translate("EditItem", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditItem: public Ui_EditItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITITEM_H
