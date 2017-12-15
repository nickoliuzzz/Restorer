#include "datas.h"

datas::datas()
{

}


void datas::datas_s(Resident* temp)
{
    char* tempBuf = (char*)temp;
    resident = true;
    int i , sm =temp->smAtr, j = temp->sizeOfAtr+temp->smAtr;
    i = sm;
    for(;i<=j;i++){
        buf.push_back(tempBuf[i]);
    }
}


void datas::datas_s(NonResident *temp){
    resident = false;
    NonResidentData = ((MFT*)temp)->takeQueOfClasters((Atribute*)temp);
}


datas::datas(Atribute* temp)
{
    if(temp->flag == 0) datas_s(((MFT*)temp)->takeResident(temp));
    else datas_s(((MFT*)temp)->takeNonResident(temp));
}


datas& datas::operator=(const datas& right){
    if(this == &right)
        return *this;
    buf = right.buf;
    NonResidentData = right.NonResidentData;
    resident = right.resident;
    return *this;
}
