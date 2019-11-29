#include "cpasserreclamation.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
cpasserreclamation::cpasserreclamation()
{
    id=0;
    sujet="";
    type="";
    etat="";
    message ="";
    mail="";
    pourqui="";
}

QSqlQueryModel * cpasserreclamation::combob()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select ID from RECLAMATION where POURQUI='client'");

    return model;

}
QSqlQueryModel * cpasserreclamation::combob1()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select ID from RECLAMATION where POURQUI='employé'");

    return model;

}

cpasserreclamation::cpasserreclamation(int id,QString sujet,QString type,QString etat,QString message,QString mail,QString pourqui)
{
    this->id=id;
    this->sujet=sujet;
    this->type=type;
    this->etat=etat;
    this->message=message;
    this->mail=mail;
    this->pourqui=pourqui;
}

bool cpasserreclamation::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO RECLAMATION (id,sujet,type,etat,message,mail,pourqui) VALUES (:id,:SUJET,:TYPE,'non traitée',:MESSAGE,:MAIL,'client')");
query.bindValue(":id",id);
query.bindValue(":SUJET",sujet);
query.bindValue(":TYPE",type);
query.bindValue(":MESSAGE",message);
query.bindValue(":MAIL",mail);
query.bindValue(":POURQUI",pourqui);
return    query.exec();
}
bool cpasserreclamation::ajouter1()
{
QSqlQuery query;

query.prepare("INSERT INTO RECLAMATION (id,sujet,type,etat,message,mail,pourqui) VALUES (:id,:SUJET,:TYPE,'non traitée',:MESSAGE,:MAIL,'employé')");
query.bindValue(":id",id);
query.bindValue(":SUJET",sujet);
query.bindValue(":TYPE",type);
query.bindValue(":MESSAGE",message);
query.bindValue(":MAIL",mail);
query.bindValue(":POURQUI",pourqui);
return    query.exec();
}

bool cpasserreclamation::modifier(int id,QString sujet ,QString type,QString message ,QString mail)
{

 QSqlQuery query;
 QString res= QString::number(id);


 query.prepare("UPDATE RECLAMATION SET SUJET='"+sujet+"',TYPE='"+type+"',MESSAGE='"+message+"',MAIL='"+mail+"' where ID='"+res+"'" );
 return query.exec();

}

QSqlQueryModel * cpasserreclamation::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel;

model->setQuery("select * from RECLAMATION where POURQUI='client' and ETAT='non traitée' order by DATED asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("SUJET"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("MESSAGE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("MAIL"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("DATED"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("POURQUI"));
return model;
}
QSqlQueryModel * cpasserreclamation::afficher1()
{
    QSqlQueryModel * model= new QSqlQueryModel;

model->setQuery("select * from RECLAMATION where POURQUI='employé' and ETAT='non traitée' order by DATED asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("SUJET"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("MESSAGE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("MAIL"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("DATED"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("POURQUI"));
return model;
}


bool cpasserreclamation::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from RECLAMATION where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
QSqlQueryModel * cpasserreclamation::rechercher(int id)
{

    QSqlQueryModel * model= new QSqlQueryModel();
     QString res= QString::number(id);
    model->setQuery("select * from RECLAMATION where ID='"+res+"' and POURQUI='client' and ETAT='non traitée'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("SUJET"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("MESSAGE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("MAIL"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DATED"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("POURQUI"));
    return model;
}
