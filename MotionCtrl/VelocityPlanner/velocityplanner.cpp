#include "velocityplanner.h"
#include "ui_velocityplanner.h"
#include "QDebug"
#define Ts 50
#include<QTime>
QTime m_time;
VelocityPlanner::VelocityPlanner(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VelocityPlanner)
{
    ui->setupUi(this);
    plannerTask=new QPLCTask(Ts);
    m_sender=new Vsender();
    plannerTask->addObjectToTask(m_sender);
    connect(this,&VelocityPlanner::SendVelocitylist,m_sender,&Vsender::setList,Qt::QueuedConnection);
    connect(m_sender,SIGNAL(SendVelocity(omniVelocity*)),this,SLOT(SendTarV(omniVelocity*)),Qt::DirectConnection);
    //    plannerTask->addfuncToTask(this,SLOT(SendTarV()));
    plannerTask->startTask();
    maxAcc=5;
    initPlot();
    /**test**/
    //    omniVelocity ACT;
    //    omniVelocity t;
    //    ACT.vx=-5;
    //    ACT.vy=-8;
    //    ACT.omega=0;

    //    t.vx=10;
    //    t.vy=10;
    //    t.omega=10;
    //
    //    PlanVelocity(ACT,t);
}

VelocityPlanner::~VelocityPlanner()
{
    delete ui;
}

void VelocityPlanner::PlanVelocity(omniVelocity TAR)
{

    omniVelocity ACT;
    if(!tarV.isEmpty()){
        ACT=tarV.takeFirst();
        tarV.clear();
    }
    else{
        ACT=LastVelocity;
    };
    while(m_lineSeries->points().size()>0)m_lineSeries->remove(0);
    double deltaSpeed=sqrt((TAR.vx-ACT.vx)*(TAR.vx-ACT.vx)+(TAR.vy-ACT.vy)*(TAR.vy-ACT.vy)) ;
    double dx=(TAR.vx-ACT.vx);
    double dy=(TAR.vy-ACT.vy);
    double domega=(TAR.omega-ACT.omega);
    double mtime=1000*deltaSpeed/maxAcc;//ms
    if(mtime<20)mtime=50;
    double step=round(mtime/Ts);
    double Tx;
    double Ty;
    double Tomega;
    m_axisX->setMax(step*10);
    double actSpeed=sqrt(ACT.vx*ACT.vx+ACT.vy*ACT.vy);
    double tarSpeed=sqrt(TAR.vx*TAR.vx+TAR.vy*TAR.vy);
    if(actSpeed>tarSpeed){
        m_axisY->setMax(actSpeed);
        m_axisY->setMin(tarSpeed);
    }
    else{
        m_axisY->setMax(tarSpeed);
        m_axisY->setMin(actSpeed);
    };
    for (int i=0;i<step +1;i++ ) {
        Tx=dx*(cos(3.1415926*(i/step+1))+1)/2;
        Ty=dy*(cos(3.1415926*(i/step+1))+1)/2;
        Tomega=domega*(cos(3.1415926*(i/step+1))+1)/2;
        omniVelocity T;
        T.vx=Tx+ACT.vx;
        T.vy=Ty+ACT.vy;
        T.omega=Tomega+ACT.omega;
        double speed=sqrt(T.vx*T.vx+T.vy*T.vy);
        if(speed<m_axisY->min())m_axisY->setMin(speed);
        if(speed>m_axisY->max())m_axisY->setMax(speed);
        tarV.append(T);
        m_lineSeries->append(QPointF(i*10,speed));
    };
    LastVelocity=TAR;
//    qDebug()<<"step:"<<step;
    emit SendVelocitylist(&tarV);
};

void VelocityPlanner::setMaxAcceleration(double acc)
{
    maxAcc=acc;
}

void VelocityPlanner::initPlot()
{
    m_axisX=new QValueAxis();
    m_axisY=new QValueAxis();
    //    m_axisX->setTitleText("t-ms");
    //    m_axisY->setTitleText("V-m/s");
    m_axisX->setMin(0);
    m_axisX->setMax(0);

    m_lineSeries=new QLineSeries();
    //    m_lineSeries->setPointLabelsVisible();
    //    m_lineSeries->setName("SPEED LINE");

    m_chart=new QChart();
    m_chart->addAxis(m_axisY,Qt::AlignLeft);
    m_chart->addAxis(m_axisX,Qt::AlignBottom);
    m_chart->addSeries(m_lineSeries);
    //    m_chart->legend()->visibleChanged(0);
    m_chart->legend()->setVisible(false);
//    m_chart->setAnimationOptions(QChart::SeriesAnimations);

    m_lineSeries->attachAxis(m_axisX);
    m_lineSeries->attachAxis(m_axisY);

    ui->graphicsView->setChart(m_chart);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

};

void VelocityPlanner::SendTarV(omniVelocity* tmp)
{

    //    if(!tarV.isEmpty())
    //    {
    //        omniVelocity tmp=tarV.takeFirst();
    ////        qDebug()<<tmp.vx;

            emit SendVelocity(*tmp);
    //    };
};


void Vsender::setList(QList<omniVelocity> *list)
{
    mylist.swap(*list);
//    m_time.start();
}

Vsender::Vsender()
{

}

Vsender::~Vsender()
{

}

void Vsender::inputData(const QJsonObject &myDoc)
{

}
//QTime t,p;
void Vsender::refresh()
{
    if(!mylist.isEmpty())
    {
        omniVelocity tmp=mylist.takeFirst();
        //        qDebug()<<tmp.vx;
//if(mylist.isEmpty())qDebug()<<m_time.elapsed()<<"ms time used";
//        qDebug()<<p.elapsed()<<"ms used for 4 motors";

//        p.start();
        emit SendVelocity(&tmp);
    };
};
