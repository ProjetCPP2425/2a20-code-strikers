QT+= charts serialport
QT +=printsupport
QT       += core gui sql
QT += charts
QT += network
QT +=serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arbitre.cpp \
    arduino.cpp \
    card.cpp \
    connection.cpp \
    dialog.cpp \
    function.cpp \
    main.cpp \
    smtp.cpp \
    uiemp.cpp

HEADERS += \
    arbitre.h \
    arduino.h \
    card.h \
    connection.h \
    dialog.h \
    functions.h \
    smtp.h \
    uiemp.h

FORMS += \
    card.ui \
    dialog.ui \
    dialog.ui \
    uiemp.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc \
    search.qrc
