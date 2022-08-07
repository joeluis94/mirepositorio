#ifndef MYVIDEO_H
#define MYVIDEO_H

#include <QAbstractVideoSurface>
#include <QList>
#include <QVideoFrame>
#include <QVideoSurfaceFormat>
#include <QtCore/qobject.h>
#include <QDebug>
#include <QAbstractVideoBuffer>
#include <QImage>

class MyVideo : public QAbstractVideoSurface{
    Q_OBJECT
public:
    MyVideo(QObject* parent = NULL): QAbstractVideoSurface(parent)
    {}
    ~MyVideo(){}
    QImage img;
    QVideoFrame::PixelFormat formato;

    QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const
    {
        if(handleType == QAbstractVideoBuffer::NoHandle){
            return QList<QVideoFrame::PixelFormat> () << QVideoFrame::Format_AYUV444 << QVideoFrame::Format_Jpeg << QVideoFrame::Format_NV12 << QVideoFrame::Format_NV21 << QVideoFrame::Format_RGB565 << QVideoFrame::Format_YUV420P << QVideoFrame::Format_YV12;
        }
        else{
           return QList<QVideoFrame::PixelFormat>();
        }
        //return QList<QVideoFrame::PixelFormat> () << QVideoFrame::Format_ARGB32 << QVideoFrame::Format_ARGB32_Premultiplied << QVideoFrame::Format_ARGB8565_Premultiplied << QVideoFrame::Format_AYUV444 << QVideoFrame::Format_AYUV444_Premultiplied << QVideoFrame::Format_BGR24 << QVideoFrame::Format_BGR32 << QVideoFrame::Format_BGR555 << QVideoFrame::Format_BGR565 << QVideoFrame::Format_BGRA32 << QVideoFrame::Format_BGRA32_Premultiplied << QVideoFrame::Format_BGRA5658_Premultiplied << QVideoFrame::Format_CameraRaw << QVideoFrame::Format_IMC1 << QVideoFrame::Format_IMC2 << QVideoFrame::Format_IMC3 << QVideoFrame::Format_IMC4 << QVideoFrame::Format_Invalid << QVideoFrame::Format_Jpeg << QVideoFrame::Format_NV12 << QVideoFrame::Format_NV21 << QVideoFrame::Format_RGB24 << QVideoFrame::Format_RGB32 << QVideoFrame::Format_RGB555 << QVideoFrame::Format_RGB565 << QVideoFrame::Format_User <<QVideoFrame::Format_UYVY << QVideoFrame::Format_Y8 << QVideoFrame::Format_Y16 << QVideoFrame::Format_YUV420P << QVideoFrame::Format_YUV444 << QVideoFrame::Format_YUYV << QVideoFrame::Format_YV12 << QVideoFrame::Format_AdobeDng;
    }

    bool present(const QVideoFrame &frame)
    {
        if(!frame.isValid()){
            setError(IncorrectFormatError);
            return false;
        }
        else{
            QVideoFrame frametodraw(frame);
            formato = frametodraw.pixelFormat();
            if(!frametodraw.map(QAbstractVideoBuffer::ReadOnly)){
                setError(ResourceError);
                return false;
            }
            //qDebug() << QVideoFrame::imageFormatFromPixelFormat(QVideoFrame::Format_NV21);

            img = QImage(frametodraw.bits(), frametodraw.width(), frametodraw.height(), frametodraw.bytesPerLine(), QVideoFrame::imageFormatFromPixelFormat(frametodraw.pixelFormat()));
            frametodraw.unmap();
            emit pasefoto(img);
            return true;
        }
    }
signals:
    void pasefoto(QImage img);
};

#endif // MYVIDEO_H
