/********************************************************************************
** Form generated from reading UI file 'sensor.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSOR_H
#define UI_SENSOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sensor
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *pTabSensor;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pPBClear;
    QVBoxLayout *pChartViewLayout;

    void setupUi(QWidget *Sensor)
    {
        if (Sensor->objectName().isEmpty())
            Sensor->setObjectName("Sensor");
        Sensor->resize(596, 476);
        gridLayout = new QGridLayout(Sensor);
        gridLayout->setObjectName("gridLayout");
        pTabSensor = new QVBoxLayout();
        pTabSensor->setObjectName("pTabSensor");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pPBClear = new QPushButton(Sensor);
        pPBClear->setObjectName("pPBClear");

        horizontalLayout->addWidget(pPBClear);

        horizontalLayout->setStretch(0, 9);
        horizontalLayout->setStretch(1, 1);

        pTabSensor->addLayout(horizontalLayout);

        pChartViewLayout = new QVBoxLayout();
        pChartViewLayout->setObjectName("pChartViewLayout");

        pTabSensor->addLayout(pChartViewLayout);

        pTabSensor->setStretch(0, 1);
        pTabSensor->setStretch(1, 9);

        gridLayout->addLayout(pTabSensor, 0, 0, 1, 1);


        retranslateUi(Sensor);

        QMetaObject::connectSlotsByName(Sensor);
    } // setupUi

    void retranslateUi(QWidget *Sensor)
    {
        Sensor->setWindowTitle(QCoreApplication::translate("Sensor", "Form", nullptr));
        pPBClear->setText(QCoreApplication::translate("Sensor", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sensor: public Ui_Sensor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSOR_H
