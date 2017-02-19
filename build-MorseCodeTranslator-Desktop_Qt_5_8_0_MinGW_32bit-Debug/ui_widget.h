/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton_OpenFile;
    QPushButton *pushButton_SaveFile;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton;
    QSpacerItem *horizontalSpacer;
    QRadioButton *radioButton_2;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit_Origin;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QPlainTextEdit *plainTexEdit_Converted;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        pushButton_OpenFile = new QPushButton(Widget);
        pushButton_OpenFile->setObjectName(QStringLiteral("pushButton_OpenFile"));
        pushButton_OpenFile->setGeometry(QRect(90, 250, 75, 23));
        pushButton_SaveFile = new QPushButton(Widget);
        pushButton_SaveFile->setObjectName(QStringLiteral("pushButton_SaveFile"));
        pushButton_SaveFile->setGeometry(QRect(190, 250, 75, 23));
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 10, 321, 22));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(widget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout->addWidget(radioButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        radioButton_2 = new QRadioButton(widget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        horizontalLayout->addWidget(radioButton_2);

        widget1 = new QWidget(Widget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(40, 60, 301, 162));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        plainTextEdit_Origin = new QPlainTextEdit(widget1);
        plainTextEdit_Origin->setObjectName(QStringLiteral("plainTextEdit_Origin"));

        verticalLayout->addWidget(plainTextEdit_Origin);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        plainTexEdit_Converted = new QPlainTextEdit(widget1);
        plainTexEdit_Converted->setObjectName(QStringLiteral("plainTexEdit_Converted"));

        verticalLayout->addWidget(plainTexEdit_Converted);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        pushButton_OpenFile->setText(QApplication::translate("Widget", "Open file...", Q_NULLPTR));
        pushButton_SaveFile->setText(QApplication::translate("Widget", "Save file...", Q_NULLPTR));
        radioButton->setText(QApplication::translate("Widget", "RadioButton", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("Widget", "RadioButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
