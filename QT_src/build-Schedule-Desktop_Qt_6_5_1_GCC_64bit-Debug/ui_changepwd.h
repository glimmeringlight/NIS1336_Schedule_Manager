/********************************************************************************
** Form generated from reading UI file 'changepwd.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPWD_H
#define UI_CHANGEPWD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Changepwd
{
public:
    QTextBrowser *result;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label;
    QPushButton *commit;
    QLineEdit *oldpwd;
    QLabel *label_3;
    QLineEdit *uname;
    QLineEdit *newpwd;
    QLabel *label_5;
    QPushButton *back;

    void setupUi(QWidget *Changepwd)
    {
        if (Changepwd->objectName().isEmpty())
            Changepwd->setObjectName("Changepwd");
        Changepwd->resize(709, 499);
        QFont font;
        font.setPointSize(13);
        Changepwd->setFont(font);
        result = new QTextBrowser(Changepwd);
        result->setObjectName("result");
        result->setGeometry(QRect(110, 365, 481, 51));
        QFont font1;
        font1.setPointSize(14);
        result->setFont(font1);
        label_2 = new QLabel(Changepwd);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(130, 155, 151, 21));
        label_2->setFont(font1);
        label_4 = new QLabel(Changepwd);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 40, 241, 31));
        QFont font2;
        font2.setPointSize(17);
        label_4->setFont(font2);
        label = new QLabel(Changepwd);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 105, 101, 21));
        label->setFont(font1);
        commit = new QPushButton(Changepwd);
        commit->setObjectName("commit");
        commit->setGeometry(QRect(450, 270, 141, 51));
        oldpwd = new QLineEdit(Changepwd);
        oldpwd->setObjectName("oldpwd");
        oldpwd->setGeometry(QRect(290, 150, 191, 31));
        oldpwd->setFont(font1);
        label_3 = new QLabel(Changepwd);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(110, 340, 101, 21));
        label_3->setFont(font1);
        uname = new QLineEdit(Changepwd);
        uname->setObjectName("uname");
        uname->setGeometry(QRect(290, 100, 191, 31));
        uname->setFont(font1);
        newpwd = new QLineEdit(Changepwd);
        newpwd->setObjectName("newpwd");
        newpwd->setGeometry(QRect(290, 210, 191, 31));
        newpwd->setFont(font1);
        label_5 = new QLabel(Changepwd);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(140, 215, 141, 21));
        label_5->setFont(font1);
        back = new QPushButton(Changepwd);
        back->setObjectName("back");
        back->setGeometry(QRect(20, 450, 151, 31));
        QFont font3;
        font3.setPointSize(11);
        back->setFont(font3);

        retranslateUi(Changepwd);

        QMetaObject::connectSlotsByName(Changepwd);
    } // setupUi

    void retranslateUi(QWidget *Changepwd)
    {
        Changepwd->setWindowTitle(QCoreApplication::translate("Changepwd", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("Changepwd", "Origin Password:", nullptr));
        label_4->setText(QCoreApplication::translate("Changepwd", "Change Password", nullptr));
        label->setText(QCoreApplication::translate("Changepwd", "Username:", nullptr));
        commit->setText(QCoreApplication::translate("Changepwd", "Commit", nullptr));
        label_3->setText(QCoreApplication::translate("Changepwd", "Feedback:", nullptr));
        label_5->setText(QCoreApplication::translate("Changepwd", "New Password:", nullptr));
        back->setText(QCoreApplication::translate("Changepwd", "Back to main page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Changepwd: public Ui_Changepwd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPWD_H
