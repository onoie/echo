
#ifndef ECHODIALOG_H
#define ECHODIALOG_H

#include <QWidget>

#include "echointerface.h"
#include "sandboxinterface.h"

QT_BEGIN_NAMESPACE
class QString;
class QLineEdit;
class QLabel;
class QPushButton;
class QGridLayout;
class QDir;
QT_END_NAMESPACE

class Core : public QWidget{
    Q_OBJECT
public:
    Core();
private slots:
    void sendEcho();
private:
    void loadPlugins();
    bool loadPlugin(QDir,QString);

    EchoInterface *echoInterface;
    SandboxInterface *sandboxInterface;

    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *button;
    QGridLayout *layout;
};

#endif
