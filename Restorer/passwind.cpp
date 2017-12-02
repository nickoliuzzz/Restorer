#include "passwind.h"
#include "ui_passwind.h"

PassWind::PassWind(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PassWind)
{
    ui->setupUi(this);
}

PassWind::~PassWind()
{
    delete ui;
}
