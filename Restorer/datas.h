#ifndef DATAS_H
#define DATAS_H

#include <QString>
#include <QQueue>
#include <mft.h>
#include <QFile>




class datas
{
    bool resident;
    QQueue<size> NonResidentData;
    QString buf;
    void datas_s(Resident*);
    void datas_s(NonResident*);

public:
    bool isResident();
    QQueue<size> getNonResident();
    QString getStringOfSize();
    datas();
    datas(Atribute*);
    datas& operator=(const datas& right);
    void restoreResident(QFile&);
    void restoreNon(QFile&);

};

#endif // DATAS_H
