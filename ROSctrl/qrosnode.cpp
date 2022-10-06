#include "qrosnode.hpp"
#include <qdebug.h>
QROSNode::QROSNode(std::map<std::string,std::string> remapping_args , const std::string& name )
{
    remappings=remapping_args;
    init_node_name = name;
//    init();
    logging_model=new QStringListModel();
}

QROSNode::~QROSNode() {
    if(ros::isStarted()) {
        ros::shutdown(); // explicitly needed since we use ros::start();
        ros::waitForShutdown();
    }
    wait();//线程等待
}
bool QROSNode::init() {
    ros::init(remappings,init_node_name);
    if ( ! ros::master::check() ) {
        return false;
    }
    ros::start();
    ros::NodeHandle n;
//    chatter_publisher = n.advertise<std_msgs::String>("chatter", 1000);
    chatter_subscriber = n.subscribe(topic.toStdString(), 1000, &QROSNode::Callback, this); //add

    start();//线程开启
    return true;
}

void QROSNode::run()
{
    ros::Rate loop_rate(10);//频率
//    int count = 0;
    while(ros::ok())
    {
//        std_msgs::String msg;
//        std::stringstream ss;
//        ss << "hello world " << count;
//        msg.data = ss.str();
//        chatter_publisher.publish(msg);//发布

//        ++count;

        ros::spinOnce();
        loop_rate.sleep();
    };
};
void QROSNode::Callback(const std_msgs::StringConstPtr &msg)
{
    QString n_msg=msg->data.c_str();
    log(Info,std::string("I heard: ")+msg->data);
//    qDebug()<<n_msg;
    emit NewMessage(n_msg);
}

void QROSNode::SetTopic(QString topic)
{
    this->topic=topic;
};
void QROSNode::log( const LogLevel &level, const std::string &msg) {
    logging_model->insertRows(logging_model->rowCount(),1);
    std::stringstream logging_model_msg;
    switch ( level ) {
        case(Debug) : {
                ROS_DEBUG_STREAM(msg);
                logging_model_msg << "[DEBUG] [" << ros::Time::now() << "]: " << msg;
                break;
        }
        case(Info) : {
                ROS_INFO_STREAM(msg);
                logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
                break;
        }
        case(Warn) : {
                ROS_WARN_STREAM(msg);
                logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
                break;
        }
        case(Error) : {
                ROS_ERROR_STREAM(msg);
                logging_model_msg << "[ERROR] [" << ros::Time::now() << "]: " << msg;
                break;
        }
        case(Fatal) : {
                ROS_FATAL_STREAM(msg);
                logging_model_msg << "[FATAL] [" << ros::Time::now() << "]: " << msg;
                break;
        }
    }
    QVariant new_row(QString(logging_model_msg.str().c_str()));
    logging_model->setData(logging_model->index(logging_model->rowCount()-1),new_row);
}
