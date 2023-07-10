/********************************************************************************
** Form generated from reading UI file 'user.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_H
#define UI_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_User
{
public:
    QTextBrowser *task_list;
    QPushButton *add;
    QPushButton *delete_2;
    QTextBrowser *welcome;
    QPushButton *logout;
    QTextBrowser *remind;
    QLabel *label;

    void setupUi(QWidget *User)
    {
        if (User->objectName().isEmpty())
            User->setObjectName("User");
        User->resize(1015, 620);
        task_list = new QTextBrowser(User);
        task_list->setObjectName("task_list");
        task_list->setGeometry(QRect(50, 110, 911, 221));
        QFont font;
        font.setPointSize(13);
        task_list->setFont(font);
        add = new QPushButton(User);
        add->setObjectName("add");
        add->setGeometry(QRect(710, 390, 141, 51));
        QFont font1;
        font1.setPointSize(14);
        add->setFont(font1);
        delete_2 = new QPushButton(User);
        delete_2->setObjectName("delete_2");
        delete_2->setGeometry(QRect(710, 450, 141, 51));
        delete_2->setFont(font1);
        welcome = new QTextBrowser(User);
        welcome->setObjectName("welcome");
        welcome->setGeometry(QRect(50, 40, 251, 41));
        welcome->setFont(font1);
        logout = new QPushButton(User);
        logout->setObjectName("logout");
        logout->setGeometry(QRect(30, 570, 101, 31));
        remind = new QTextBrowser(User);
        remind->setObjectName("remind");
        remind->setGeometry(QRect(150, 400, 471, 141));
        remind->setFont(font1);
        label = new QLabel(User);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 366, 351, 31));
        label->setFont(font1);

        retranslateUi(User);

        QMetaObject::connectSlotsByName(User);
    } // setupUi

    void retranslateUi(QWidget *User)
    {
        User->setWindowTitle(QCoreApplication::translate("User", "Form", nullptr));
        add->setText(QCoreApplication::translate("User", "Add Task", nullptr));
        delete_2->setText(QCoreApplication::translate("User", "Delete Task", nullptr));
        logout->setText(QCoreApplication::translate("User", "log out", nullptr));
        label->setText(QCoreApplication::translate("User", "Here is your task reminder information:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class User: public Ui_User {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_H
