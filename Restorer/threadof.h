#ifndef THREADOF_H
#define THREADOF_H

#include <ntfs.h>
#include <QListWidget>
//#include "searching.h"
#include <QStringList>
#include <QThread>

class threadOf : public QThread
{
    NTFS *ntfs;
    bool stop;
    QListWidget *ui;


public:
    void takeNTFS(NTFS *ntf);
    void takeUI(QListWidget *ui1);
    threadOf();
    int getMaxOfProgress();
    void run();
};

#endif // THREADOF_H
