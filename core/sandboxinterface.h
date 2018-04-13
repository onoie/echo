
#ifndef SANDBOXINTERFACE_H
#define SANDBOXINTERFACE_H

#include <QString>

class SandboxInterface{
public:
    virtual ~SandboxInterface() {}
    virtual QString hello() = 0;
};

QT_BEGIN_NAMESPACE
#define SandboxInterface_iid "org.qt-project.Qt.Examples.SandboxInterface"
Q_DECLARE_INTERFACE(SandboxInterface, SandboxInterface_iid)
QT_END_NAMESPACE

#endif
