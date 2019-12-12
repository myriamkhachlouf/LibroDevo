#ifndef MAINWINDOWS_H
#define MAINWINDOWS_H
#include "employer.h"

#include <QDialog>

namespace Ui {
class mainwindows;
}

class mainwindows : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindows(QWidget *parent = nullptr);
    ~mainwindows();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();
    void on_pb_Modifier_clicked();

private:
    Ui::mainwindows *ui;
    Employer tmpemployer;
};

#endif // MAINWINDOWS_H
