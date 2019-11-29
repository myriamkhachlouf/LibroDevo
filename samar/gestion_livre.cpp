#include "gestion_livre.h"
#include "ui_gestion_livre.h"

#include "livre.h"
#include <QMessageBox>
#include"notification.h"
#include"smtp.h"

gestion_livre::gestion_livre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_livre)
{
    ui->setupUi(this);
    ui->tablivre->setModel(tmplivre.afficher());
    ui->comboBox_L->setModel(tmplivre.get_id_model());
}

gestion_livre::~gestion_livre()
{
    delete ui;
}



void gestion_livre::on_ajouter_pushButton_clicked()
{
        int id = ui->lineEdit_id->text().toInt();
        QString titre= ui->lineEdit_titre->text();
        QString genre= ui->lineEdit_genre->text();
        int prix = ui->lineEdit_prix->text().toInt();
        int rayon = ui->lineEdit_rayon->text().toInt();

      livre l(id,titre,genre,prix,rayon);
      bool test=l.ajouter();
      if(test)
    {ui->tablivre->setModel(tmplivre.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un livre"),
                      QObject::tr("livre ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    notification notif;
    notif.notification_ajout_LIVRE(titre);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un livre"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);



}

void gestion_livre::on_supprimer_pushButton_clicked()
{
    int id = ui->lineEdit_7->text().toInt();
    bool test=tmplivre.supprimer(id);
    if(test)
    {ui->tablivre->setModel(tmplivre.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un livre"),
                    QObject::tr("livre supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un livre"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion_livre::on_comboBox_L_currentIndexChanged(const QString &arg1)
{
    QString id= QString::number(ui->comboBox_L->currentText().toInt());
    QSqlQuery query;
    query.prepare("select * from livre where id='"+id+"'");
    query.exec();
    while(query.next())
    {
        ui->lineEdit_titre_2->setText(query.value(1).toString());
        ui->lineEdit_genre_2->setText(query.value(2).toString());
        ui->lineEdit_prix_2->setText(query.value(3).toString());
        ui->lineEdit_rayon_2->setText(query.value(4).toString());

    }
}




void gestion_livre::on_modifier_pushButton_clicked()
{
    QString titre = ui->lineEdit_titre_2->text();
     QString genre = ui->lineEdit_genre_2->text();
      int prix = ui->lineEdit_prix_2->text().toInt();
       int rayon = ui->lineEdit_rayon_2->text().toInt();
    int id = ui->comboBox_L->currentText().toInt();
    livre l;
    bool test=l.modifier(id,titre,genre,prix,rayon);
    if(test)
    {
       ui->tablivre->setModel(tmplivre.afficher());//refresh
     QMessageBox::information(nullptr,QObject::tr("Modifier livre"),"Modification effectuée");
    }
    else
    {

        QMessageBox::warning(nullptr,QObject::tr("Modifier livre"),"ERROR:Modification non effectuée!");
}
}

void gestion_livre::on_lineEdit_textChanged(const QString &arg1)
{
    valeur=arg1;
    ui->tablivre->setModel(tmplivre.rechercheLivre(arg1,etat));

}




void gestion_livre::on_mail_pushButton_clicked()
{
    Smtp* smtp = new Smtp("samar.riabi25@gmail.com", "sr25021998", "smtp.gmail.com", 465);
          if(smtp->sendMail("samar.riabi25@gmail.com","samar.riabi@esprit.tn" , "mail object","contenu du mail"))
          QMessageBox::information(nullptr,QObject::tr("mail"),"e-mail envoyé");
}

void gestion_livre::on_checkBox_stateChanged(int arg1)
{

        etat=arg1;

        ui->tablivre->setModel(tmplivre.rechercheLivre(valeur,etat));



}
