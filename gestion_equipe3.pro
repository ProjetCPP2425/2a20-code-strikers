QT       += core gui charts
QT       += sql
QT       += core
INCLUDEPATH += C:/Qt/6.7.0/msvc2019_64/include/QtCharts
LIBS += -LC:/Qt/6.7.2/mingw_64/lib -lQt6Charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    equipe.cpp \
    main.cpp \
    mainwindow.cpp \
    match.cpp \
    smallwindow.cpp \


HEADERS += \
    equipe.h \
    mainwindow.h \
    match.h \
    smallwindow.h

FORMS += \
    mainwindow.ui \
    smallwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
