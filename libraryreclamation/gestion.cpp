#include "gestion.h"
#include "ui_gestion.h"
#include"QMessageBox"
#include"QTableView"
#include "client.h"
#include"smtp.h"
#include"statistique.h"
gestion::gestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion)
{
    ui->setupUi(this);
    ui->tabclient->setModel(tmpclient.afficher());
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
        connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
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
{
      ui->tabclient->setModel(tmpclient.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("client ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}








void gestion::on_pushButton_supprimerclient_clicked()
{

    QString ID =ui->supp->text();
        bool test=tmpclient.supprimer(ID);
        if(test)
        {
            ui->tabclient->setModel(tmpclient.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                        QObject::tr("client supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                        QObject::tr("Erreur !.\n" "Click Cancel to exit."), QMessageBox::Cancel);



}

void gestion::on_TRI_clicked()
{
     ui->tabclient->setModel(tmpclient.afficher_tri());

}






void gestion::on_lineEdit_textChanged(const QString &arg1)
{
     ui->tabclient->setModel(tmpclient.chercher_client(arg1));
}




void gestion::on_modifier_clicked()
{
    QString ID= ui->modifid->text();
       QString NOM= ui->nommodif->text();
       QString PRENOM = ui->prenommodif->text();
       QString TEL = ui->telmodif->text();
       QString ADRESSE= ui->adressemodif->text();
       QString DATEDENAISSANCE = ui->DNmodif->text();


 client c;
   bool test;
   test=c.modifier(ID,NOM,PRENOM,TEL,ADRESSE,DATEDENAISSANCE);
   if(test)
   {
       ui->tabclient->setModel(tmpclient.afficher_tri());

      QMessageBox::information(nullptr,QObject::tr("modifier client"),
        QObject::tr(" client modifer") ,QMessageBox::Cancel);

     }else

         QMessageBox::critical(nullptr,QObject::tr("modifier client"),
           QObject::tr("merci de remplir tout les champs correctement") ,QMessageBox::Cancel) ;
}
void gestion::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void gestion::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}





void gestion::on_stat_clicked()
{
    ui->tabstat->setModel(tmpclient.stats());
    STATISTIQUE *a=new STATISTIQUE();
    a->show();
}
