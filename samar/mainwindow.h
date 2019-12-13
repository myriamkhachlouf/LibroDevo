#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "livre.h"
#include "rayon.h"
#include "QMessageBox"
#include <QSound>
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer *monTimer;




public slots:
     void mytimer();
private slots:
    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
