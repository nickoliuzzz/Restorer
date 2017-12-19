#ifndef threadOfSearchSEARCH_H
#define threadOfSearchSEARCH_H

#include <QObject>

#include <ntfs.h>
#include <QListWidget>
//#include "searching.h"
#include <QStringList>
#include <QThread>
#include <QDataStream>

class threadOfSearch : public QObject
{
   Q_OBJECT
private:

    NTFS *ntfs;
    QListWidget *ui;
    QStringList list;

public:
    explicit threadOfSearch();
    void takeNTFS(NTFS *ntf);
    void takeUI(QListWidget *ui1);
    int getMaxOfProgress();
    void run();
    QStringList getList();


signals:
    void send();


};


#endif // threadOfSearchSEARCH_H
