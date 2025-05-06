QT += core gui widgets charts sql serialport

QT       += core gui sql
QT += core gui network
QT += sql
QT += network
QT += printsupport
QT += charts
QT += core gui network
QT += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    arduino.cpp \
    arduinoo.cpp \
    equipe.cpp \
    main.cpp \
    mainwindow.cpp \
    match.cpp \
    materiels.cpp \
    pie.cpp \
    piechart.cpp \
    qrcode.cpp \
    reservationmanager.cpp \
    smallwindow.cpp \
    sms.cpp \
    tournois.cpp

HEADERS += \
    arduino.h \
    arduinoo.h \
    equipe.h \
    mainwindow.h \
    match.h \
    materiels.h \
    pie.h \
    piechart.h \
    qrcode.h \
    reservationmanager.h \
    smallwindow.h \
    sms.h \
    tournois.h

FORMS += \
    mainwindow.ui \
    mainwindowTr.ui \
    piechart.ui \
    smallwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
