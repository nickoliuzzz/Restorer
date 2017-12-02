#include "stec.h"

Stec::Stec()
{
    stec = NULL;
}

Stec::~Stec ()
{
    while(root != NULL)
    {
        stec *tmp = root->next;
        delete root;
        root = tmp;
    }
}

void Stec::add(adress NewAdress){
    stec now = new stec();
    now->size =NewAdress;
    now->next = NULL;
    if(root == NULL) root = now;
    else
}




