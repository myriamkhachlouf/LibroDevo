#ifndef RECLAMATION_H
#define RECLAMATION_H

#include <QDialog>
#include "ui_reclamation.h"
#include "passerreclamation.h"

namespace Ui {
class reclamation;
}

class reclamation : public QDialog
{
    Q_OBJECT

public:
    explicit reclamation(QWidget *parent = nullptr);
    ~reclamation();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::reclamation *ui;


};

#endif // RECLAMATION_H
