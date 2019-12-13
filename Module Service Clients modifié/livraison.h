#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTime>
class livraison
{public:
    livraison();
    livraison(int,int,int,QString,QString,QString);
    int get_id();
    int get_nbcopie();
    int get_prix();
    QString get_livre();
    QString get_datelivraison();
    QString get_etat();
    void set_id(int);
    void set_nbcopie(int);
    void set_prix(int);
    void set_livre(QString);
    void set_datelivraison(QString);
    void set_etat(QString);
   bool ajouter();
bool supprimer();

    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_list();
    bool modifierl();

private:
    int id ;
    int nbcopie ;
    int prix ;
    QString livre ;
    QString datelivraison;
    QString etat;


};

#endif // EQUIPEMENT_H
