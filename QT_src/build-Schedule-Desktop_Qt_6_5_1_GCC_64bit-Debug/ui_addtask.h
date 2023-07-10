/********************************************************************************
** Form generated from reading UI file 'addtask.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTASK_H
#define UI_ADDTASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Addtask
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *tname;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *det;
    QDateTimeEdit *stime;
    QDateTimeEdit *rtime;
    QComboBox *prio;
    QComboBox *cat;
    QPushButton *pushButton;
    QTextBrowser *result;
    QLabel *label_8;

    void setupUi(QWidget *Addtask)
    {
        if (Addtask->objectName().isEmpty())
            Addtask->setObjectName("Addtask");
        Addtask->resize(652, 564);
        label = new QLabel(Addtask);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 20, 121, 41));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label_2 = new QLabel(Addtask);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 100, 101, 21));
        QFont font1;
        font1.setPointSize(14);
        label_2->setFont(font1);
        tname = new QLineEdit(Addtask);
        tname->setObjectName("tname");
        tname->setGeometry(QRect(220, 95, 181, 28));
        QFont font2;
        font2.setPointSize(13);
        tname->setFont(font2);
        label_3 = new QLabel(Addtask);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(130, 250, 81, 21));
        label_3->setFont(font1);
        label_4 = new QLabel(Addtask);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(115, 300, 101, 21));
        label_4->setFont(font1);
        label_5 = new QLabel(Addtask);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(65, 200, 151, 21));
        label_5->setFont(font1);
        label_6 = new QLabel(Addtask);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(140, 350, 71, 21));
        label_6->setFont(font1);
        label_7 = new QLabel(Addtask);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(110, 150, 111, 21));
        label_7->setFont(font1);
        det = new QLineEdit(Addtask);
        det->setObjectName("det");
        det->setGeometry(QRect(220, 345, 181, 28));
        det->setFont(font2);
        stime = new QDateTimeEdit(Addtask);
        stime->setObjectName("stime");
        stime->setGeometry(QRect(220, 150, 194, 26));
        stime->setFont(font2);
        stime->setDateTime(QDateTime(QDate(2023, 1, 1), QTime(0, 0, 0)));
        rtime = new QDateTimeEdit(Addtask);
        rtime->setObjectName("rtime");
        rtime->setGeometry(QRect(220, 200, 194, 26));
        rtime->setFont(font2);
        rtime->setDateTime(QDateTime(QDate(2023, 1, 1), QTime(0, 0, 0)));
        prio = new QComboBox(Addtask);
        prio->addItem(QString());
        prio->addItem(QString());
        prio->addItem(QString());
        prio->setObjectName("prio");
        prio->setGeometry(QRect(220, 250, 131, 25));
        prio->setFont(font1);
        cat = new QComboBox(Addtask);
        cat->addItem(QString());
        cat->addItem(QString());
        cat->addItem(QString());
        cat->setObjectName("cat");
        cat->setGeometry(QRect(220, 300, 131, 25));
        cat->setFont(font1);
        pushButton = new QPushButton(Addtask);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(420, 400, 121, 41));
        pushButton->setFont(font1);
        result = new QTextBrowser(Addtask);
        result->setObjectName("result");
        result->setGeometry(QRect(50, 475, 541, 51));
        result->setFont(font1);
        label_8 = new QLabel(Addtask);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(40, 450, 91, 21));
        label_8->setFont(font1);

        retranslateUi(Addtask);

        QMetaObject::connectSlotsByName(Addtask);
    } // setupUi

    void retranslateUi(QWidget *Addtask)
    {
        Addtask->setWindowTitle(QCoreApplication::translate("Addtask", "Form", nullptr));
        label->setText(QCoreApplication::translate("Addtask", "Add task", nullptr));
        label_2->setText(QCoreApplication::translate("Addtask", "Task name:", nullptr));
        label_3->setText(QCoreApplication::translate("Addtask", "Priority:", nullptr));
        label_4->setText(QCoreApplication::translate("Addtask", "Category:", nullptr));
        label_5->setText(QCoreApplication::translate("Addtask", "Reminder Time:", nullptr));
        label_6->setText(QCoreApplication::translate("Addtask", "Detail:", nullptr));
        label_7->setText(QCoreApplication::translate("Addtask", "Start Time:", nullptr));
        stime->setDisplayFormat(QCoreApplication::translate("Addtask", "yyyy/M/d hh:mm", nullptr));
        rtime->setDisplayFormat(QCoreApplication::translate("Addtask", "yyyy/M/d hh:mm", nullptr));
        prio->setItemText(0, QCoreApplication::translate("Addtask", "LOW", nullptr));
        prio->setItemText(1, QCoreApplication::translate("Addtask", "MODERATE", nullptr));
        prio->setItemText(2, QCoreApplication::translate("Addtask", "HIGH", nullptr));

        cat->setItemText(0, QCoreApplication::translate("Addtask", "LIFE", nullptr));
        cat->setItemText(1, QCoreApplication::translate("Addtask", "STUDY", nullptr));
        cat->setItemText(2, QCoreApplication::translate("Addtask", "ENTERTAINMENT", nullptr));

        pushButton->setText(QCoreApplication::translate("Addtask", "Add", nullptr));
        label_8->setText(QCoreApplication::translate("Addtask", "Feedback:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Addtask: public Ui_Addtask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTASK_H
