#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTextDocument>
#include <QTextStream>
#include <QPrintDialog>
#include <QPrinter>
#include"QDate"
#include "livraison.h"
#include <QMainWindow>
#include "CARTE_FIDELITE.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();





    void on_date_livraison_e_userDateChanged(const QDate &date);

    void on_comboBox_3_activated(const QString &arg1);

    void on_pb_supprimer_clicked();

    void on_comboBox_2_activated(const QString &arg1);

    void on_pushButton_clicked();

    void on_date_livraison_e_2_userDateChanged(const QDate &date);

    void on_nombre_copie_2_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_4_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_3_clicked();

    void on_comboBox_6_currentIndexChanged(const QString &arg1);

    void on_etat_e_4_cursorPositionChanged(int arg1, int arg2);

    void on_nombre_copie_4_cursorPositionChanged(int arg1, int arg2);

    void on_nombre_copie_cursorPositionChanged(int arg1, int arg2);

    void on_prix_cursorPositionChanged(int arg1, int arg2);

    void on_id_combobox_activated(const QString &arg1);

    void on_pb_ajouter_2_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_tab_livraison_activated(const QModelIndex &index);

    void on_tabetudiant_2_activated(const QModelIndex &index);

    void on_tabcarte_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    livraison tmplivraison;
    CARTE_FIDELITE tmpcarte;


};

#endif // MAINWINDOW_H
