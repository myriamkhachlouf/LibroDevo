#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <reclamation.h>
#include <QMessageBox>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QSound>
#include "intermediaire.h"
#include "livre.h"
#include "rayon.h"
#include "dialog.h"
#include "gestion.h"
#include <QTimer>
#include<QSound>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString id_return();
    bool traitment_en_retard();
    QTimer *monTimer;
public slots:
    void mytimer();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    reclamation *recl;
    QSound *son;

};
#endif // MAINWINDOW_H
