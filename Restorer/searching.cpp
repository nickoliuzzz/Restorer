#include "searching.h"


Searching::Searching(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Searching)
{
    ui->setupUi(this);
}

Searching::~Searching()
{
    delete ui;
}
