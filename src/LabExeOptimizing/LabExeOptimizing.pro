TEMPLATE = lib
DESTDIR = ../../bin
CONFIG(debug, debug|release) {
	TARGET = $$join(TARGET,,,_D)
}

QT += core gui widgets concurrent

DEFINES += LABEXEOPTIMIZING_LIB

INCLUDEPATH += \
    ./../../include/eo \
    ./../../include \
    ./../../src \
    ./GeneratedFiles \
    .

LIBS += \
    -L"./../../lib" \
    -L"./../../bin" \
	-L"./../../lib/eo"

CONFIG(debug, debug|release) {
	LIBS += -llabexe_D \
	-leo_d \
	-leoutils_d \
	-les_d \
	-lga_d \
	-lcma_d \
	-llibnlopt-0
} else {
	LIBS += -llabexe
}

MOC_DIR += ./GeneratedFiles
OBJECTS_DIR += ./GeneratedFiles/Obj
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles

include(LabExeOptimizing.pri)
