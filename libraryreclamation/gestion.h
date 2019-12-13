#ifndef GESTION_H
#define GESTION_H
#include "client.h"
#include <QDialog>

namespace Ui {
class gestion;
}

class gestion : public QDialog
{
    Q_OBJECT

public:
    explicit gestion(QWidget *parent = nullptr);
    ~gestion();
        QSqlQueryModel * tri();

private slots:
    void on_pushButton_clicked();



    void on_pushButton_supprimerclient_clicked();

    void on_TRI_clicked();



    void on_lineEdit_textChanged(const QString &arg1);

    void sendMail();
       void mailSent(QString);



    void on_modifier_clicked();


    void on_stat_clicked();

private:
    Ui::gestion *ui;
    client tmpclient;
};

#endif // GESTION_H
