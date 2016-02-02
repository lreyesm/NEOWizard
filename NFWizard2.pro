#-------------------------------------------------
#
# Project created by QtCreator 2016-01-29T22:47:50
#
#-------------------------------------------------

QT       += core gui concurrent xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NFWizard2
TEMPLATE = app


SOURCES += Source/main.cpp\
        Source/NFWizard2.cpp \
    Source/FileParser.cpp \
    Source/FolderTreeGenerator.cpp

HEADERS  += Source/NFWizard2.h \
    Source/FileParser.h \
    Source/FolderTreeGenerator.h

FORMS    += Source/NFWizard2.ui

INCLUDEPATH += Source
