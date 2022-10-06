#ifndef tcpLIB_H
#define tcpLIB_H
#include <QObject>
#include <QWidget>
#include <qjsonobject.h>
#include<controlAPI.hpp>
#include<tcp/tcpctrl.h>
class tcpLib :public controlAPI
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID controlAPI_iid)
    Q_INTERFACES(controlAPI);

public:
    explicit tcpLib();
    ~tcpLib();
    virtual QWidget* get_widget() override;
    virtual QJsonObject save() override;
    virtual void restore(QJsonObject &paras) override;
    virtual void SetEnable(bool enable=true)override {status=enable;};
    virtual void SetDisable(bool disable=false)override{status=disable;};
    virtual bool isEnable()override{return status;};
    virtual QJsonObject GetINFO()override{return info;};
private:
    tcpctrl* myctrl;
public:
    bool status=false;
    QJsonObject info;
signals:
    void SetVel(omniVelocity VEL);
};

#endif // tcpLIB_H
