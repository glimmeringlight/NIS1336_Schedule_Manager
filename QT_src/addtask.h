#ifndef ADDTASK_H
#define ADDTASK_H

#include <QWidget>
#include "Head.h"

namespace Ui {
class Addtask;
}

class Addtask : public QWidget
{
    Q_OBJECT

public:
    explicit Addtask(QString user, QString pwd, QWidget *parent = nullptr);
    ~Addtask();

private slots:
    void on_pushButton_clicked();

signals:
    void taskAdded();

private:
    Ui::Addtask *ui;
    QString username;
    QString password;
};

#endif // ADDTASK_H
