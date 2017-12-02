#ifndef STEC_H
#define STEC_H

struct adress {
    unsigned long long start;
    unsigned long long size;
};


struct stec {
    adress temp;
    stec *next;
};

class Stec {

    stec *root;
public:
    Stec();
    ~Stec();
    void add(adress);
    size pop();
};

#endif // STEC_H
