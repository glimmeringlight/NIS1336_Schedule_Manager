#include "alt_help.h"
#include "ui_alt_help.h"

Alt_Help::Alt_Help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Alt_Help)
{
    ui->setupUi(this);
}

Alt_Help::~Alt_Help()
{
    delete ui;
}
