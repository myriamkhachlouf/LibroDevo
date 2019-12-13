#include "gestion.h"
#include "ui_gestion.h"
#include"QMessageBox"
gestion::gestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion)
{
    ui->setupUi(this);
}

gestion::~gestion()
{
    delete ui;
}

void gestion::on_pushButton_clicked()
{

    QString ID= ui->lineEdit_id->text();
    QString ADRESSE= ui->lineEdit_adresse->text();
    QString NOM= ui->lineEdit_nom->text();
    QString PRENOM= ui->lineEdit_prenom->text();
    QString TEL= ui->lineEdit_tel->text();
    QString DATEDENAISSANCE= ui->lineEdit_DN->text();
  client  c(ID,NOM,PRENOM,ADRESSE,TEL,DATEDENAISSANCE);
  bool test=c.ajouter();
  if(test)
{ui->tabclient->setModel(tmpclient.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("client ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
