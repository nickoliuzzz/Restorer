#ifndef NONRESIDENT_H
#define NONRESIDENT_H

#include <atribute.h>

class NonResident
{
    Atribute atr;
    long long int startVCN;		//Íà÷àüíûé âèðòóàëüíûé íîìåð VCN
    long long int endVCN;		//Êîíå÷íûé ñïèñîê
    short smList;
    short sizeZIPEDBloc;
    int nonUsed;
    long long int allocedMem;   //ÂÛäåëåíàÿ ïàìÿòü íà îäåðæèìîå
    long long int realMem; //Ðåàëüíàÿ ïàìÿò
    long long int InitMem;
public:

    NonResident();
};

#endif // NONRESIDENT_H
