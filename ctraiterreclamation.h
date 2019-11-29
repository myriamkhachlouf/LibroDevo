#ifndef CTRAITERRECLAMATION_H
#define CTRAITERRECLAMATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class ctraiterreclamation
{
public:
    ctraiterreclamation();
  ctraiterreclamation(QString,int);
  QSqlQueryModel * combob();
  QSqlQueryModel * combob1();
  bool supprimer(int);
  bool supprimer1(int);

  bool ajouter();
  QSqlQueryModel * afficher();
  QSqlQueryModel * afficher1();
  QSqlQueryModel * afficher2();
  QSqlQueryModel * afficher3();

  bool modifier(int,QString);
bool modifieretat ();
private:
  QString reponse;
  int id;

};

#endif // CTRAITERRECLAMATION_H
