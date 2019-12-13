#include "crudachat.h"
#include "ui_crudachat.h"
#include "achat.h"
#include <QMessageBox>
crudachat::crudachat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::crudachat)
{
    ui->setupUi(this);
}

crudachat::~crudachat()
{
    delete ui;
}
void crudachat::on_pb_ajouter_clicked()
{   QString ID = ui->lineEdit_id->text();
    QString Nom_Livre= ui->lineEdit_NomL->text();
    QString Nom_Client= ui->lineEdit_NomC->text();
    QString Genre= ui->lineEdit_Genre->text();
    QString Date= ui->lineEdit_Date->text();
    int Prix = ui->lineEdit_Prix->text().toInt();

Achat e (Date,Genre,Nom_Livre,Nom_Client,Prix,ID);
  bool test=e.ajouter_Achat();
  if(test)
{ui->tabachat->setModel(tmpachat.afficher_Achat());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un Achat"),
                  QObject::tr("Achat ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Achat"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void crudachat::on_pb_supprimer_clicked()
{
QString id = ui->lineEdit_id_2->text();
bool test=tmpachat.supprimer(id);
if(test)
{ui->tabachat->setModel(tmpachat.afficher_Achat());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un Achat"),
                QObject::tr("Achat supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void crudachat::on_pb_Modifier_clicked()
{ QString id = ui->lineEdit_idrech->text();
  //  QSqlQueryModel * model= new QSqlQueryModel();
   // model->setQuery("select ID NOM_LIVRE, NOM_CLIENT, GENRE, DATE_, PRIX from ACHAT where ID='"+id+"'");
            QString Nom_Client= ui->lineEdit_NomCN->text();
            QString Nom_Livre= ui->lineEdit_NomLN->text();
            QString Genre= ui->lineEdit_GenreN->text();
            QString Date= ui->lineEdit_DateN->text();
            int Prix = ui->lineEdit_PrixN->text().toInt();
            Achat e (Date,Genre,Nom_Livre,Nom_Client,Prix,id);
            bool l=e.modifier(id);
            if(l)
            {ui->tabachat->setModel(tmpachat.afficher_Achat());//refresh
                QMessageBox::information(nullptr, QObject::tr("Supprimer un Achat"),
                            QObject::tr("Achat Modifié.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);


            }



