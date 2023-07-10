/********************************************************************************
** Form generated from reading UI file 'deletetask.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
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
            DeleteTask->setObjectName("DeleteTask");
        DeleteTask->resize(634, 318);
        label = new QLabel(DeleteTask);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 80, 331, 21));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        number = new QLineEdit(DeleteTask);
        number->setObjectName("number");
        number->setGeometry(QRect(390, 75, 81, 31));
        pushButton = new QPushButton(DeleteTask);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(410, 150, 131, 51));
        pushButton->setFont(font);
        label_2 = new QLabel(DeleteTask);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 220, 101, 17));
        label_2->setFont(font);
        result = new QTextBrowser(DeleteTask);
        result->setObjectName("result");
        result->setGeometry(QRect(60, 240, 481, 51));
        result->setFont(font);

        retranslateUi(DeleteTask);

        QMetaObject::connectSlotsByName(DeleteTask);
    } // setupUi

    void retranslateUi(QWidget *DeleteTask)
    {
        DeleteTask->setWindowTitle(QCoreApplication::translate("DeleteTask", "Form", nullptr));
        label->setText(QCoreApplication::translate("DeleteTask", "The task number you want to delete:", nullptr));
        pushButton->setText(QCoreApplication::translate("DeleteTask", "Commit", nullptr));
        label_2->setText(QCoreApplication::translate("DeleteTask", "Feedback:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteTask: public Ui_DeleteTask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETETASK_H
