QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    searchcombobox.cpp \
    searchscrollarea.cpp \
    soundeffectform.cpp \
    utils/utils.cpp \
    widgetlistview.cpp

HEADERS += \
    mainwindow.h \
    searchcombobox.h \
    searchscrollarea.h \
    soundeffectform.h \
    utils/utils.h \
    widgetlistview.h

FORMS += \
    mainwindow.ui \
    searchcombobox.ui \
    searchscrollarea.ui \
    soundeffectform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
