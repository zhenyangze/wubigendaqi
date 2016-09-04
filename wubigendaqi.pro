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
    wfilepipi.cpp \
    wfilterstatement.cpp \
    wfilterword.cpp \
    wfiltercentence.cpp

HEADERS  += mainwindow.h \
    wfileinfo.h \
    wfileterform.h \
    wfilepipi.h \
    wfilterstatement.h \
    wfilterword.h \
    wfiltercentence.h

FORMS    += mainwindow.ui \
    wfileterform.ui \
    wfilterstatement.ui \
    wfilterword.ui \
    wfiltercentence.ui

DISTFILES += \
    img/file.png \
    img/icon.ico

RESOURCES += \
    source.qrc
