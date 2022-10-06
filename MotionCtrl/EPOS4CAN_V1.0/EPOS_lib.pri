HEADERS += \
    EPOS_Linux_Library/include/Definitions.h \

unix:!macx: LIBS += -L$$PWD/EPOS_Linux_Library/lib/intel/x86_64/ -lEposCmd

INCLUDEPATH += $$PWD/EPOS_Linux_Library/lib/intel/x86_64
DEPENDPATH += $$PWD/EPOS_Linux_Library/lib/intel/x86_64

unix:!macx: LIBS += -L$$PWD/EPOS_Linux_Library/lib/intel/x86_64/ -lftd2xx

INCLUDEPATH += $$PWD/EPOS_Linux_Library/lib/intel/x86_64
DEPENDPATH += $$PWD/EPOS_Linux_Library/lib/intel/x86_64
