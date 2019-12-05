#pragma once
#include<QString>

class send_mail
{
public:
    send_mail();
    bool sendMail_cl (QString email,QString nom,QString prenom);
    bool sendMail_s (QString email,QString nom,QString prenom);
};
