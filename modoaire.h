#ifndef MODOAIRE_H
#define MODOAIRE_H

#include <QObject>

#include <QQuickView>
#include <QDebug>
#include <QUdpSocket>
#include <QByteArray>

#include <QCamera>
#include <QImage>
#include <QCameraImageCapture>
//#include "MyVideo.h"
#include <QBuffer>
#include <QtTest/QTest>
#include <QTimer>
#include <QVideoProbe>
#include <QCameraViewfinder>

class modoaire : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(type name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString entrada READ leerentrada NOTIFY entradaChanged)
    Q_PROPERTY(QString foto READ getimage NOTIFY newimage)
    Q_PROPERTY(int formato READ getformato)
    Q_PROPERTY(int alto READ getalto)

public:
    explicit modoaire(QObject *parent = 0);
    ~modoaire();

signals:
    void vinculado();
    void autenticado();
    void entradaChanged();
    void tierradesvinculado();
    void newimage();

public slots:
    void on_conecta_clicked();
    void listo();
    void envio(QByteArray val, QHostAddress dir, quint16 port);
    QString leerentrada();
    void saludar();

    void setCamera(const QByteArray &cameraDevice);
    void muestra(int pos, QImage foto);
    void flash();
    void leerfoto(QImage img);
    QString getimage();
    void porsegundos();
    int getformato();
    void processFrame(QVideoFrame marco);
    int getalto();

private:
    QUdpSocket socket;
    QByteArray datos;
    QHostAddress dirNodeMCU;
    quint16 puertoNodeMCU;
    QHostAddress dirTierra;
    quint16 puertoTierra;
    quint32 a;
    char* entrada;
    QString entra;
    qint64 tamano;
    QString salida;
    QString despTierra;

    QCamera *camera;
    QString foto;
    QCameraImageCapture* imageCapture;
    //MyVideo* visor;
    QTimer tempo;
    int cant;
    int formato;
    QVideoProbe* probe;
    QImage fot;
    int alto;
    QCameraViewfinder* view;
};

#endif // MODOAIRE_H
