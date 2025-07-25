#include "sqlite.h"
#include "ui_sqlite.h"

Sqlite::Sqlite(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Sqlite)
{
    ui->setupUi(this);
    qSqlDatabase = QSqlDatabase::addDatabase("QSQLITE");
    qSqlDatabase.setDatabaseName("aiot.db");
    if(qSqlDatabase.open())
        qDebug() << "Success DB Connection";
    else
        qDebug() << "Fail DB Connection";
    QString strQuery = "create table sensor_tb ("
                       "name varchar(10),"
                       "date DATETIME primary key,"
                       "illu varchar(10),"
                       "temp float(10),"
                       "humi float(10))";
    QSqlQuery sqlQuery;
    if(sqlQuery.exec(strQuery))
        qDebug() << "Create Table";


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
    pQChart->axes(Qt::Vertical).constFirst()->setRange(0, 100);

    pQChartView = new QChartView(pQChart);
    pQChartView->setRenderHint(QPainter::Antialiasing);

    ui->pSqlChartView->layout()->addWidget(pQChartView);
    pQDateTimeAxisX = new QDateTimeAxis;
    pQDateTimeAxisX->setFormat("hh:mm");
    //    pQDateTimeAxisX->setFormat("MM-dd hh:mm");

    updateLastDateTime(0);
    pQChartView->chart()->setAxisX(pQDateTimeAxisX,illuLine);
    pQChartView->chart()->setAxisX(pQDateTimeAxisX,tempLine);
    pQChartView->chart()->setAxisX(pQDateTimeAxisX,humiLine);

}

Sqlite::~Sqlite()
{
    delete ui;
}


void Sqlite::updateLastDateTime(bool bFlag)
{
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();

    firstDateTime.setDate(date);
    firstDateTime.setTime(time);

    lastDateTime.setDate(date);
    QTime tempTime = time.addSecs(10*60);  //10분
    lastDateTime.setTime(tempTime);

    pQDateTimeAxisX->setRange(firstDateTime,lastDateTime);
}

void Sqlite::tab5RecvDataSlot(QString recvData)
{

    QDateTime dateTime = QDateTime::currentDateTime();
    QStringList strList = recvData.split("@");   //recvData : [SENSIRID]SENSOR@조도@온도@습도
    QString name = strList[1];
    QString illu  = strList[3];     //조도
    QString temp = strList[4];
    QString humi = strList[5];
    //    illuLine->append(dateTime.toMSecsSinceEpoch(),illu.toInt());
    //qDebug() << illu ;

    QString strQuery = "insert into sensor_tb(name, date, illu, temp, humi) values('" + name + "', '" + dateTime.toString("yyyy/MM/dd hh:mm:ss") + "' , '" + illu + "' , '" + temp + "' , '" + humi + "')";
    QSqlQuery sqlQuery;
    if(sqlQuery.exec(strQuery))
        qDebug() << "Insert Query Ok";

}

void Sqlite::updateLastDateTimeSql(bool bFlag)
{
    QDateTime fromDateTime = ui->pTEFromTime->dateTime();
    QString strFromDateTime = fromDateTime.toString("yyyy/MM/dd hh:mm:ss");
    QDateTime toDateTime = ui->pTEToTime->dateTime();
    QString strToDateTime = toDateTime.toString("yyyy/MM/dd hh:mm:ss");

    QString strQuery = "select * from sensor_tb where '" + strFromDateTime + "' <= date AND date <= '" + strToDateTime + "'";
    QSqlQuery sqlQuery;
    if(sqlQuery.exec(strQuery))
    {
        sqlQuery.first();
        firstDateTime = QDateTime::fromString(sqlQuery.value("date").toString(), "yyyy/MM/dd hh:mm:ss");
        sqlQuery.last();
        lastDateTime = QDateTime::fromString(sqlQuery.value("date").toString(), "yyyy/MM/dd hh:mm:ss");
    }
    if(!firstDateTime.isValid())
        firstDateTime = QDateTime::fromString(strFromDateTime, "yyyy/MM/dd hh:mm:ss");
    if(!lastDateTime.isValid())
        lastDateTime = QDateTime::fromString(strToDateTime, "yyyy/MM/dd hh:mm:ss");
    pQDateTimeAxisX->setRange(firstDateTime,lastDateTime);
}

void Sqlite::on_pPBSerch_clicked()
{
    QDateTime fromDateTime = ui->pTEFromTime->dateTime();
    QString strFromDateTime = fromDateTime.toString("yyyy/MM/dd hh:mm:ss");
    QDateTime toDateTime = ui->pTEToTime->dateTime();
    QString strToDateTime = toDateTime.toString("yyyy/MM/dd hh:mm:ss");

    //    ui->pTBsensor->clearContents();
    //    on_pPBClearChart_clicked();
    updateLastDateTimeSql(0);
    illuLine->clear();

    QString strQuery = "select * from sensor_tb where '" + strFromDateTime + "'  <= date and date <= '" + strToDateTime + "' ";
    QSqlQuery sqlQuery;
    if(sqlQuery.exec(strQuery))
    {
        int rowCount=0;
        qDebug() << "Select Query Ok";
        while(sqlQuery.next())
            rowCount++;

        if(pQTableWidgetItemId != nullptr)
        {
            delete [] pQTableWidgetItemId;
            delete [] pQTableWidgetItemDate;
            delete [] pQTableWidgetItemIllu;
            delete [] pQTableWidgetItemTemp;
            delete [] pQTableWidgetItemHumi;
        }

        pQTableWidgetItemId = new QTableWidgetItem[rowCount];
        pQTableWidgetItemDate = new QTableWidgetItem[rowCount];
        pQTableWidgetItemIllu = new QTableWidgetItem[rowCount];
        pQTableWidgetItemTemp = new QTableWidgetItem[rowCount];
        pQTableWidgetItemHumi = new QTableWidgetItem[rowCount];

        rowCount=0;
        sqlQuery.first();
        while(sqlQuery.next())
        {
            ui->tableWidget->setRowCount(rowCount+1);

            (pQTableWidgetItemId+rowCount)->setText(sqlQuery.value("name").toString());
            (pQTableWidgetItemDate+rowCount)->setText(sqlQuery.value("date").toString());
            (pQTableWidgetItemIllu+rowCount)->setText(sqlQuery.value("illu").toString());
            (pQTableWidgetItemTemp+rowCount)->setText(sqlQuery.value("temp").toString());
            (pQTableWidgetItemHumi+rowCount)->setText(sqlQuery.value("humi").toString());

            ui->tableWidget->setItem(rowCount,0, (pQTableWidgetItemId+rowCount));
            ui->tableWidget->setItem(rowCount,1, (pQTableWidgetItemDate+rowCount));
            ui->tableWidget->setItem(rowCount,2, (pQTableWidgetItemIllu+rowCount));
            ui->tableWidget->setItem(rowCount,3, (pQTableWidgetItemTemp+rowCount));
            ui->tableWidget->setItem(rowCount,4, (pQTableWidgetItemHumi+rowCount));

            QDateTime xValue = QDateTime::fromString((pQTableWidgetItemDate+rowCount)->text(), "yyyy/MM/dd hh:mm:ss");
            illuLine->append(xValue.toMSecsSinceEpoch(),(pQTableWidgetItemIllu+rowCount)->text().toInt());
            tempLine->append(xValue.toMSecsSinceEpoch(),(pQTableWidgetItemTemp+rowCount)->text().toFloat());
            humiLine->append(xValue.toMSecsSinceEpoch(),(pQTableWidgetItemHumi+rowCount)->text().toFloat());
            rowCount++;
        }
        ui->tableWidget->resizeColumnToContents(0);
        ui->tableWidget->resizeColumnToContents(1);
        ui->tableWidget->resizeColumnToContents(2);
    }
}


void Sqlite::on_pPBDelete_clicked()
{
    QDateTime fromDateTime = ui->pTEFromTime->dateTime();
    QString strFromDateTime = fromDateTime.toString("yyyy/MM/dd hh:mm:ss");
    QDateTime toDateTime = ui->pTEToTime->dateTime();
    QString strToDateTime = toDateTime.toString("yyyy/MM/dd hh:mm:ss");

    QString strQuery = "delete from sensor_tb where '" + strFromDateTime + "' <= date AND date <= '" + strToDateTime + "'";
    QSqlQuery sqlQuery;
    if(!sqlQuery.exec(strQuery))
        qDebug() << "Delete Query Ok";
    \
        //  ui->pTBsensor->clearContents();
        illuLine->clear();
    tempLine->clear();
    humiLine->clear();
}

