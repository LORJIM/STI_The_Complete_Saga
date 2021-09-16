QT       += core gui
QT       += multimedia #necesario para reproducir musica o videos qmedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    listwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    modalpj.cpp \
    sti2.cpp \
    sti3.cpp

HEADERS += \
    listwidget.h \
    mainwindow.h \
    modalpj.h \
    sti2.h \
    sti3.h

FORMS += \
    listwidget.ui \
    mainwindow.ui \
    modalpj.ui \
    sti2.ui \
    sti3.ui
#icono de la app, USAR IMAGENES PNG DE 512px Y CONVERTIR A ICONOS DE 48px
RC_ICONS = STI_The_Complete_Saga.ico

#necesario para el qsystemtrayicon (segundo plano y notis)
QMAKE_CXXFLAGS += -std=gnu++14

#necesario para trabajar con SQL, agrega sus librerias
QT += sql

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    iconos.qrc \
    images.qrc \
    music.qrc

# Esto de debajo es lo necesario para incluir el DLL de Dani en nuestra app
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-DaniAssistant-Desktop_Qt_5_14_0_MinGW_64_bit-Release/ -lDaniAssistant
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-DaniAssistant-Desktop_Qt_5_14_0_MinGW_64_bit-Release/ -lDaniAssistantd
else:unix: LIBS += -L$$PWD/../build-DaniAssistant-Desktop_Qt_5_14_0_MinGW_64_bit-Release/ -lDaniAssistant

INCLUDEPATH += $$PWD/../DaniAssistant
DEPENDPATH += $$PWD/../DaniAssistant
