#include "gestion_rayon.h"
#include "ui_gestion_rayon.h"
#include"rayon.h"
#include<QMessageBox>
#include<QComboBox>
#include "intermediaire.h"

gestion_rayon::gestion_rayon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_rayon)
{
    ui->setupUi(this);
    ui->tabrayon->setModel(tmprayon.afficher());
    ui->comboBox->setModel(tmprayon.get_id_model());

}

gestion_rayon::~gestion_rayon()
{
    delete ui;
}


void gestion_rayon::on_ajouter_pushButton_clicked()
{    int id = ui->lineEdit_id->text().toInt();
    int numero=ui->spinBox->text().toInt();
     rayon r(id,numero);
      bool test=r.ajouter();
     if(test)
   {
         ui->tabrayon->setModel(tmprayon.afficher());
         ui->comboBox->setModel(tmprayon.get_id_model());

   QMessageBox::information(nullptr, QObject::tr("Ajouter un rayon"),
                     QObject::tr("rayon ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
     else
         QMessageBox::critical(nullptr, QObject::tr("Ajouter un rayon"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion_rayon::on_supprimer_pushButton_clicked()
{
    int id = ui->lineEdit_7->text().toInt();
    bool test=tmprayon.supprimer(id);
    if(test)
    {
        ui->tabrayon->setModel(tmprayon.afficher());
        ui->comboBox->setModel(tmprayon.get_id_model());

        QMessageBox::information(nullptr, QObject::tr("Supprimer un rayon"),
                    QObject::tr("livre supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un rayon"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion_rayon::on_comboBox_currentIndexChanged(const QString &arg1)
{
     QString id= QString::number(ui->comboBox->currentText().toInt());
     QSqlQuery query;
     query.prepare("select * from rayon where id='"+id+"'");
     query.exec();
     while(query.next())
     {
         ui->num_linedit->setText(query.value(1).toString());
     }
}


void gestion_rayon::on_modifier_pushbutton_clicked()
{
    int numero = ui->num_linedit->text().toInt();
    int id = ui->comboBox->currentText().toInt();
    rayon r;
    bool test=r.modifier(id,numero);
    if(test)
    {
        ui->tabrayon->setModel(tmprayon.afficher());
        ui->comboBox->setModel(tmprayon.get_id_model());

     QMessageBox::information(nullptr,QObject::tr("Modifier Rayon"),"Modification effectuée");
    }
    else
    {

        QMessageBox::warning(nullptr,QObject::tr("Modifier Rayon"),"ERROR:Modification non effectuée!");
}
}



void gestion_rayon::on_fermer_clicked()
{
    intermediaire *i;
    hide();
    i=new intermediaire(this);
    i->show();
}

void gestion_rayon::on_pushButton_clicked()
{
    intermediaire *i;
    hide();
    i=new intermediaire(this);
    i->show();
}

void gestion_rayon::on_pushButton_2_clicked()
{
    intermediaire *i;
    hide();
    i=new intermediaire(this);
    i->show();
}
