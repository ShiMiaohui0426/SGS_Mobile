#include "widget.h"
#include <qdebug.h>
#include <QApplication>
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I heard: [%s]", msg->data.c_str());
    qDebug()<< msg->data.c_str();
};
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  //  w.Start_listen(argc,argv);
    std::map<std::string,std::string> remappings;
    remappings["__master"] = "http://127.0.0.1:11311/";
    remappings["__hostname"] = "host_url";
    ros::init(remappings, "listener");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
    ros::spin();
    return a.exec();
}
