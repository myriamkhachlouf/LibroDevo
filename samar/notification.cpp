#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>
notification::notification()
{

}

void notification:: notification_ajout_LIVRE(QString titre)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/kamel/Desktop/lib3.jpg"));
    QString s = titre;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","Un nouveau livre nommé "+s+" a été ajouté !",QSystemTrayIcon::Information,15000);
//num++;
}
