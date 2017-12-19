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
    bool chekAllMemery(datas&);
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
    bool allFormats;
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
    bool checkDeleted(MFT*, unsigned long long);
    bool checkClasters(QQueue<size>,unsigned long long);


    QString getPath();
    QStringList getFormats();
    QString getPlaceForSave();
    unsigned long long getAdress();
    bool getAllDisk();
    QQueue<size> getMFTst();
    unsigned long long getSectorInClast();
    QList<FilesInfo> getFiles();

    void setPath(QString);
    void setAllDisk(bool);   
    void setPlaceForSave(QString);    
    void addFormat(QString);
    void addDatas(FilesInfo);
    void restore(FilesInfo data,unsigned long long i);

    void goTo( long long int clast);
    void goTosector( long long int, long long int);
    MFT* takeNextMFT(char *);
};



#endif // NTFS_H
