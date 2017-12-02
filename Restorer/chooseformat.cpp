#include "chooseformat.h"
#include "ui_chooseformat.h"

ChooseFormat::ChooseFormat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseFormat)
{
    ui->setupUi(this);
}

ChooseFormat::~ChooseFormat()
{
    delete ui;
}
