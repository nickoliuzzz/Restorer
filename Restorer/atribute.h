#ifndef ATRIBUTE_H
#define ATRIBUTE_H


class Atribute
{
    int atributeMode;
    int sizeOfAtribute;
    char flag;						//resident 0 / ne residend 1
    char sizeOfName;
    short smName;
    short flags;					//razriazen 0x80000 /zashifovan 0x000040/ szat 0x00001
    short idAtribute;
public:
    Atribute();

};

#endif // ATRIBUTE_H
