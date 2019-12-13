#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QDialog>
#include"connection.h"
#include <QWidget>
#include"qcostomplot.h"

namespace Ui {
class STATISTIQUE;
}

class STATISTIQUE : public QDialog
{
    Q_OBJECT

public:
    explicit STATISTIQUE(QWidget *parent = nullptr);
    ~STATISTIQUE();
void makePolt();
private:
    Ui::STATISTIQUE *ui;
};

#endif // STATISTIQUE_H
