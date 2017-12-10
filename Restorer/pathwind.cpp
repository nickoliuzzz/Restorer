#include "pathwind.h"


QString fileName;

PathWind::PathWind(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PathWind)
{
    ui->setupUi(this);

}

PathWind::~PathWind()
{
    delete ui;
}

QString PathWind::on_pushButton_clicked()
{
    fileName = QFileDialog::getExistingDirectory();
    qDebug() << fileName;
    if (fileName.isEmpty()) //If user choice nothing
        return NULL;
    ui->lineEdit->setText(fileName);
    return fileName;
}

void PathWind::on_pushButton_2_clicked()
{
    if(fileName.isEmpty()) {
        QMessageBox::information(this,"Вы не выбрали путь","Укажите путь");
    }
    else{
        ntfs = new NTFS;
        ChoosingPlaceForSave *form  = new ChoosingPlaceForSave();
        form->show();
        ntfs->setPath(fileName);
        ntfs->setAllDisk(false);
        form->takeNTFS(ntfs);
        this->setVisible(false);


    }
}
