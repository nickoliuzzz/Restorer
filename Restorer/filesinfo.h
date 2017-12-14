#ifndef FILESINFO_H
#define FILESINFO_H

#include <QQueue>
#include <QString>
#include <datas.h>



class FilesInfo
{
    datas data;
    QString name;
public:
    FilesInfo();
    FilesInfo(datas,QString);
    void Restore();

};

#endif // FILESINFO_H
