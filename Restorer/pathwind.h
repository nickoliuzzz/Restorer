#ifndef PATHWIND_H
#define PATHWIND_H

#include <QMainWindow>

namespace Ui {
class PathWind;
}

class PathWind : public QMainWindow
{
    Q_OBJECT

public:
    explicit PathWind(QWidget *parent = 0);
    ~PathWind();

private slots:
    QString on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::PathWind *ui;
};

#endif // PATHWIND_H
