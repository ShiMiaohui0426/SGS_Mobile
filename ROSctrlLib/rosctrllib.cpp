#include "rosctrllib.hpp"

#include<qdebug.h>


ROSctrlLib::ROSctrlLib()
{
    myctrl=new Widget;
    connect(myctrl,&Widget::SetVelocity,this,[=](omniVelocity v){
        if(status)emit SetVel(v);
        });
    info["name"]="ROSctrl";
}

ROSctrlLib::~ROSctrlLib()
{

};

QWidget *ROSctrlLib::get_widget()
{
    return myctrl;
}

QJsonObject ROSctrlLib::save()
{
    QJsonObject obj;
    obj["myctrl"]=myctrl->save();
    obj["status"]=status;
    return obj;
}

void ROSctrlLib::restore(QJsonObject &paras)
{
    QJsonObject mydoc=paras;
    status=mydoc["status"].toBool();
    QJsonObject myctrlres=mydoc["myctrl"].toObject();
    myctrl->restore(myctrlres);
};
