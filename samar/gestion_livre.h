#ifndef GESTION_LIVRE_H
#define GESTION_LIVRE_H
#include "livre.h"
#include <QDialog>

namespace Ui {
class gestion_livre;
}

class gestion_livre : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_livre(QWidget *parent = nullptr);
    ~gestion_livre();

private slots:


    void on_ajouter_pushButton_clicked();

    void on_supprimer_pushButton_clicked();

    void on_comboBox_L_currentIndexChanged(const QString &arg1);
    //void on_modifier_pushButton_clicked();

    void on_modifier_pushButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_mail_pushButton_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::gestion_livre *ui;
    livre tmplivre;
    int etat=1;
    QString valeur=0;

};

#endif // GESTION_LIVRE_H
