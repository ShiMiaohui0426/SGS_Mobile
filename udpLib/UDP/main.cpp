#include "udpctrl.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    udpctrl w;
    w.show();
    return a.exec();
}
