#ifndef ROSctrlLIB_H
#define ROSctrlLIB_H
#include <QObject>
#include <QWidget>
#include <qjsonobject.h>
#include<controlAPI.hpp>
#include<ROSctrl/widget.h>
class ROSctrlLib :public controlAPI
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID controlAPI_iid)
    Q_INTERFACES(controlAPI);

public:
    explicit ROSctrlLib();
    ~ROSctrlLib();
    virtual QWidget* get_widget() override;
    virtual QJsonObject save() override;
    virtual void restore(QJsonObject &paras) override;
    virtual void SetEnable(bool enable)override {status=enable;};
    virtual void SetDisable(bool disable)override{status=disable;};
    virtual bool isEnable()override{return status;};
    virtual QJsonObject GetINFO()override{return info;};
private:
    Widget* myctrl;
public:
    bool status=false;
    QJsonObject info;
signals:
    void SetVel(omniVelocity VEL);
};

#endif // ROSctrlLIB_H
