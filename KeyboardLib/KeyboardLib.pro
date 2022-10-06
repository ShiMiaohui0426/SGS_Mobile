QT   += gui core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11
CONFIG += plugin
#CONFIG += staticlib
TEMPLATE = lib
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    keyboardlib.cpp

HEADERS += \
    keyboardlib.hpp

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
include(Keyboard.pri)
include(controlAPI.pri)

DESTDIR = ~/SGS_Mobile/SGS_Mobile_release/lib
