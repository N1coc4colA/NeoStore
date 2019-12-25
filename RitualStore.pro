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
    NextUIInterface.cpp \
    about.cpp \
    appcomponent.cpp \
    bookpage.cpp \
    categories.cpp \
    components.cpp \
    contentdownloader.cpp \
    downloadarea.cpp \
    downloadhandler.cpp \
    downloadpage.cpp \
    dtitlebar.cpp \
    flowlayout.cpp \
    installedpackagesview.cpp \
    localfilter.cpp \
    lookupobj.cpp \
    main.cpp \
    mainview.cpp \
    ndeclarative.cpp \
    packageview.cpp \
    screenshotwidget.cpp \
    secondui.cpp \
    servicemanager.cpp \
    start.cpp \
    textprogressbar.cpp \
    tools.cpp \
    toolsview.cpp

HEADERS += \
    NextUIInterface.h \
    about.h \
    appcomponent.h \
    bookpage.h \
    categories.h \
    components.h \
    contentdownloader.h \
    dapplication_p.h \
    downloadarea.h \
    downloadhandler.h \
    downloadpage.h \
    dtitlebar.h \
    flowlayout.h \
    installedpackagesview.h \
    localfilter.h \
    lookupobj.h \
    mainview.h \
    ndeclarative.h \
    packageview.h \
    screenshotwidget.h \
    secondui.h \
    servicemanager.h \
    start.h \
    textprogressbar.h \
    tools.h \
    toolsview.h

FORMS += \
    about.ui \
    appcomponent.ui \
    bookpage.ui \
    categories.ui \
    components.ui \
    downloadarea.ui \
    downloadpage.ui \
    lookupobj.ui \
    mainview.ui \
    packageview.ui \
    screenshotwidget.ui \
    secondui.ui \
    start.ui \
    installedpackagesview.ui \
    tools.ui \
    toolsview.ui

unix:!macx: LIBS += -ldebconf-kde -lKF5CoreAddons -lKF5KIOCore

RESOURCES += \
    main.qrc
