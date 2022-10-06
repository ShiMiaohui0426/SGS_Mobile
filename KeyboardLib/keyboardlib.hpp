#ifndef KEYBOARDLIB_H
#define KEYBOARDLIB_H
#include <QObject>
#include <QWidget>
#include <qjsonobject.h>
#include<controlAPI.hpp>
#include<Keyboard/keyboardctrl.h>
class KeyboardLib :public controlAPI
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID controlAPI_iid)
    Q_INTERFACES(controlAPI);

public:
    explicit KeyboardLib();
    ~KeyboardLib();
    virtual QWidget* get_widget() override;
    virtual QJsonObject save() override;
    virtual void restore(QJsonObject &paras) override;
    virtual void SetEnable(bool enable)override {status=enable;};
    virtual void SetDisable(bool disable)override{status=disable;};
    virtual bool isEnable()override{return status;};
    virtual QJsonObject GetINFO()override{return info;};
private:
    KeyboardCtrl* myctrl;
public:
    bool status=false;
    QJsonObject info;
signals:
    void SetVel(omniVelocity VEL);
};

#endif // KEYBOARDLIB_H
