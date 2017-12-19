#include "datas.h"

datas::datas()
{

}


bool datas::isResident() { return resident;}

QQueue<size> datas::getNonResident(){return NonResidentData;}



void datas::datas_s(Resident* temp)
{

    resident = true;
    int i , sm =temp->smAtr, j = temp->sizeOfAtr+temp->smAtr;
    i = sm;
    char* tempBuf = (char*)temp + sm;
    buf = QString::fromLocal8Bit(tempBuf,j-i);

   // }
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


QString datas::getStringOfSize(){
    if(resident) return (QString::number(buf.size()) + "Б");
     QQueue<size> temp = NonResidentData;
     unsigned long long i = 0;
     while(temp.size() != 0){
         i += temp.first().size1;
         temp.pop_front();
     }
     return  QString::number(i) + "KБ";
}


datas& datas::operator=(const datas& right){
    if(this == &right)
        return *this;
    buf = right.buf;
    NonResidentData = right.NonResidentData;
    resident = right.resident;
    return *this;
}


void datas::restoreResident(QFile& file){
    file.write(buf.toUtf8().data(),buf.toUtf8().size());
}
