#ifndef MAINWIND_H
#define MAINWIND_H

#include <QMainWindow>

namespace Ui {
class MainWind;
}

class MainWind : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWind(QWidget *parent = 0);
    ~MainWind();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWind *ui;
};

#endif // MAINWIND_H
