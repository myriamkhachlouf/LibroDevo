#include "reclamation.h"
#include "ui_reclamation.h"
#include "traiterreclamation.h"
reclamation::reclamation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reclamation)
{
    ui->setupUi(this);
}

reclamation::~reclamation()
{
    delete ui;
}

void reclamation::on_pushButton_clicked()
{QSound::play("C:/Users/ZIZOU/Desktop/click.wav");
    passerreclamation *precl;
    hide();
    precl= new passerreclamation();
    precl->show();
}

void reclamation::on_pushButton_3_clicked()
{QSound::play("C:/Users/ZIZOU/Desktop/click.wav");
    close();
}

void reclamation::on_pushButton_2_clicked()
{QSound::play("C:/Users/ZIZOU/Desktop/click.wav");
    traiterreclamation *precl;
    hide();
    precl= new traiterreclamation();
    precl->show();
}
