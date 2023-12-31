#include "addtask.h"
#include "ui_addtask.h"

Addtask::Addtask(QString user, QString pwd, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Addtask)
{
    ui->setupUi(this);
    username = user;
    password = pwd;
}

Addtask::~Addtask()
{
    delete ui;
}



QString convert(const QString& inputDateTime) {

    QDateTime dateTime = QDateTime::fromString(inputDateTime, "yyyy/MM/dd hh:mm:ss");
    if (!dateTime.isValid()) {
        dateTime = QDateTime::fromString(inputDateTime, "yyyy/MM/dd hh:mm:ss");
    }
    if (!dateTime.isValid()) {
        dateTime = QDateTime::fromString(inputDateTime, "yyyy/M/dd hh:mm:ss");
    }
    if (!dateTime.isValid()) {
        dateTime = QDateTime::fromString(inputDateTime, "yyyy/MM/d hh:mm:ss");
    }
    if (dateTime.isValid()) {
        QString outputDateTime = dateTime.toString("yyyy-MM-dd,HH:mm:ss");
        return outputDateTime;
    } else {
        return QString();
    }
}


void Addtask::on_pushButton_clicked()
{


    QProcess* m_proces_bash = new QProcess;
    m_proces_bash->setProcessEnvironment(QProcessEnvironment::systemEnvironment());

    QString name = ui -> tname -> text();

    QString start_time_raw = ui->stime->text();
    QString start_time = convert(start_time_raw);

    QString rem_time_raw = ui->rtime->text();
    QString rem_time = convert(rem_time_raw);


    QString priority = ui -> prio -> currentText();
    QString category = ui -> cat -> currentText();

    QString detail = ui -> det -> text();
    if( detail == "" ) detail = "No detail.";

    QStringList command;
    command << "add" << "-u" << username << "-p" << password << "-n" << name << "-o" << priority << "-c" << category << "-r" <<rem_time << "-d" << detail << "-s" << start_time;

    m_proces_bash->start("./cli", command);


    if (m_proces_bash->waitForStarted() && m_proces_bash->waitForFinished()){

        QByteArray output = m_proces_bash->readAllStandardOutput();
        QString outputString(output);
        ui -> result -> setText(outputString);
        emit taskAdded();

    }
    else
    {
        ui -> result -> setText("Fail to connect.");
    }

}
