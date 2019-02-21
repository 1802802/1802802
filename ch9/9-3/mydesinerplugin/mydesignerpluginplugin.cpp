#include "mydesignerplugin.h"
#include "mydesignerpluginplugin.h"

#include <QtPlugin>

MyDesignerpluginPlugin::MyDesignerpluginPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void MyDesignerpluginPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool MyDesignerpluginPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *MyDesignerpluginPlugin::createWidget(QWidget *parent)
{
    return new MyDesignerplugin(parent);
}

QString MyDesignerpluginPlugin::name() const
{
    return QLatin1String("MyDesignerplugin");
}

QString MyDesignerpluginPlugin::group() const
{
    return QLatin1String("");
}

QIcon MyDesignerpluginPlugin::icon() const
{
    return QIcon(QLatin1String(":/pushbutton.png"));
}

QString MyDesignerpluginPlugin::toolTip() const
{
    return QLatin1String("");
}

QString MyDesignerpluginPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool MyDesignerpluginPlugin::isContainer() const
{
    return false;
}

QString MyDesignerpluginPlugin::domXml() const
{
    return QLatin1String("<widget class=\"MyDesignerplugin\" name=\"myDesignerplugin\">\n</widget>\n");
}

QString MyDesignerpluginPlugin::includeFile() const
{
    return QLatin1String("mydesignerplugin.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(mydesignerpluginplugin, MyDesignerpluginPlugin)
#endif // QT_VERSION < 0x050000
