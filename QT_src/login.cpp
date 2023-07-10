#include "login.h"
#include "ui_login.h"


Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui -> pwd -> setEchoMode(QLineEdit::Password);

}

Login::~Login()
{
    delete ui;
}

void Login::on_login_clicked()
{

    QProcess* m_proces_bash = new QProcess;
//    m_proces_bash->setProcessEnvironment(QProcessEnvironment::systemEnvironment());

    QString username = ui -> uname -> text();
    QString password = ui -> pwd -> text();

    QStringList command;
    command << "login" << "-u" << username << "-p" << password;

    m_proces_bash->start("./bin/cli", command);


    if (m_proces_bash->waitForStarted() && m_proces_bash->waitForFinished()){

        QByteArray output = m_proces_bash->readAllStandardOutput();
        QString outputString(output);

        if( outputString == "Incorrect user name or password. Please check your input.\n" || outputString == "Too few arguments!\n"){
            ui -> result -> setText(outputString);
        }
        else{
            ui -> result -> setText(outputString);
            User *user = new User(username,password);
            user -> show();
            this -> close();
        }


    }
    else
    {
        // 处理启动失败或执行超时的情况
        ui -> result -> setText("Fail to connect.");
    }




}

void Login::on_back_clicked()
{
    Widget *widget = new Widget;
    widget -> show();
    this -> close();
}
