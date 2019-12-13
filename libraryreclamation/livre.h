#ifndef LIVRE_H
#define LIVRE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class livre
{
public:
    livre();
    livre(int id, QString titre, QString genre , int prix, int rayon);
    int get_id();
    QString get_titre();
    QString get_genre();
    int get_prix();
    int get_rayon();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * get_id_model();
    bool modifier(int, QString, QString, int, int);

    QSqlQueryModel * rechercheLivre(QString valeur,int etat);
private:
  int id,prix,rayon;
  QString titre,genre;
};

#endif // LIVRE_H
