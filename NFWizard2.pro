#-------------------------------------------------
#
# Project created by QtCreator 2016-01-29T22:47:50
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NFWizard2
TEMPLATE = app


SOURCES += Source/main.cpp\
        Source/NFWizard2.cpp \
    Source/FolderTreeGenerator.cpp \
    Source/CubeInterruptFileProcessor.cpp \
    Source/MainFilesProcessor.cpp \
    Source/XMLKeilModify.cpp

HEADERS  += Source/NFWizard2.h \
    Source/FolderTreeGenerator.h \
    Source/CubeInterruptFileProcessor.h \
    Source/MainFilesProcessor.h \
    Source/XMLKeilModify.h

FORMS    += Source/NFWizard2.ui

INCLUDEPATH += Source
