#ifndef SEARCHING_H
#define SEARCHING_H

#include <QThread>
#include <QMainWindow>
#include "ui_searching.h"
#include <QString>
#include <QStringList>
#include "ntfs.h"
#include "threadofsearch.h"
#include <choosingfiles.h>

namespace Ui {
class Searching;
}

class Searching : public QMainWindow
{
    Q_OBJECT
    NTFS *ntfs;
    MFT* mft;
    char buf[1024];
    threadOfSearch* threa;


public:
    explicit Searching(QWidget *parent = 0);
    ~Searching();
    void takeNTFS(NTFS *ntfs);
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

public slots:
    void getString();

private:
    Ui::Searching *ui;
    QStringList list;

};


#endif // SEARCHING_H
