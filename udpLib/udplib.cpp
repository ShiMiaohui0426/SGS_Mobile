#include "udplib.hpp"

#include<qdebug.h>


udpLib::udpLib()
{
    myctrl=new udpctrl;
    connect(myctrl,&udpctrl::sendVelocity,this,[=](omniVelocity v){
        if(status)
            emit SetVel(v);});
    info["name"]="udpctrl";
}

udpLib::~udpLib()
{

};

QWidget *udpLib::get_widget()
{
    return myctrl;
}

QJsonObject udpLib::save()
{
    QJsonObject obj;
        obj["status"]=status;
    return obj;
}

void udpLib::restore(QJsonObject &paras)
{
    QJsonObject obj=paras;
    status=obj["status"].toBool();
};
