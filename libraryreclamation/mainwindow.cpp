#include "mainwindow.h"
#include "ui_mainwindow.h"

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
{

        QString username= ui->lineEdit->text();
        QString password=ui->lineEdit_2->text();
        if (username == "hamadi" && password == "157842")
    {
            QMessageBox::information(this, "login", "login done successfully");
            hide();
            recl= new reclamation(this);
            recl->show();


        }
        else
            QMessageBox::warning(this, "login", "login failed");



}

void MainWindow::on_pushButton_2_clicked()
{
    close();
}
/*bool MainWindow::traitment_en_retard()
{
int c1,c2;
    bool test;
    QString d1,d,du;
    QDate d2;
    QSqlQuery query;
QString res="non traitée";
    QString dated1 = QDate::currentDate().toString();
    query.prepare("select RECLAMATION.ID , RECLAMATION.DATED from RECLAMATION where ETAT='"+res+"'");


    while (query.next()) {

           d1= query.value(0).toString();
           d2=query.value(1).toDate();


    }
    d=d2.toString();

    du=d[8]+d[9];



}*/