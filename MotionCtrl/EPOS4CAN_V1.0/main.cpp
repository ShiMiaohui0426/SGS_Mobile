#include "epos4can.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EPOS4CAN w;
    w.show();
    return a.exec();
}
