#ifndef CLIENT_H
#define CLIENT_H
#include "QString"
#include <QSqlQuery>
#include <QSqlQueryModel>

class client
{
public:
    client();
    client(QString,QString,QString,QString,QString,QString);
    QString get_NOM();
    QString get_PRENOM();
    QString get_ID();
    QString get_ADRESSE();
    QString get_TEL();
    QString get_DATEDENAISSANCE();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString ID);
    QSqlQueryModel * afficher_tri();
    QSqlQueryModel * chercher_client(QString nom);
    bool modifier(QString ID, QString NOM, QString PRENOM ,QString ADRESSE,QString TEL,QString DATEDENAISSANCE );
QSqlQueryModel * stats();



    private:
        QString ID,NOM,PRENOM,ADRESSE,TEL,DATEDENAISSANCE;
};

#endif // CLIENT_H
