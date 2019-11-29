#ifndef PASSERRECLAMATION_H
#define PASSERRECLAMATION_H

#include <QDialog>
#include <QFontComboBox>
#include "cpasserreclamation.h"
#include "reclamation.h"
namespace Ui {
class passerreclamation;
}

class passerreclamation : public QDialog
{
    Q_OBJECT

public:
    explicit passerreclamation(QWidget *parent = nullptr);
    ~passerreclamation();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_15_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_lineEdit_14_cursorPositionChanged(int arg1, int arg2);

    void on_comboBox_5_currentIndexChanged(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_pushButton_6_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_30_clicked();

    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_pushButton_33_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_38_clicked();

    void on_comboBox_4_currentIndexChanged(const QString &arg1);

private:
    Ui::passerreclamation *ui;
    cpasserreclamation c;
    cpasserreclamation tmprec;

};

#endif // PASSERRECLAMATION_H
