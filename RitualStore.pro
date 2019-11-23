QT       += core gui network dbus widgets-private

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 link_pkgconfig no_keywords

PKGCONFIG += dtkwidget dtkcore libqapt

TARGET = NeoStore

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    appcomponent.cpp \
    bookpage.cpp \
    categories.cpp \
    components.cpp \
    downloadarea.cpp \
    downloadmanager.cpp \
    downloadpage.cpp \
    localfilter.cpp \
    main.cpp \
    mainview.cpp \
    packageview.cpp \
    secondui.cpp \
    servicemanager.cpp \
    start.cpp

HEADERS += \
    appcomponent.h \
    bookpage.h \
    categories.h \
    components.h \
    downloadarea.h \
    downloadmanager.h \
    downloadpage.h \
    localfilter.h \
    mainview.h \
    packageview.h \
    secondui.h \
    servicemanager.h \
    start.h

FORMS += \
    appcomponent.ui \
    bookpage.ui \
    categories.ui \
    components.ui \
    downloadarea.ui \
    downloadpage.ui \
    mainview.ui \
    packageview.ui \
    secondui.ui \
    start.ui

RESOURCES += \
    main.qrc
