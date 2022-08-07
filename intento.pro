# Add more folders to ship with the application, here
folder_01.source = qml/intento
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

QT += qml quick multimedia network testlib

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    modoaire.cpp \
    modotierra.cpp

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qtquick2applicationviewer/qtquick2applicationviewer.pri)
qtcAddDeployment()

FORMS +=

HEADERS += \
    modoaire.h \
    modotierra.h \
    

OTHER_FILES += principal.qml\
aire.qml\
tierra.qml \
cargador.qml \


RESOURCES += \
    recursos.qrc
