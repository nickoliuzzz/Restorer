#ifndef CHOOSEFORMAT_H
#define CHOOSEFORMAT_H

#include <QMainWindow>
#include "searching.h"
#include "ntfs.h"
#include <QMessageBox>

namespace Ui {
class ChooseFormat;
}

class ChooseFormat : public QMainWindow
{
    Q_OBJECT
    NTFS *ntfs;
public:
    explicit ChooseFormat(QWidget *parent = 0);
    ~ChooseFormat();
    void takeNTFS(NTFS *ntfs);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ChooseFormat *ui;
};

#endif // CHOOSEFORMAT_H
