#-------------------------------------------------
#
# Project created by QtCreator 2013-02-28T18:18:02
#
#-------------------------------------------------

QT       += core gui

TARGET = QKalmanWalker2D
TEMPLATE = app

INCLUDEPATH += /home/lopez/qt/qwt-5.2.1/src
LIBS += -lqwt

SOURCES += main.cpp\
        ui/mainwindow.cpp \
    ui/settingsdock.cpp \
    simulation/profile/profile.cpp \
    simulation/profile/profilehandler.cpp \
    simulation/simulation.cpp \
    ui/resultwidget.cpp \
    utils/signal.cpp \
    kalman/kalman1d.cpp

HEADERS  += ui/mainwindow.hpp \
    ui/settingsdock.hpp \
    simulation/profile/profile.hpp \
    simulation/profile/profilehandler.hpp \
    utils/array.hpp \
    utils/types.hpp \
    utils/traits/typetrait.hpp \
    utils/traits/parametertrait.hpp \
    utils/traits/select.hpp \
    utils/traits/ispointer.hpp \
    utils/singleton.hpp \
    simulation/simulation.hpp \
    ui/resultwidget.hpp \
    utils/signal.hpp \
    utils/binary_functions/math.hpp \
    kalman/kalman1d.hpp \
    kalman/kalmanfilter.hpp \
    utils/matrix.hpp \
    utils/matrixhelper.hpp
