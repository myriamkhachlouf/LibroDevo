#ifndef CPASSERRECLAMATION_H
#define CPASSERRECLAMATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class cpasserreclamation
{
public:
    cpasserreclamation();
    cpasserreclamation(int,QString,QString,QString,QString,QString,QString);
    bool ajouter();
    bool ajouter1();
    QSqlQueryModel * combob();
    QSqlQueryModel * combob1();


    bool modifier(int,QString,QString,QString,QString);
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher1();

    bool supprimer(int);
    QSqlQueryModel * rechercher(int);







private:
    QString sujet , type , etat , message , mail,pourqui;
    int id;


};

#endif // CPASSERRECLAMATION_H
