QT       += core gui
QT       += core gui sql printsupport
QT       +=network multimedia
QT +=serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    achat.cpp \
    arduino.cpp \
    capteur.cpp \
    client.cpp \
    connection.cpp \
    cpasserreclamation.cpp \
    crudachat.cpp \
    ctraiterreclamation.cpp \
    dialog.cpp \
    employer.cpp \
    gestion.cpp \
    gestion_livre.cpp \
    gestion_rayon.cpp \
    intermediaire.cpp \
    livre.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindows.cpp \
    notification.cpp \
    passerreclamation.cpp \
    qcostomplot.cpp \
    rayon.cpp \
    recherche_achat.cpp \
    recherche_emp.cpp \
    reclamation.cpp \
    smtp.cpp \
    statistique.cpp \
    statshaba.cpp \
    traiterreclamation.cpp
    smtp.cpp \

HEADERS += \
    achat.h \
    arduino.h \
    capteur.h \
    client.h \
    connection.h \
    cpasserreclamation.h \
    crudachat.h \
    ctraiterreclamation.h \
    dialog.h \
    employer.h \
    gestion.h \
    gestion_livre.h \
    gestion_rayon.h \
    intermediaire.h \
    livre.h \
    mainwindow.h \
    mainwindows.h \
    notification.h \
    passerreclamation.h \
    qcostomplot.h \
    rayon.h \
    recherche_achat.h \
    recherche_emp.h \
    reclamation.h \
    smtp.h \
    statistique.h \
    statshaba.h \
    traiterreclamation.h
    smtp.h \

FORMS += \
    capteur.ui \
    crudachat.ui \
    dialog.ui \
    gestion.ui \
    gestion_livre.ui \
    gestion_rayon.ui \
    intermediaire.ui \
    mainwindow.ui \
    mainwindows.ui \
    passerreclamation.ui \
    recherche_achat.ui \
    recherche_emp.ui \
    reclamation.ui \
    statistique.ui \
    statshaba.ui \
    traiterreclamation.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
