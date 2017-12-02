#include "searching.h"
#include "ui_searching.h"
#include <QString>

Searching::Searching(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Searching)
{
    ui->setupUi(this);
    ui->ListOfFiles->setVerticalScrollBar(ui->verticalScrollBar);
    ui->ListOfFiles->setReadOnly(true);
    QString html;
    html +="1 <br> 2<br>3<br>4<br>5<br>6<br>7<br>8<br>9<br>0<br>11<br>22<br>33\n";
    ui->ListOfFiles->setHtml(html);
}

Searching::~Searching()
{
    delete ui;
}
