TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = ~/build_dir/figures
TARGET = figures

SOURCES += \
        main.cpp \
    figure.cpp \
    rectangle.cpp \
    square.cpp \
    oval.cpp \
    circle.cpp \
    triangle.cpp

HEADERS += \
    figure.h \
    rectangle.h \
    square.h \
    oval.h \
    circle.h \
    triangle.h

contains( CONFIG, qt ) {
    MOC_DIR = ./.moc
    UI_DIR  = ./.ui
    RCC_DIR = ./.rcc
    INCLUDEPATH += ./.ui
}

OBJECTS_DIR = ./.o

unix|win32: LIBS += -lgraph
