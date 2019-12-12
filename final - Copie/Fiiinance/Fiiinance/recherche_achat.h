#ifndef RECHERCHE_ACHAT_H
#define RECHERCHE_ACHAT_H
#include "achat.h"
#include <QDialog>

namespace Ui {
class Recherche_Achat;
}

class Recherche_Achat : public QDialog
{
    Q_OBJECT

public:
    explicit Recherche_Achat(QWidget *parent = nullptr);
    ~Recherche_Achat();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pdf_2_clicked();

private:
    Ui::Recherche_Achat *ui;
    Achat tmpachat;
};

#endif // RECHERCHE_ACHAT_H
