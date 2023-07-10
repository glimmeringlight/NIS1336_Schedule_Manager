#ifndef CHANGEPWD_H
#define CHANGEPWD_H

#include <QWidget>
#include "Head.h"
#include "widget.h"


namespace Ui {
class Changepwd;
}

class Changepwd : public QWidget
{
    Q_OBJECT

public:
    explicit Changepwd(QWidget *parent = nullptr);
    ~Changepwd();

private slots:
    void on_commit_clicked();

    void on_back_clicked();

private:
    Ui::Changepwd *ui;
};

#endif // CHANGEPWD_H
