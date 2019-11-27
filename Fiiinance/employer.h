#ifndef Employer_H
#define Employer_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Employer
{
    public:
        Employer();
        virtual ~Employer();
        Employer(QString,QString,QString,QString,int);
        QString GetNom() { return Nom; }
        void SetNom(QString val) { Nom = val; }
        QString GetPrenom() { return Prenom; }
        void SetPrenom(QString val) { Prenom = val; }
        QString GetID() { return ID; }
        void SetID(QString val) { ID = val; }
        QString GetMdp() { return Mdp; }
        void SetMdp(QString val) { Mdp = val; }
        int Getsalaire() { return salaire; }
        void Setsalaire(int val) { salaire = val; }
        bool ajouter_Employer();
        QSqlQueryModel * afficher_Employer();
        bool supprimer_Employer(QString);
        bool modifier_Employer(QString id);
        QSqlQueryModel * recherche(QString);
    private:
        QString Nom;
        QString Prenom;
        QString ID;
        QString Mdp;
        int salaire;
};

#endif // Employer_H
