#include "mainwidget.h"
#include "ui_mainwidget.h"

mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainWidget)
{
    ui->setupUi(this);
    pSocket = new Socket(ui->pTabSocket);
    pSocket->setLayout(pSocket->layout());

    pSensor = new Sensor(ui->pTabSensor);
    pSensor->setLayout(pSensor->layout());

    pSqlite = new Sqlite(ui->pTabSqlite);
    pSqlite->setLayout(pSqlite->layout());


    connect(pSocket, SIGNAL(tab4RecvDataSig(QString)), pSensor, SLOT(tab4RecvDataSlot(QString)));
    connect(pSocket, SIGNAL(tab5RecvDataSig(QString)), pSqlite, SLOT(tab5RecvDataSlot(QString)));

    ui->pTabWidget->setCurrentIndex(0);
}

mainWidget::~mainWidget()
{
    delete ui;
}
