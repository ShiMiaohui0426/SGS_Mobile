#ifndef QROSNODE_H
#define QROSNODE_H
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <QThread>
#include <qstring.h>
#include<qstringlistmodel.h>
class QROSNode : public QThread
{
    Q_OBJECT
public:
    QROSNode(std::map<std::string,std::string> remapping_args , const std::string& name );//构造函数,节点名字传过去
    virtual ~QROSNode();
    bool init();
    void run();//循环
    void Callback(const std_msgs::StringConstPtr &msg);  //回调函数
    void SetTopic(QString topic);
    QStringListModel* loggingModel() { return logging_model; };
private:
    std::string init_node_name;
    ros::Publisher chatter_publisher;//发布器
    ros::Subscriber chatter_subscriber; //订阅器
    QString topic;
    std::map<std::string,std::string> remappings;
    enum LogLevel {
             Debug,
             Info,
             Warn,
             Error,
             Fatal
     };


    void log( const LogLevel &level, const std::string &msg);
    QStringListModel *logging_model;
signals:
    void NewMessage(QString v);
};

#endif // QROSNODE_H
