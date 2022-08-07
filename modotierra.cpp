#include "modotierra.h"

modotierra::modotierra(QObject *parent) :
    QObject(parent)
{
    connect(&socket,SIGNAL(readyRead()),this,SLOT(listo()));
    dirNodeMCU.setAddress("192.168.1.177");
    puertoNodeMCU = 7777;
    salida = "Tierra";
    despAire = "sefueA";
    socket.bind(0, QUdpSocket::ShareAddress);
}

modotierra::~modotierra()
{
    QString despedida("sefueT");
    envio(despedida.toLatin1(), dirNodeMCU, puertoNodeMCU);
    envio(despedida.toLatin1(), dirAire, puertoAire);
    qDebug() << despedida;
}

void modotierra::on_conecta_clicked()
{    
    envio(salida.toLatin1(), dirNodeMCU, puertoNodeMCU);
}

void modotierra::listo()
{
    QByteArray datagrama;
    QHostAddress host;
    unsigned short puerto = 0;
    tamano = socket.pendingDatagramSize();
    datagrama.resize(tamano);
    socket.readDatagram(datagrama.data(), datagrama.size(), &host, &puerto);
    qDebug() << tamano;

    if(host == dirNodeMCU){
        QString on = datagrama.data();
        qDebug() << on;

        if(on == salida){
            emit vinculado();
        }
        else if(on != salida && tamano == 6){
         QDataStream in(&datagrama, QIODevice::ReadOnly);
         in >> a >> puertoAire;
         dirAire.setAddress(a);

         qDebug() << "Direccion IP de Aire:";
         qDebug() << dirAire.toString();
         qDebug() << "Puerto de Aire:";
         qDebug() << puertoAire;
         qDebug() << "Autenticacion Completada";
         emit autenticado();
        }
        //else{}
    }
    else if(host == dirAire){
        QString on = datagrama.data();

        if(on == despAire){
            emit airedesvinculado();
            qDebug() << "aire se desvinculo";
        }
        else{
            QDataStream in(&datagrama, QIODevice::ReadOnly);
            in.setVersion(QDataStream::Qt_4_0);
            in >> entrada;
            qDebug() << entrada;
            emit entradaChanged();
        }
    }
}

void modotierra::envio(QByteArray val, QHostAddress dir, quint16 port)
{
    int muestra = 0;
    muestra = socket.writeDatagram(val, val.size(), dir, port);
    qDebug() << muestra;
}

QString modotierra::leerentrada()
{
    entra = QString::fromLatin1(entrada);
    return entra;
}

void modotierra::saludar()
{
    QDataStream  out (&datos,  QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << "Hola Mundo";
    envio(datos, dirAire, puertoAire);
}
