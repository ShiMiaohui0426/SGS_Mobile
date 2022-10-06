#ifndef omni
#define omni
typedef struct omniVelocity{
    double vx=0;
    double vy=0;
    double omega=0;
}omniVelocity;
#endif
#ifndef WIDGET_H
#define WIDGET_H
#define MaxLinearVelocity 1.5
#define MaxRotateVelocity 60
#include <QWidget>
#include<qstring.h>
#include<ROSctrl/qrosnode.hpp>
#include<qjsonobject.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QJsonObject save();
    void restore(QJsonObject &paras);

private slots:
    void on_pushButton_Apply_clicked();
    void msgReady(QString v);

private:
    Ui::Widget *ui;
    QString topic;
    QROSNode* node;
    std::map<std::string,std::string> remappings;
    omniVelocity TARVelocity;
    void KeyPressEvent(const char &key);
    void KeyReleasedEvent(char key);

signals:
    void SetVelocity(omniVelocity v);
};
#endif // WIDGET_H
