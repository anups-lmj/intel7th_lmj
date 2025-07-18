/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *pTabWidget;
    QWidget *pTabSocket;
    QGridLayout *gridLayout;
    QWidget *pTabSensor;
    QWidget *pTabSqlite;

    void setupUi(QWidget *mainWidget)
    {
        if (mainWidget->objectName().isEmpty())
            mainWidget->setObjectName("mainWidget");
        mainWidget->resize(800, 600);
        verticalLayout = new QVBoxLayout(mainWidget);
        verticalLayout->setObjectName("verticalLayout");
        pTabWidget = new QTabWidget(mainWidget);
        pTabWidget->setObjectName("pTabWidget");
        pTabSocket = new QWidget();
        pTabSocket->setObjectName("pTabSocket");
        gridLayout = new QGridLayout(pTabSocket);
        gridLayout->setObjectName("gridLayout");
        pTabWidget->addTab(pTabSocket, QString());
        pTabSensor = new QWidget();
        pTabSensor->setObjectName("pTabSensor");
        pTabWidget->addTab(pTabSensor, QString());
        pTabSqlite = new QWidget();
        pTabSqlite->setObjectName("pTabSqlite");
        pTabWidget->addTab(pTabSqlite, QString());

        verticalLayout->addWidget(pTabWidget);


        retranslateUi(mainWidget);

        pTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mainWidget);
    } // setupUi

    void retranslateUi(QWidget *mainWidget)
    {
        mainWidget->setWindowTitle(QCoreApplication::translate("mainWidget", "mainWidget", nullptr));
        pTabWidget->setTabText(pTabWidget->indexOf(pTabSocket), QCoreApplication::translate("mainWidget", "Socket", nullptr));
        pTabWidget->setTabText(pTabWidget->indexOf(pTabSensor), QCoreApplication::translate("mainWidget", "Sensor", nullptr));
        pTabWidget->setTabText(pTabWidget->indexOf(pTabSqlite), QCoreApplication::translate("mainWidget", "Sqlite", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainWidget: public Ui_mainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
