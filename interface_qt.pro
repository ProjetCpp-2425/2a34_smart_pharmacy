QT += core gui widgets charts quick quickwidgets sql printsupport network serialport

CONFIG += c++17

QT += core gui charts sql
QT += charts
QT += serialport

# Optional: Disable deprecated APIs
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += \
    arduino_ha.cpp \
    commande.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp \
    ordonnance.cpp \
    staff.cpp \
    transactions.cpp \
    usermanager.cpp

HEADERS += \
    arduino_ha.h \
    commande.h \
    connection.h \
    mainwindow.h \
    ordonnance.h \
    staff.h \
    transactions.h \
    usermanager.h

FORMS += \
    mainwindow.ui \


RESOURCES += \
    resource.qrc

# Deployment rules
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
