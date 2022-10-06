#include "tcpctrl.h"
#include "ui_tcpctrl.h"
#include <qdebug.h>
#define maxV 1.5;
#define maxR 60;
//#include<qnetworkinterface.h>
tcpctrl::tcpctrl(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::tcpctrl)
{
    ui->setupUi(this);
    logging_model=new QStringListModel();
    ui->listView->setModel(logging_model);
    m_server=new QTcpServer(this);
    QTimer::singleShot(500,this,[=]{
        m_server->listen(QHostAddress::AnyIPv4,ui->lineEdit_port->text().toInt());
        QString message("");
        message+="Start listen";
        logging_model->insertRows(logging_model->rowCount(),1);
        QVariant new_row(message);
        logging_model->setData(logging_model->index(logging_model->rowCount()-1),new_row);
        ui->listView->scrollToBottom();
        connect(m_server,&QTcpServer::newConnection,this,&tcpctrl::getNewConnection);
    });
    QString message("");
    message+="Start listen after 500 ms";
    logging_model->insertRows(logging_model->rowCount(),1);
    QVariant new_row(message);
    logging_model->setData(logging_model->index(logging_model->rowCount()-1),new_row);
    ui->listView->scrollToBottom();
    connect(m_server,&QTcpServer::newConnection,this,&tcpctrl::getNewConnection);

};

tcpctrl::~tcpctrl()
{
    delete ui;
}

QJsonObject tcpctrl::save()
{
    QJsonObject m_obj;
    m_obj["port"]=ui->lineEdit_port->text();
    return m_obj;
}

void tcpctrl::restore(QJsonObject &paras)
{
    QJsonObject m_para=paras;
    ui->lineEdit_port->setText(m_para["port"].toString());
}

void tcpctrl::receiveMsg()
{

    QByteArray buffer = m_socket->readAll();
    QString str(buffer);
    QStringList stringList;
    stringList << "righ" << "down"<<"up  "<<"left"<<"lrot"<<"rrot"<<"stop"<<"outt";
    omniVelocity m_Velo;
    switch(stringList.indexOf(str))
    {

    case Operation::righ:
        m_Velo.vx=maxV;
        emit sendVelocity(m_Velo);
        //qDebug()<<"right";
        break;
    case Operation::down:
        m_Velo.vy=-maxV;
        emit sendVelocity(m_Velo);
        //qDebug()<<"down";
        break;
    case Operation::up  :
        m_Velo.vy=maxV;
        emit sendVelocity(m_Velo);
        //qDebug()<<"up";
        break;
    case Operation::left:
        m_Velo.vx=-maxV;
        emit sendVelocity(m_Velo);
        //qDebug()<<"left";
        break;
    case Operation::lrot:
        m_Velo.omega=-maxR;
        emit sendVelocity(m_Velo);
        //qDebug()<<"lrot";
        break;
    case Operation::rrot:
        m_Velo.omega=maxR;
        emit sendVelocity(m_Velo);
        //qDebug()<<"rrot";
        break;
    case Operation::stop:
        emit sendVelocity(m_Velo);
        //qDebug()<<"stop";
        break;
        //    case Operation::outt: m_server->close();
        //        break;
    default:
        break;
    };

    QString message("tcp received:");
    message+=str;
    logging_model->insertRows(logging_model->rowCount(),1);
    QVariant new_row(message);
    logging_model->setData(logging_model->index(logging_model->rowCount()-1),new_row);
    ui->listView->scrollToBottom();
}

void tcpctrl::getNewConnection()
{
    while (m_server->hasPendingConnections()) {
        m_socket = m_server->nextPendingConnection();
        connect(m_socket,&QTcpSocket::readyRead,this,&tcpctrl::receiveMsg);
    };
    QString message("");
    message+="new connection: "+m_socket->peerAddress().toString();
    logging_model->insertRows(logging_model->rowCount(),1);
    QVariant new_row(message);
    logging_model->setData(logging_model->index(logging_model->rowCount()-1),new_row);
    ui->listView->scrollToBottom();
};

