#include "mainwindows.h"
#include "ui_mainwindows.h"
#include "employer.h"
#include <QMessageBox>
mainwindows::mainwindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainwindows)
{
    ui->setupUi(this);
}

mainwindows::~mainwindows()
{
    delete ui;
}

void mainwindows::on_pb_ajouter_clicked()
{
    QString ID = ui->lineEdit_IDe->text();
        QString Nom= ui->lineEdit_Nome->text();
        QString Prenom= ui->lineEdit_Prenom->text();
        QString Mdp= ui->lineEdit_MDP->text();
        int Salaire = ui->lineEdit_Salaire->text().toInt();

    Employer e (ID,Nom,Prenom,Mdp,Salaire);
      bool test=e.ajouter_Employer();
      if(test)
    {ui->tabemp->setModel(tmpemployer.afficher_Employer());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un Employer"),
                      QObject::tr("Employer ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un Employer"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void mainwindows::on_pb_supprimer_clicked()
{
    QString id = ui->lineEdit_ide_2->text();
    bool test=tmpemployer.supprimer_Employer(id);
    if(test)
    {ui->tabemp->setModel(tmpemployer.afficher_Employer());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Employer"),
                    QObject::tr("Employer supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un employer"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void mainwindows::on_pb_Modifier_clicked()
{
    QString id = ui->lineEdit_idrech_e->text();
               QString Nom= ui->lineEdit_NomeN->text();
               QString Prenom= ui->lineEdit_PrenomN->text();
               QString Mdp= ui->lineEdit_MdpN->text();
               int Salaire = ui->lineEdit_SalaireN->text().toInt();
               Employer e (id,Nom,Prenom,Mdp,Salaire);
               bool l=e.modifier_Employer(id);
               if(l)
               {ui->tabemp->setModel(tmpemployer.afficher_Employer());//refresh
                   QMessageBox::information(nullptr, QObject::tr("Modifier un Employer"),
                               QObject::tr("Employer Modifié.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

               }
               else
                   QMessageBox::critical(nullptr, QObject::tr("Modifier un Employer"),
                               QObject::tr("Erreur !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}
