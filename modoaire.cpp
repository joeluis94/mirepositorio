#include "modoaire.h"

modoaire::modoaire(QObject *parent) :
    QObject(parent), camera(0), imageCapture(0), probe(0), view(0)//visor(0),
{
    connect(&socket,SIGNAL(readyRead()),this,SLOT(listo()));
    dirNodeMCU.setAddress("192.168.1.177");
    puertoNodeMCU = 7777;
    salida = "Aireee";
    despTierra = "sefueT";
    socket.bind(0, QUdpSocket::ShareAddress);

    tempo.setInterval(1000);
    cant = 0;

    // Dispositivo Camara:
    QByteArray cameraDevice;
    int i = 0;
    foreach(const QByteArray &deviceName, QCamera::availableDevices())
    {
        i++;
        if (deviceName.isEmpty()) {
            qDebug() << "No Tenemos Camara";
            //cameraDevice = deviceName;
        }
        else{
            cameraDevice = deviceName;
            qDebug() << "Tenemos Camara";
        }
    }
    qputenv("QSG_RENDER_LOOP", "basic");//ojo
    setCamera(cameraDevice);
}

modoaire::~modoaire()
{
    QString despedida("sefueA");
    envio(despedida.toLatin1(), dirNodeMCU, puertoNodeMCU);
    envio(despedida.toLatin1(), dirTierra, puertoTierra);
    qDebug() << despedida;

    delete camera;
    delete imageCapture;
    //delete visor;
    delete probe;
    delete view;
}

void modoaire::on_conecta_clicked()
{
    envio(salida.toLatin1(), dirNodeMCU, puertoNodeMCU);
}

void modoaire::listo()
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
        in >> a >> puertoTierra;
        dirTierra.setAddress(a);

        qDebug() << "Direccion IP de Tierra:";
        qDebug() << dirTierra.toString();
        qDebug() << "Puerto de Tierra:";
        qDebug() << puertoTierra;
        qDebug() << "Autenticacion Completada";
        emit autenticado();
       }
       //else{}
   }
   else if(host == dirTierra){
       QString on = datagrama.data();

       if(on == despTierra){
        emit tierradesvinculado();
        qDebug() << "tierra se desvinculo";
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

void modoaire::envio(QByteArray val, QHostAddress dir, quint16 port)
{
    int muestra = 0;
    muestra = socket.writeDatagram(val, val.size(), dir, port);
    qDebug() << muestra;
}

QString modoaire::leerentrada()
{
    entra = QString::fromLatin1(entrada);
    return entra;
}

void modoaire::saludar()
{
    QDataStream  out (&datos,  QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << "Hello Word";
    envio(datos, dirTierra, puertoTierra);
}

void modoaire::setCamera(const QByteArray &cameraDevice)
{
    delete imageCapture;
    delete camera;
    //delete visor;
    delete probe;
    delete view;

    camera = new QCamera(cameraDevice);
    camera->setCaptureMode(QCamera::CaptureVideo);
    view = new QCameraViewfinder();
    probe = new QVideoProbe(this);
    probe->setSource((QMediaObject*)camera);
    //visor = new MyVideo(this);
    camera->setViewfinder(view);

    imageCapture = new QCameraImageCapture(camera);
    imageCapture->setCaptureDestination(QCameraImageCapture::CaptureToBuffer);
    connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(muestra(int,QImage)));
    //connect(visor, SIGNAL(pasefoto(QImage)), this, SLOT(leerfoto(QImage)));
    connect(&tempo, SIGNAL(timeout()), this, SLOT(porsegundos()));
    connect(probe, SIGNAL(videoFrameProbed(QVideoFrame)), this, SLOT(processFrame(QVideoFrame)));
    camera->start();
    //tempo.start();
}

void modoaire::muestra(int pos, QImage foto)
{
    Q_UNUSED(pos);
    qDebug() << foto.size();
    foto.save("E:/foto2.jpg");
}

void modoaire::flash()
{
    imageCapture->capture();

}

void modoaire::leerfoto(QImage img)
{

    QByteArray bArray;
    QBuffer buffer(&bArray);
    buffer.open(QIODevice::WriteOnly);
    img.save(&buffer, "JPEG");
    foto = QString("data:image/jpg;base64,");
    foto.append(QString::fromLatin1(bArray.toBase64().data()));
    QTest::qWait(1);
    emit newimage();
}

QString modoaire::getimage()
{   //QTest::qWait(100);
    cant = cant+1;
    return foto;
}

void modoaire::porsegundos()
{
    qDebug() << cant;
    cant = 0;
}

int modoaire::getformato()
{
    return camera->state();//formato;
}

void modoaire::processFrame(QVideoFrame marco)
{
    QVideoFrame presente(marco);
    formato = presente.pixelFormat();
    presente.map(QAbstractVideoBuffer::ReadOnly);
    //qDebug() << QVideoFrame::imageFormatFromPixelFormat(QVideoFrame::Format_NV21);
    alto = presente.height();
    fot = QImage(presente.bits(), presente.width(), presente.height(), presente.bytesPerLine(), QVideoFrame::imageFormatFromPixelFormat(presente.pixelFormat()));
    marco.unmap();
    leerfoto(fot);
}

int modoaire::getalto()
{
    if(probe->isActive())
        return 1; // alto;
    else
        return 0;
}
