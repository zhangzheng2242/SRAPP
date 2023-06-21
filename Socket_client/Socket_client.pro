QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    client.cpp \
    login.cpp \
    mainwindow.cpp \
    signup.cpp

HEADERS += \
    client.h \
    login.h \
    mainwindow.h \
    signup.h

FORMS += \
    client.ui \
    login.ui \
    mainwindow.ui \
    signup.ui


msvc {
    QMAKE_CFLAGS += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}

#opencv配置
win32:CONFIG(release, debug|release): LIBS += -LD:/Qt/OpenCV4.7.0/opencv/build/x64/vc16/lib/ -lopencv_world470
else:win32:CONFIG(debug, debug|release): LIBS += -LD:/Qt/OpenCV4.7.0/opencv/build/x64/vc16/lib/ -lopencv_world470d

INCLUDEPATH += D:/Qt/OpenCV4.7.0/opencv/build/x64/vc16
DEPENDPATH += D:/Qt/OpenCV4.7.0/opencv/build/x64/vc16

INCLUDEPATH += D:/Qt/OpenCV4.7.0/opencv/build/include \
 D:/Qt/OpenCV4.7.0/opencv/build/include\opencv2

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
