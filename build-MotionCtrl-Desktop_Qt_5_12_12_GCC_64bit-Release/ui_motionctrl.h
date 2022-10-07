/********************************************************************************
** Form generated from reading UI file 'motionctrl.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOTIONCTRL_H
#define UI_MOTIONCTRL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MotionCtrl
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_override;
    QLabel *label_3;
    QCheckBox *checkBox_Enabled;
    QStackedWidget *stackedWidget_controller;
    QWidget *page;
    QWidget *page_2;
    QStackedWidget *stackedWidget_planner;
    QWidget *page_3;
    QWidget *page_4;

    void setupUi(QWidget *MotionCtrl)
    {
        if (MotionCtrl->objectName().isEmpty())
            MotionCtrl->setObjectName(QString::fromUtf8("MotionCtrl"));
        MotionCtrl->resize(400, 800);
        MotionCtrl->setFocusPolicy(Qt::StrongFocus);
        gridLayout = new QGridLayout(MotionCtrl);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(MotionCtrl);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(tab);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(tab_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_override = new QLineEdit(tab_2);
        lineEdit_override->setObjectName(QString::fromUtf8("lineEdit_override"));

        horizontalLayout_2->addWidget(lineEdit_override);

        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);


        verticalLayout_2->addLayout(horizontalLayout_2);

        checkBox_Enabled = new QCheckBox(tab_2);
        checkBox_Enabled->setObjectName(QString::fromUtf8("checkBox_Enabled"));

        verticalLayout_2->addWidget(checkBox_Enabled);

        stackedWidget_controller = new QStackedWidget(tab_2);
        stackedWidget_controller->setObjectName(QString::fromUtf8("stackedWidget_controller"));
        stackedWidget_controller->setFocusPolicy(Qt::StrongFocus);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget_controller->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget_controller->addWidget(page_2);

        verticalLayout_2->addWidget(stackedWidget_controller);

        stackedWidget_planner = new QStackedWidget(tab_2);
        stackedWidget_planner->setObjectName(QString::fromUtf8("stackedWidget_planner"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget_planner->sizePolicy().hasHeightForWidth());
        stackedWidget_planner->setSizePolicy(sizePolicy);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        stackedWidget_planner->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        stackedWidget_planner->addWidget(page_4);

        verticalLayout_2->addWidget(stackedWidget_planner);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);


        retranslateUi(MotionCtrl);

        tabWidget->setCurrentIndex(1);
        comboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MotionCtrl);
    } // setupUi

    void retranslateUi(QWidget *MotionCtrl)
    {
        MotionCtrl->setWindowTitle(QApplication::translate("MotionCtrl", "MotionCtrl", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MotionCtrl", "Montior", nullptr));
        label->setText(QApplication::translate("MotionCtrl", "Control", nullptr));
        label_2->setText(QApplication::translate("MotionCtrl", "override", nullptr));
        lineEdit_override->setText(QApplication::translate("MotionCtrl", "20", nullptr));
        label_3->setText(QApplication::translate("MotionCtrl", "%", nullptr));
        checkBox_Enabled->setText(QApplication::translate("MotionCtrl", "Enabled", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MotionCtrl", "Control", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MotionCtrl: public Ui_MotionCtrl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOTIONCTRL_H
