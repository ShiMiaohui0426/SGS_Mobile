#ifndef omni
#define omni

typedef struct omniVelocity{
    double vx=0;
    double vy=0;
    double omega=0;
}omniVelocity;

#endif

#ifndef VELOCITYPLANNER_H
#define VELOCITYPLANNER_H

#include <QWidget>
#include "qplcmodel.hpp"
#include <QChartView>
#include <QtCharts>
using namespace QtCharts;
QT_BEGIN_NAMESPACE
namespace Ui { class VelocityPlanner; }
QT_END_NAMESPACE
class Vsender: public QPLCDriver{
    Q_OBJECT
public:
    Vsender();
    ~Vsender();
public:

    QList<omniVelocity> mylist;
signals:
    void SendVelocity(omniVelocity *v);
public slots:
    virtual void inputData(const QJsonObject &myDoc) override;
    void refresh();
    void setList(QList<omniVelocity> *list);
};

class VelocityPlanner : public QWidget
{
    Q_OBJECT

public:
    VelocityPlanner(QWidget *parent = nullptr);
    ~VelocityPlanner();

    void setMaxAcceleration(double acc);
signals:
    void SendVelocity(omniVelocity Tar);
    void SendVelocitylist(QList<omniVelocity> *list);
private:
    Ui::VelocityPlanner *ui;
    double maxAcc;
    QList<omniVelocity> tarV;
    QPLCTask* plannerTask;
    void initPlot();
    Vsender *m_sender;
public slots:
    void SendTarV(omniVelocity* Tar);
    void PlanVelocity(omniVelocity Tar);


private:
    QChart* m_chart;
    QValueAxis* m_axisX;
    QValueAxis* m_axisY;
    QLineSeries* m_lineSeries;
    omniVelocity LastVelocity;
};
#endif // VELOCITYPLANNER_H
