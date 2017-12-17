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
    datas getData();
    QString getName();
    FilesInfo();
    FilesInfo(datas,QString);
    FilesInfo& operator=(const FilesInfo& right);

};

#endif // FILESINFO_H
