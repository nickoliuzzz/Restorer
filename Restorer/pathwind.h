#ifndef PATHWIND_H
#define PATHWIND_H

#include <QMainWindow>
#include "ui_pathwind.h"
#include <QFile>
#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QLineEdit>
#include <QMetaObject>
#include "choosingplaceforsave.h"
#include <QMessageBox>
#include "ntfs.h"


namespace Ui {
class PathWind;
}

class PathWind : public QMainWindow
{
    Q_OBJECT
    NTFS *ntfs;
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
