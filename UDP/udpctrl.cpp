#include "udpctrl.h"
#include "ui_udpctrl.h"
#include "qdebug.h"
udpctrl::udpctrl(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::udpctrl)
{
    ui->setupUi(this);
    m_receiver=new QUdpSocket(this);
    m_receiver->bind(6666,QUdpSocket::ShareAddress);
        //当接收端接收到数据时，就会发送readRead信号
        connect(m_receiver,&QUdpSocket::readyRead,this,&udpctrl::processData);
}

udpctrl::~udpctrl()
{
    delete ui;
}

void udpctrl::processData()
{
    QString strData;
        //有未处理的数据报
        while(m_receiver->hasPendingDatagrams()){
            QByteArray dataGram;
            //读取的数据报大小
            dataGram.resize(m_receiver->pendingDatagramSize());
            m_receiver->readDatagram(dataGram.data(),dataGram.size());
            QJsonDocument doc=QJsonDocument::fromJson(dataGram);
            QJsonObject obj=doc.object();
//            qDebug()<<obj;
            omniVelocity tarV;
            tarV.vx=obj["vx"].toDouble();
            tarV.vy=obj["vy"].toDouble();
            tarV.omega=obj["omega"].toDouble();
            emit sendVelocity(tarV);
        };
}

