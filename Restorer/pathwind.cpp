#include "pathwind.h"
#include "ui_pathwind.h"
#include <QFile>
#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QLineEdit>
#include <QMetaObject>
#include <searching.h>
#include <QMessageBox>


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
        Searching *form  = new Searching();
        form->show();
    }
}
