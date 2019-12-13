#include "client.h"
#include "QString"
#include <QDebug>
client::client()

{

}
client::client(QString ID,QString NOM,QString PRENOM,QString ADRESSE,QString TEL,QString DATEDENAISSANCE)
{
  this->ID=ID;
  this->NOM=NOM;
  this->PRENOM=PRENOM;
  this->ADRESSE=ADRESSE;
  this->TEL=TEL;
  this->DATEDENAISSANCE=DATEDENAISSANCE;
}
QString client::get_NOM(){return  NOM;}
QString client::get_PRENOM(){return PRENOM;}
QString client::get_ID(){return  ID;}
QString client::get_ADRESSE(){return ADRESSE;}
QString client::get_TEL(){return TEL;}
QString client::get_DATEDENAISSANCE(){return DATEDENAISSANCE;}

bool client::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO etudiant (ID, NOM, PRENOM,ADRESSE,TEL,DATEDENAISSANCE) "
                    "VALUES (:ID, :NOM, :PRENOM, :ADRESSE, :TEL ,:DATEDENAISSANCE)");
query.bindValue(":ID", ID);
query.bindValue(":NOM", NOM);
query.bindValue(":PRENOM", PRENOM);
query.bindValue(":ADRESSE", ADRESSE);
query.bindValue(":TEL", TEL);
query.bindValue(":DATEDENAISSANCE", DATEDENAISSANCE);


return    query.exec();
}

QSqlQueryModel * client::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TEL "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATEDENAISSANCE"));
    return model;
}
