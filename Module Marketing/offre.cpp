#include "offre.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"QString"
#include <QVariant>
offre::offre()
{
    id=0;
  nom="";
   dateDebut="";
  dateFin="";
}
offre::offre(int a,QString b,QString c,QString d)
{
     id=a;
   nom=b;
    dateDebut=c;
   dateFin=d;
}


bool offre::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO offre (id, nom,datedebut,datefin) "
                    "VALUES (:id, :nom,:datedebut,:datefin)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":datedebut", dateDebut);
query.bindValue(":datefin", dateFin);

return    query.exec();
}

QSqlQueryModel * offre::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from offre ORDER BY id");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date Debut"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date FIN"));
    return model;
}


bool offre::supprimer(QString id)
{
QSqlQuery query;

query.prepare("Delete from offre where id = :id ");
query.bindValue(":id", id);
return    query.exec();
}


bool offre::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE offre SET  nom=:nom, datedebut=:datedebut,datefin=:datefin where id=:id ");
    QString res= QString::number(id);
    query.bindValue(":id", res);
    query.bindValue(":nom", nom);
    query.bindValue(":datedebut", dateDebut);
    query.bindValue(":datefin",dateFin);

    return    query.exec();

}
QSqlQueryModel * offre :: rechercher2(QString ch)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString str="select * from offre where ID like '"+ch+"%'";
    model->setQuery(str);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date Debut"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date FIN"));
    return model;
}



