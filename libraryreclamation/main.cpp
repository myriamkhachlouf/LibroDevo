#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include "notification.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MainWindow d;

    connection c;
    bool test=c.createconnect();

    bool test1=d.traitment_en_retard();
    if(test && test1)
    {w.show();

        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        QString okd="";

        notification ok;
          ok.notification_retard(okd);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();
}
