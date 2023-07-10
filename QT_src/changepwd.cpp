#include "changepwd.h"
#include "ui_changepwd.h"

Changepwd::Changepwd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Changepwd)
{
    ui->setupUi(this);

    ui -> oldpwd -> setEchoMode(QLineEdit::Password);
    ui -> newpwd -> setEchoMode(QLineEdit::Password);

}

Changepwd::~Changepwd()
{
    delete ui;
}

void Changepwd::on_commit_clicked()
{


    QProcess* m_proces_bash = new QProcess;
    m_proces_bash->setProcessEnvironment(QProcessEnvironment::systemEnvironment());

    QString username = ui -> uname -> text();
    QString oldpassword = ui -> oldpwd -> text();
    QString newpassword = ui -> newpwd -> text();


    QStringList command;
    command << "passwd" << "-u" << username << "-p" << oldpassword << "-n" << newpassword;

    m_proces_bash->start("./bin/cli", command);


    if (m_proces_bash->waitForStarted() && m_proces_bash->waitForFinished()){

        QByteArray output = m_proces_bash->readAllStandardOutput();
        QString outputString(output);
        ui -> result -> setText(outputString);

    }
    else
    {
        // 处理启动失败或执行超时的情况
        ui -> result -> setText("Fail to connect.");
    }










}

void Changepwd::on_back_clicked()
{
    Widget *widget = new Widget;
    widget -> show();
    this -> close();
}
