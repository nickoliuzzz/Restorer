#ifndef CHOOSINGFILES_H
#define CHOOSINGFILES_H

#include <QMainWindow>
#include "ui_choosingfiles.h"
#include <QList>
#include <QCheckBox>
#include <QStringList>
#include <QWidgetList>
#include <QListWidgetItem>
#include "ntfs.h"



namespace Ui {
class ChoosingFiles;
}

class ChoosingFiles : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChoosingFiles(QWidget *parent = 0);
    ~ChoosingFiles();
    void takeNTFS(NTFS*);
    void takeList(QStringList lis);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ChoosingFiles *ui;
    NTFS* ntfs;
    QStringList list;



};

#endif // CHOOSINGFILES_H
