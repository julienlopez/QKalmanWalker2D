include(../QKalmanWalker2D.pri)

QT += testlib
QT -= gui

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

OBJECTS_DIR = $$QKALMANWALKER2D_OBJ_TESTS
MOC_DIR = $$QKALMANWALKER2D_MOC_TESTS

SRCPATH = $$QKALMANWALKER2D_SRC
INCLUDEPATH += $$SRCPATH

SOURCES += main.cpp \ 
    testsignal.cpp \
    $$SRCPATH/utils/signal.cpp

HEADERS += \
    testsignal.hpp \
    $$SRCPATH/utils/signal.hpp \
    $$SRCPATH/utils/binary_functions/math.hpp

