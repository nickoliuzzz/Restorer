#include "ntfs.h"




NTFS::NTFS()
{    
}

void NTFS::setPath(QString pat){
    this->path = pat;
}

void NTFS::setAllDisk(bool tmp){
    allDisk = tmp;
}


QString NTFS::getPath(){
    return path;
}


QString NTFS::getPlaceForSave(){
    return placeForSave;
}

void NTFS::setPlaceForSave(QString tmp){
    placeForSave = tmp;
}

void NTFS::addFormat(QString tmp){
    formats.push_back(tmp);
}


QStringList NTFS::getFormats(){
    return formats;
}

void NTFS::start(){
    number = 0;
    hFile.setFileName("\\\\.\\"+path[0]+":");
    if (!hFile.open(QIODevice::ReadOnly)) {
        qDebug() << hFile.errorString();
        return;
    }
    qDebug() << "lel";
    char buf[512];
    hFile.read(buf,512);
    startClasterMFT = *(unsigned long long int *)(buf + 48);
    short int BytesPerSector = *(short int*)(buf + 11);
    char SectorsPerCluster = *(char*)(buf + 13);
    numberOfSectors = *(unsigned long long int *)(buf + 40);
    clasterForIndex = *(char*)(buf + 0x44);
    classterForMFT = *(char*)(buf + 0x40);
    sizeOfSetor = (int)BytesPerSector;
    sizeOfClaster = BytesPerSector * SectorsPerCluster;
    char c = *(char*)(buf + 64);
    if (c > 0) sizeOfMFT = sizeOfSetor*c;
    else {
        sizeOfMFT = 1;
        while (c++) sizeOfMFT *= 2;
    }
    qDebug() << sizeOfClaster;
    goTo(startClasterMFT);
    hFile.read(buf,512);
    if(QString(buf).mid(0,6) != "FILE0"){
        exit(1);
    }
}

void NTFS::init(){
    Atribute *tempAtribute = NULL;
    char *buf = (char*)malloc(SIZ);
    MFT *tempMFT = (MFT*)malloc(SIZ);
    goTo(startClasterMFT);
    hFile.read(buf,SIZ);
    memcpy((void*)tempMFT, (void*)buf, SIZ);
    if (!tempMFT->chek()) return;
    tempAtribute = tempMFT->searchAtribute(tempMFT, 128);
    MFTSt =tempMFT->takeQueOfClasters(tempAtribute);
    tempAtribute = tempMFT->searchAtribute(tempMFT, 176);
    BitMap =tempMFT->takeQueOfClasters(tempAtribute);


    while (tempMFT->takeName((Resident*)tempMFT->searchAtribute(tempMFT, 48))->Name[0] != '.') {
        do {
            hFile.read(buf,SIZ);
            number++;
            memcpy((void*)tempMFT, (void*)buf, SIZ);
            if (!tempMFT->chek()) return;
        } while ((tempMFT->searchAtribute(tempMFT, 144) == NULL));
    }

    if ((tempAtribute =tempMFT->searchAtribute(tempMFT, 144)) == NULL) { qDebug() << "ny chto j"; }
    else {
        adress = ((unsigned long long)tempMFT->LSVnumb)*SIXBYTES;
        adress += (number - 1);
    }

    while (tempMFT->LSVnumb != 6) {
        do {
            hFile.read(buf,SIZ);
            number++;
            qDebug() << hFile.errorString();
            memcpy((void*)tempMFT, (void*)buf, SIZ);
            if (!tempMFT->chek()) continue;
        } while ((tempMFT->searchAtribute(tempMFT, 48) == NULL));
    }
    tempAtribute =tempMFT->searchAtribute(tempMFT, 128);
    MapOfClasters =tempMFT->takeQueOfClasters(tempAtribute);
    qDebug() << " konec inita";
}



void NTFS::fullPath(){
    Disk = path;
    if(allDisk) return;
    folder = path.mid(2, path.size()-1);
}



void NTFS::goTo( long long int clast){
    goTosector(clast,0);
}


void NTFS::goTosector( long long int clast, long long int number){
    clast *= sizeOfClaster;
    clast += number * sizeOfMFT;
    hFile.seek(clast);
}


MFT* NTFS::takeNextMFT(char *buf){
    hFile.read(buf,SIZ);
    qDebug() << hFile.errorString();
    return (MFT*)buf;
}


