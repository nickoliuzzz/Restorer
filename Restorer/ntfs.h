#ifndef NTFS_H
#define NTFS_H

#pragma once

#include <QFile>
#include <QString>
#include <QStringList>

class NTFS
{
    unsigned int sizeOfClaster;
    unsigned int sizeOfSetor;
    unsigned long long int numberOfSectors;
    unsigned long long int startClasterMFT;
    char classterForMFT;
    char clasterForIndex;
    QString path;
    QString placeForSave;
    int sizeOfMFT;
    QFile hFile;
    QString Disk;
    QString folder;
    bool allDisk;
    QStringList formats;
    unsigned long long int adress;

    void fullPath();
public:
    NTFS();
    QStringList getFormats();
    void setPath(QString);
    void setAllDisk(bool);
    QString getPath();
    void setPlaceForSave(QString);
    QString getPlaceForSave();
    void addFormat(QString);

};



#endif // NTFS_H
