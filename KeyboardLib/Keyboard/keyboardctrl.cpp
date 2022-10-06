#include "keyboardctrl.h"
#include "ui_keyboardctrl.h"
//#include <qdebug.h>
#define MaxLinearVelocity 1.5
#define MaxRotateVelocity 60

KeyboardCtrl::KeyboardCtrl(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::KeyboardCtrl)
{
    ui->setupUi(this);
    QObjectList _objectList=this->children();
    for(auto &obj:_objectList){
        if(QString(obj->metaObject()->className())==QString("QPushButton"))
        {
            ((QPushButton*)obj)->setStyleSheet("background-color:white");
        };
    };
    TARVelocity.vx=0;
    TARVelocity.vy=0;
    TARVelocity.omega=0;
}

KeyboardCtrl::~KeyboardCtrl()
{
    delete ui;
}
void KeyboardCtrl::keyPressEvent(QKeyEvent *e)
{
    if(!e->isAutoRepeat()){
    switch (e->key())
    {
    case Qt::Key_W :

        on_WButton_pressed();
        break;
    case Qt::Key_S :
        on_SButton_pressed();
        break;
    case Qt::Key_A :
        on_AButton_pressed();
        break;
    case Qt::Key_D :
        on_DButton_pressed();
        break;
    case Qt::Key_J :
        on_JButton_pressed();
        break;
    case Qt::Key_K :
        on_KButton_pressed();
        break;
    };};
};
void KeyboardCtrl::keyReleaseEvent(QKeyEvent *e)
{
    if(!e->isAutoRepeat()){
    switch (e->key())
    {
    case Qt::Key_W :
        on_WButton_released();
        break;
    case Qt::Key_S :
        on_SButton_released();
        break;
    case Qt::Key_A :
        on_AButton_released();
        break;
    case Qt::Key_D :
        on_DButton_released();
        break;
    case Qt::Key_J :
        on_JButton_released();
        break;
    case Qt::Key_K :
        on_KButton_released();
        break;
    };};
};

void KeyboardCtrl::on_WButton_pressed()
{
    ui->WButton->setStyleSheet("background-color:red");
    TARVelocity.vy +=MaxLinearVelocity;
    emit SetVelocity(TARVelocity);
};



void KeyboardCtrl::on_WButton_released()
{
    ui->WButton->setStyleSheet("background-color:white");
    TARVelocity.vy -=MaxLinearVelocity;
            emit SetVelocity(TARVelocity);
};


void KeyboardCtrl::on_SButton_pressed()
{
    ui->SButton->setStyleSheet("background-color:red");
    TARVelocity.vy -=MaxLinearVelocity;
            emit SetVelocity(TARVelocity);
};


void KeyboardCtrl::on_SButton_released()
{
    ui->SButton->setStyleSheet("background-color:white");
    TARVelocity.vy +=MaxLinearVelocity;
            emit SetVelocity(TARVelocity);
};


void KeyboardCtrl::on_AButton_pressed()
{
    ui->AButton->setStyleSheet("background-color:red");
    TARVelocity.vx -=MaxLinearVelocity;
            emit SetVelocity(TARVelocity);
}


void KeyboardCtrl::on_AButton_released()
{
    ui->AButton->setStyleSheet("background-color:white");
    TARVelocity.vx +=MaxLinearVelocity;
            emit SetVelocity(TARVelocity);
}


void KeyboardCtrl::on_DButton_pressed()
{
    ui->DButton->setStyleSheet("background-color:red");
    TARVelocity.vx +=MaxLinearVelocity;
            emit SetVelocity(TARVelocity);
}


void KeyboardCtrl::on_DButton_released()
{
    ui->DButton->setStyleSheet("background-color:white");
    TARVelocity.vx -=MaxLinearVelocity;
            emit SetVelocity(TARVelocity);
}


void KeyboardCtrl::on_JButton_pressed()
{
    ui->JButton->setStyleSheet("background-color:red");
    TARVelocity.omega +=MaxRotateVelocity;
            emit SetVelocity(TARVelocity);
}


void KeyboardCtrl::on_JButton_released()
{
    ui->JButton->setStyleSheet("background-color:white");
    TARVelocity.omega -=MaxRotateVelocity;
            emit SetVelocity(TARVelocity);
}


void KeyboardCtrl::on_KButton_pressed()
{
    ui->KButton->setStyleSheet("background-color:red");
    TARVelocity.omega -=MaxRotateVelocity;
            emit SetVelocity(TARVelocity);
}


void KeyboardCtrl::on_KButton_released()
{
     ui->KButton->setStyleSheet("background-color:white");
     TARVelocity.omega +=MaxRotateVelocity;
             emit SetVelocity(TARVelocity);
}

