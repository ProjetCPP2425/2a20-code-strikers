QT += core gui widgets charts sql serialport

CONFIG += c++17

SOURCES += \
    arduino.cpp \
    equipe.cpp \
    main.cpp \
    mainwindow.cpp \
    match.cpp \
    pie.cpp \
    piechart.cpp \
    smallwindow.cpp

HEADERS += \
    arduino.h \
    equipe.h \
    mainwindow.h \
    match.h \
    pie.h \
    piechart.h \
    smallwindow.h

FORMS += \
    mainwindow.ui \
    mainwindowTr.ui \
    piechart.ui \
    smallwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
