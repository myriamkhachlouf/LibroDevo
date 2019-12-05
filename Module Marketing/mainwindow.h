#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "smtp.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_buton_ajouter_clicked();

    void on_pushButton_4_clicked();

    void on_boutonsupprimer_clicked();

    void on_bouton_modifier_clicked();

    void on_retour4_clicked();

    void on_pushButton_2_clicked();

    void on_RETOUR1_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_5_clicked();


void notif(QString t,QString m);
    void on_SUPPRIMER_clicked();

    void on_MODIF_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_eventsupprimer_2_clicked();

    void on_retour4_2_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_RETOUR1_3_clicked();

    void on_retour4_5_clicked();

    void on_event_ajouter_2_clicked();

    void on_event_afficher_clicked();

    void on_event_modifier_2_clicked();

    void on_pushButton_9_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_SUPPRIMER_3_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_7_clicked();


    void on_pushButton_13_clicked();


    void on_pushButton_65_clicked();

    void on_pushButton_14_clicked();

    void on_retour4_3_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
