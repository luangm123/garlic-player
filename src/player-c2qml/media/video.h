#ifndef VIDEO_H
#define VIDEO_H

#include "smilparser/video.h"
#include "base_media.h"

class Video : public BaseMedia
{
        Q_OBJECT
    public:
        const int STRETCH            = 0;
        const int PRESERVEASPECTFIT  = 1;
        const int PRESERVEASPECTCROP = 2;
        Video(QQmlComponent *mc, QString r_id, QObject *parent = nullptr);
        ~Video();
        void                        init(TMedia *media);
        void                        deinit();
        void                        setParentItem(QQuickItem *parent);
    protected:
        TVideo                     *MyVideo;
        QScopedPointer<QQuickItem>  video_item;
        int                         determineFillMode(QString smil_fit);
    protected slots:
        void                        finished();
};

#endif // VIDEO_H
