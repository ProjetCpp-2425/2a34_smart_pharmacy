QT += core gui widgets charts quick quickwidgets sql printsupport network serialport

CONFIG += c++17

# Optional: Disable deprecated APIs
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += \
    arduino_ha.cpp \
    connection.cpp \
    historique.cpp \
    main.cpp \
    mainwindow.cpp \
    notification.cpp \
    ordonnance.cpp \
    staff.cpp \
    stock.cpp \
    transactions.cpp

HEADERS += \
    arduino_ha.h \
    connection.h \
    historique.h \
    mainwindow.h \
    notification.h \
    ordonnance.h \
    staff.h \
    stock.h \
    transactions.h

FORMS += \
    mainwindow.ui \


RESOURCES += \
    resource.qrc

# Deployment rules
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
