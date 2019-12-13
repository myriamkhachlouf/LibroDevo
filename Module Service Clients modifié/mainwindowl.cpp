#include "mainwindowl.h"
#include "ui_mainwindowl.h"
#include<QMessageBox>
#include "mainwindow.h"


MainWindowl::MainWindowl(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowl)
{
    ui->setupUi(this);
}

MainWindowl::~MainWindowl()
{
    delete ui;
}

void MainWindowl::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
        QString password = ui->lineEdit_2->text();

        if(username ==  "myriam" && password == "test") {
            QMessageBox::information(this, "Id", "Id et mot de passe correct");
            hide();
            mainwindow= new MainWindow(this);
            mainwindow->show();
        }
        else {
            QMessageBox::warning(this,"Id", "Id et mot de passe incorrect");
        }
}
