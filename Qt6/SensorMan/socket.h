#ifndef SOCKET_H
#define SOCKET_H

#include <QWidget>
#include <QDebug>
#include <QTime>
#include <QLineEdit>
#include "socketclient.h"
#include "keyboard.h"
namespace Ui {
class Socket;
}

class Socket : public QWidget
{
    Q_OBJECT

public:
    explicit Socket(QWidget *parent = nullptr);
    SocketClient * getpSocketClient();
    ~Socket();

private slots:
    void on_pPBConnect_toggled(bool checked);
    void updateRecvDataSlot(QString);
    void socketSendToLinux(int);
    void on_pPBDelete_clicked();
    void on_pPBSendToId_clicked();
    void on_pLESend_selectionChanged();
    void on_pLEId_selectionChanged();

signals:
    void ledWriteSig(int);
    void tab3RecvDataSig(QString);
    void tab4RecvDataSig(QString);
    void tab5RecvDataSig(QString);
private:
    Ui::Socket *ui;
    SocketClient *pSocketClient;
    Keyboard *pKeyBoard;
};

#endif // SOCKET_H
