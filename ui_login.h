/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
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
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(735, 473);
        label = new QLabel(Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 100, 101, 17));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(Login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(135, 150, 101, 17));
        label_2->setFont(font);
        uname = new QLineEdit(Login);
        uname->setObjectName(QString::fromUtf8("uname"));
        uname->setGeometry(QRect(240, 90, 231, 31));
        uname->setFont(font);
        pwd = new QLineEdit(Login);
        pwd->setObjectName(QString::fromUtf8("pwd"));
        pwd->setGeometry(QRect(240, 140, 231, 31));
        pwd->setFont(font);
        result = new QTextBrowser(Login);
        result->setObjectName(QString::fromUtf8("result"));
        result->setGeometry(QRect(80, 320, 561, 51));
        result->setFont(font);
        label_3 = new QLabel(Login);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 290, 101, 17));
        label_3->setFont(font);
        login = new QPushButton(Login);
        login->setObjectName(QString::fromUtf8("login"));
        login->setGeometry(QRect(390, 200, 171, 51));
        login->setFont(font);
        label_4 = new QLabel(Login);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 40, 161, 31));
        QFont font1;
        font1.setPointSize(17);
        label_4->setFont(font1);
        back = new QPushButton(Login);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(20, 434, 171, 31));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", nullptr));
        label->setText(QApplication::translate("Login", "Username:", nullptr));
        label_2->setText(QApplication::translate("Login", "Password:", nullptr));
        label_3->setText(QApplication::translate("Login", "Feedback:", nullptr));
        login->setText(QApplication::translate("Login", "Login", nullptr));
        label_4->setText(QApplication::translate("Login", "User Login", nullptr));
        back->setText(QApplication::translate("Login", "Go back to main page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
