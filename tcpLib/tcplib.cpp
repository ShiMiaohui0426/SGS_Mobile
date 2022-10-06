#include "tcplib.hpp"

#include<qdebug.h>


tcpLib::tcpLib()
{
    myctrl=new tcpctrl;
    connect(myctrl,&tcpctrl::sendVelocity,this,[=](omniVelocity v){
        if(status)
            emit SetVel(v);});
    info["name"]="tcpctrl";
}

tcpLib::~tcpLib()
{

};

QWidget *tcpLib::get_widget()
{
    return myctrl;
}

QJsonObject tcpLib::save()
{
    QJsonObject obj;
        obj["status"]=status;
        obj["tcpctrl_para"]=myctrl->save();
    return obj;
}

void tcpLib::restore(QJsonObject &paras)
{
    QJsonObject obj=paras;
    status=obj["status"].toBool();
    QJsonObject obj2=obj["tcpctrl_para"].toObject();
    myctrl->restore(obj2);
};
