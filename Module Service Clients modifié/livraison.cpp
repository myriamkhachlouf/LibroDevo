#include "livraison.h"
#include <QDebug>
livraison::livraison()
{
id=0;
nbcopie=0;
prix=0;
etat="";
}
livraison::livraison(  int id , int nbcopie ,int prix ,QString livre ,QString datelivraison, QString etat  )
{
  this->id=id;
  this->nbcopie=nbcopie;
  this->prix=prix;
   this->livre=livre;
    this->datelivraison=datelivraison;
    this->etat=etat;

}
int livraison::get_id(){return  id ;}
int livraison::get_nbcopie(){return nbcopie;}
int livraison::get_prix(){return  prix ;}
QString livraison::get_livre(){return  livre ;}
QString livraison::get_datelivraison(){return  datelivraison ;}
QString livraison::get_etat(){return  etat ;}
void livraison::set_id(int id)
{this->id=id;}
void livraison::set_nbcopie(int nbcopie)
{this->nbcopie=nbcopie;}
void livraison::set_prix(int prix)
{this->prix=prix;}
void livraison::set_livre(QString livre)
{this->livre=livre;}
void livraison::set_datelivraison(QString datelivraison)
{this->datelivraison=datelivraison;}
void livraison::set_etat(QString etat)
{this->etat=etat;}
bool livraison::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO LIVRAISON (id,nombre_copie,prix,livre,date_livraison,etat) "
                    "VALUES (:id,:nombre_copie,:prix,:livre,:date_livraison,:etat)");
query.bindValue(":id", id);
query.bindValue(":nombre_copie", nbcopie);
query.bindValue(":prix", prix);
query.bindValue(":livre", livre );
query.bindValue(":date_livraison", datelivraison );
query.bindValue(":etat", etat );
return    query.exec();
}

QSqlQueryModel * livraison::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from livraison");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMBRE_COPIE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("LIVRE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_LIVRAISON"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ETAT"));
return model;
}

bool livraison::supprimer(){
    QSqlQuery query;
    query.prepare("Delete from livraison where id=:id ");
    query.bindValue(":id", id);
    return query.exec();
}
QSqlQueryModel * livraison::afficher_list()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select id from livraison");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
return model;
}
bool livraison::modifierl(){
    QSqlQuery query;
    query.prepare("update livraison set nombre_copie=:nombre_copie ,prix=:prix,livre=:livre,date_livraison=:date_livraison,etat=:etat where id=:id");
    query.bindValue(":id", id);
    query.bindValue(":nombre_copie", nbcopie);
    query.bindValue(":prix", prix);
    query.bindValue(":livre", livre );
    query.bindValue(":date_livraison", datelivraison );
    query.bindValue(":etat", etat );
    return query.exec();
}


