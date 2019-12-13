#include "mainwindow.h"
#include <QString>
#include "ui_mainwindow.h"
#include<QDateTime>
#include<QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ZIZOU/Desktop/lib.jpg");
    son=new QSound("C:/Utilisateurs/ZIZOU/Téléchargements/pssst-1.wav");
    monTimer=new QTimer(this);
    connect(monTimer,SIGNAL(timeout()),this,SLOT(mytimer()));
    monTimer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::mytimer()
{

    QTime time=QTime ::currentTime();
    QString time_text=time.toString("hh:mm:ss");
    ui->label_time->setText(time_text);
}




void MainWindow::on_pushButton_clicked()
{
QSound::play("C:/Users/ZIZOU/Desktop/click.wav");
        QString username= ui->lineEdit->text();
        QString password=ui->lineEdit_2->text();
        if (username == "aziz" && password == "157842")
    {

            QMessageBox::information(this, "login", "login done successfully");
            hide();
            recl= new reclamation(this);
            recl->show();


        }


        else if (username == "samar" && password == "123456")
       {
               QMessageBox::information(this, "login", "login done successfully");
             //  hide();
               intermediaire *i=new intermediaire();
               i->show();



           }

        else if (username == "shaba" && password == "shaba")
       {
               QMessageBox::information(this, "login", "login done successfully");
             //  hide();
               Dialog *i=new Dialog();
               i->show();



           }
        else if (username == "kais" && password == "kais")
       {
               QMessageBox::information(this, "login", "login done successfully");
             //  hide();
               gestion *i=new gestion();
               i->show();



           }




        else
                   QMessageBox::warning(this, "login", "login failed");
       }





void MainWindow::on_pushButton_2_clicked()
{QSound::play("C:/Users/ZIZOU/Desktop/click.wav");
    close();
}
QString MainWindow::id_return()
{
    QString res="non traitée";
    QString d1;
    QSqlQuery query;
    query.prepare("select RECLAMATION.ID from RECLAMATION where ETAT='"+res+"'");


    while (query.next()) {

           d1= query.value(0).toString();
           return d1;


    }
}




bool MainWindow::traitment_en_retard()
{

    bool test=true;
    QString res=id_return();
    QDate d1;

    QDate dated1 = QDate::currentDate();
    QSqlQuery query;
    query.prepare("select RECLAMATION.DATED from RECLAMATION where ID='"+res+"'");
    while (query.next()) {

           d1= query.value(0).toDate();

    }
    if(dated1.day()-d1.day()<2 )
{test =false;}

return test;
}
