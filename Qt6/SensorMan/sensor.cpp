#include "sensor.h"
#include "ui_sensor.h"

Sensor::Sensor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Sensor)
{
    ui->setupUi(this);
    illuLine = new QLineSeries(this);
    illuLine->setName("조도");
    tempLine = new QLineSeries(this);
    tempLine->setName("온도");
    humiLine = new QLineSeries(this);
    humiLine->setName("습도");

    QPen pen;
    pen.setWidth(2);
    pen.setBrush(Qt::red);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::MiterJoin);
    illuLine->setPen(pen);

    pen.setBrush(Qt::green);
    tempLine->setPen(pen);

    pen.setBrush(Qt::blue);
    humiLine->setPen(pen);

    pQChart = new QChart();
    pQChart->addSeries(illuLine);
    pQChart->addSeries(tempLine);
    pQChart->addSeries(humiLine);
    pQChart->createDefaultAxes();
    pQChart->axes(Qt::Vertical).constFirst()->setRange(0,100);

    pQChartView = new QChartView(pQChart);
    pQChartView->setRenderHint(QPainter::Antialiasing);

    ui->pChartViewLayout->layout()->addWidget(pQChartView);
    pQDateTimeAxisX  = new QDateTimeAxis;
    pQDateTimeAxisX->setFormat("hh:mm:ss");

    updateLastDateTime(0);
    pQChartView->chart()->setAxisX(pQDateTimeAxisX,illuLine);
    pQChartView->chart()->setAxisX(pQDateTimeAxisX,tempLine);
    pQChartView->chart()->setAxisX(pQDateTimeAxisX,humiLine);
}
void Sensor::updateLastDateTime(bool bFlag)
{
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();

    firstDateTime.setDate(date);
    firstDateTime.setTime(time);

    lastDateTime.setDate(date);
    QTime tempTime = time.addSecs(60*5); //10분
    lastDateTime.setTime(tempTime);


    pQDateTimeAxisX->setRange(firstDateTime,lastDateTime);
}
Sensor::~Sensor()
{
    delete ui;
}
void Sensor::tab4RecvDataSlot(QString recvData)
{
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    if(time>=lastDateTime.time())
    {
        //time = time.addSecs(60*5);
        lastDateTime.setTime(time);
        pQDateTimeAxisX->setRange(firstDateTime,lastDateTime);
    }
    QDateTime xValue;
    xValue.setDate(date);
    xValue.setTime(time);

    QStringList strList = recvData.split("@"); //[SENSORID]:SNESOR@조도@온도@습도 형태로 수신
    QString illu = strList[3]; //조도
    QString temp = strList[4]; //온도
    QString humi = strList[5]; //습도
    illuLine->append(xValue.toMSecsSinceEpoch(),illu.toInt());
    tempLine->append(xValue.toMSecsSinceEpoch(),temp.toDouble());
    humiLine->append(xValue.toMSecsSinceEpoch(),humi.toDouble());
}

void Sensor::on_pPBClear_clicked()
{
    illuLine->clear();
    tempLine->clear();
    humiLine->clear();
    updateLastDateTime(0);
}

