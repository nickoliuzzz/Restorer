#ifndef DATAS_H
#define DATAS_H

#include <QString>
#include <QQueue>
#include <mft.h>





class datas
{
    bool resident;
    QQueue<size> NonResidentData;
    QString buf;
    void datas_s(Resident*);
    void datas_s(NonResident*);

public:
    QString getStringOfSize();
    datas();
    datas(Atribute*);
    datas& operator=(const datas& right);

};

#endif // DATAS_H
