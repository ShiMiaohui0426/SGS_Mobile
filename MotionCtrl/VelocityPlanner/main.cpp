#include "velocityplanner.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VelocityPlanner w;
    w.show();
    return a.exec();
}
