#include "traiterreclamation.h"
#include "ui_traiterreclamation.h"
#include "ctraiterreclamation.h"
#include "cpasserreclamation.h"
#include <QtWidgets/QMessageBox>
#include "smtp.h"
traiterreclamation::traiterreclamation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::traiterreclamation)
{
    ui->setupUi(this);
    ui->comboBox->setModel(tmprec.combob());
    ui->comboBox_6->setModel(tmprec.combob1());
    ui->tabreclamation_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->comboBox_3->setModel(tmprec.combob1());

}

traiterreclamation::~traiterreclamation()
{
    delete ui;
}

void traiterreclamation::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QSqlQuery qry;
    QString sec = ui->comboBox->currentText();

    qry.prepare("select SUJET,TYPE,MAIL,MESSAGE,POURQUI from RECLAMATION where ID='"+sec+"' and ETAT='non traitée'");

    if(qry.exec())
    {
        while(qry.next())
        {
        ui->lineEdit_26->setText(qry.value(0).toString());
        ui->lineEdit_25->setText(qry.value(1).toString());
        ui->lineEdit_27->setText(qry.value(2).toString());
        ui->lineEdit_28->setText(qry.value(3).toString());
        ui->lineEdit_30->setText(qry.value(4).toString());


        }
    }
}

void traiterreclamation::on_pushButton_47_clicked()
{QSound::play("C:/Users/ZIZOU/Desktop/click.wav");
    ui->comboBox->setModel(tmprec.afficher2());

    ctraiterreclamation tmp;

    int id= ui->comboBox->currentText().toInt();
    QString reponse= ui->lineEdit_29->text();

    ctraiterreclamation p(reponse,id);
    bool test=p.ajouter();
     bool test1=p.modifieretat();
    if(test && test1){
        ui->tabreclamation_2->setModel(tmp.afficher());//refresh
        ui->comboBox->setModel(tmprec.afficher2());
        ui->comboBox_6->setModel(tmprec.afficher1());

        ui->comboBox_3->setModel(tmprec.afficher1());

  QMessageBox::information(nullptr, QObject::tr("reponse de reclamation ajouté"),
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

void traiterreclamation::on_comboBox_6_currentIndexChanged(const QString &arg1)
{
    QSqlQuery qry;

    QString sec = ui->comboBox_6->currentText();

    qry.prepare("select SUJET,TYPE,MESSAGE,MAIL,POURQUI from RECLAMATION where ID='"+sec+"' ");

    if(qry.exec())

    {
        while(qry.next())
        {
        ui->lineEdit_10->setText(qry.value(0).toString());
        ui->lineEdit_9->setText(qry.value(1).toString());
        ui->lineEdit_18->setText(qry.value(2).toString());
        ui->lineEdit_17->setText(qry.value(3).toString());
        ui->lineEdit_31->setText(qry.value(4).toString());


        }
    }

}






void traiterreclamation::on_pushButton_clicked()
{QSound::play("C:/Users/ZIZOU/Desktop/click.wav");
    ui->tabreclamation_2->setModel(tmprec.afficher());

}


void traiterreclamation::on_pushButton_8_clicked()
{
QSound::play("C:/Users/ZIZOU/Desktop/click.wav");
    QString reponse =ui->lineEdit_35->text();
    int id = ui->comboBox_6->currentText().toInt();

bool test=tmprec.modifier(id,reponse);

if(test)
{
ctraiterreclamation rec;
   ui->tabreclamation_2->setModel(rec.afficher());
   ui->comboBox_6->setModel(tmprec.afficher1());
   ui->comboBox_3->setModel(tmprec.afficher1());

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

void traiterreclamation::on_pushButton_3_clicked()
{QSound::play("C:/Users/ZIZOU/Desktop/click.wav");
    reclamation *r;
        hide();
        r= new reclamation(this);
        r->show();
}

void traiterreclamation::on_pushButton_9_clicked()
{QSound::play("C:/Users/ZIZOU/Desktop/click.wav");
    reclamation *r;
        hide();
        r= new reclamation(this);
        r->show();
}

void traiterreclamation::on_pushButton_2_clicked()
{QSound::play("C:/Users/ZIZOU/Desktop/click.wav");
    reclamation *r;
        hide();
        r= new reclamation(this);
        r->show();
}

void traiterreclamation::on_pushButton_4_clicked()
{QSound::play("C:/Users/ZIZOU/Desktop/click.wav");
    reclamation *r;
        hide();
        r= new reclamation(this);
        r->show();
}


void traiterreclamation::on_pushButton_10_clicked()
{QSound::play("C:/Users/ZIZOU/Desktop/click.wav");
    int id= ui->comboBox_3->currentText().toInt();
    bool test=tmprec.supprimer(id);
    bool test1=tmprec1.supprimer1(id);
    if(test && test1)
    {ui->tabreclamation_2->setModel(tmprec.afficher());//refresh
        ui->comboBox_6->setModel(tmprec.afficher1());
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






void traiterreclamation::on_pushButton_5_clicked()
{QSound::play("C:/Users/ZIZOU/Desktop/click.wav");
    QString uname="mohamedazizsmati@gmail.com";
    QString passwd="Aziz_28157057@";
    QString server="smtp.gmail.com";

    Smtp* smtp = new Smtp(uname, passwd, server,465);
             if(smtp->sendMail(uname,ui->lineEdit_27->text() , "on a traité bien traité votre reclamation",ui->lineEdit_29->text()))
             QMessageBox::information(nullptr,QObject::tr("mail"),"e-mail envoyé");
}
