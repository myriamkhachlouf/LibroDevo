#include "crud.h"
#include "ui_crud.h"

crud::crud(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::crud)
{
    ui->setupUi(this);
}

crud::~crud()
{
    delete ui;
}
