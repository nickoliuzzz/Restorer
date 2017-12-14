#include "mft.h"

MFT::MFT()
{

}



Atribute* MFT::takeAtribute(MFT* temp,int sm) {

    if (*(int*)((int(temp) + sm)) == 0xffffffff) return NULL;
    return (Atribute*)((int)temp + sm);
}

Atribute* MFT::takeFrstAtribute(MFT* temp) {
    int sm = (int)temp->smAtr;
    if (sm >= 0)
        return (Atribute*)((int)temp + sm);
    else return NULL;
}

NonResident* MFT::takeNonResident(Atribute * temp) {
    return (NonResident*)temp;
}

Resident* MFT::takeResident(Atribute* temp) {
    return (Resident*)temp;
}

FILE_NAME* MFT::takeName(Resident* temp) {
    return (FILE_NAME*)((int)temp + SIZERESIDENT);
}

Atribute* MFT::searchAtribute(MFT* tempMft, int mode) {

    Atribute *temp = takeFrstAtribute(tempMft);
    if (temp == NULL)  return NULL;
    if (temp->atributeMode == 0) return NULL;
    bool flag = true;
    while (temp != NULL && temp->atributeMode != mode) {
        if (temp->sizeOfAtribute <= 0 || temp->sizeOfAtribute > 256) {
            flag = false;
            break;
        }
        temp = takeAtribute((MFT*)temp, temp->sizeOfAtribute);
    }
    if (flag) return temp;
    return NULL;
}

QQueue<size> MFT::takeQueOfClasters(Atribute* temp){
    QQueue<size> MFTSt;
    NonResident *tmp = takeNonResident(temp);
    long long j1 = 1;
    unsigned long long i1 = 1;

    unsigned char *cm = (unsigned char*)(tmp->smList + (int)tmp);
    while (i1 || j1) {
        unsigned char c = *cm;
        j1 = 0;
        i1 = 0;
        int i = (int)c % 16, j = (int)c / 16;
        cm++;
        int f = j, f1 = i;
        while (i--)
        {
            i1 *= 256;
            i1 += *(cm + i);
        }
        while (f1--) *(cm++);

        while (j--)
        {
            j1 *= 256;
            j1 += *(cm + j);
        }
        while (f--) *(cm++);

        if (j1 != 0) {
            size mem;
            mem.size1 = i1;
            mem.start = j1;
            MFTSt.push_back(mem);
        }
    }
    return MFTSt;
}


bool MFT::chek(){
    QString(start).mid(0,5) == "FILE0";

}



size& size::operator=(const size& right){
    if(this == &right)
        return *this;
    start = right.start;
    size1 = right.size1;
    return *this;
}
