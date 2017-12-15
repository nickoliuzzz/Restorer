#include "threadforsearch.h"

threadForSearch::threadForSearch()
{

}

void threadForSearch::takeNTFS(NTFS *ntf){
    ntfs = ntf;
}


void threadForSearch::run(){
    ntfs->findLVS();

}



void threadForSearch::stop(){
    this->exit(0);
}
