#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui -> pwd -> setEchoMode(QLineEdit::Password);

}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_clicked()
{
    QProcess* m_proces_bash = new QProcess;
    m_proces_bash->setProcessEnvironment(QProcessEnvironment::systemEnvironment());

    QString username = ui -> uname -> text();
    QString password = ui -> pwd -> text();

    QStringList command;
    command << "reg" << "-u" << username << "-p" << password;

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

void Register::on_pushButton_2_clicked()
{
    Widget *widget = new Widget;
    widget -> show();
    this -> close();
}
