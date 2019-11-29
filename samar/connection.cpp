#include "connection.h"

connection::connection()
{

}

bool connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet2a5");
db.setUserName("samar");//inserer nom de l'utilisateur
db.setPassword("123456");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}

