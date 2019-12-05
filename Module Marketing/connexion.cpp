#include "connexion.h"
#include <exception>
#include <QDebug>
#include <QSqlError>
#include<QSqlQuery>

Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("zied");//inserer nom de l'utilisateur
db.setPassword("esprit19");//inserer mot de passe de cet utilisateur

if (db.open()){
    test=true;
    printf("test");}
else
    throw QString ("Erreur Paramétres"+test);
return  test;
}
void Connexion::fermerConnexion()
{db.close();}
