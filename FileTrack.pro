TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

SOURCES += main.cpp \
    filemonitor.cpp \
    filestate.cpp \
    fileprinter.cpp

HEADERS += \
    filestate.h \
    filemonitor.h \
    fileprinter.h

DISTFILES += \
    file1.txt
