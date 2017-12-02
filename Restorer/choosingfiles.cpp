#include "choosingfiles.h"
#include "ui_choosingfiles.h"
#include <QList>
#include <QCheckBox>
#include <QStringList>
#include <QWidgetList>
#include <QListWidgetItem>

ChoosingFiles::ChoosingFiles(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChoosingFiles)
{
     ui->setupUi(this);

    QListWidget* widget;
    QWidgetList checkboxes;


  //  ui->listWidget->addScrollBarWidget(ui->verticalScrollBar);




    QStringList list;

    for(int i = 0 ; i < 20; i++){
        list.push_back(QString('a'+i));
    }
    ui->listWidget_2->addItems(list);
    ui->listWidget_2->setVerticalScrollBar(ui->verticalScrollBar);

    QListWidgetItem* item = 0;
      for(int i = 0; i < ui->listWidget_2->count(); ++i){
          item = ui->listWidget_2->item(i);
          item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
          item->setCheckState(Qt::Unchecked);
      }

    ui->listWidget_3->addItems(list);
    ui->listWidget_3->setVerticalScrollBar(ui->verticalScrollBar);

}

ChoosingFiles::~ChoosingFiles()
{
    delete ui;
}
