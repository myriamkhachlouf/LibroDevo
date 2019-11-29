#include "notification.h"

notification::notification()
{
int num=0;
}
void notification::notification_ajout_reclamation_client(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Utilisateurs/ZIZOU/Bureau/notif.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("notification","Une nouvelle reclamation a été ajouté !",QSystemTrayIcon::Information,15000);
//num++;
}
void notification::notification_ajout_reclamation_employe(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Utilisateurs/ZIZOU/Bureau/notif.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","Une nouvelle reclamation a été ajouté !",QSystemTrayIcon::Information,15000);
//num++;
}
