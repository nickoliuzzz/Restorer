#ifndef FILENAME_H
#define FILENAME_H


class FileName
{
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
public:
    FileName();
};

#endif // FILENAME_H
