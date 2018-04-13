
#ifndef SANDBOXPLUGIN_H
#define SANDBOXPLUGIN_H

#include <QObject>
#include <QtPlugin>
#include "sandboxinterface.h"

class SandboxPlugin : public QObject, SandboxInterface{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.Examples.SandboxInterface" FILE "sandboxplugin.json")
    Q_INTERFACES(SandboxInterface)
public:
    QString hello() override;
};

#endif
