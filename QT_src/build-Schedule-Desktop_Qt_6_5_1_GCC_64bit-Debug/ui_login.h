/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *uname;
    QLineEdit *pwd;
    QTextBrowser *result;
    QLabel *label_3;
    QPushButton *login;
    QLabel *label_4;
    QPushButton *back;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(735, 473);
        label = new QLabel(Login);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 100, 101, 17));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(Login);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(135, 150, 101, 17));
        label_2->setFont(font);
        uname = new QLineEdit(Login);
        uname->setObjectName("uname");
        uname->setGeometry(QRect(240, 90, 231, 31));
        uname->setFont(font);
        pwd = new QLineEdit(Login);
        pwd->setObjectName("pwd");
        pwd->setGeometry(QRect(240, 140, 231, 31));
        pwd->setFont(font);
        result = new QTextBrowser(Login);
        result->setObjectName("result");
        result->setGeometry(QRect(80, 320, 561, 51));
        result->setFont(font);
        label_3 = new QLabel(Login);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 290, 101, 17));
        label_3->setFont(font);
        login = new QPushButton(Login);
        login->setObjectName("login");
        login->setGeometry(QRect(390, 200, 171, 51));
        login->setFont(font);
        label_4 = new QLabel(Login);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 40, 161, 31));
        QFont font1;
        font1.setPointSize(17);
        label_4->setFont(font1);
        back = new QPushButton(Login);
        back->setObjectName("back");
        back->setGeometry(QRect(20, 434, 171, 31));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        label->setText(QCoreApplication::translate("Login", "Username:", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "Password:", nullptr));
        label_3->setText(QCoreApplication::translate("Login", "Feedback:", nullptr));
        login->setText(QCoreApplication::translate("Login", "Login", nullptr));
        label_4->setText(QCoreApplication::translate("Login", "User Login", nullptr));
        back->setText(QCoreApplication::translate("Login", "Go back to main page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
