QT += core gui widgets sql

INCLUDEPATH += "C:/Program Files/MySQL/MySQL Server 8.0/include"
LIBS += -L"C:/Program Files/MySQL/MySQL Server 8.0/lib" -lmysql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui
