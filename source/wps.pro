
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wps
TEMPLATE = app

DESTDIR += bin
RCC_DIR += output
MOC_DIR += output
OBJECTS_DIR += output
DEPENDPATH += . src inc output qss
INCLUDEPATH += inc

CODECFORSRC = UTF8

SOURCES += main.cpp \
	src/wps_wmainwidget.cpp \
	src/wps_wtitlebar.cpp

HEADERS  += inc/wps_wmainwidget.h \
	inc/wps_wtitlebar.h

RESOURCES += \
    qss/wps.qrc









