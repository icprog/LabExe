# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = lib
TARGET = ImagePixelAdderPlugin
DESTDIR = ../../plugins/ImagePixelAdderPlugin
QT += core gui
CONFIG += release
DEFINES += QT_LARGEFILE_SUPPORT IMAGEPIXELADDERPLUGIN_LIB
INCLUDEPATH += ./../../include \
    ./../../src \
    ./GeneratedFiles \
    ./GeneratedFiles/Release \
    .
LIBS += -L"./../../lib" \
    -L"./../../bin" \
    -llabexe
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/release
OBJECTS_DIR += release
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(ImagePixelAdderPlugin.pri)
