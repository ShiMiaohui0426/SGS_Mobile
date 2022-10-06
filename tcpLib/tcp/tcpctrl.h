#ifndef tcpctrl_H
#define tcpctrl_H
#ifndef omni
#define omni
typedef struct omniVelocity{
    double vx=0;
    double vy=0;
    double omega=0;
}omniVelocity;
#endif
#include <QWidget>
#include <QTcpServer>
#include <qtcpsocket.h>
#include<QStringListModel>
#include<qstring.h>
#include<qjsonobject.h>
#include<qtimer.h>
QT_BEGIN_NAMESPACE
namespace Ui { class tcpctrl; }
QT_END_NAMESPACE

class tcpctrl : public QWidget
{
    Q_OBJECT

public:
    tcpctrl(QWidget *parent = nullptr);
    ~tcpctrl();
    QJsonObject save();
    void restore(QJsonObject &paras);

signals:
    void sendVelocity(omniVelocity);

private:
    Ui::tcpctrl *ui;
    QTcpServer *m_server;
    QTcpSocket *m_socket;
    QStringListModel *logging_model;
public:
    enum Operation
    {
        righ,
        down,
        up  ,
        left,
        lrot,
        rrot,
        stop,
        outt
    };
    Q_ENUM(Operation)

private slots:
    void receiveMsg();
    void getNewConnection();
};
#endif // tcpctrl_H
