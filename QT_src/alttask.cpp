#include "alttask.h"
#include "ui_alttask.h"

Alttask::Alttask(QString user, QString pwd, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Alttask)
{
    ui->setupUi(this);
    username = user;
    password = pwd;
}

Alttask::~Alttask()
{
    delete ui;
}

void Alttask::on_help_clicked()
{
    Alt_Help *help = new Alt_Help;
    help -> show();
}

void Alttask::on_commit_clicked()
{

    QString number = ui -> id -> text();

    QString item;
    if ( ui->item->currentText() == "Task Name" )
    {
        item = "-n";
    }
    else if ( ui->item->currentText() == "Start Time" )
    {
        item = "-s";
    }
    else if ( ui->item->currentText() == "Priority" )
    {
        item = "-o";
    }
    else if ( ui->item->currentText() == "Category" )
    {
        item = "-c";
    }
    else if ( ui->item->currentText() == "Remind Time" )
    {
        item = "-r";
    }
    else if ( ui->item->currentText() == "Details" )
    {
        item = "-d";
    }





    QString cont = ui -> content -> text();

    if( item == "-d" && cont == "" ) cont = "No Detail.";




    QProcess* process = new QProcess;
    process->setProcessEnvironment(QProcessEnvironment::systemEnvironment());

    QStringList command;
    command << "alt" << "-u" << username << "-p" << password << "-i" << number << item << cont;

    process->start("./cli", command);

    if (process->waitForStarted() && process->waitForFinished()){

        QByteArray output = process->readAllStandardOutput();
        QString outputString(output);
        ui -> result -> setText(outputString);
        emit taskAlted();
    }
    else
    {
        // 处理启动失败或执行超时的情况
        ui -> result -> setText("Fail to connect.");
    }


//    ui -> test -> setText(command);



}
