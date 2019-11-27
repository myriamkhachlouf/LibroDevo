#ifndef LOGIN_H
#define LOGIN_H
#include"mainwindow.h"
#include"mainwindows.h"
#include <QWidget>
#include <QDialog>
#include "dialog.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_Login_clicked();

private:
    Ui::Login *ui;
    Dialog * dial;
};

#endif // LOGIN_H
