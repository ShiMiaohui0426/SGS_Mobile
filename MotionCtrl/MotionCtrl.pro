QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_LFLAGS += -no-pie
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    motionctrl.cpp

HEADERS += \
    motionctrl.h

FORMS += \
    motionctrl.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include(EPOS4CAN_V1.0/EPOS4CAN.pri)
include(controlAPI.pri)
include(VelocityPlanner/VelocityPlanner.pri)
DESTDIR=~/SGS_Mobile/SGS_Mobile_release
