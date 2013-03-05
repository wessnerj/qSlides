QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qSlides
TEMPLATE = app

SOURCES += src/main.cpp\
	src/MainWindow.cpp

HEADERS  += src/MainWindow.h

FORMS    += forms/mainWindow.ui