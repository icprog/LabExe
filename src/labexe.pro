# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = lib
TARGET = labexe_D
DESTDIR = ../bin
QT += core gui script widgets
CONFIG += debug
DEFINES += LABEXE_LIB QT_SCRIPT_LIB
INCLUDEPATH += ./../include \
    ./GeneratedFiles \
    ./GeneratedFiles/Debug \
    . \
    ./Device \
    ./Param \
    ./ToolBox \
    ./TheLab
LIBS += -L"./../lib" \
    -L"./../bin" \
    -L"."
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/debug
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(labexe.pri)
