#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

}

//void Widget::Start_listen(int argc, char *argv[])
//{
//    ros::init(argc, argv, "listener");
//    ros::NodeHandle n;
//    ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
//    ros::spin();
//}

Widget::~Widget()
{
    delete ui;
}

