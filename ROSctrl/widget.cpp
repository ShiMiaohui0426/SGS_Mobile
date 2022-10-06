#include "widget.h"
#include "ui_widget.h"
#include <qdebug.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    remappings["__master"] = ui->lineEdit_master->text().toStdString();
    remappings["__hostname"] =ui->lineEdit_host->text().toStdString();
    topic=ui->lineEdit_topic->text();


//    logging_model.
    node =new QROSNode(remappings,"SGS_Mobile");
    ui->listView->setModel(node->loggingModel());
    connect(node,SIGNAL(NewMessage(QString)),this,SLOT(msgReady(QString)));
    node->SetTopic(topic);
    node->init();
};

Widget::~Widget()
{
    delete ui;
}

QJsonObject Widget::save()
{
    QJsonObject obj;
    obj["__master"]=ui->lineEdit_master->text();
    obj["__hostname"]=ui->lineEdit_host->text();
    obj["topic"]=topic;
    return obj;
}

void Widget::restore(QJsonObject &paras)
{
    QJsonObject obj =paras;
    ui->lineEdit_master->setText(obj["__master"].toString());
    ui->lineEdit_host->setText(obj["__hostname"].toString());
    topic=obj["topic"].toString();
    on_pushButton_Apply_clicked();
};


void Widget::on_pushButton_Apply_clicked()
{
    remappings["__master"] = ui->lineEdit_master->text().toStdString();
    remappings["__hostname"] =ui->lineEdit_host->text().toStdString();
    topic=ui->lineEdit_topic->text();
}

void Widget::msgReady(QString v)
{

    if(v.at(0)=="p"){
        KeyPressEvent(v.at(1).toLatin1());
        qDebug()<<"pressed";

    };

    if(v.at(0)=="r"){
        KeyReleasedEvent(v.at(1).toLatin1());
        qDebug()<<"released";
    };
    ui->listView->scrollToBottom();
}

void Widget::KeyPressEvent(const char &key)
{
    switch (key)
    {
    case 'w':
        TARVelocity.vy +=MaxLinearVelocity;
        break;
    case 's' :
        TARVelocity.vy -=MaxLinearVelocity;
        break;
    case 'a' :
        TARVelocity.vx -=MaxLinearVelocity;
        break;
    case 'd' :
        TARVelocity.vx +=MaxLinearVelocity;
        break;
    case 'j' :
        TARVelocity.omega +=MaxRotateVelocity;
        break;
    case 'k' :
        TARVelocity.omega -=MaxRotateVelocity;
        break;
    };
    emit SetVelocity(TARVelocity);
}

void Widget::KeyReleasedEvent(char key)
{
    switch (key)
    {
    case 'w':
        TARVelocity.vy -=MaxLinearVelocity;
        break;
    case 's' :
        TARVelocity.vy +=MaxLinearVelocity;
        break;
    case 'a' :
        TARVelocity.vx +=MaxLinearVelocity;
        break;
    case 'd' :
        TARVelocity.vx -=MaxLinearVelocity;
        break;
    case 'j' :
        TARVelocity.omega -=MaxRotateVelocity;
        break;
    case 'k' :
        TARVelocity.omega +=MaxRotateVelocity;
        break;
    };
    emit SetVelocity(TARVelocity);
};

