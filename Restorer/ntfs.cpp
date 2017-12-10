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

void NTFS::fullPath(){

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




