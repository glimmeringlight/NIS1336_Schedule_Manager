/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLabel *label;
    QLabel *label_2;
    QTextBrowser *result;
    QLabel *label_3;
    QLineEdit *uname;
    QLineEdit *pwd;
    QPushButton *pushButton;
    QLabel *label_4;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(769, 501);
        label = new QLabel(Register);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 110, 101, 21));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(Register);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 180, 101, 21));
        label_2->setFont(font);
        result = new QTextBrowser(Register);
        result->setObjectName(QString::fromUtf8("result"));
        result->setGeometry(QRect(80, 355, 571, 71));
        QFont font1;
        font1.setPointSize(13);
        result->setFont(font1);
        label_3 = new QLabel(Register);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 330, 101, 21));
        label_3->setFont(font);
        uname = new QLineEdit(Register);
        uname->setObjectName(QString::fromUtf8("uname"));
        uname->setGeometry(QRect(270, 100, 241, 35));
        uname->setFont(font);
        pwd = new QLineEdit(Register);
        pwd->setObjectName(QString::fromUtf8("pwd"));
        pwd->setGeometry(QRect(270, 170, 241, 35));
        pwd->setFont(font);
        pushButton = new QPushButton(Register);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(440, 240, 181, 51));
        pushButton->setFont(font);
        label_4 = new QLabel(Register);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 30, 221, 41));
        QFont font2;
        font2.setPointSize(16);
        label_4->setFont(font2);
        pushButton_2 = new QPushButton(Register);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 460, 161, 31));
        QFont font3;
        font3.setPointSize(11);
        pushButton_2->setFont(font3);

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Form", nullptr));
        label->setText(QApplication::translate("Register", "Username:", nullptr));
        label_2->setText(QApplication::translate("Register", "Password:", nullptr));
        label_3->setText(QApplication::translate("Register", "Feedback:", nullptr));
        pushButton->setText(QApplication::translate("Register", "Register", nullptr));
        label_4->setText(QApplication::translate("Register", "User Registration", nullptr));
        pushButton_2->setText(QApplication::translate("Register", "Back to main page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
