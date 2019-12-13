#ifndef CRUDACHAT_H
#define CRUDACHAT_H
#include"achat.h"
#include <QDialog>

namespace Ui {
class crudachat;
}

class crudachat : public QDialog
{
    Q_OBJECT

public:
    explicit crudachat(QWidget *parent = nullptr);
    ~crudachat();
private slots:
   void on_pb_ajouter_clicked();

   void on_pb_supprimer_clicked();
   void on_pb_Modifier_clicked();

   void on_pb_rechercher_clicked();

private:
    Ui::crudachat *ui;
     Achat tmpachat;
};

#endif // CRUDACHAT_H
