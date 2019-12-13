#ifndef RAYON_H
#define RAYON_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class rayon
{
public:
    rayon();

    rayon(int id, int numero);
    int get_id();
    int get_numero();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * get_id_model();
    bool modifier(int,int);

    QSqlQueryModel * rechercheRayon(QString valeur,int etat);
private:
    int id,numero;
};

#endif // RAYON_H
