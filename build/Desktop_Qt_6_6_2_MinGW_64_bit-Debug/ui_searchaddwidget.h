/********************************************************************************
** Form generated from reading UI file 'searchaddwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHADDWIDGET_H
#define UI_SEARCHADDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchAddWidget
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *SearchLine;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *AddButton;
    QPushButton *DeleteButton;
    QPushButton *DeleteAllButton;
    QScrollArea *ScrollSensors;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QWidget *Container;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *VLayout;

    void setupUi(QWidget *SearchAddWidget)
    {
        if (SearchAddWidget->objectName().isEmpty())
            SearchAddWidget->setObjectName("SearchAddWidget");
        SearchAddWidget->setWindowModality(Qt::ApplicationModal);
        SearchAddWidget->setEnabled(true);
        SearchAddWidget->resize(300, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SearchAddWidget->sizePolicy().hasHeightForWidth());
        SearchAddWidget->setSizePolicy(sizePolicy);
        SearchAddWidget->setMinimumSize(QSize(300, 0));
        SearchAddWidget->setMaximumSize(QSize(300, 16777215));
        verticalLayout = new QVBoxLayout(SearchAddWidget);
        verticalLayout->setObjectName("verticalLayout");
        frame = new QFrame(SearchAddWidget);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        SearchLine = new QLineEdit(frame);
        SearchLine->setObjectName("SearchLine");
        SearchLine->setFrame(false);

        verticalLayout_2->addWidget(SearchLine);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        AddButton = new QPushButton(frame);
        AddButton->setObjectName("AddButton");
        AddButton->setMinimumSize(QSize(50, 20));
        AddButton->setMaximumSize(QSize(170, 20));

        horizontalLayout_2->addWidget(AddButton);

        DeleteButton = new QPushButton(frame);
        DeleteButton->setObjectName("DeleteButton");
        DeleteButton->setMaximumSize(QSize(170, 20));

        horizontalLayout_2->addWidget(DeleteButton);

        DeleteAllButton = new QPushButton(frame);
        DeleteAllButton->setObjectName("DeleteAllButton");
        DeleteAllButton->setMinimumSize(QSize(50, 20));
        DeleteAllButton->setMaximumSize(QSize(170, 20));

        horizontalLayout_2->addWidget(DeleteAllButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        ScrollSensors = new QScrollArea(frame);
        ScrollSensors->setObjectName("ScrollSensors");
        ScrollSensors->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        ScrollSensors->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        ScrollSensors->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 258, 502));
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout->setObjectName("horizontalLayout");
        Container = new QWidget(scrollAreaWidgetContents);
        Container->setObjectName("Container");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Container->sizePolicy().hasHeightForWidth());
        Container->setSizePolicy(sizePolicy2);
        Container->setMinimumSize(QSize(0, 0));
        verticalLayout_4 = new QVBoxLayout(Container);
        verticalLayout_4->setObjectName("verticalLayout_4");
        VLayout = new QVBoxLayout();
        VLayout->setObjectName("VLayout");
        VLayout->setSizeConstraint(QLayout::SetFixedSize);

        verticalLayout_4->addLayout(VLayout);


        horizontalLayout->addWidget(Container);

        ScrollSensors->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(ScrollSensors);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout->addWidget(frame);


        retranslateUi(SearchAddWidget);

        QMetaObject::connectSlotsByName(SearchAddWidget);
    } // setupUi

    void retranslateUi(QWidget *SearchAddWidget)
    {
        SearchAddWidget->setWindowTitle(QCoreApplication::translate("SearchAddWidget", "Form", nullptr));
        SearchLine->setPlaceholderText(QCoreApplication::translate("SearchAddWidget", "Search sensors", nullptr));
        AddButton->setText(QCoreApplication::translate("SearchAddWidget", "Add", nullptr));
        DeleteButton->setText(QCoreApplication::translate("SearchAddWidget", "Delete", nullptr));
        DeleteAllButton->setText(QCoreApplication::translate("SearchAddWidget", "Delete All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchAddWidget: public Ui_SearchAddWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHADDWIDGET_H
