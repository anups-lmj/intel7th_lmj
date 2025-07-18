/********************************************************************************
** Form generated from reading UI file 'sqlite.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQLITE_H
#define UI_SQLITE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sqlite
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QDateTimeEdit *pTEFromTime;
    QDateTimeEdit *pTEToTime;
    QPushButton *pPBSerch;
    QPushButton *pPBDelete;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidget;
    QVBoxLayout *pSqlChartView;

    void setupUi(QWidget *Sqlite)
    {
        if (Sqlite->objectName().isEmpty())
            Sqlite->setObjectName("Sqlite");
        Sqlite->resize(715, 496);
        gridLayout = new QGridLayout(Sqlite);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pTEFromTime = new QDateTimeEdit(Sqlite);
        pTEFromTime->setObjectName("pTEFromTime");
        pTEFromTime->setDateTime(QDateTime(QDate(2025, 7, 17), QTime(0, 0, 0)));

        horizontalLayout->addWidget(pTEFromTime);

        pTEToTime = new QDateTimeEdit(Sqlite);
        pTEToTime->setObjectName("pTEToTime");
        pTEToTime->setDateTime(QDateTime(QDate(2025, 7, 18), QTime(0, 0, 0)));

        horizontalLayout->addWidget(pTEToTime);

        pPBSerch = new QPushButton(Sqlite);
        pPBSerch->setObjectName("pPBSerch");

        horizontalLayout->addWidget(pPBSerch);

        pPBDelete = new QPushButton(Sqlite);
        pPBDelete->setObjectName("pPBDelete");

        horizontalLayout->addWidget(pPBDelete);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        tableWidget = new QTableWidget(Sqlite);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName("tableWidget");

        horizontalLayout_2->addWidget(tableWidget);

        pSqlChartView = new QVBoxLayout();
        pSqlChartView->setObjectName("pSqlChartView");

        horizontalLayout_2->addLayout(pSqlChartView);

        horizontalLayout_2->setStretch(0, 5);
        horizontalLayout_2->setStretch(1, 5);

        verticalLayout_3->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(Sqlite);

        QMetaObject::connectSlotsByName(Sqlite);
    } // setupUi

    void retranslateUi(QWidget *Sqlite)
    {
        Sqlite->setWindowTitle(QCoreApplication::translate("Sqlite", "Form", nullptr));
        pPBSerch->setText(QCoreApplication::translate("Sqlite", "\354\241\260\355\232\214", nullptr));
        pPBDelete->setText(QCoreApplication::translate("Sqlite", "\354\202\255\354\240\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Sqlite", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Sqlite", "\353\202\240\354\247\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Sqlite", "\354\241\260\353\217\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Sqlite", "\354\230\250\353\217\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Sqlite", "\354\212\265\353\217\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sqlite: public Ui_Sqlite {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQLITE_H
