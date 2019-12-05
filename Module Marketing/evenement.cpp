#include "evenement.h"

evenement::evenement()
{
    id=0;
        nom="";
        date="";
}
evenement::evenement(int a,QString b, QString c)
{id=a;
    nom=b;
    date=c;
}

bool evenement::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO evenement (id, nom,datee) "
                    "VALUES (:id, :nom,:datee)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":datee", date);


return    query.exec();
}

QSqlQueryModel * evenement::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from evenement ORDER BY id");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("datee"));
    return model;
}


bool evenement::supprimer(QString id)
{
QSqlQuery query;

query.prepare("Delete from evenement where id = :id ");
query.bindValue(":id", id);
return    query.exec();
}


bool evenement::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE evenement SET  nom=:nom, datee=:datee where id=:id ");
    QString res= QString::number(id);
    query.bindValue(":id", res);
    query.bindValue(":nom", nom);
    query.bindValue(":datee", date);


    return    query.exec();

}
QSqlQueryModel * evenement :: rechercher2(QString ch)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString str="select * from evenement where ID like '"+ch+"%'";
    model->setQuery(str);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));

    return model;
}



