#ifndef CARTE_FIDELITE_H
#define CARTE_FIDELITE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTime>

class CARTE_FIDELITE
{
public:
    CARTE_FIDELITE();
    CARTE_FIDELITE(int, int, int,QString);

int get_Id();
int get_Nombre_points();
int get_Pourcentage();
QString get_Historique();

void set_Id(int);
void set_Nombre_points(int);
void set_Pourcentage(int);
void set_Historique(QString);

bool ajouter();
bool supprimer();

 QSqlQueryModel * afficher();
 QSqlQueryModel * afficher_list();
 bool modifier();

private :
    int Id;
    int Nombre_points;
    int Pourcentage;
    QString Historique;
};

#endif // CARTE_FIDELITE_H
