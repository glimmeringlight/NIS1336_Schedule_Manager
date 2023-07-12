#include "user.h"
#include "ui_user.h"

User::User(QString user, QString pwd, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::User),
    username(user),
    password(pwd),
    process(new QProcess(this)),
    remindtext("")
{
    ui->setupUi(this);

    QFont font("Courier New");
    ui->task_list->setFont(font);
    ui->remind->setFont(font);

//    ui -> remind -> setText("Now you have no task to do.");

    // Remind
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &User::Reminder);
    timer->setInterval(3000);
    timer->start();


    // task list
    QProcess* m_proces_bash = new QProcess;
    m_proces_bash->setProcessEnvironment(QProcessEnvironment::systemEnvironment());

    QString welcome_msg = " Hello " + username + ".";
    ui -> welcome -> setText(welcome_msg);

    QStringList command;
    command << "show" << "-u" << username << "-p" << password;

    m_proces_bash->start("./cli", command);

    if (m_proces_bash->waitForStarted() && m_proces_bash->waitForFinished()){

        QByteArray output = m_proces_bash->readAllStandardOutput();
        QString outputString(output);
        ui -> task_list -> setText(outputString);
    }
    else
    {
        // 处理启动失败或执行超时的情况
        ui -> task_list -> setText("Fail to connect.");
    }

}

User::~User()
{
    delete ui;
    delete process;
}




void User::Reminder()
{

    QProcess* m_proces_bash = new QProcess;
    m_proces_bash->setProcessEnvironment(QProcessEnvironment::systemEnvironment());
    QStringList command;
    command << "check" << "-u" << username << "-p" << password;
    m_proces_bash->start("./cli", command);

    if (m_proces_bash->waitForStarted() && m_proces_bash->waitForFinished()){

        QByteArray output = m_proces_bash->readAllStandardOutput();
        QString outputString(output);
        ui -> remind -> setText(outputString);
        if(outputString.isEmpty()){
            ui -> remind -> append("Now you have no task to do.");
        }
        else{
                ui -> remind-> append(remindtext);
        }

    }
    else
    {
        // 处理启动失败或执行超时的情况
        ui -> remind -> setText("Fail to connect.");
    }

}

void User::Refresh()
{
    QProcess* m_proces_bash = new QProcess;
    m_proces_bash->setProcessEnvironment(QProcessEnvironment::systemEnvironment());

    QStringList command;
    command << "show" << "-u" << username << "-p" << password;

    m_proces_bash->start("./cli", command);

    if (m_proces_bash->waitForStarted() && m_proces_bash->waitForFinished()){

        QByteArray output = m_proces_bash->readAllStandardOutput();
        QString outputString(output);
        ui -> task_list -> setText(outputString);
    }
    else
    {
        ui -> task_list -> setText("Fail to connect.");
    }

}



void User::on_add_clicked()
{
    Addtask *addtask = new Addtask(username,password);
    connect(addtask, &Addtask::taskAdded, this, &User::Refresh);
    addtask -> show();
}

void User::on_delete_2_clicked()
{
    DeleteTask *deletetask = new DeleteTask(username,password);
    connect(deletetask, &DeleteTask::taskDeleted, this, &User::Refresh);
    deletetask -> show();
}

void User::on_logout_clicked()
{
    Widget *widget = new Widget;
    widget -> show();
    this -> close();
}


void User::on_pushButton_clicked()
{
    reminder *remind = new reminder(username,password);
    remind -> show();
}

void User::on_modify_clicked()
{
    Alttask *alt = new Alttask(username,password);
    connect(alt, &Alttask::taskAlted, this, &User::Refresh);
    alt -> show();
}
