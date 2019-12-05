#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "offre.h"
#include <QSystemTrayIcon>
#include "evenement.h"
#include "mailing/SmtpMime"
#include "smtp.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_buton_ajouter_clicked()
{
this->ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_4_clicked()
{

    offre o;
    this->ui->tableView->setModel(o.afficher());
    this->ui->stackedWidget->setCurrentIndex(2) ;
}

void MainWindow::on_boutonsupprimer_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(3) ;
}

void MainWindow::on_bouton_modifier_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(4) ;
}

void MainWindow::on_retour4_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_2_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_RETOUR1_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_3_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    offre o;
    if (arg1=="")
    this->ui->tableView->setModel(o.afficher());
    else
    this->ui->tableView->setModel(o.rechercher2(arg1));


}

void MainWindow::on_pushButton_5_clicked()
{
     int id=ui->id_ajout->text().toInt();
    offre o(id,this->ui->nom_ajout->text(),this->ui->dated_ajout->text(),this->ui->datef_ajout->text());
    if(o.ajouter())
    {this->ui->stackedWidget->setCurrentIndex(2);
      ui->tableView->setModel(o.afficher());
}}

void MainWindow::on_SUPPRIMER_clicked()
{ offre o;
    QString id=ui->id_supp->text();
    if(o.supprimer(id))
    {this->ui->tableView->setModel(o.afficher());
        this->ui->stackedWidget->setCurrentIndex(2) ;
     MainWindow::notif("supression reussite","supression reussite");}
}

void MainWindow::on_MODIF_clicked()
{
    int id=ui->id_Modif->text().toInt();
   offre o(id,this->ui->nom_Modif->text(),this->ui->dated_Modif->text(),this->ui->datef_Modif->text());
   if(o.modifier())
   {this->ui->stackedWidget->setCurrentIndex(2);
     ui->tableView->setModel(o.afficher());}

}
void MainWindow::notif(QString t,QString m)
{
    QPixmap p(32,32);
    p.load("\\chemin mte3ek");
    QIcon icon(p);
    QSystemTrayIcon n(icon);
    n.setVisible(true);
    n.showMessage(t,m,QSystemTrayIcon::Information,1000);

}



void MainWindow::on_pushButton_8_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_eventsupprimer_2_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_retour4_2_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_11_clicked()
{
   this->ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_12_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_RETOUR1_3_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_retour4_5_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_event_ajouter_2_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_event_afficher_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_event_modifier_2_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_9_clicked()
{

    int id=ui->id_ajout_2->text().toInt();
   evenement e(id,this->ui->nom_ajout_2->text(),this->ui->date_ajout_2->text());
   if(e.ajouter())
   {this->ui->stackedWidget->setCurrentIndex(9);
     ui->tableView_2->setModel(e.afficher());
}

}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    evenement e;
    if (arg1=="")
    this->ui->tableView_2->setModel(e.afficher());
    else
    this->ui->tableView_2->setModel(e.rechercher2(arg1));
}

void MainWindow::on_SUPPRIMER_3_clicked()
{

    evenement e;
        QString id=ui->id_supp_3->text();
        if(e.supprimer(id))
        {this->ui->tableView_2->setModel(e.afficher());
            this->ui->stackedWidget->setCurrentIndex(9) ;
         MainWindow::notif("supression reussite","supression reussite");}

}

void MainWindow::on_pushButton_24_clicked()
{
    int id=ui->id_ajout_5->text().toInt();
  evenement e(id,this->ui->nom_ajout_5->text(),this->ui->date_ajout_4->text());
   if(e.modifier())
   {this->ui->stackedWidget->setCurrentIndex(9);
     ui->tableView_2->setModel(e.afficher());}


}

void MainWindow::on_pushButton_7_clicked()
{
     this->ui->stackedWidget->setCurrentIndex(7);
}



void MainWindow::on_pushButton_13_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
}



/*void MainWindow::on_pushButton_6_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

        // We need to set the username (your email address) and the password
        // for smtp authentification.

        smtp.setUser("zied.soukni@esprit.tn");
        smtp.setPassword("181JMT0077");

        // Now we create a MimeMessage object. This will be the email.

        MimeMessage message;

        message.setSender(new EmailAddress("zied.soukni@esprit.tn", "Zied Soukni"));
        message.addRecipient(new EmailAddress(ui->lineEdit_adresse->text(), "client"));
        message.setSubject(ui->lineEdit_sujet->text());

        // Now add some text to the email.
        // First we create a MimeText object.

        MimeText text;

        text.setText(ui->lineEdit_contenu->text());

        // Now add it to the mail

        message.addPart(&text);

        // Now we can send the mail

        smtp.connectToHost();
        smtp.login();
        smtp.sendMail(message);
        smtp.quit();
}*/



void MainWindow::on_pushButton_65_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(5);

}

void MainWindow::on_pushButton_14_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(6);

}

void MainWindow::on_retour4_3_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_6_clicked()
{
    QString receiver;
    QString objet;
    QString contenu;
    receiver = ui->lineEdit_adresse->text();
    objet = ui->lineEdit_sujet->text();
    contenu = ui->lineEdit_contenu->text();
    Smtp *smtp = new Smtp("zied.soukni@esprit.tn", "181JMT0077", "smtp.gmail.com");
    smtp->sendMail("zied.soukni@esprit.tn",receiver,objet,contenu);
}
