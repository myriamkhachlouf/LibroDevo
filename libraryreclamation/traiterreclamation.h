#ifndef TRAITERRECLAMATION_H
#define TRAITERRECLAMATION_H

#include <QDialog>
#include "ctraiterreclamation.h"
#include "QMessageBox"
#include "reclamation.h"
#include<QSound>
namespace Ui {
class traiterreclamation;
}

class traiterreclamation : public QDialog
{
    Q_OBJECT

public:
    explicit traiterreclamation(QWidget *parent = nullptr);
    ~traiterreclamation();

private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_47_clicked();

    void on_comboBox_6_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_pushButton_10_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::traiterreclamation *ui;
    ctraiterreclamation c;
    ctraiterreclamation tmprec;
    ctraiterreclamation tmprec1;
private slots :
  void sendMail();


};

#endif // TRAITERRECLAMATION_H
