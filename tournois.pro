QT       += core gui sql

QT += printsupport
QT += charts


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    connexion.cpp \   # ✅ Assure l’ajout de connexion.cpp
    qrcode.cpp \
    tournois.cpp

HEADERS += \
    mainwindow.h \
    connexion.h \    # ✅ Ajout du header connexion.h
    qrcode.h \
    tournois.h

FORMS += \
    mainwindow.ui
