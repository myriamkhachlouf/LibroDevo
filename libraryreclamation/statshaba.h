#ifndef STATSHABA_H
#define STATSHABA_H

#include <QDialog>

#include"connection.h"
#include "qcostomplot.h"
#include <QWidget>
namespace Ui {
class StatShaba;
}

class StatShaba : public QDialog
{
    Q_OBJECT

public:
    explicit StatShaba(QWidget *parent = nullptr);
    ~StatShaba();
    void makePolt();

private:
    Ui::StatShaba *ui;
};

#endif // STATSHABA_H
