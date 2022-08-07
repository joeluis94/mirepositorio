#ifndef MODOTIERRA_H
#define MODOTIERRA_H

#include <QObject>

#include <QQuickView>
#include <QDebug>
#include <QUdpSocket>
#include <QByteArray>

class modotierra : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString entrada READ leerentrada NOTIFY entradaChanged)

public:
    explicit modotierra(QObject *parent = 0);
    ~modotierra();

signals:
    void vinculado();
    void autenticado();
    void entradaChanged();
    void airedesvinculado();

public slots:
    void on_conecta_clicked();
    void listo();
    void envio(QByteArray val, QHostAddress dir, quint16 port);
    QString leerentrada();
    void saludar();

private:
    QUdpSocket socket;
    QByteArray datos;
    QHostAddress dirNodeMCU;
    quint16 puertoNodeMCU;
    QHostAddress dirAire;
    quint16 puertoAire;
    quint32 a;
    char* entrada;
    QString entra;
    qint64 tamano;
    QString salida;
    QString despAire;
};

#endif // MODOTIERRA_H
