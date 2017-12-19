#include "choosingfiles.h"


ChoosingFiles::ChoosingFiles(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChoosingFiles)
{
     ui->setupUi(this);

    //QListWidget* widget;
    QWidgetList checkboxes;


  //  ui->listWidget->addScrollBarWidget(ui->verticalScrollBar);




  //  QStringList list;

 //   for(int i = 0 ; i < 20; i++){
  //      list.push_back(QString('a'+i));
  //  }
  //  ui->listWidget_2->addItems(list);
    ui->listWidget_2->setVerticalScrollBar(ui->verticalScrollBar);

    QListWidgetItem* item = 0;
      for(int i = 0; i < ui->listWidget_2->count(); ++i){
          item = ui->listWidget_2->item(i);
          item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
          item->setCheckState(Qt::Unchecked);
      }

 //   ui->listWidget_3->addItems(list);
  //  ui->listWidget_3->setVerticalScrollBar(ui->verticalScrollBar);

}

void ChoosingFiles::takeList(QStringList lis){
    list = lis;
    ui->listWidget_2->addItems(list);

}
void ChoosingFiles::takeNTFS(NTFS * ntf){
    ntfs = ntf;
}



ChoosingFiles::~ChoosingFiles()
{
    delete ui;
}

void ChoosingFiles::on_pushButton_clicked()
{
    QList<FilesInfo> files = ntfs->getFiles();
    int n = files.size();
    for(int i = 0; i < n; i++){
        ntfs->restore(files.at(i),i);
    }
}
