#ifndef UDPCTRL_H
#define UDPCTRL_H
#ifndef omni
#define omni
typedef struct omniVelocity{
    double vx=0;
    double vy=0;
    double omega=0;
}omniVelocity;
#endif
#include <QWidget>
#include<QUdpSocket>
#include<qjsondocument.h>
#include<qjsonobject.h>
QT_BEGIN_NAMESPACE
namespace Ui { class udpctrl; }
QT_END_NAMESPACE

class udpctrl : public QWidget
{
    Q_OBJECT

public:
    udpctrl(QWidget *parent = nullptr);
    ~udpctrl();
private slots:
    void processData();
signals:
    void sendVelocity(omniVelocity);
private:
    Ui::udpctrl *ui;
    QUdpSocket* m_receiver;
};
#endif // UDPCTRL_H
