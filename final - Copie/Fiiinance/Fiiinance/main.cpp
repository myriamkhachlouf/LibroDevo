#include "mainwindow.h"
#include"login.h"
#include"employer.h"
#include <QApplication>
#include"connexion.h"
#include<QtDebug>
#include "statshaba.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion c;
    Login l;
    Employer k;
    StatShaba z;
    try{
        c.createconnect();
        l.show();
        z.show();
    }catch(QString s){
        qDebug()<<s;}
    return a.exec();
}
