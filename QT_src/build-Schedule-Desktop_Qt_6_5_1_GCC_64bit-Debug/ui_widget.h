/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *login;
    QPushButton *register_2;
    QPushButton *changepwd;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(598, 380);
        login = new QPushButton(Widget);
        login->setObjectName("login");
        login->setGeometry(QRect(150, 120, 291, 51));
        QFont font;
        font.setPointSize(14);
        login->setFont(font);
        register_2 = new QPushButton(Widget);
        register_2->setObjectName("register_2");
        register_2->setGeometry(QRect(150, 190, 291, 51));
        register_2->setFont(font);
        changepwd = new QPushButton(Widget);
        changepwd->setObjectName("changepwd");
        changepwd->setGeometry(QRect(150, 260, 291, 51));
        changepwd->setFont(font);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 40, 551, 31));
        label->setFont(font);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        login->setText(QCoreApplication::translate("Widget", "Login", nullptr));
        register_2->setText(QCoreApplication::translate("Widget", "Register", nullptr));
        changepwd->setText(QCoreApplication::translate("Widget", "Change Password", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Stay organized and make the most of your day!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
