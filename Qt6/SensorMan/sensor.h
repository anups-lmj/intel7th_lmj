#ifndef SENSOR_H
#define SENSOR_H

#include <QWidget>
#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
#include <QChartView>
#include <QLineSeries>
#include <QDateTimeAxis>
#include <QValueAxis>
#else
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>
QT_CHARTS_USE_NAMESPACE
#endif
#include <QDate>
#include <QTime>
#include <QDebug>

namespace Ui {
class Sensor;
}

class Sensor : public QWidget
{
    Q_OBJECT
public:
    explicit Sensor(QWidget *parent = nullptr);
    ~Sensor();

private:
    Ui::Sensor *ui;
    QLineSeries *illuLine;
    QLineSeries *tempLine;
    QLineSeries *humiLine;
    QChart *pQChart;
    QChartView *pQChartView;
    QDateTimeAxis *pQDateTimeAxisX;
    QDateTime firstDateTime;
    QDateTime lastDateTime;

    void updateLastDateTime(bool bFlag);

private slots:
    void tab4RecvDataSlot(QString);
    void on_pPBClear_clicked();
};


#endif // SENSOR_H
