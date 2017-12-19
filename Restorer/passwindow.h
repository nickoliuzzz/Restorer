#ifndef PASSWINDOW_H
#define PASSWINDOW_H

#include <QMainWindow>

namespace Ui {
class PassWindow;
}

class PassWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PassWindow(QWidget *parent = 0);
    ~PassWindow();

private:
    Ui::PassWindow *ui;
};

#endif // PASSWINDOW_H
