#ifndef CHOOSINGPLACEFORSAVE_H
#define CHOOSINGPLACEFORSAVE_H

#include <QMainWindow>
#include "ui_choosingplaceforsave.h"
#include "chooseformat.h"
#include "ntfs.h"
#include <QString>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>


namespace Ui {
class ChoosingPlaceForSave;
}

class ChoosingPlaceForSave : public QMainWindow
{
    Q_OBJECT
    NTFS *ntfs;
    QString fileName;

public:
    explicit ChoosingPlaceForSave(QWidget *parent = 0);
    ~ChoosingPlaceForSave();
    void takeNTFS(NTFS *ntfs);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ChoosingPlaceForSave *ui;

};

#endif // CHOOSINGPLACEFORSAVE_H
