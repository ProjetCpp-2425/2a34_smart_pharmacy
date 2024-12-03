QT   += core gui charts
    quick
QT       += core gui sql printsupport network
QT += sql
QT += serialport
QT += widgets quickwidgets
QT += core gui network quick positioning location
QT += network #weather

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino_ha.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp \
    ordonnance.cpp \
    transactions.cpp

HEADERS += \
    arduino_ha.h \
    connection.h \
    mainwindow.h \
    ordonnance.h \
    transactions.h

FORMS += \
    mainwindow.ui
    OpenAIImageGenerator.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
