#ifndef omni
#define omni
typedef struct omniVelocity{
    double vx=0;
    double vy=0;
    double omega=0;
}omniVelocity;
#endif
#ifndef CONTROLAPI_H
#define CONTROLAPI_H

#include <QWidget>
#include <qjsonobject.h>

class controlAPI:public QObject
{
    Q_OBJECT
public:
    controlAPI(){};
virtual ~controlAPI(){};
    virtual QWidget* get_widget()=0;
    virtual QJsonObject save()=0;
    virtual void restore(QJsonObject &paras)= 0;
    virtual void SetEnable(bool enable)= 0;
    virtual void SetDisable(bool disable)= 0;
    virtual bool isEnable()= 0;
    virtual QJsonObject GetINFO()= 0;
signals:
    void SetVel(omniVelocity VEL);



};

#define controlAPI_iid "com.Plugin.controlAPI"
Q_DECLARE_INTERFACE(controlAPI, controlAPI_iid)
#endif // CONTROL_H
