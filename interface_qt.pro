QT       += core gui
QT       += core gui sql
QT += charts
QT += core gui network



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


SOURCES += \
    connection.cpp \
    main.cpp \
    mainwindow.cpp \
    staff.cpp

HEADERS += \
    connection.h \
    mainwindow.h \
    staff.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc





