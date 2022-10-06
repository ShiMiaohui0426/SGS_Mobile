#include "tcpctrl.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tcpctrl w;
    w.show();
    return a.exec();
}
