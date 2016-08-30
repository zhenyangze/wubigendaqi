#-------------------------------------------------
#
# Project created by QtCreator 2016-08-29T17:33:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wubigendaqi
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wfileinfo.cpp \
    wfileterform.cpp \
    wfilterdanzi.cpp \
    wfilepipi.cpp

HEADERS  += mainwindow.h \
    wfileinfo.h \
    wfileterform.h \
    wfilterdanzi.h \
    wfilepipi.h

FORMS    += mainwindow.ui \
    wfileterform.ui

DISTFILES += \
    img/file.png

RESOURCES += \
    source.qrc
