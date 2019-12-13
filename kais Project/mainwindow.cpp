#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{  QString k;
    k=ui->pass->text();
    if(k==password){gestion g;
        g.exec();}
    }
