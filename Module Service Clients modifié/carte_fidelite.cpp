#include "carte_fidelite.h"
#include <QDebug>


CARTE_FIDELITE::CARTE_FIDELITE()
{
id=0;
Nombre_points=0;
Pourcentage=0;
historique="" ;
}


CARTE_FIDELITE::CARTE_FIDELITE(int id,int Nombre_points,int Pourcentage , QString historique)
{
    this ->id=id;
    this->Nombre_points=Nombre_points;
    this ->Pourcentage=Pourcentage;
    this ->historique=historique;


}

int CARTE_FIDELITE::get_Id(){return id;}
int CARTE_FIDELITE::get_Nombre_points(){return Nombre_points;}
int CARTE_FIDELITE::get_Pourcentage(){return Pourcentage;}
QString CARTE_FIDELITE ::get_Historique(){return historique;}

void CARTE_FIDELITE::set_Id(int id){
    this->id=id;
}
void CARTE_FIDELITE::set_Nombre_points(int Nombre_points){
    this->Nombre_points=Nombre_points;
}
void CARTE_FIDELITE::set_Pourcentage(int pourcentage){
    this->Pourcentage=pourcentage;
}
void CARTE_FIDELITE::set_Historique(QString historique){
    this ->historique=historique;
}



bool CARTE_FIDELITE::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO CARTE_FIDELITE (ID,NOMBRE_POINTS,POURCENTAGE_REDUCTION,HISTORIQUE) "
                    "VALUES (:id,:Nombre_points,:Pourcentage,:historique)");

query.bindValue(":id", id);
query.bindValue(":Nombre_points", Nombre_points);
query.bindValue(":Pourcentage", Pourcentage );
query.bindValue(":historique", historique);
return    query.exec();
}

QSqlQueryModel * CARTE_FIDELITE::afficher_carte()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from carte_fidelite");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMBRE_points"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Pourcentage"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("historique"));
return model;
}



bool CARTE_FIDELITE::supprimer(){
    QSqlQuery query;
    query.prepare("Delete from CARTE_FIDELITE where ID=:id ");
    query.bindValue(":id", id);
    return query.exec();
}



QSqlQueryModel * CARTE_FIDELITE::afficher_list()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select Id from CARTE_FIDELITE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
return model;
}



bool CARTE_FIDELITE::modifier(){
    QSqlQuery query;
    query.prepare("update CARTE_FIDELITE set NOMBRE_POINTS=:Nombre_points,POURCENTAGE_REDUCTION=:Pourcentage,HISTORIQUE=:Historique where ID=:id");
    query.bindValue(":id", id);
    query.bindValue(":Nombre de points", Nombre_points);
    query.bindValue(":Pourcentage", Pourcentage);
    query.bindValue(":historique", historique );

    return query.exec();
}

