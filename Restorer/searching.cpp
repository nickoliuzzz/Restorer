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
    threa.takeNTFS(ntfs);
    threa.takeUI(ui->listWidget);
    ui->statusbar->setMaximumWidth((int)threa.getMaxOfProgress());


}

void Searching::on_pushButton_2_clicked()
{
        threa.run();
}
