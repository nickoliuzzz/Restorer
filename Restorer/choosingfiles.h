#ifndef CHOOSINGFILES_H
#define CHOOSINGFILES_H

#include <QMainWindow>
#include "ui_choosingfiles.h"
#include <QList>
#include <QCheckBox>
#include <QStringList>
#include <QWidgetList>
#include <QListWidgetItem>


namespace Ui {
class ChoosingFiles;
}

class ChoosingFiles : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChoosingFiles(QWidget *parent = 0);
    ~ChoosingFiles();

private:
    Ui::ChoosingFiles *ui;
};

#endif // CHOOSINGFILES_H
