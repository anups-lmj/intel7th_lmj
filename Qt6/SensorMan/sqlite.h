#ifndef SQLITE_H
#define SQLITE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
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
#include <QTableWidgetItem>
#include <QDebug>

namespace Ui {
class Sqlite;
}

class Sqlite : public QWidget
{
    Q_OBJECT

public:
    explicit Sqlite(QWidget *parent = nullptr);
    ~Sqlite();

private:
    Ui::Sqlite *ui;
    QSqlDatabase qSqlDatabase;
    QLineSeries *illuLine;
    QLineSeries *tempLine;
    QLineSeries *humiLine;
    QChart *pQChart;
    QChartView *pQChartView;
    QDateTimeAxis *pQDateTimeAxisX;
    QDateTime firstDateTime;
    QDateTime lastDateTime;


    QTableWidgetItem* pQTableWidgetItemId = nullptr;
    QTableWidgetItem* pQTableWidgetItemDate = nullptr;
    QTableWidgetItem* pQTableWidgetItemIllu = nullptr;
    QTableWidgetItem* pQTableWidgetItemTemp = nullptr;
    QTableWidgetItem* pQTableWidgetItemHumi = nullptr;

    void updateLastDateTime(bool);
    void updateLastDateTimeSql(bool);
private slots:
    void tab5RecvDataSlot(QString);
    void on_pPBSerch_clicked();
    void on_pPBDelete_clicked();
};


#endif // SQLITE_H
