#include "threadOf.h"

threadOf::threadOf()
{
    stop = false;
}

void threadOf::takeNTFS(NTFS *ntf){
    ntfs = ntf;
}


void threadOf::run(){
    ntfs->findLVS();
    QQueue<size> temp = ntfs->getMFTst();

    unsigned long long i = 0;
    unsigned long long siz = 0;
    unsigned long long number = 0;
    unsigned long long col = 0;
    char* buf = new char[SIZ];

    MFT* mft;
    FILE_NAME* name;
    Atribute* atr;

    QStringList list;
 //   ntfs->goTosector(0,0);//
    while (temp.size() != 0) {
        siz = temp.first().size1 * ntfs->getSectorInClast() ;
        i += temp.first().start;

        while(siz--){
            if(stop) return;
           ntfs->goTosector(i, col);
            mft = ntfs->takeNextMFT(buf);
            col++;
            if(!mft->chek()) continue;
            number++;

            name = mft->takeName(mft->takeResident(mft->searchAtribute(mft,48)));
            if(!ntfs->getAllDisk())
                if((unsigned long long)name->rootAdress != ntfs->getAdress()) continue;

            QString tempName = mft->takeStringOfName();
            if(!ntfs->compareTag(tempName)) continue;

            if(mft->Linkes == 0) {
                qDebug() << number;
            }


            if(!ntfs->checkDeleted(mft,col)) continue;  //if MFT is already using



            datas dat(mft->searchAtribute(mft,128));

            FilesInfo tmp(dat,mft->takeStringOfName());

            ntfs->addDatas(tmp);
            list.push_back(mft->takeStringOfName() + "  " + dat.getStringOfSize());

            ui->clear();
            ui->addItems(list);
        }
        temp.pop_front();
    }
}

void threadOf::takeUI(QListWidget *ui1){
    ui = ui1;
}

int threadOf::getMaxOfProgress(){
    QQueue<size> temp = ntfs->getMFTst();
    unsigned long long i = 0;

    while(temp.size() != 0) {
        i += temp.first().size1;
        temp.pop_front();
    }
    return i;

}
