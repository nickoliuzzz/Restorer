#include "searching.h"


Searching::Searching(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Searching)
{
    ui->setupUi(this);
    ui->statusbar->clearMessage();

    QThread *thread = new QThread;
   // threa = new threadOfSearch(parent);
    threa  = new threadOfSearch();
    threa->moveToThread(thread);

    connect(threa,SIGNAL(send() ),this, SLOT(getString() ) );
}

Searching::~Searching()
{
    delete ui;
}

void Searching::takeNTFS(NTFS *ntf){
    ntfs = ntf;
    ntfs->start();
    ntfs->init();
    threa->takeNTFS(ntfs);
    threa->takeUI(ui->listWidget);
    ui->statusbar->setMaximumWidth((int)threa->getMaxOfProgress());


}

void Searching::on_pushButton_2_clicked()
{
        threa->run();
        list = threa->getList();
}



void Searching::getString(){
    ui->listWidget->clear();
    ui->listWidget->addItems(threa->getList());
     QMessageBox::information(this,"Готово","Укажите форматы");
}

void Searching::on_pushButton_clicked()
{
    ChoosingFiles *form  = new ChoosingFiles();
    form->show();
    this->setVisible(false);
    form->takeNTFS(ntfs);
    form->takeList(list);
}
