#include "choosedisc.h"


QFileSystemModel *fileModel;
QModelIndex index;
QString mPath;

ChooseDisc::ChooseDisc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseDisc)
{
    ui->setupUi(this);

    fileModel = new QFileSystemModel(this);
    fileModel->setFilter(QDir::Drives);
    fileModel->setRootPath(QString("") );
    ui->treeView->setModel(fileModel);

    ui->Disc->setText(QString(""));

}

ChooseDisc::~ChooseDisc()
{
    delete ui;
}

void ChooseDisc::on_pushButton_clicked()
{
    if(index.isValid()){
        mPath = fileModel->fileInfo(index).absoluteFilePath();
        ui->Disc->setText(mPath.remove(1,mPath.size() - 1));
    }

}

void ChooseDisc::on_pushButton_2_clicked()
{
    if(mPath.isEmpty()) {
        QMessageBox::information(this,"Вы не выбрали путь","Укажите путь");
    }
    else{
        ntfs = new NTFS;
        ChoosingPlaceForSave *form  = new ChoosingPlaceForSave();
        form->show();
        ntfs->setPath(mPath);
        ntfs->setAllDisk(true);
        form->takeNTFS(ntfs);
        this->setVisible(false);
    }
}

void ChooseDisc::on_treeView_clicked(const QModelIndex &Index)
{
    index = Index;
}
