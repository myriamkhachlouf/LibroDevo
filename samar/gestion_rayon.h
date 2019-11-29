#ifndef GESTION_RAYON_H
#define GESTION_RAYON_H
#include"rayon.h"
#include <QDialog>

namespace Ui {
class gestion_rayon;
}

class gestion_rayon : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_rayon(QWidget *parent = nullptr);
    ~gestion_rayon();

private slots:


    void on_ajouter_pushButton_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);



    void on_modifier_pushbutton_clicked();

    void on_supprimer_pushButton_clicked();

private:
    Ui::gestion_rayon *ui;
    rayon tmprayon;
};

#endif // GESTION_RAYON_H
