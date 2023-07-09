/********************************************************************************
** Form generated from reading UI file 'reminder.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMINDER_H
#define UI_REMINDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reminder
{
public:
    QTextBrowser *result;
    QTextBrowser *test;

    void setupUi(QWidget *reminder)
    {
        if (reminder->objectName().isEmpty())
            reminder->setObjectName(QString::fromUtf8("reminder"));
        reminder->resize(655, 488);
        result = new QTextBrowser(reminder);
        result->setObjectName(QString::fromUtf8("result"));
        result->setGeometry(QRect(60, 50, 531, 192));
        test = new QTextBrowser(reminder);
        test->setObjectName(QString::fromUtf8("test"));
        test->setGeometry(QRect(50, 270, 531, 192));

        retranslateUi(reminder);

        QMetaObject::connectSlotsByName(reminder);
    } // setupUi

    void retranslateUi(QWidget *reminder)
    {
        reminder->setWindowTitle(QApplication::translate("reminder", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reminder: public Ui_reminder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMINDER_H
