#ifndef CHOOSEDISC_H
#define CHOOSEDISC_H

#include <QMainWindow>
#include "ui_choosedisc.h"
#include <QFileSystemModel>
#include <QString>
#include <QDebug>
#include "choosingplaceforsave.h"
#include "ntfs.h"

namespace Ui {
class ChooseDisc;
}

class ChooseDisc : public QMainWindow
{
    Q_OBJECT
    NTFS *ntfs;

public:
    explicit ChooseDisc(QWidget *parent = 0);
    ~ChooseDisc();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_treeView_clicked(const QModelIndex &Index);

private:
    Ui::ChooseDisc *ui;
};

#endif // CHOOSEDISC_H
