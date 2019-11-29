#include "ctraiterreclamation.h"

ctraiterreclamation::ctraiterreclamation()
{
    reponse ="";
    id=0;
}
ctraiterreclamation::ctraiterreclamation(QString reponse,int id)
{
 this->reponse=reponse;
    this->id=id;
}

QSqlQueryModel * ctraiterreclamation::combob()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select ID from RECLAMATION");

    return model;

}

QSqlQueryModel * ctraiterreclamation::combob1()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select ID from RECLAMATION where ETAT='traitée'");

    return model;

}

bool ctraiterreclamation::ajouter()
{
QSqlQuery query;
QString res=QString::number(id);
query.prepare("INSERT INTO TRAITEMENT (id,reponse) VALUES (:ID,:REPONSE)");
query.bindValue(":ID",id);
query.bindValue(":REPONSE",reponse);
return    query.exec();
}


QSqlQueryModel * ctraiterreclamation::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel;
    QString res2="traitée";


//model->setQuery("select * from RECLAMATION right join TRAITEMENT on RECLAMATION.ID=TRAITEMENT.ID");
    model->setQuery("SELECT RECLAMATION.DATE , RECLAMATION.TYPE , RECLAMATION.SUJET , RECLAMATION.MESSAGE , TRAITEMENT.REPONSE FROM RECLAMATION , TRAITEMENT WHERE RECLAMATION.ID = TRAITEMENT.ID;");
    return model;
}
QSqlQueryModel * ctraiterreclamation::afficher1()
{
    QSqlQueryModel * model= new QSqlQueryModel;
    QString res2="traitée";
model->setQuery("select * from RECLAMATION where ETAT='"+res2+"'");
    return model;
}

QSqlQueryModel * ctraiterreclamation::afficher2()
{
    QSqlQueryModel * model= new QSqlQueryModel;
    QString res2="non traitée";
model->setQuery("select * from RECLAMATION where ETAT='"+res2+"'");
    return model;
}

bool ctraiterreclamation::modifier(int id,QString reponse)
{

 QSqlQuery query;
 QString res= QString::number(id);
 query.prepare("UPDATE TRAITEMENT SET REPONSE='"+reponse+"' where ID='"+res+"'" );

 return query.exec();

}
bool ctraiterreclamation::modifieretat ()
{
    QSqlQuery query1;
    QString res=QString::number(id);

    query1.prepare("UPDATE RECLAMATION SET ETAT='traitée' where ID='"+res+"'" );
    return query1.exec();

}
bool ctraiterreclamation::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from RECLAMATION where ID = '"+res+"'");
query.bindValue(":ID", res);
return    query.exec();
}
bool ctraiterreclamation::supprimer1(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from TRAITEMENT where ID = '"+res+"'");
query.bindValue(":ID", res);
return    query.exec();
}
