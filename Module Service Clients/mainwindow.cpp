#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"livraison.h"
#include <QMessageBox>
#include <QPixmap>
#include "CARTE_FIDELITE.h"
#include <QTextDocument>
#include <QTextStream>
#include <QPrintDialog>
#include <QPrinter>
#include"QDate"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tab_livraison->setModel(tmplivraison.afficher());
ui->comboBox_3->setModel(tmplivraison.afficher_list());
ui->comboBox_2->setModel(tmplivraison.afficher_list());
ui->comboBox_6->setModel(tmplivraison.afficher_list());
 QPixmap photo("C:/Users/fac/Desktop/projet/multimedia/biblo.png") ;
  ui->label_photo->setPixmap(photo);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
     QString datelivraison = ui->date_livraison_e->date().toString();
     QString livre,date,etat;
     int id=ui->id_edit->text().toInt();
     int nbcopie=ui->nombre_copie->text().toInt();
     int prix=ui->prix->text().toInt();
     livraison l(id ,nbcopie,prix,livre,tmplivraison.get_datelivraison(),etat);

  bool test=l.ajouter();



          if(test)
{

QMessageBox::information(nullptr, QObject::tr("Ajouter un livraison"),
                  QObject::tr("livraison ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

ui->tab_livraison->setModel(tmplivraison.afficher());
ui->comboBox_3->setModel(tmplivraison.afficher_list());
}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un livraison"),
                  QObject::tr("Déja saisie !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_date_livraison_e_userDateChanged(const QDate &date)
{
tmplivraison.set_datelivraison(date.toString());
}

void MainWindow::on_comboBox_3_activated(const QString &arg1)
{
    tmplivraison.set_id(arg1.toInt());

}

void MainWindow::on_pb_supprimer_clicked()
{
    if(tmplivraison.supprimer()){
        ui->tab_livraison->setModel(tmplivraison.afficher());
        ui->comboBox_3->setModel(tmplivraison.afficher_list());
        ui->comboBox_2->setModel(tmplivraison.afficher_list());
}
}

void MainWindow::on_comboBox_2_activated(const QString &arg1)
{
    tmplivraison.set_id(arg1.toInt());
   }

void MainWindow::on_pushButton_clicked()
{
    tmplivraison.set_etat(ui->etat_e_2->text());

tmplivraison.set_prix(ui->prix_2->text().toInt());
tmplivraison.set_nbcopie(ui->nombre_copie_2->text().toInt());

    if(tmplivraison.modifier()){
        ui->tab_livraison->setModel(tmplivraison.afficher());
        ui->comboBox_3->setModel(tmplivraison.afficher_list());
        ui->comboBox_2->setModel(tmplivraison.afficher_list());
}}

void MainWindow::on_date_livraison_e_2_userDateChanged(const QDate &date)
{
    tmplivraison.set_datelivraison(date.toString());

}

void MainWindow::on_nombre_copie_2_cursorPositionChanged(int arg1, int arg2)
{

}

void MainWindow::on_lineEdit_4_cursorPositionChanged(int arg1, int arg2)
{

}

void MainWindow::on_pushButton_3_clicked()
{

}

void MainWindow::on_comboBox_6_currentIndexChanged(const QString &arg1)
{

}

void MainWindow::on_etat_e_4_cursorPositionChanged(int arg1, int arg2)
{

}

void MainWindow::on_nombre_copie_4_cursorPositionChanged(int arg1, int arg2)
{

}

void MainWindow::on_nombre_copie_cursorPositionChanged(int arg1, int arg2)
{

}

void MainWindow::on_prix_cursorPositionChanged(int arg1, int arg2)
{

}

void MainWindow::on_id_combobox_activated(const QString &arg1)
{

}

void MainWindow::on_pb_ajouter_2_clicked()
{
    int Id = ui->lineEdit_4->text().toInt();
    int Nombre_points=ui->lineEdit_5->text().toInt();
    int Pourcentage=ui->lineEdit_6->text().toInt();
    QString Historique=ui->lineEdit_7->text();
    CARTE_FIDELITE C(Id,Nombre_points,Pourcentage,Historique);

 bool test=C.ajouter();



         if(test)
{

QMessageBox::information(nullptr, QObject::tr("Ajouter une carte"),
                 QObject::tr("Carte ajoutée.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

ui->tabcarte->setModel(tmpcarte.afficher());
ui->comboBox_4->setModel(tmpcarte.afficher_list());
}
 else
     QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                 QObject::tr("Déja saisie !.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
         ui->tabcarte->setModel(tmpcarte.afficher());
}


void MainWindow::on_tabWidget_currentChanged(int index)
{

}

void MainWindow::on_tab_livraison_activated(const QModelIndex &index)
{

}

void MainWindow::on_tabetudiant_2_activated(const QModelIndex &index)
{

}

void MainWindow::on_tabcarte_activated(const QModelIndex &index)
{

}
