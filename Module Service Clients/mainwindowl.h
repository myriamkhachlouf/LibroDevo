#ifndef MAINWINDOWL_H
#define MAINWINDOWL_H
#include "mainwindow.h"

#include <QMainWindow>

namespace Ui {
class MainWindowl;
}

class MainWindowl : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowl(QWidget *parent = nullptr);
    ~MainWindowl();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindowl *ui;
    MainWindow *mainwindow;
};

#endif // MAINWINDOWL_H
