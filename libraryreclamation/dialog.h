#ifndef DIALOG_H
#define DIALOG_H
#include "crudachat.h"
#include "mainwindows.h"
#include <QDialog>
#include "recherche_achat.h"
#include "recherche_emp.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Dialog *ui;
    crudachat *mainwindow;
    mainwindows *Mainwindows;
    Recherche_Emp *R1;
    Recherche_Achat *R2;
};

#endif // DIALOG_H
