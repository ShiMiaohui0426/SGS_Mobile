//#define addfuncToTask(x) addfuncToTask_(this,x)
#ifndef QPLCMODEL_H
#define QPLCMODEL_H

#include <QObject>
#include <QTimer>
#include <qthread.h>
#include <qlist.h>
#include <qjsonobject.h>
#include <qdebug.h>

class QPLCDriver:public QObject
{
    Q_OBJECT
public:
    QPLCDriver(){};
    ~QPLCDriver(){};
protected:
    QJsonObject iData;
    QJsonObject oData;
public slots:
    virtual void inputData(const QJsonObject &myDoc)=0;
    void refresh(){
        emit outputData(oData); };
signals:
    void outputData(QJsonObject oData);

};
class QPLCTask :public QObject
{ Q_OBJECT
public:
    QPLCTask(int msec);
    void addObjectToTask(QObject *object);
    void addObjectToTask(QPLCDriver *object);
    void addfuncToTask(const QObject *receiver,const char *member);
    void startTask();
    void stopTask();
private:
    int CycleTime;
    QTimer *timer;
    QThread *timerthread;
    QThread *taskthread;
    QJsonObject iData;
    QJsonObject oData;
public slots:
    void inputData(const QJsonObject &myDoc);
    void refreshOutData();
signals:
    void outputData(QJsonObject oData);

};


class QPLCModel
{
public:
    QPLCModel();
};

#endif // QPLCMODEL_H
