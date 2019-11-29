#include "CARTE_FIDELITE.h"
#include <QDebug>


CARTE_FIDELITE::CARTE_FIDELITE()
{
Id=0;
Nombre_points=0;
Pourcentage=0;
Historique="" ;
}


CARTE_FIDELITE::CARTE_FIDELITE(int Id,int Nombre_points,int Pourcentage , QString Historique)
{
    this ->Id=Id;
    this->Nombre_points=Nombre_points;
    this ->Pourcentage=Pourcentage;
    this ->Historique=Historique;


}

int CARTE_FIDELITE::get_Id(){return Id;}
int CARTE_FIDELITE::get_Nombre_points(){return Nombre_points;}
int CARTE_FIDELITE::get_Pourcentage(){return Pourcentage;}
QString CARTE_FIDELITE ::get_Historique(){return Historique;}

void CARTE_FIDELITE::set_Id(int Id){
    this->Id=Id;
}
void CARTE_FIDELITE::set_Nombre_points(int Nombre_points){
    this->Nombre_points=Nombre_points;
}
void CARTE_FIDELITE::set_Pourcentage(int pourcentage){
    this->Pourcentage=pourcentage;
}
void CARTE_FIDELITE::set_Historique(QString Historique){
    this ->Historique=Historique;
}



bool CARTE_FIDELITE::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO CARTE_FIDELITE (id,nombre_points,pourcentage_reduction,historique) "
                    "VALUES (:Id,:Nombre_points,:Pourcentage,:historique)");
query.bindValue(":Id", Id);
query.bindValue(":Nombre_Points", Nombre_points);
query.bindValue(":Pourcentage", Pourcentage );
query.bindValue(":Historique", Historique );
return    query.exec();
}



QSqlQueryModel * CARTE_FIDELITE::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from CARTE_FIDELITE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr(" Nombre_Points"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Pourcentage"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Historique"));

return model;
}



bool CARTE_FIDELITE::supprimer(){
    QSqlQuery query;
    query.prepare("Delete from CARTE_FIDELITE where Id=:Id ");
    query.bindValue(":Id", Id);
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
    query.prepare("update CARTE_FIDELITE set Id=:Id ,Nombre_points=:Nombre_points,Pourcentage=:Pourcentage,Historique=:Historique where Id=:Id");
    query.bindValue(":Id", Id);
    query.bindValue(":Nombre de points", Nombre_points);
    query.bindValue(":Pourcentage", Pourcentage);
    query.bindValue(":Historique", Historique );

    return query.exec();
}

