QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    entidad.cpp \
    gestorarchivos.cpp \
    item.cpp \
    main.cpp \
    mainwindow.cpp \
    objetopesado.cpp \
    obstaculo.cpp \
    personaje.cpp \
    tile.cpp

HEADERS += \
    entidad.h \
    gestorarchivos.h \
    item.h \
    mainwindow.h \
    objetopesado.h \
    obstaculo.h \
    personaje.h \
    tile.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
