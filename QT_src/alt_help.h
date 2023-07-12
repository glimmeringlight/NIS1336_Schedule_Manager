#ifndef ALT_HELP_H
#define ALT_HELP_H

#include <QWidget>

namespace Ui {
class Alt_Help;
}

class Alt_Help : public QWidget
{
    Q_OBJECT

public:
    explicit Alt_Help(QWidget *parent = nullptr);
    ~Alt_Help();

private:
    Ui::Alt_Help *ui;
};

#endif // ALT_HELP_H
