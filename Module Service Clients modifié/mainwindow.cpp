#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"livraison.h"
#include <QMessageBox>
#include <QPixmap>
#include "carte_fidelite.h"
#include <QTextDocument>
#include <QTextStream>
#include <QPrintDialog>
#include <QPrinter>
#include"QDate"
#include "QDebug"
#include "connexion.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tab_livraison->setModel(tmplivraison.afficher());
ui->comboBox_3->setModel(tmplivraison.afficher_list());
ui->comboBox_2->setModel(tmplivraison.afficher_list());
ui->comboBox_6->setModel(tmplivraison.afficher_list());
ui->tabcarte->setModel(tmpcarte.afficher_carte());
ui->comboBox_4->setModel(tmpcarte.afficher_list());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    //ajouter
    QString datelivraison = ui->date_livraison_e->date().toString();
     QString livre,date,etat;
     int id=ui->id_edit->text().toInt();
     int nbcopie=ui->nombre_copie->text().toInt();
     int prix=ui->prix_ajout->text().toInt();
      etat=ui->etat_e->text();
     livraison l(id ,nbcopie,prix,livre,tmplivraison.get_datelivraison(),etat);

  bool test=l.ajouter();



          if(test)
{

QMessageBox::information(nullptr, QObject::tr("modifier un livraison"),
                QObject::tr("livraison modifié.\n"
                            "Click Cancel to exit."), QMessageBox::Ok);
//ui->tab_livraison->setModel(tmplivraison.afficher());
//ui->comboBox_3->setModel(tmplivraison.afficher_list());
}
  else
      QMessageBox::information(nullptr, QObject::tr("Ajouter un livraison"),
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
tmplivraison.set_id(ui->id_edit_2->text().toInt());
tmplivraison.set_prix(ui->comboBox_6->currentText().toInt());
tmplivraison.set_nbcopie(ui->nombre_copie_2->text().toInt());

    if(tmplivraison.modifierl()){
        ui->tab_livraison->setModel(tmplivraison.afficher());
        ui->comboBox_3->setModel(tmplivraison.afficher_list());
        ui->comboBox_2->setModel(tmplivraison.afficher_list());
}}

void MainWindow::on_date_livraison_e_2_userDateChanged(const QDate &date)
{
    tmplivraison.set_datelivraison(date.toString());

}
/*
void MainWindow::on_nombre_copie_2_cursorPositionChanged(int arg1, int arg2)
{

}

void MainWindow::on_lineEdit_4_cursorPositionChanged(int arg1, int arg2)
{

}
*/
void MainWindow::on_pushButton_3_clicked()
{

    //modifier
    QString datelivraison = ui->date_livraison_e->date().toString();
    QString livre,date,etat;
    int id=ui->id77->text().toInt();
    int nbcopie=ui->nombre_copie_4->text().toInt();
    int prix=ui->prix_line->text().toInt();
     etat=ui->etat_e_4->text();
    livraison l(id ,nbcopie,prix,livre,tmplivraison.get_datelivraison(),etat);

 bool test=l.modifierl();



         if(test)
{

QMessageBox::information(nullptr, QObject::tr("modifier un livraison"),
                 QObject::tr("livraison modifié.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

ui->tab_livraison->setModel(tmplivraison.afficher());
ui->comboBox_3->setModel(tmplivraison.afficher_list());
}
 else
     QMessageBox::critical(nullptr, QObject::tr("Ajouter un livraison"),
                 QObject::tr("Déja saisie !.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
}
/*
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
*/
void MainWindow::on_pb_ajouter_2_clicked()
{
    int id = ui->ajouter_id_carte_fidelite->text().toInt();
    int Nombre_points=ui->ajouter_nombre_de_points->text().toInt();
    int Pourcentage=ui->ajouter_pourcentage->text().toInt();
    QString historique=ui->ajouter_historique->text();
    CARTE_FIDELITE C(id,Nombre_points,Pourcentage,historique);


 bool test=C.ajouter();



         if(test)
{
ui->tabcarte->setModel(tmpcarte.afficher_carte());
QMessageBox::information(nullptr, QObject::tr("Ajouter une carte"),
                 QObject::tr("Carte ajoutée.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

//ui->tabcarte->setModel(tmpcarte.afficher());
ui->comboBox_4->setModel(tmpcarte.afficher_list());
}
 else
     {
             QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                 QObject::tr("Déja saisie !.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
        // ui->tabcarte->setModel(tmpcarte.afficher());
}
}



void MainWindow::on_comboBox_4_activated(const QString &arg1)
{

    tmpcarte.set_Id(arg1.toInt());

}


void MainWindow::on_pb_supprimer_2_clicked()
{
            if(tmpcarte.supprimer())
            {
        ui->tabcarte->setModel(tmpcarte.afficher_carte());
        ui->comboBox_4->setModel(tmpcarte.afficher_list());
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if (tmpcarte.modifier())
    {
        ui->tabcarte->setModel(tmpcarte.afficher_list());
        ui->comboBox_4->setModel(tmpcarte.afficher_list());
    }
}

void MainWindow::on_pushButton_4_clicked()
{

            QString strStream;
                    QTextStream out(&strStream);

                    const int rowCount = ui->tabcarte->model()->rowCount();
                    const int columnCount = ui->tabcarte->model()->columnCount();
                    QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                    out <<"<html>\n"
                          "<head>\n"
                           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        << "<title>ERP - COMmANDE LIST<title>\n "
                        << "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"
                        "<h1 style=\"text-align: center;\"><strong> ****LISTE DES Factures **** "+TT+"</strong></h1>"
                        "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                          "</br> </br>";
                    // headers
                    out << "<thead><tr bgcolor=#d6e5ff>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tabcarte->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tabcarte->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    // data table
                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!ui->tabcarte->isColumnHidden(column)) {
                                QString data =ui->tabcarte->model()->data(ui->tabcarte->model()->index(row, column)).toString().simplified();
                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                            }
                        }
                        out << "</tr>\n";
                    }
                    out <<  "</table>\n"
                        "</body>\n"
                        "</html>\n";

                    QTextDocument *document = new QTextDocument();
                    document->setHtml(strStream);

                    QPrinter printer;

                    QPrintDialog *baba = new QPrintDialog(&printer, NULL);
                    if (baba->exec() == QDialog::Accepted) {
                        document->print(&printer);
                    }

                    delete document;
}
