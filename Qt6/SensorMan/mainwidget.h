#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "socket.h"
#include "sensor.h"
#include "sqlite.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class mainWidget;
}
QT_END_NAMESPACE

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = nullptr);
    ~mainWidget();

private:
    Ui::mainWidget *ui;

    Socket *pSocket;
    Sensor *pSensor;
    Sqlite *pSqlite;
};
#endif // MAINWIDGET_H
