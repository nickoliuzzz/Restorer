#include "chooseformat.h"
#include "ui_chooseformat.h"

ChooseFormat::ChooseFormat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseFormat)
{
    ui->setupUi(this);
    ui->pushButton->setShortcut(QKeySequence(Qt::Key_Enter));
    ui->InputFormate->setFocus();
}

ChooseFormat::~ChooseFormat()
{
    delete ui;
}


void ChooseFormat::takeNTFS(NTFS* ntf)
{
    this->ntfs = ntf;
    ui->FindingLabel->setText(ntf->getPath());
    ui->SavingLabel->setText(ntf->getPlaceForSave());
}

void ChooseFormat::on_pushButton_clicked()
{
    if(!ui->InputFormate->displayText().isEmpty()){
        ntfs->addFormat(ui->InputFormate->displayText());
        ui->listWidget->clear();
        ui->listWidget->addItems(ntfs->getFormats());
        ui->InputFormate->setText("");
        ui->InputFormate->setFocus();
    }
}

void ChooseFormat::on_pushButton_3_clicked()
{
    if(!ntfs->getFormats().size()) {
        QMessageBox::information(this,"Вы не выбрали форматы","Укажите форматы");
    }
    else{

        Searching *form  = new Searching();
        form->show();
        this->setVisible(false);
        ntfs->fullPath();
        form->takeNTFS(ntfs);

    }
}
