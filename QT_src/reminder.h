#ifndef REMINDER_H
#define REMINDER_H

#include <QWidget>
#include "Head.h"

namespace Ui {
class reminder;
}

class reminder : public QWidget
{
    Q_OBJECT

public:
    explicit reminder(QString username, QString password, QWidget *parent = nullptr);
    ~reminder();

private slots:
    void Remind();

private:
    Ui::reminder *ui;
    QString username;
    QString password;
    QProcess *process;
};

#endif // REMINDER_H
