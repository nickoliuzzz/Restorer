#include "choosingplaceforsave.h"


ChoosingPlaceForSave::ChoosingPlaceForSave(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChoosingPlaceForSave)
{
    ui->setupUi(this);

}

ChoosingPlaceForSave::~ChoosingPlaceForSave()
{
    delete ui;
}


void ChoosingPlaceForSave::takeNTFS(NTFS* ntf)
{
    this->ntfs = ntf;
    ui->PathFrom->setText(ntf->getPath());
}

void ChoosingPlaceForSave::on_pushButton_clicked()
{
    fileName = QFileDialog::getExistingDirectory();
    qDebug() << fileName;
    if (!fileName.isEmpty())
        ui->lineEdit->setText(fileName);
}

void ChoosingPlaceForSave::on_pushButton_2_clicked()
{
    ChooseFormat *form = new ChooseFormat;
     ntfs->setPlaceForSave(fileName);
    form->takeNTFS(ntfs);

    form->show();
    this->setVisible(false);
}
