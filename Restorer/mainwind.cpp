#include "mainwind.h"


MainWind::MainWind(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWind)
{
    ui->setupUi(this);
}

MainWind::~MainWind()
{
    delete ui;
}

void MainWind::on_pushButton_clicked()
{
    ChooseDisc *form = new ChooseDisc();
    form->show();
    this->setVisible(false);

}


void MainWind::on_pushButton_2_clicked()
{
    PathWind *form = new PathWind;
    form->show();
    this->setVisible(false);

}
