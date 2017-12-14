#ifndef SEARCHING_H
#define SEARCHING_H

#include <QThread>
#include <QMainWindow>
#include "ui_searching.h"
#include <QString>
#include <QStringList>
#include "ntfs.h"

namespace Ui {
class Searching;
}

class Searching : public QMainWindow
{
    Q_OBJECT
    NTFS *ntfs;
    MFT* mft;
    char buf[1024];


public:
    explicit Searching(QWidget *parent = 0);
    ~Searching();
    void takeNTFS(NTFS *ntfs);
private:
    Ui::Searching *ui;
};


#endif // SEARCHING_H
