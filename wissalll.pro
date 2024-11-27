QT += core gui widgets printsupport sql
QT += core gui charts sql

QT += charts

CONFIG += c++17

SOURCES += \
    commande.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp \
    usermanager.cpp

HEADERS += \
    commande.h \
    connection.h \
    mainwindow.h \
    usermanager.h

FORMS += \
    mainwindow.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
