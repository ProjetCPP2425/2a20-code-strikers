QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    connexion.cpp   # ✅ Assure l’ajout de connexion.cpp

HEADERS += \
    mainwindow.h \
    connexion.h    # ✅ Ajout du header connexion.h

FORMS += \
    mainwindow.ui
