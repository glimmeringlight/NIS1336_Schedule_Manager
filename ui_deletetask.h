/********************************************************************************
** Form generated from reading UI file 'deletetask.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETETASK_H
#define UI_DELETETASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeleteTask
{
public:
    QLabel *label;
    QLineEdit *number;
    QPushButton *pushButton;
    QLabel *label_2;
    QTextBrowser *result;

    void setupUi(QWidget *DeleteTask)
    {
        if (DeleteTask->objectName().isEmpty())
            DeleteTask->setObjectName(QString::fromUtf8("DeleteTask"));
        DeleteTask->resize(634, 318);
        label = new QLabel(DeleteTask);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 80, 331, 21));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        number = new QLineEdit(DeleteTask);
        number->setObjectName(QString::fromUtf8("number"));
        number->setGeometry(QRect(390, 75, 81, 31));
        pushButton = new QPushButton(DeleteTask);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(410, 150, 131, 51));
        pushButton->setFont(font);
        label_2 = new QLabel(DeleteTask);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 220, 101, 17));
        label_2->setFont(font);
        result = new QTextBrowser(DeleteTask);
        result->setObjectName(QString::fromUtf8("result"));
        result->setGeometry(QRect(60, 240, 481, 51));
        result->setFont(font);

        retranslateUi(DeleteTask);

        QMetaObject::connectSlotsByName(DeleteTask);
    } // setupUi

    void retranslateUi(QWidget *DeleteTask)
    {
        DeleteTask->setWindowTitle(QApplication::translate("DeleteTask", "Form", nullptr));
        label->setText(QApplication::translate("DeleteTask", "The task number you want to delete:", nullptr));
        pushButton->setText(QApplication::translate("DeleteTask", "Commit", nullptr));
        label_2->setText(QApplication::translate("DeleteTask", "Feedback:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteTask: public Ui_DeleteTask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETETASK_H
