
#include <QtWidgets>

#include "core.h"

Core::Core(){

    lineEdit = new QLineEdit;
    label = new QLabel;
    label->setFrameStyle(QFrame::Box | QFrame::Plain);
    button = new QPushButton(tr("Send Message"));

    connect(lineEdit, SIGNAL(editingFinished()),
            this, SLOT(sendEcho()));
    connect(button, SIGNAL(clicked()),
            this, SLOT(sendEcho()));

    layout = new QGridLayout;
    layout->addWidget(new QLabel(tr("Message:")), 0, 0);
    layout->addWidget(lineEdit, 0, 1);
    layout->addWidget(new QLabel(tr("Answer:")), 1, 0);
    layout->addWidget(label, 1, 1);
    layout->addWidget(button, 2, 1, Qt::AlignRight);
    layout->setSizeConstraint(QLayout::SetFixedSize);

    setLayout(layout);
    setWindowTitle("Echo Plugin Example");

    loadPlugins();
}

void Core::sendEcho(){
    QString text = echoInterface->echo(lineEdit->text());
    label->setText(text);
}
void Core::loadPlugins(){
    QDir pluginsDir(qApp->applicationDirPath());
#if defined(Q_OS_WIN)
    if (pluginsDir.dirName().toLower() == "debug" || pluginsDir.dirName().toLower() == "release")
        pluginsDir.cdUp();
#elif defined(Q_OS_MAC)
    if (pluginsDir.dirName() == "MacOS") {
        pluginsDir.cdUp();
        pluginsDir.cdUp();
        pluginsDir.cdUp();
    }
#endif
    pluginsDir.cd("plugins");
    QStringList plugins;
    plugins << "libechoplugin.so" << "libsandboxplugin.so";
    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        //qDebug()<< "fileName:" << fileName;
        switch(plugins.indexOf(fileName)){
            case 0:
                if (!loadPlugin(pluginsDir,fileName)) {
                      QMessageBox::information(this, "Error", "Could not load the plugin:"+fileName);
                      lineEdit->setEnabled(false);
                      button->setEnabled(false);
                }
                break;
            case 1:
                QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
                QObject *plugin = pluginLoader.instance();
                if (plugin) {
                    sandboxInterface = qobject_cast<SandboxInterface *>(plugin);
                    if (sandboxInterface){
                        qDebug()<<sandboxInterface->hello();
                    }
                }
                break;
        }
    }
}
bool Core::loadPlugin(QDir pluginsDir,QString fileName){
    QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
    QObject *plugin = pluginLoader.instance();
    if (plugin) {
        echoInterface = qobject_cast<EchoInterface *>(plugin);
        if (echoInterface){
            return true;
        }
    }
    return false;
}
