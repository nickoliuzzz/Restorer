#include "searching.h"


Searching::Searching(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Searching)
{
    ui->setupUi(this);
    ui->statusbar->clearMessage();
}

Searching::~Searching()
{
    delete ui;
}

void Searching::takeNTFS(NTFS *ntf){
    ntfs = ntf;
    ntfs->start();
    ntfs->init();
    QThread threadForSearch;

}
