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
    Source/MainFilesProcessor.cpp \
    Source/XMLKeilModify.cpp \
    Source/DialogConfigurationHelp.cpp \
    Source/TextFileProcessor.cpp

HEADERS  += Source/NFWizard2.h \
    Source/FolderTreeGenerator.h \
    Source/MainFilesProcessor.h \
    Source/XMLKeilModify.h \
    Source/DialogConfigurationHelp.h \
    Source/TextFileProcessor.h

FORMS    += Source/NFWizard2.ui \
    Source/DialogConfigurationHelp.ui

INCLUDEPATH += Source

RESOURCES += \
    assets.qrc \
    templates.qrc

RC_ICONS = Assets/icon.ico
