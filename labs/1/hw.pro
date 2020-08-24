TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/l1_UserInterface.cpp \
    src/l2_ApplicationLayer.cpp \
    src/l3_DomainLayer.cpp \
    src/l4_InfrastructureLayer.cpp

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include
DEPENDPATH += $$PWD/src

HEADERS += \
    include/hw/l2_ApplicationLayer.h \
    include/hw/l3_DomainLayer.h \
    include/hw/l4_InfrastructureLayer.h

