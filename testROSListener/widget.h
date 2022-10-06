#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "ros/ros.h"
#include "std_msgs/String.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
//    void Start_listen(int argc, char *argv[]);
    ~Widget();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
