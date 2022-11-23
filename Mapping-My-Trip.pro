TARGET = Mapping-My-Trip
QT = core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets quickwidgets
CONFIG+= c++11

HEADERS += \
    dbhelper.h \
    logindialog.h \
    mapdialog.h \
    picturedialog.h \
    pictureentity.h \
    pointentity.h \
    registerdialog.h \
    userentity.h

SOURCES += \
    dbhelper.cpp \
    logindialog.cpp \
    main.cpp \
    mapdialog.cpp \
    picturedialog.cpp \
    pictureentity.cpp \
    pointentity.cpp \
    registerdialog.cpp \
    userentity.cpp

FORMS += \
    logindialog.ui \
    mapdialog.ui \
    picturedialog.ui \
    registerdialog.ui

RESOURCES += \
    qml.qrc
