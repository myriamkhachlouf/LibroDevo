#include "livre.h"
#include <QDebug>
#include <QCoreApplication>
livre::livre()
{
    id=0;
    titre="";
    genre="";
    prix=0;
    rayon=0;

}
livre::livre(int id, QString titre, QString genre , int prix, int rayon)
{
  this->id=id;
  this->titre=titre;
  this->genre=genre;
  this->prix=prix;
  this->rayon=rayon;
}

int livre::get_id(){return  id;}
QString livre::get_titre(){return  titre;}
QString livre::get_genre(){return genre;}
int livre::get_prix(){return  prix;}
int livre::get_rayon(){return  rayon;}

bool livre::ajouter()
{
QSqlQuery query;
QString res1= QString::number(id);
QString res2= QString::number(prix);
QString res3= QString::number(rayon);
query.prepare("INSERT INTO livre (ID, TITRE, GENRE,PRIX,RAYON) "
                    "VALUES (:id, :titre, :genre,:prix,:rayon)");
query.bindValue(":id", res1);
query.bindValue(":titre", titre);
query.bindValue(":genre", genre);
query.bindValue(":prix", res2);
query.bindValue(":rayon", res3);

return    query.exec();
}

QSqlQueryModel * livre::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from livre");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Genre"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Rayon"));
    return model;
}

bool livre::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from livre where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

QSqlQueryModel * livre::get_id_model()
{
  QSqlQueryModel *model= new  QSqlQueryModel();
  QSqlQuery *query=new QSqlQuery() ;
  query->prepare("select id from livre");
  query->exec();
  model->setQuery(*query);
  return model;
}

bool livre::modifier(int id, QString titre, QString genre , int prix, int rayon)
{
    QString idlivre=QString::number(id);
    QSqlQuery query;
    query.prepare("update livre set titre=:titre,genre=:genre,prix=:prix,rayon=:rayon where id='"+idlivre+"'");
    query.bindValue(":titre",titre);
    query.bindValue(":genre",genre);
    query.bindValue(":prix",prix);
    query.bindValue(":rayon",rayon);
    return query.exec();
}
//recherche et tri
QSqlQueryModel * livre:: rechercheLivre(QString valeur,int etat)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query;
    if(etat==0)
    { query.prepare("SELECT * FROM LIVRE WHERE TITRE LIKE :valeur order by TITRE");}
    else
    { query.prepare("SELECT * FROM LIVRE WHERE TITRE LIKE :valeur order by TITRE desc");}
    valeur="%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("titre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("genre"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("rayon"));
    return model;
}
