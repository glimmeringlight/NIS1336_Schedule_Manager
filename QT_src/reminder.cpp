#include "reminder.h"
#include "ui_reminder.h"

reminder::reminder(QString user, QString pwd, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reminder),
    username(user),
    password(pwd),
    process(new QProcess(this))
{
    ui->setupUi(this);

    ui -> result -> setText("Now you have no task to do.");

    connect(process, &QProcess::readyReadStandardOutput, this, &reminder::Remind);

    process->setProcessEnvironment(QProcessEnvironment::systemEnvironment());

    QStringList command;
    command << "check" << "-u" << username << "-p" << password;

    process->start("./cli", command);
}

reminder::~reminder()
{
    delete ui;
    delete process;
}

void reminder::Remind()
{



    QByteArray output = process->readAllStandardOutput();
    QString remindtext = QString::fromUtf8(output);

    if (remindtext.isEmpty()) {
        ui -> result -> setText("Now you have no task to do.");
    } else {
        ui -> result -> setText(remindtext);
    }
}
