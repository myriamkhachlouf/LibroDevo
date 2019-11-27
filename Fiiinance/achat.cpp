#include "achat.h"
#include <QDebug>

Achat::Achat() {}

Achat::Achat(QString Date,QString Genre,QString Nom_Livre,QString Nom_Client,int Prix,QString ID){
this->Date=Date;
this->Genre=Genre;
this->Nom_Livre=Nom_Livre;
this->Nom_Client=Nom_Client;
this->Prix=Prix;
this->ID=ID;
}
bool Achat::ajouter_Achat()
{
QSqlQuery query;
QString res= GetID();
query.prepare("INSERT INTO ACHAT (ID, NOM_CLIENT, NOM_LIVRE, GENRE, DATE_, PRIX) "
                    "VALUES (:id, :Nom_Client, :Nom_Livre, :Genre, :Date, :Prix)");
query.bindValue(":id", res);
query.bindValue(":Nom_Client", Nom_Client);
query.bindValue(":Nom_Livre", Nom_Livre);
query.bindValue(":Genre", Genre);
query.bindValue(":Date_", Date);
query.bindValue(":Prix", Prix);

return    query.exec();
}
QSqlQueryModel * Achat::afficher_Achat()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from ACHAT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_CLIENT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_LIVRE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("GENRE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX"));

return model;
}

bool Achat::supprimer(QString id)
{
QSqlQuery query;
QString res= id;
query.prepare("Delete from ACHAT where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool Achat::modifier(QString id)
{
    QSqlQuery query ;

                query.prepare("update ACHAT set NOM_LIVRE=:Nom_livre, NOM_CLIENT=:Nom_client, DATE_=:Date, GENRE=:Genre, PRIX=:Prix where id=:id");
                query.bindValue (":Nom_livre",Nom_Livre);
                query.bindValue (":Nom_client",Nom_Client);
                query.bindValue(":Date",Date);
                query.bindValue(":Genre",Genre);
                query.bindValue(":Prix",Prix);
 query.bindValue(":id",id);
            return  query.exec();

    }

/*QSqlQueryModel * Achat :: recherche(QString id)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select ID,NOM_CLIENT,NOM_LIVRE,GENRE,DATE_,PRIX from ACHAT where ID='"+id+"'");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_CLIENT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_LIVRE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("GENRE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX"));

    return model;
}
*/
Achat::~Achat(){};

