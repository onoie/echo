

#include <QtWidgets>

#include "core.h"
#include "interface/echointerface.h"

int main(int argv, char *args[])
{
    QApplication app(argv, args);

    Core window;
    window.show();

    return app.exec();
}
