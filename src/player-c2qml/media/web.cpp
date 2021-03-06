#include "web.h"

Web::Web(QQmlComponent *mc, QString r_id, QObject *parent) : BaseMedia(mc, r_id, parent)
{
    setRegionId(r_id);
#ifdef SUPPORT_RPI
    QString module = "import QtWebView 1.1\n WebView ";
#else
    QString module = "import QtWebEngine 1.2\n WebEngineView";
#endif
    media_component = mc;
    QString str("import QtQuick 2.7\n"+
                module + "{\n \
                        id: "+getRegionId()+"_web;\n \
                        anchors.fill: parent;\n \
                   }\n"
    );
    web_item.reset(createMediaItem(media_component, str));
}

Web::~Web()
{
    web_item.reset();
}

void Web::init(TMedia *media)
{
    MyMedia = media;
    web_item.data()->setVisible(true);
    web_item.data()->setProperty("url", MyMedia->getLoadablePath());
    if (MyMedia->getLogContentId() != "")
        setStartTime();
}

void Web::deinit()
{
    if (MyMedia->getLogContentId() != "")
        qInfo(PlayLog).noquote() << createPlayLogXml();
    web_item.data()->setProperty("url", "");
    web_item.data()->setVisible(false);
}

void Web::setParentItem(QQuickItem *parent)
{
    web_item.data()->setParentItem(parent);
}
