#ifndef EPOS4CAN_H
#define EPOS4CAN_H

#include <QWidget>
#include "EPOS_Linux_Library/include/Definitions.h"
#include <QString>
#include <QDebug>
#include <QTimer>
#include <qthread.h>
QT_BEGIN_NAMESPACE
namespace Ui { class EPOS4CAN; }
QT_END_NAMESPACE

typedef void* HANDLE;
typedef int BOOL;
enum EAppMode
{
    AM_UNKNOWN,
    AM_DEMO,
    AM_INTERFACE_LIST,
    AM_PROTOCOL_LIST,
    AM_VERSION_INFO
};
#ifndef MMC_SUCCESS
#define MMC_SUCCESS 0
#endif

#ifndef MMC_FAILED
#define MMC_FAILED 1
#endif

#ifndef MMC_MAX_LOG_MSG_SIZE
#define MMC_MAX_LOG_MSG_SIZE 512
#endif
class EPOS4CAN_VelocitySetter : public QObject
{
    Q_OBJECT
public:
    EPOS4CAN_VelocitySetter(void* pKeyHandle,unsigned short usNodeId,unsigned int ErrorCode);
    ~EPOS4CAN_VelocitySetter();
public slots:
    void setV(long Velocity);
private:
    void* g_pKeyHandle;
    unsigned short g_usNodeId;
    unsigned int ulErrorCode;

};
class EPOS4CAN : public QWidget
{
    Q_OBJECT

public:
    EPOS4CAN(QWidget *parent = nullptr);
    ~EPOS4CAN();
    bool eventFilter(QObject *target, QEvent *event);

private:
    Ui::EPOS4CAN *ui;
    EPOS4CAN_VelocitySetter* Vsendder;
    QThread *sendder_thread;


//OPerating
public:
    void SetNodeID(unsigned short ID);
    int OpenDevice();
    int DriverInit(unsigned int* p_pErrorCode);
    int RunCSVMode(unsigned int* p_pErrorCode);
    void EnableDriver();
    int CloseDevice();
    void* GetKeyHandle();
    void SetKeyHandle(void* KeyHandle);

private:
    unsigned int ulErrorCode = 0;
    void* g_pKeyHandle = 0;
    unsigned short g_usNodeId = 1;
    QString g_deviceName= "EPOS4";
    QString g_protocolStackName= "MAXON SERIAL V2";
    QString g_interfaceName= "USB";
    QString g_portName= "USB0";
    int g_baudrate = 1000000;
    EAppMode g_eAppMode = AM_DEMO;
    const QString g_programName = "HelloEposCmd";

//Motion Control
public:
    void SetVelocity(double Velocity);
    void SetENCVelocity(long Velocity);
    double GetVelocity();
    void SetReduceRate(double Rate);
    void SetMaxVelocity(double mxVelocity);
    void SetThread(QThread* CanThread);

private:
    double ReduceRate=1;
    long MaxENCVelocity=10000;
    long ACTENCVelocity=0;
    long TARENCVelocity=0;

//GUI update& Monitor

private:
    QTimer* updater;
    QTimer* CANtimer;
private slots:
    void update();

private slots:
    void on_spinBox_SetVelocity_valueChanged(int arg1);


    void on_pushButton_SetVelocity_clicked();
signals:
    void tarV(long Velocity);
};


#endif // EPOS4CAN_H
