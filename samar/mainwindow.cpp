#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion_livre.h"
#include "intermediaire.h"
#include<QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/kamel/Desktop/lib.jpg");
    ui->label_pic->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString username= ui->lineEdit->text();
    QString password=ui->lineEdit_2->text();
    if (username == "samar" && password == "123456")
{
        QMessageBox::information(this, "login", "login done successfully");
      //  hide();
        intermediaire *i=new intermediaire();
        i->show();



    }
    else
        QMessageBox::warning(this, "login", "login failed");

}
