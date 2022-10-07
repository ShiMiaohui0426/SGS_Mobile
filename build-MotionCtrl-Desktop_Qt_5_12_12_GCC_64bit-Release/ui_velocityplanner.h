/********************************************************************************
** Form generated from reading UI file 'velocityplanner.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VELOCITYPLANNER_H
#define UI_VELOCITYPLANNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qchartview.h"

QT_BEGIN_NAMESPACE

class Ui_VelocityPlanner
{
public:
    QVBoxLayout *verticalLayout;
    QtCharts::QChartView *graphicsView;

    void setupUi(QWidget *VelocityPlanner)
    {
        if (VelocityPlanner->objectName().isEmpty())
            VelocityPlanner->setObjectName(QString::fromUtf8("VelocityPlanner"));
        VelocityPlanner->resize(390, 341);
        verticalLayout = new QVBoxLayout(VelocityPlanner);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView = new QtCharts::QChartView(VelocityPlanner);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);


        retranslateUi(VelocityPlanner);

        QMetaObject::connectSlotsByName(VelocityPlanner);
    } // setupUi

    void retranslateUi(QWidget *VelocityPlanner)
    {
        VelocityPlanner->setWindowTitle(QApplication::translate("VelocityPlanner", "VelocityPlanner", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VelocityPlanner: public Ui_VelocityPlanner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VELOCITYPLANNER_H
