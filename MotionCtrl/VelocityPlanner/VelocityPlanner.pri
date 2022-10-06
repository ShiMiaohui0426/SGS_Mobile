QT       += charts

SOURCES += \
    $$PWD$$/velocityplanner.cpp

HEADERS += \
    $$PWD$$/velocityplanner.h

FORMS += \
    $$PWD$$/velocityplanner.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
include($$PWD$$/qplcmodel.pri)
