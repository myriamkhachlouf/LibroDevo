#include "intermediaire.h"
#include "ui_intermediaire.h"
#include "gestion_livre.h"
#include "gestion_rayon.h"
#include<QPixmap>

intermediaire::intermediaire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::intermediaire)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/kamel/Desktop/lib2.jpg");
    ui->label_pic->setPixmap(pix);
}

intermediaire::~intermediaire()
{
    delete ui;
}


void intermediaire::on_rayon_pushbutton_clicked()
{
    gestion_rayon *r= new gestion_rayon(this);
    r->show();
}

void intermediaire::on_livre_pushbutton_clicked()
{
    gestion_livre *l= new gestion_livre(this);
    l->show();
}
