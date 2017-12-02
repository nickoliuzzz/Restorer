#ifndef CHOOSEFORMAT_H
#define CHOOSEFORMAT_H

#include <QMainWindow>

namespace Ui {
class ChooseFormat;
}

class ChooseFormat : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChooseFormat(QWidget *parent = 0);
    ~ChooseFormat();

private:
    Ui::ChooseFormat *ui;
};

#endif // CHOOSEFORMAT_H
