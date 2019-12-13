#include "client.h"
#include "QString"
#include <QDebug>
#include<QSqlQuery>
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

query.prepare("INSERT INTO client_kais (ID, NOM, PRENOM,ADRESSE,TEL,DATEDENAISSANCE) "
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

model->setQuery("select * from client_kais");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEDENAISSANCE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEL"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));
    return model;
}

bool client::supprimer(QString ID)
{
    QSqlQuery query;

        query.prepare("delete from client_kais where ID = :ID ");
        query.bindValue(":ID", ID);
        return    query.exec();


}


QSqlQueryModel * client::afficher_tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from client_kais order by id");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEDENAISSANCE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEL"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));
    return model;
}

QSqlQueryModel * client::chercher_client(QString id)
{QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
id='%'+id+'%';
query.prepare(" select * from client_kais where id like :id order by id  ");
query.bindValue(":id",id);
query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEDENAISSANCE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEL"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));
    return model;
}
bool client::modifier(QString ID, QString NOM, QString PRENOM ,QString ADRESSE,QString TEL,QString DATEDENAISSANCE)
{
    QSqlQuery query;
    query.prepare("update client_kais set  NOM=:NOM,PRENOM=:PRENOM,ADRESSE=:ADRESSE,TEL=:TEL,DATEDENAISSANCE=:DATEDENAISSANCE where ID=:ID");
  /*,,,,
    */
    qDebug()<<ID<<NOM<<PRENOM<<ADRESSE<<TEL<<DATEDENAISSANCE;
    query.bindValue(":NOM",NOM);
    query.bindValue(":PRENOM",PRENOM);
    query.bindValue(":ADRESSE",ADRESSE);
    query.bindValue(":TEL",TEL);
query.bindValue(":DATEDENAISSANCE",DATEDENAISSANCE);


    query.bindValue(":ID",ID);

    return query.exec();




}
QSqlQueryModel *client::stats()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT NOM, PRENOM,((NOM*100)/(select SUM(NOM) from client_kais) from client_kais");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("stats"));

        return model;
}
