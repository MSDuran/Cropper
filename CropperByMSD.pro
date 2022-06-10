QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 ltcg -reduce-relocations

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_CFLAGS_RELEASE += -O3

#QMAKE_CXXFLAGS_RELEASE = /O2 /GS- /sdl-
#QMAKE_CFLAGS_RELEASE = /O2 /GS- /sdl-
#QMAKE_LFLAGS_RELEASE = /LTCG

RC_ICONS = C:\Users\90543\Documents\CropperByMSD/images/scissors.ico

SOURCES += \
    croppingwindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    croppingwindow.h \
    mainwindow.h

FORMS += \
    croppingwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
