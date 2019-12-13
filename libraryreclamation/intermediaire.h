#ifndef INTERMEDIAIRE_H
#define INTERMEDIAIRE_H
#include "capteur.h"
#include <QDialog>

namespace Ui {
class intermediaire;
}

class intermediaire : public QDialog
{
    Q_OBJECT

public:
    explicit intermediaire(QWidget *parent = nullptr);
    ~intermediaire();

private slots:

    void on_rayon_pushbutton_clicked();

    void on_livre_pushbutton_clicked();

    void on_capteur_pushButton_clicked();

private:
    Ui::intermediaire *ui;

};

#endif // INTERMEDIAIRE_H
