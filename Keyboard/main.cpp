#include "keyboardctrl.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KeyboardCtrl w;
    w.show();
    return a.exec();
}
