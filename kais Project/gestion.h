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

private slots:
    void on_pushButton_clicked();

private:
    Ui::gestion *ui;
    client tmpclient;
};

#endif // GESTION_H
