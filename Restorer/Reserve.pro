#-------------------------------------------------
#
# Project created by QtCreator 2017-12-01T00:47:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Reserve
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwind.cpp \
    pathwind.cpp \
    ntfs.cpp \
    chooseformat.cpp \
    searching.cpp \
    choosingfiles.cpp \
    choosedisc.cpp \
    choosingplaceforsave.cpp \
    filesinfo.cpp \
    datas.cpp \
    mft.cpp \
    threadof.cpp

HEADERS += \
        mainwind.h \
    pathwind.h \
    ntfs.h \
    chooseformat.h \
    searching.h \
    choosingfiles.h \
    choosedisc.h \
    choosingplaceforsave.h \
    coolapp.rc \
    filesinfo.h \
    datas.h \
    mft.h \
    threadof.h

FORMS += \
        mainwind.ui \
    pathwind.ui \
    chooseformat.ui \
    searching.ui \
    choosingfiles.ui \
    choosedisc.ui \
    choosingplaceforsave.ui

DISTFILES += \
    coolapp.exe.manifest

STATECHARTS += \
    di.scxml
