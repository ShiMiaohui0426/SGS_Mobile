#include "epos4can.h"
#include "ui_epos4can.h"

EPOS4CAN::EPOS4CAN(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EPOS4CAN)
{
    ui->setupUi(this);
    QString info="EPOS4 NOT CONNECTED";
    ui->label_info->setText(info);
    updater=new QTimer();
    CANtimer=new QTimer();
    connect(updater,SIGNAL(timeout()),this,SLOT(update()));
};

EPOS4CAN::~EPOS4CAN()
{
    SetVelocity(0);
    delete ui;
}

bool EPOS4CAN::eventFilter(QObject *target, QEvent *event)
{
    return false;
}

void EPOS4CAN::SetNodeID(unsigned short ID)
{
    g_usNodeId=ID;
    QString info="EPOS4 NODE #"+QString::number(g_usNodeId);
    ui->label_info->setText(info);
};

void* EPOS4CAN::GetKeyHandle()
{
    return g_pKeyHandle;
}

void EPOS4CAN::SetKeyHandle(void *KeyHandle)
{
    g_pKeyHandle=KeyHandle;
}

void EPOS4CAN::SetVelocity(double Velocity)
{
    long v=Velocity*ReduceRate;
    if(v!=TARENCVelocity&&v<=MaxENCVelocity){
        TARENCVelocity=v;
        SetENCVelocity(TARENCVelocity);
        ui->spinBox_SetVelocity->setValue(TARENCVelocity/ReduceRate);
    };
    if(v>MaxENCVelocity){
        TARENCVelocity=MaxENCVelocity;
        SetENCVelocity(TARENCVelocity);
        ui->spinBox_SetVelocity->setValue(TARENCVelocity/ReduceRate);
    };

}
//#include <QTime>
void EPOS4CAN::SetENCVelocity(long Velocity)
{
//    QTime t;
//    t.start();
    VCS_SetVelocityMust(g_pKeyHandle,g_usNodeId,Velocity,&ulErrorCode);
//    emit tarV(Velocity);
//        VCS_SetVelocityMust(g_pKeyHandle,g_usNodeId,Velocity,&ulErrorCode);
//    qDebug()<<t.elapsed();
};

double EPOS4CAN::GetVelocity()
{
    return ui->lcdNumber_ACTVelocity->value();

};

int EPOS4CAN::OpenDevice()
{
    int lResult = MMC_FAILED;
    unsigned int *p_pErrorCode=&ulErrorCode;
    char* pDeviceName = new char[255];
    char* pProtocolStackName = new char[255];
    char* pInterfaceName = new char[255];
    char* pPortName = new char[255];
    std::string std;
    std=g_deviceName.toStdString();
    strcpy(pDeviceName,std.c_str());

    std=g_protocolStackName.toStdString();
    strcpy(pProtocolStackName,std.c_str());

    std=g_interfaceName.toStdString();
    strcpy(pInterfaceName,std.c_str());

    std=g_portName.toStdString();
    strcpy(pPortName,std.c_str());

    qDebug()<<"Open device...";


    g_pKeyHandle = VCS_OpenDevice(pDeviceName, pProtocolStackName, pInterfaceName, pPortName, p_pErrorCode);
    qDebug()<<"handle:"<<g_pKeyHandle;
    if(*p_pErrorCode!=0){
        qDebug()<<"open error code"<<*p_pErrorCode;
    };
    if(g_pKeyHandle!=0 && *p_pErrorCode == 0)
    {
        unsigned int lBaudrate = 0;
        unsigned int lTimeout = 0;

        if(VCS_GetProtocolStackSettings(g_pKeyHandle, &lBaudrate, &lTimeout, p_pErrorCode)!=0)
        {
            if(VCS_SetProtocolStackSettings(g_pKeyHandle, g_baudrate, lTimeout, p_pErrorCode)!=0)
            {
                if(VCS_GetProtocolStackSettings(g_pKeyHandle, &lBaudrate, &lTimeout, p_pErrorCode)!=0)
                {
                    if(g_baudrate==(int)lBaudrate)
                    {
                        lResult = MMC_SUCCESS;
                        qDebug()<<"Open device success";
                    }
                }
            }
        }
    }
    else
    {
        g_pKeyHandle = 0;
    };


    return lResult;

};

int EPOS4CAN::DriverInit(unsigned int *p_pErrorCode)
{
    int lResult = MMC_SUCCESS;
    BOOL oIsFault = 0;

    if(VCS_GetFaultState(g_pKeyHandle, g_usNodeId, &oIsFault, p_pErrorCode ) == 0)
    {
        qDebug()<<"VCS_GetFaultState"<< lResult<<*p_pErrorCode;
        lResult = MMC_FAILED;
    }

    if(lResult==0)
    {
        if(oIsFault)
        {
            QString msg= "clear fault, node = '" + QString(g_usNodeId) + "'";;
            qDebug()<<msg;

            if(VCS_ClearFault(g_pKeyHandle, g_usNodeId, p_pErrorCode) == 0)
            {
                qDebug()<<"VCS_ClearFault"<<lResult<<*p_pErrorCode;
                lResult = MMC_FAILED;
            }
        }

        if(lResult==0)
        {
            BOOL oIsEnabled = 0;

            if(VCS_GetEnableState(g_pKeyHandle, g_usNodeId, &oIsEnabled, p_pErrorCode) == 0)
            {
                qDebug()<<"VCS_GetEnableState"<< lResult<<*p_pErrorCode;
                lResult = MMC_FAILED;
            }

            if(lResult==0)
            {
                if(!oIsEnabled)
                {
                    if(VCS_SetEnableState(g_pKeyHandle, g_usNodeId, p_pErrorCode) == 0)
                    {
                        qDebug()<<"VCS_SetEnableState"<<lResult<< *p_pErrorCode;
                        lResult = MMC_FAILED;
                    }
                }
            }
        }
    }
    return lResult;
};

int EPOS4CAN::RunCSVMode(unsigned int *p_pErrorCode)
{
    int lResult=MMC_SUCCESS;
    QString msg="set profile velocity mode, node = " +QString(g_usNodeId) ;
    qDebug()<<msg;
    if(VCS_ActivateVelocityMode(g_pKeyHandle,g_usNodeId,p_pErrorCode)){
        qDebug()<<"VCS_ActivateProfileVelocityMode"<<lResult<< p_pErrorCode;
        lResult = MMC_FAILED;
    }
    else{

        VCS_SetVelocityMust(g_pKeyHandle,g_usNodeId,0,p_pErrorCode);
    };
    return lResult;
}

void EPOS4CAN::EnableDriver()
{
    unsigned int *p_pErrorCode=&ulErrorCode;
    DriverInit(p_pErrorCode);
    RunCSVMode(p_pErrorCode);
    Vsendder= new EPOS4CAN_VelocitySetter(g_pKeyHandle,g_usNodeId,ulErrorCode);
    sendder_thread=new QThread();
    Vsendder->moveToThread(sendder_thread);
    CANtimer->moveToThread(sendder_thread);
    sendder_thread->start();
    connect(this,SIGNAL(tarV(long)),Vsendder,SLOT(setV(long)),Qt::QueuedConnection);
    connect(CANtimer,&QTimer::timeout,sendder_thread,[=]{
//        VCS_GetVelocityMust(g_pKeyHandle,g_usNodeId,&ACTENCVelocity,&ulErrorCode);
    },Qt::QueuedConnection);
    updater->start(100);
    QTimer* s=new QTimer();
    s->moveToThread(sendder_thread);
    s->singleShot(10,CANtimer,[=]{
        CANtimer->start(100);
    });
};

int EPOS4CAN::CloseDevice()
{
    int lResult = MMC_FAILED;
    unsigned int *p_pErrorCode=&ulErrorCode;
    *p_pErrorCode = 0;

    qDebug()<<"Close device";

    if(VCS_CloseDevice(g_pKeyHandle, p_pErrorCode)!=0 && *p_pErrorCode == 0)
    {
        lResult = MMC_SUCCESS;
    }

    return lResult;
};

void EPOS4CAN::SetReduceRate(double Rate)
{
    if(Rate>1) ReduceRate=Rate;
}

void EPOS4CAN::SetMaxVelocity(double mxVelocity)
{
    MaxENCVelocity=long(mxVelocity*ReduceRate);
}

void EPOS4CAN::SetThread(QThread *CanThread)
{
    sendder_thread=CanThread;
}
//int test=0;
void EPOS4CAN::update()
{

//    //test code
//        test--;
//        ACTENCVelocity=test;
//    //done
    int speed=ACTENCVelocity;
    ui->progressBar_VelocityPercent->setValue(abs(speed*100/MaxENCVelocity));
    ui->lcdNumber_ACTVelocity->display(speed/ReduceRate);

};

void EPOS4CAN::on_spinBox_SetVelocity_valueChanged(int arg1)
{
    if(abs(arg1)>abs(int(round(MaxENCVelocity/ReduceRate))))ui->spinBox_SetVelocity->setValue(int(round(MaxENCVelocity/ReduceRate))*arg1/abs(arg1));
};


void EPOS4CAN::on_pushButton_SetVelocity_clicked()
{
    SetVelocity(ui->spinBox_SetVelocity->value());
}


EPOS4CAN_VelocitySetter::EPOS4CAN_VelocitySetter(void* pKeyHandle, unsigned short usNodeId, unsigned int ErrorCode)
{
 g_pKeyHandle=pKeyHandle;
 g_usNodeId=usNodeId;
 ulErrorCode=ErrorCode;
};

EPOS4CAN_VelocitySetter::~EPOS4CAN_VelocitySetter()
{

}
void EPOS4CAN_VelocitySetter::setV(long Velocity)
{



    VCS_SetVelocityMust(g_pKeyHandle,g_usNodeId,Velocity,&ulErrorCode);

};
