#include "rayon.h"

rayon::rayon()
{

}
rayon::rayon(int id, int numero)
{
  this->id=id;
  this->numero=numero;

}
int rayon::get_id(){return  id;}
int rayon::get_numero(){return  numero;}

bool rayon::ajouter()
{
QSqlQuery query;
QString res1= QString::number(id);
QString res2= QString::number(numero);

query.prepare("INSERT INTO rayon (ID, NUMERO) "
                    "VALUES (:id, :numero)");
query.bindValue(":id", res1);
query.bindValue(":numero", res2);


return    query.exec();
}

QSqlQueryModel * rayon::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from rayon");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("numero "));
    return model;
}

bool rayon::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from rayon where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

 QSqlQueryModel * rayon::get_id_model()
{
   QSqlQueryModel *model= new  QSqlQueryModel();
   QSqlQuery *query=new QSqlQuery() ;
   query->prepare("select id from rayon");
   query->exec();
   model->setQuery(*query);
   return model;
 }


bool rayon::modifier(int id, int numero)
{
    QString idrayon=QString::number(id);
    QSqlQuery query;
    query.prepare("update rayon set numero=:numero where id='"+idrayon+"'");
    query.bindValue(":numero",numero);
    query.exec();
    return query.exec();
}

QSqlQueryModel * rayon:: rechercheRayon(QString valeur, int etat)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query;
    if(etat==1)
    { query.prepare("SELECT * FROM RAYON WHERE NUMERO LIKE :valeur order by NUMERO");}
    else
    { query.prepare("SELECT * FROM NUMERO WHERE NOM LIKE :valeur order by NUMERO desc");}
    valeur="%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("numero"));
    return model;
}
