#ifndef ALTTASK_H
#define ALTTASK_H

#include <QWidget>
#include "alt_help.h"
#include "Head.h"

namespace Ui {
class Alttask;
}

class Alttask : public QWidget
{
    Q_OBJECT

public:
    explicit Alttask(QString username, QString password, QWidget *parent = nullptr);
    ~Alttask();

private slots:
    void on_help_clicked();

    void on_commit_clicked();

signals:
    void taskAlted();

private:
    Ui::Alttask *ui;
    QString username;
    QString password;
};

#endif // ALTTASK_H
