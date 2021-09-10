QT -= gui
QT += widgets #necesario para el qsystemtrayicon (segundo plano y notis)
TEMPLATE = lib
DEFINES += DANIASSISTANT_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    daniassistant.cpp

HEADERS += \
    DaniAssistant_global.h \
    daniassistant.h

#necesario para el qsystemtrayicon (segundo plano y notis) y para el qmouseevent
QMAKE_CXXFLAGS += -std=gnu++14

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
