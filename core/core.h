
#ifndef ECHODIALOG_H
#define ECHODIALOG_H

#include <QWidget>

#include "interface/echointerface.h"

QT_BEGIN_NAMESPACE
class QString;
class QLineEdit;
class QLabel;
class QPushButton;
class QGridLayout;
QT_END_NAMESPACE


class Core : public QWidget
{
    Q_OBJECT

public:
    Core();

private slots:
    void sendEcho();

private:
    void createGUI();
    bool loadPlugin();

    EchoInterface *echoInterface;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *button;
    QGridLayout *layout;
};

#endif
