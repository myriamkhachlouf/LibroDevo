#include "login.h"
#include "ui_login.h"
#include"mainwindow.h"
#include"mainwindows.h"
#include <QMessageBox>
#include <QPixmap>
#include<QDialog>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username ==  "test" && password == "test") {
        QMessageBox::information(this, "Login", "Username and password are correct");
       men = new menu(this);
            men->show();

    }
    else {
        QMessageBox::warning(this,"Login", "Username and password are not correct");
    }
}
