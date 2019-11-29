#include "passerreclamation.h"
#include "ui_passerreclamation.h"
#include "cpasserreclamation.h"
#include <QMessageBox>
#include "smtp.h"
#include "notification.h"
passerreclamation::passerreclamation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::passerreclamation)


{
    ui->setupUi(this);
    ui->tabreclamation->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tabreclamation->setModel(tmprec.afficher());

    ui->tablreclamation_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablreclamation_2->setModel(tmprec.afficher1());

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->comboBox_5->setModel(tmprec.combob());
    ui->comboBox_2->setModel(tmprec.combob());
    ui->comboBox_3->setModel(tmprec.combob1());
    ui->comboBox_4->setModel(tmprec.combob1());


}

passerreclamation::~passerreclamation()
{
    delete ui;
}

void passerreclamation::on_pushButton_clicked()
{
    reclamation *r;
        hide();
        r= new reclamation(this);
        r->show();
}





void passerreclamation::on_pushButton_3_clicked()
{
    cpasserreclamation tmp;
    int id= ui->lineEdit_12->text().toInt();
    QString sujet= ui->lineEdit_2->text();
    QString type= ui->lineEdit_4->text();
    QString message= ui->lineEdit_5->text();
    QString mail= ui->lineEdit_11->text();
    cpasserreclamation p(id,sujet, type, "non traitée", message, mail,"employé");
    bool test=p.ajouter();
    if(test){
        ui->tabreclamation->setModel(tmp.afficher());//refresh
        ui->comboBox_5->setModel(tmprec.afficher());
        ui->comboBox_2->setModel(tmprec.afficher());
        QString okd="";

        notification ok;
          ok.notification_ajout_reclamation(okd);

  QMessageBox::information(nullptr, QObject::tr("reclamation ajouté"),
                    QObject::tr("reclamation ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("reclamation non ajouté"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }



}



void passerreclamation::on_pushButton_12_clicked()
{
    ui->lineEdit_4->setText("A propos de commande");

}

void passerreclamation::on_pushButton_11_clicked()
{
    ui->lineEdit_4->setText("A propos de Produit");

}

void passerreclamation::on_pushButton_14_clicked()
{
    ui->lineEdit_2->setText("Stock de livres fini");

}


void passerreclamation::on_pushButton_13_clicked()
{
    ui->lineEdit_2->setText("Retard de commande");

}


void passerreclamation::on_pushButton_15_clicked()
{
    ui->lineEdit_2->setText("defaut de produit");

}






void passerreclamation::on_comboBox_5_currentIndexChanged(const QString &arg1)
{
    QSqlQuery qry;
    QString sec = ui->comboBox_5->currentText();

    qry.prepare("select SUJET,TYPE,ETAT,MESSAGE,MAIL from RECLAMATION where ID='"+sec+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
        ui->lineEdit_3->setText(qry.value(0).toString());
        ui->lineEdit->setText(qry.value(1).toString());
        ui->lineEdit_15->setText(qry.value(2).toString());
        ui->lineEdit_14->setText(qry.value(3).toString());


        }
    }
}

void passerreclamation::on_pushButton_4_clicked()
{
    int id= ui->comboBox_5->currentText().toInt();
    QString sujet =ui->lineEdit_3->text();
     QString type=ui->lineEdit->text();
      QString message=ui->lineEdit_15->text();
      QString mail=ui->lineEdit_14->text();

bool test=tmprec.modifier(id,sujet,type,message,mail);
if(test)
{
cpasserreclamation rec;
   ui->tabreclamation->setModel(rec.afficher());
   QMessageBox::information(nullptr, QObject::tr("reclamation modifiée "),
               QObject::tr("reclamation modifiée.\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);


}

else
{
    QMessageBox::critical(nullptr, QObject::tr("reclamation non modifiée"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
}

void passerreclamation::on_pushButton_5_clicked()
{
    int id= ui->comboBox_2->currentText().toInt();

    bool test=tmprec.supprimer(id);
    if(test)
    {ui->tabreclamation->setModel(tmprec.afficher());//refresh
        ui->comboBox_5->setModel(tmprec.afficher());
        ui->comboBox_2->setModel(tmprec.afficher());

        QMessageBox::information(nullptr, QObject::tr("Supprimer une reclamation"),
                    QObject::tr("reclamation supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une reclamation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void passerreclamation::on_pushButton_6_clicked()
{
reclamation *r;
    hide();
    r= new reclamation(this);
    r->show();
}

void passerreclamation::on_pushButton_31_clicked()
{
    reclamation *r;
        hide();
        r= new reclamation(this);
        r->show();
}

void passerreclamation::on_pushButton_32_clicked()
{
    reclamation *r;
        hide();
        r= new reclamation(this);
        r->show();
}

void passerreclamation::on_pushButton_16_clicked()
{
    ui->lineEdit->setText("A Propos De Commande");

}

void passerreclamation::on_pushButton_17_clicked()
{
    ui->lineEdit->setText("A Propos De Produit");

}


void passerreclamation::on_pushButton_18_clicked()
{
    ui->lineEdit_3->setText("Retard de commande");

}



void passerreclamation::on_pushButton_19_clicked()
{
    ui->lineEdit_3->setText("fausse commande (la personne , caracteristiques)");

}

void passerreclamation::on_pushButton_20_clicked()
{
    ui->lineEdit_3->setText("defaut de produit");

}

void passerreclamation::on_pushButton_21_clicked()
{
    ui->lineEdit_7->setText("A Propos De Stock ");

}

void passerreclamation::on_pushButton_22_clicked()
{
    ui->lineEdit_7->setText("A propos des Conditions de travail ");

}

void passerreclamation::on_pushButton_23_clicked()
{
    ui->lineEdit_8->setText("Stock de livres fini ");

}

void passerreclamation::on_pushButton_24_clicked()
{
    ui->lineEdit_8->setText("Stock de livres fini");

}

void passerreclamation::on_pushButton_25_clicked()
{
    ui->lineEdit_8->setText("Autres Conditions de travail pas favorables ");

}

void passerreclamation::on_pushButton_8_clicked()
{
    cpasserreclamation tmp;
    int id= ui->lineEdit_18->text().toInt();
    QString sujet= ui->lineEdit_8->text();
    QString type= ui->lineEdit_7->text();
    QString message= ui->lineEdit_6->text();
    QString mail= ui->lineEdit_17->text();
    cpasserreclamation p(id,sujet, type, "non traitée", message, mail,"employé");
    bool test=p.ajouter1();
    if(test){
        ui->tablreclamation_2->setModel(tmp.afficher());//refresh
    ui->comboBox_3->setModel(tmprec.afficher1());
        ui->comboBox_4->setModel(tmprec.afficher1());
  QMessageBox::information(nullptr, QObject::tr("reclamation ajouté"),
                    QObject::tr("reclamation ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("reclamation non ajouté"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void passerreclamation::on_pushButton_26_clicked()
{
    ui->lineEdit_9->setText("A propos de Stock");

}

void passerreclamation::on_pushButton_27_clicked()
{
    ui->lineEdit_9->setText("A propos des Conditions de travail ");

}

void passerreclamation::on_pushButton_28_clicked()
{
    ui->lineEdit_10->setText("Stock de livres fini ");

}


void passerreclamation::on_pushButton_29_clicked()
{
    ui->lineEdit_10->setText("Salaire D'employé");

}

void passerreclamation::on_pushButton_30_clicked()
{
    ui->lineEdit_10->setText("Autres Conditions de travail pas favorables ");

}

void passerreclamation::on_comboBox_3_currentIndexChanged(const QString &arg1)
{

    QSqlQuery qry;
    QString sec = ui->comboBox_3->currentText();

    qry.prepare("select SUJET,TYPE,ETAT,MESSAGE,MAIL from RECLAMATION where ID='"+sec+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
        ui->lineEdit_10->setText(qry.value(0).toString());
        ui->lineEdit_9->setText(qry.value(1).toString());
        ui->lineEdit_16->setText(qry.value(3).toString());
        ui->lineEdit_13->setText(qry.value(4).toString());


        }
    }
}



void passerreclamation::on_pushButton_33_clicked()
{
    int id= ui->comboBox_3->currentText().toInt();
    QString sujet =ui->lineEdit_10->text();
     QString type=ui->lineEdit_9->text();
      QString message=ui->lineEdit_16->text();
      QString mail=ui->lineEdit_9->text();

bool test=tmprec.modifier(id,sujet,type,message,mail);
if(test)
{
cpasserreclamation rec;
   ui->tablreclamation_2->setModel(rec.afficher());
   QMessageBox::information(nullptr, QObject::tr("reclamation modifiée "),
               QObject::tr("reclamation modifiée.\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);


}

else
{
    QMessageBox::critical(nullptr, QObject::tr("reclamation non modifiée"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
}

void passerreclamation::on_pushButton_10_clicked()
{
    int id= ui->comboBox_4->currentText().toInt();

    bool test=tmprec.supprimer(id);
    if(test)
    {ui->tablreclamation_2->setModel(tmprec.afficher());//refresh
            ui->comboBox_4->setModel(tmprec.afficher1());
                ui->comboBox_3->setModel(tmprec.afficher1());
        QMessageBox::information(nullptr, QObject::tr("Supprimer une reclamation"),
                    QObject::tr("reclamation supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une reclamation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void passerreclamation::on_pushButton_9_clicked()
{
 ui->tablreclamation_2->setModel(tmprec.afficher1());
}

void passerreclamation::on_pushButton_2_clicked()
{
    reclamation *r;
        hide();
        r= new reclamation(this);
        r->show();
}

void passerreclamation::on_pushButton_36_clicked()
{
    int id = ui->lineEdit_19->text().toInt();
    ui->tableView->setModel(tmprec.rechercher(id));
}

void passerreclamation::on_pushButton_34_clicked()
{
    reclamation *r;
        hide();
        r= new reclamation(this);
        r->show();
}

void passerreclamation::on_pushButton_35_clicked()
{
    reclamation *r;
        hide();
        r= new reclamation(this);
        r->show();
}

void passerreclamation::on_pushButton_7_clicked()
{
    reclamation *r;
        hide();
        r= new reclamation(this);
        r->show();
}

void passerreclamation::on_pushButton_37_clicked()
{
    ui->tabreclamation->setModel(tmprec.afficher());

}

void passerreclamation::on_pushButton_38_clicked()
{
    reclamation *r;
        hide();
        r= new reclamation(this);
        r->show();
}


