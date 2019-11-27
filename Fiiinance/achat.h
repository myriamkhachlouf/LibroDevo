#ifndef ACHAT_H
#define ACHAT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class Achat
{
public:
        Achat();
        virtual ~Achat();
        Achat(QString,QString,QString,QString,int,QString);
        QString GetDate() { return Date; }
        void SetDate(QString val) { Date = val; }
        QString GetNom_Livre() { return Nom_Livre; }
        void SetNom_Livre(QString val) { Nom_Livre = val; }
        int GetPrix() { return Prix; }
        void SetPrix(int val) { Prix = val; }
        QString GetGenre() { return Genre; }
        void SetGenre(QString val) { Genre = val; }
        QString GetNom_Client() { return Nom_Client; }
        void SetNom_Client(QString val) { Nom_Client = val; }
        QString GetID() { return ID; }
        void SetId(QString val) { ID = val; }
        bool ajouter_Achat();
        QSqlQueryModel * afficher_Achat();
        bool supprimer(QString);
        bool modifier(QString id);
        QSqlQueryModel * recherche(QString);

    private:
        QString ID;
        QString Date;
        QString Genre;
        QString Nom_Livre;
        QString Nom_Client;
        int Prix;

};

#endif // ACHAT_H
