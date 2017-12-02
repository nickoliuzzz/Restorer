#include "mainwind.h"
#include "ui_mainwind.h"
#include "pathwind.h"
#include "choosingfiles.h"

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
    PathWind *form = new PathWind();
    form->show();

}


void MainWind::on_pushButton_2_clicked()
{
    ChoosingFiles *form = new ChoosingFiles;
    form->show();
}
