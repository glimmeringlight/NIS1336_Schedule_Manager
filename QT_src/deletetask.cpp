#include "deletetask.h"
#include "ui_deletetask.h"

DeleteTask::DeleteTask(QString user, QString pwd, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteTask)
{
    ui->setupUi(this);
    username = user;
    password = pwd;
}

DeleteTask::~DeleteTask()
{
    delete ui;
}

void DeleteTask::on_pushButton_clicked()
{
    QString id = ui -> number -> text();

    QProcess* process = new QProcess;
    process->setProcessEnvironment(QProcessEnvironment::systemEnvironment());

    QStringList command;
    command << "del" << "-u" << username << "-p" << password << "-i" << id;

    process->start("./bin/cli", command);

    if (process->waitForStarted() && process->waitForFinished()){

        QByteArray output = process->readAllStandardOutput();
        QString outputString(output);
        ui -> result -> setText(outputString);
        emit taskDeleted();
    }
    else
    {
        // 处理启动失败或执行超时的情况
        ui -> result -> setText("Fail to connect.");
    }

}
