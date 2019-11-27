#include "mainwindow.h"
#include"login.h"
#include"employer.h"
#include <QApplication>
#include"connexion.h"
#include<QtDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion c;
    Login l;
    Employer k;
    try{
        c.createconnect();
        l.show();
    }catch(QString s){
        qDebug()<<s;}
    return a.exec();
}
