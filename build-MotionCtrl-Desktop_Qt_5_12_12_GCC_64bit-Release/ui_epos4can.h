/********************************************************************************
** Form generated from reading UI file 'epos4can.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EPOS4CAN_H
#define UI_EPOS4CAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EPOS4CAN
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *line;
    QLabel *label_info;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_SetVelocity;
    QSpinBox *spinBox_SetVelocity;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLCDNumber *lcdNumber_ACTVelocity;
    QLabel *label;
    QProgressBar *progressBar_VelocityPercent;

    void setupUi(QWidget *EPOS4CAN)
    {
        if (EPOS4CAN->objectName().isEmpty())
            EPOS4CAN->setObjectName(QString::fromUtf8("EPOS4CAN"));
        EPOS4CAN->resize(249, 140);
        verticalLayout = new QVBoxLayout(EPOS4CAN);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        line = new QFrame(EPOS4CAN);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label_info = new QLabel(EPOS4CAN);
        label_info->setObjectName(QString::fromUtf8("label_info"));

        verticalLayout->addWidget(label_info);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_SetVelocity = new QPushButton(EPOS4CAN);
        pushButton_SetVelocity->setObjectName(QString::fromUtf8("pushButton_SetVelocity"));

        horizontalLayout_2->addWidget(pushButton_SetVelocity);

        spinBox_SetVelocity = new QSpinBox(EPOS4CAN);
        spinBox_SetVelocity->setObjectName(QString::fromUtf8("spinBox_SetVelocity"));
        spinBox_SetVelocity->setMinimum(-999999999);
        spinBox_SetVelocity->setMaximum(999999999);

        horizontalLayout_2->addWidget(spinBox_SetVelocity);

        label_3 = new QLabel(EPOS4CAN);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(EPOS4CAN);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lcdNumber_ACTVelocity = new QLCDNumber(EPOS4CAN);
        lcdNumber_ACTVelocity->setObjectName(QString::fromUtf8("lcdNumber_ACTVelocity"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lcdNumber_ACTVelocity->sizePolicy().hasHeightForWidth());
        lcdNumber_ACTVelocity->setSizePolicy(sizePolicy1);
        QFont font;
        font.setItalic(false);
        lcdNumber_ACTVelocity->setFont(font);
        lcdNumber_ACTVelocity->setSmallDecimalPoint(false);
        lcdNumber_ACTVelocity->setDigitCount(9);
        lcdNumber_ACTVelocity->setMode(QLCDNumber::Dec);
        lcdNumber_ACTVelocity->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_ACTVelocity->setProperty("intValue", QVariant(0));

        horizontalLayout->addWidget(lcdNumber_ACTVelocity);

        label = new QLabel(EPOS4CAN);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        progressBar_VelocityPercent = new QProgressBar(EPOS4CAN);
        progressBar_VelocityPercent->setObjectName(QString::fromUtf8("progressBar_VelocityPercent"));
        progressBar_VelocityPercent->setValue(0);

        verticalLayout->addWidget(progressBar_VelocityPercent);


        retranslateUi(EPOS4CAN);

        QMetaObject::connectSlotsByName(EPOS4CAN);
    } // setupUi

    void retranslateUi(QWidget *EPOS4CAN)
    {
        EPOS4CAN->setWindowTitle(QApplication::translate("EPOS4CAN", "EPOS4CAN", nullptr));
        label_info->setText(QApplication::translate("EPOS4CAN", "info", nullptr));
        pushButton_SetVelocity->setText(QApplication::translate("EPOS4CAN", "SetVelociy", nullptr));
        label_3->setText(QApplication::translate("EPOS4CAN", "rpm", nullptr));
        label_2->setText(QApplication::translate("EPOS4CAN", "Velocity", nullptr));
        label->setText(QApplication::translate("EPOS4CAN", "rpm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EPOS4CAN: public Ui_EPOS4CAN {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EPOS4CAN_H
