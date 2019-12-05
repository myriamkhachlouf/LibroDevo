#ifndef OFFRE_H
#define OFFRE_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"QString"
#include <QVariant>
class offre
{
    int id;
    QString nom;
    QString dateDebut;
    QString dateFin;
public:
    offre();
    offre(int,QString,QString,QString);

    int getID(){return id;}
    QString getnom(){return nom;}
    QString getdateD(){return dateDebut;}
    QString getdateF(){return dateFin;}

    void setID(int idd){id=idd;}
    void setnom(QString nomm){nom=nomm;}
    void setdateD(QString dated){dateDebut=dated;}
    void setdateF(QString datef){dateFin=datef;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier();
    QSqlQueryModel * rechercher2(const QString);

};

#endif // OFFRE_H
