#include "widget.h"
#include "ui_widget.h"

#include "login.h"
#include "register.h"
#include "changepwd.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_login_clicked()
{
    Login *login = new Login;
    login -> show();
    this -> close();
}

void Widget::on_register_2_clicked()
{
    Register *regster = new Register;
    regster -> show();    
    this -> close();
}

void Widget::on_changepwd_clicked()
{
    Changepwd *change = new Changepwd;
    change -> show();
    this -> close();
}





