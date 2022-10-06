#include "keyboardlib.hpp"

#include<qdebug.h>


KeyboardLib::KeyboardLib()
{
    myctrl=new KeyboardCtrl;
    connect(myctrl,&KeyboardCtrl::SetVelocity,this,[=](omniVelocity v){
        if(status)
            emit SetVel(v);});
    info["name"]="manual_keyboard";
}

KeyboardLib::~KeyboardLib()
{

};

QWidget *KeyboardLib::get_widget()
{
    return myctrl;
}

QJsonObject KeyboardLib::save()
{
    QJsonObject obj;
    obj["status"]=status;
    return obj;
}

void KeyboardLib::restore(QJsonObject &paras)
{
status=paras["status"].toBool();
};
