QT       += core gui sql
QT += core gui network
QT += sql
QT += network
QT += printsupport
QT += charts
QT += core gui network
QT += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c ++11

SOURCES += \
    arduino.cpp \
    main.cpp \
    mainwindow.cpp \
    connexion.cpp \     # ✅ Assure l’ajout de connexion.cpp
    materiels.cpp \
    reservationmanager.cpp \
    sms.cpp

HEADERS += \
    arduino.h \
    mainwindow.h \
    connexion.h \      # ✅ Ajout du header connexion.h
    materiels.h \
    reservationmanager.h \
    sms.h

FORMS += \
    mainwindow.ui
