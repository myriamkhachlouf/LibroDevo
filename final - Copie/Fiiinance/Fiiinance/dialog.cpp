#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}


Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    mainwindow= new MainWindow(this);
             mainwindow->show();


}

void Dialog::on_pushButton_2_clicked()
{
    Mainwindows= new mainwindows(this);
             Mainwindows->show();
}

void Dialog::on_pushButton_4_clicked()
{
    R1 = new Recherche_Emp(this);
             R1->show();

}

void Dialog::on_pushButton_3_clicked()
{
    R2 = new Recherche_Achat(this);
             R2->show();
}
