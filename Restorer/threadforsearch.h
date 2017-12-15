#ifndef THREADFORSEARCH_H
#define THREADFORSEARCH_H

#include <QThread>
#include <ntfs.h>

class threadForSearch : public QThread
{
    NTFS *ntfs;


public:
    void takeNTFS(NTFS *ntf);
    threadForSearch();



protected:
    void run();
    void stop();
};

#endif // THREADFORSEARCH_H
