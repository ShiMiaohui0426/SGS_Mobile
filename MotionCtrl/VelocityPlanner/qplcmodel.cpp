#include "qplcmodel.hpp"
#include "qdebug.h"

QPLCModel::QPLCModel()
{

}

QPLCTask::QPLCTask(int msec)
{timerthread=new QThread;
    taskthread=new QThread;
    CycleTime=msec;
    timer=new QTimer;
    timer->setTimerType(Qt::PreciseTimer);
    timer->moveToThread(timerthread);


    connect(timer,SIGNAL(timeout()),this,SLOT(refreshOutData()));
    timerthread->start();
    taskthread->start();
};

void QPLCTask::startTask()
{
    QTimer *tempTimer=new QTimer;
    tempTimer->setSingleShot(true);
    tempTimer->start(10);
    tempTimer->moveToThread(timerthread);
    connect(tempTimer,&QTimer::timeout,this,[this](){
    timer->start(CycleTime);
    }, Qt::DirectConnection);
}

void QPLCTask::stopTask()
{
    QTimer *tempTimer=new QTimer;
    tempTimer->setSingleShot(true);
    tempTimer->start(10);
    tempTimer->moveToThread(timerthread);
    connect(tempTimer,&QTimer::timeout,this,[this](){
    timer->stop();
    }, Qt::DirectConnection);
}

void QPLCTask::inputData(const QJsonObject &Doc)
{ QJsonObject myDoc=Doc;
    for(QJsonObject::iterator it=myDoc.begin();it!=myDoc.end();it++){
        iData.insert(it.key(),it.value());
    };
//qDebug()<<iData;
}

void QPLCTask::refreshOutData()
{
    oData=iData;
    emit outputData(oData);
};


void QPLCTask::addObjectToTask(QObject *object)
{
    object->moveToThread(taskthread);
}

void QPLCTask::addObjectToTask(QPLCDriver *object)
{
    object->moveToThread(taskthread);
    connect(timer,SIGNAL(timeout()),object,SLOT(refresh()));
    connect(object,SIGNAL(outputData(QJsonObject)),this,SLOT(inputData(QJsonObject)));
}

void QPLCTask::addfuncToTask(const QObject *receiver, const char *member)
{
    connect(this,SIGNAL(outputData(QJsonObject)),receiver,member);
}
