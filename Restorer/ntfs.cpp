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
    formats.sort();
    if(formats[0] == "ALL" || formats[0] == "all") allFormats = true;
    Atribute *tempAtribute = NULL;
    char *buf = (char*)malloc(SIZ);
    MFT *tempMFT = (MFT*)malloc(SIZ);

    goTo(startClasterMFT);
    hFile.read(buf,SIZ);
    number++;
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
    qDebug() << adress;

}


void NTFS::findLVS(){
    if(allDisk) return;
    int i=0, k;
    int stat = 1;
    for(i = 0;i < folder.size(); i++) if(folder[i] == '/') stat++;
    QString tmp = folder;


    for(i = 0; i < stat; i++){
        qDebug() << tmp;
        if (tmp.indexOf('/') > 0 ) k = tmp.indexOf('/');
        else{
            checkLVS(tmp);
            qDebug() << adress;
            return;
        }
        QString temp = tmp.mid(0,k);
        checkLVS(temp);
        qDebug() << adress;
        tmp = tmp.mid(k+1);
    }
}

QQueue<size> NTFS::getMFTst(){
    return MFTSt;
}


void NTFS::checkLVS(QString tmp){
    QQueue<size> temp = MFTSt;
    MFT* mft;
    Atribute* atr;
    FILE_NAME* name;



    char *buf = new char[SIZ];
    unsigned long long i = 0;
    unsigned long long siz = 0;
    unsigned long long debag;


    number =0;

    size sizes = temp.first();


    while(temp.size() != 0){
        temp.pop_front();
        siz = sizes.size1 * 4;
        i += sizes.start;

        goTo(i);

        while(siz--){

            debag = hFile.read(buf,SIZ);
            if(debag != SIZ) exit(2);

            mft = (MFT*)buf;
            if(!mft->chek()) continue;

            number++;

            atr = mft->searchAtribute(mft,48);
            if(atr == NULL) continue;


            name = mft->takeName(mft->takeResident(atr));
            if((unsigned long long)name->rootAdress != adress)
            {continue;}


            while(atr != NULL){
                if(atr->atributeMode == 48){

                    name = mft->takeName(mft->takeResident(atr));
                    if(name->SPACE == 2) continue;

                    QString temp1 = QString((QChar*)((int)name + 66 ),name->LenghtOfName );
                    if(tmp == temp1){
                        qDebug() << temp1;
                        qDebug() << tmp;
                        unsigned long long adr = ((unsigned long long)mft->LSVnumb ) * SIXBYTES;
                        adr += (number - 1);
                        adress = adr;
                        return;
                    }
                }
                if ((int)mft + 1024 < (int)atr + atr->sizeOfAtribute)
                    atr = mft->takeAtribute((MFT*)atr, atr->sizeOfAtribute);
                else break;
            }
        }
        sizes = temp.first();
    }
}

unsigned long long NTFS::getAdress(){
    return adress;
}

bool NTFS::getAllDisk(){
    return allDisk;
}

//return true if
bool NTFS::checkDeleted(MFT *mft, unsigned long long n){
   //if( mft->Linkes != 0) return false;
   if(checkClasters(BitMap,n - 1)) return true;
   return false;
}

bool NTFS::checkClasters(QQueue<size> temp,unsigned long long n){           //return true if claster or MFT not used
    unsigned long long tmp = 0;
    unsigned long long tmpi = 0;
    bool flag = false;
    while (temp.size() != 0) {
        tmp = temp.first().size1 * sizeOfClaster * 8;   //SIZEOFBYTE = 8 bit
        tmpi += temp.first().start;
        if (tmp > n)
        {
            long long clast = n / (sizeOfClaster * 8);
            long long numMft = (n % (sizeOfClaster * 8)) / (sizeOfMFT * 8);
            long long byte = (n % (sizeOfMFT * 8)) / 8;;
            long long bit = n % 8;

            goTosector(tmpi + clast, numMft);

            char c, *buf = new char[SIZ];

            hFile.read(buf,SIZ);

            c = buf[byte];


            flag = !((c >> bit) & 1);
            break;
        }
        n -= tmp;
        temp.pop_front();
    }
    return flag;

}


void NTFS::addDatas(FilesInfo temp){
    files.push_back(temp);
}


bool NTFS::compareTag(QString tmp){

   int k;
   if (tmp.indexOf('.') > 0 ) k = tmp.indexOf('.');
   else return false;

   if(allFormats) return true;

   tmp = tmp.mid(k);

   int i,n = formats.size();
   bool flg = false;
   QString temp;

   for(i=0; i < n; i++){
       temp = formats[i];
       if(tmp == temp.toLower() || temp.toUpper() == tmp){
           flg = true;
           break;
       }
   }
   return flg;
}



void NTFS::fullPath(){
    Disk = path.mid(0, 1);
    if(allDisk) return;
    folder = path.mid(3, path.size()-1);
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
  //  qDebug() << hFile.errorString();
    return (MFT*)buf;
}

unsigned long long NTFS::getSectorInClast(){
    return (sizeOfClaster / sizeOfSetor);
}


