#ifndef DELETETASK_H
#define DELETETASK_H

#include <QWidget>
#include "Head.h"

namespace Ui {
class DeleteTask;
}

class DeleteTask : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteTask(QString user, QString pwd, QWidget *parent = nullptr);
    ~DeleteTask();

private slots:
    void on_pushButton_clicked();

signals:
    void taskDeleted();

private:
    Ui::DeleteTask *ui;
    QString username;
    QString password;
};

#endif // DELETETASK_H
