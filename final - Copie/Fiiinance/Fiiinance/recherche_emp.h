#ifndef RECHERCHE_EMP_H
#define RECHERCHE_EMP_H
#include"employer.h"
#include <QDialog>

namespace Ui {
class Recherche_Emp;
}

class Recherche_Emp : public QDialog
{
    Q_OBJECT

public:
    explicit Recherche_Emp(QWidget *parent = nullptr);
    ~Recherche_Emp();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pdf_2_clicked();

private:
    Ui::Recherche_Emp *ui;
    Employer tmpemp;
};

#endif // RECHERCHE_EMP_H
