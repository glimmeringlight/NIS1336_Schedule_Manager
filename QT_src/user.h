#ifndef USER_H
#define USER_H

#include <QWidget>
#include "Head.h"
#include "addtask.h"
#include "deletetask.h"
#include "widget.h"
#include "reminder.h"


namespace Ui {
class User;
}

class User : public QWidget
{
    Q_OBJECT

public:
    explicit User(QString username, QString password, QWidget *parent = nullptr);
    ~User();

private slots:
    void on_add_clicked();

    void on_delete_2_clicked();

    void on_logout_clicked();

    void Reminder();

    void Refresh();


    void on_pushButton_clicked();

private:
    Ui::User *ui;
    QString username;
    QString password;
    QProcess *process;
    QString remindtext;
};

#endif // USER_H
