#include "passwindow.h"
#include "ui_passwindow.h"

PassWindow::PassWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PassWindow)
{
    ui->setupUi(this);
}

PassWindow::~PassWindow()
{
    delete ui;
}
