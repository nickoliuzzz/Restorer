#ifndef MFT_H
#define MFT_H

#include <QQueue>

#define SIZATR 16
#define SIZENONRESIDENT 64
#define SIZERESIDENT 24


struct NonResident;
struct Resident;
struct Atribute;
struct FILE_NAME ;
struct size;




class MFT
{

public:
    char start[4];
    short smMarker;
    short colMarker;
    unsigned long long int LSNnumb;
    unsigned short LSVnumb;
    short Linkes;
    short smAtr;
    short catalogy;
    unsigned int  sizeRealMFT;
    unsigned int sizeAllocedMFT;
    unsigned long long int adress;
    short atribute;
    char ALL[982];




    MFT();
    QQueue<size> takeQueOfClasters(Atribute* temp);
    Atribute* searchAtribute(MFT*, int mode);
    FILE_NAME* takeName(Resident* temp);
    Resident* takeResident(Atribute* temp);
    NonResident* takeNonResident(Atribute * temp);
    Atribute* takeFrstAtribute(MFT* temp);
    Atribute* takeAtribute(MFT* temp,int sm);
    bool chek();

};



struct FILE_NAME {
    long long int rootAdress;
    long long int timeOfCreate;
    long long int timeOfChangeFile;
    long long int timeOfCangeMFT;
    long long int timeOfTouchFile;
    long long int sizeOfFile;			//malloced
    long long int RealSizeOfFile;
    int flags;
    int point;
    char LenghtOfName;
    char SPACE;
    char Name[256];
};

struct Atribute {
    int atributeMode;
    int sizeOfAtribute;
    char flag;						//resident 0 / ne residend 1
    char sizeOfName;
    short smName;
    short flags;
    short idAtribute;
};

struct Resident {
    Atribute atr;
    int sizeOfAtr;
    short smAtr;
};

struct NonResident {
    Atribute atr;
    long long int startVCN;
    long long int endVCN;
    short smList;
    short sizeZIPEDBloc;
    int nonUsed;
    long long int allocedMem;
    long long int realMem;
    long long int InitMem;
};


struct size {
    unsigned long long start;
    unsigned long long size1;
    size& operator=(const size& right);
};




#endif // MFT_H
