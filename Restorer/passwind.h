#ifndef PASSWIND_H
#define PASSWIND_H

#include <QMainWindow>

namespace Ui {
class PassWind;
}

class PassWind : public QMainWindow
{
    Q_OBJECT

public:
    explicit PassWind(QWidget *parent = 0);
    ~PassWind();

private:
    Ui::PassWind *ui;
};

#endif // PASSWIND_H
