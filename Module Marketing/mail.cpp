#include"mail.hpp"
#include "mail.hpp"
#include <QObject>
#include "QSqlQuery"
#include<QString>
#include<C:\Users\melliti\Desktop\project\service_client_rc\smtp.h>
bool send_mail::sendMail_cl(QString email, QString nom, QString prenom)
{

    QString x="465";
    QString y="";
    QString z=email;
    QString status="";
    Smtp* smtp = new Smtp("mohamedamine.melliti@esprit.tn","esprit2018","smtp.gmail.com",x.toInt());
    int i=0;
    if(z!="")
    {
          y="Bonjour "+prenom+ " "+nom+"," "\n\rPARIKING SAMRT UNIVERSITY ASSURE LA RESERVATION DE VOTRE PLACE \n";

           i++;
    }
      if(i==1)
      {
   smtp->sendMail("mohamedamine.melliti@esprit.tn",z,"INSCRIPTION IMPRIMERIE",y);
          return true;

      }
      else

      return false;
}
