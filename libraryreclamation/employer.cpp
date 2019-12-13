#include "employer.h"
#include <QString>
Employer::Employer()
{

}
Employer::~Employer()
{
    //dtor
}
Employer::Employer(QString ID,QString Nom,QString Prenom,QString Mdp,int salaire){
    this->ID=ID;
    this->Nom=Nom;
            this->Prenom=Prenom;
            this->Mdp=Mdp;
            this->salaire=salaire;
}

bool Employer::ajouter_Employer()
{
QSqlQuery query;
QString res= GetID();
query.prepare("INSERT INTO EMPLOYER (ID, NOM, PRENOM, MDP, SALAIRE) "
                    "VALUES (:id, :Nom, :Prenom, :Mdp, :Salaire)");
query.bindValue(":id", res);
query.bindValue(":Nom", Nom);
query.bindValue(":Prenom", Prenom);
query.bindValue(":Mdp", Mdp);
query.bindValue(":Salaire", salaire);

return    query.exec();
}
QSqlQueryModel * Employer::afficher_Employer()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from EMPLOYER");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("MDP"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("SALAIRE"));

return model;
}

bool Employer::supprimer_Employer(QString id)
{
QSqlQuery query;
QString res= id;
query.prepare("Delete from EMPLOYER where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool Employer::modifier_Employer(QString id)
{
    QSqlQuery query ;

                query.prepare("update EMPLOYER set NOM=:Nom, PRENOM=:Prenom, MDP=:Mdp, SALAIRE=:Salaire where id=:id");
                query.bindValue(":Nom",Nom);
                query.bindValue(":Prenom",Prenom);
                query.bindValue(":Mdp",Mdp);
                query.bindValue(":Salaire",salaire);

 query.bindValue(":id",id);
            return  query.exec();

    }

/*QSqlQueryModel * Employer :: recherche(QString id)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select ID,NOM_CLIENT,NOM_LIVRE,GENRE,DATE_,PRIX from Employer where ID='"+id+"'");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_CLIENT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_LIVRE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("GENRE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX"));

    return model;
}*/
QSqlQueryModel * Employer :: recherche_empa(QString valeur)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query;

    query.prepare("SELECT * FROM EMPLOYER WHERE ID LIKE :valeur order by ID");


    valeur="%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MDP"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("SALAIRE"));

    return model;

}
QSqlQueryModel * Employer :: recherche_empd(QString valeur)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query;
  query.prepare("SELECT * FROM EMPLOYER WHERE ID LIKE :valeur order by ID desc");
    valeur="%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MDP"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("SALAIRE"));

    return model;

}

