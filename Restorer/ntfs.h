#ifndef NTFS_H
#define NTFS_H

#pragma once

#include <QFile>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QMessageBox>
#include <QQueue>
#include <filesinfo.h>
#include <QList>


#define SIZ 1024
#define SIXBYTES 281474976710656
#define FOURBYTES 4294967296


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

    QList<FilesInfo> files;

    unsigned long long  number;
    unsigned long long int adress;

    QQueue<size> MFTSt;
    QQueue<size> BitMap;
    QQueue<size> MapOfClasters;



public:
    NTFS();
    void start();
    void init();
    void fullPath();
    void findLVS();             // find adree of choosed folder
    void checkLVS(QString);

    bool compareTag(QString);

    QString getPath();
    QStringList getFormats();
    QString getPlaceForSave();

    void setPath(QString);
    void setAllDisk(bool);   
    void setPlaceForSave(QString);    
    void addFormat(QString);

    void goTo( long long int clast);
    void goTosector( long long int, long long int);
    MFT* takeNextMFT(char *);
};



#endif // NTFS_H
