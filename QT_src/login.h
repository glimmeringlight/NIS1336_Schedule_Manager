#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "Head.h"
#include "user.h"
#include "widget.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_login_clicked();

    void on_back_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
