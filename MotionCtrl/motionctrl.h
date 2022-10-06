#ifndef MOTIONCTRL_H
#define MOTIONCTRL_H

#include <QWidget>
#include<QKeyEvent>
#include "EPOS4CAN_V1.0/epos4can.h"
#include "controlAPI.hpp"
#include <qlist.h>
#include <qjsonobject.h>
#include<qjsondocument.h>
#include<qfile.h>
#include <qdir.h>
#include <qfiledialog.h>
#include <qlibrary.h>
#include <qpluginloader.h>
#include"VelocityPlanner/velocityplanner.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MotionCtrl; }
QT_END_NAMESPACE

class MotionCtrl : public QWidget
{
    Q_OBJECT

public:
    MotionCtrl(QWidget *parent = nullptr);
    void dirverInit();
    void pluginInit();
    ~MotionCtrl();

private:
    Ui::MotionCtrl *ui;
    EPOS4CAN* Driver[4];
    double MaxLinearVelocity=1.5;//m/s
    double MaxRotateVelocity=60;//degree/s
    double override=0;
    omniVelocity TARVelocity;
    VelocityPlanner* Planner;
    QThread * cantimer;
public slots:
    void SetVelocity(omniVelocity TARVelocity);

private slots:
    void on_lineEdit_override_textChanged(const QString &arg1);
    void on_comboBox_currentIndexChanged(int index);

    void on_checkBox_Enabled_stateChanged(int arg1);

private:
    QList<controlAPI*> myAPIList;
    controlAPI* loadPlugin(QString plugin_path);
    void save();
    void restore();

};
#endif // MOTIONCTRL_H
