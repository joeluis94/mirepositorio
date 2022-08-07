#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "modoaire.h"
#include "modotierra.h"
#include <QtQml>
#include <QQmlEngine>
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QtQuick2ApplicationViewer viewer;
    viewer.setResizeMode(QtQuick2ApplicationViewer::SizeRootObjectToView);   
    QObject::connect(viewer.engine(), SIGNAL(quit()), qApp, SLOT(quit()));

    //MyProveedor pro;
    //viewer.rootContext()->setContextProperty("pro", &pro);
    //viewer.addImportPath("E:/Cosas/JoeLuis/ProyectosAndroid/intento");

    qmlRegisterType<modoaire>("org.joecorporation.obj",1,0, "ModoAire");
    qmlRegisterType<modotierra>("org.joecorporation.obj",1,0, "ModoTierra");

    viewer.setMainQmlFile(QStringLiteral("qml/intento/cargador.qml"));
    viewer.showMaximized();

    return  app.exec();
}
