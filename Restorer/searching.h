#ifndef SEARCHING_H
#define SEARCHING_H

#include <QMainWindow>

namespace Ui {
class Searching;
}

class Searching : public QMainWindow
{
    Q_OBJECT

public:
    explicit Searching(QWidget *parent = 0);
    ~Searching();

private:
    Ui::Searching *ui;
};

#endif // SEARCHING_H
