#include "socket.h"
#include "ui_socket.h"

Socket::Socket(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Socket)
{
    ui->setupUi(this);
    pKeyBoard = new Keyboard();
    ui->pPBSendToId->setEnabled(false);
    pSocketClient = new SocketClient(this);
    connect(pSocketClient, SIGNAL(socketRecvDataSig(QString)),this, SLOT(updateRecvDataSlot(QString)));
}

Socket::~Socket()
{
    delete ui;
}

void Socket::on_pPBConnect_toggled(bool checked)
{
    bool bFlag;
    if(checked)
    {
        pSocketClient->connectToServerSlot(bFlag);
        if(bFlag)
        {
            ui->pPBConnect->setText("서버 해제");
            ui->pPBSendToId->setEnabled(true);
        }
    }
    else {
        pSocketClient->socketClosedServerSlot();
        ui->pPBConnect->setText("서버 연결");
        ui->pPBSendToId->setEnabled(false);
    }
}

void Socket::updateRecvDataSlot(QString strRecvData)
{
    strRecvData.chop(1);   //끝문자 한개 "\n" 제거
    QTime time = QTime::currentTime();
    QString strTime = time.toString();
    strTime = strTime + " " + strRecvData;
    ui->pTERecvData->append(strTime);

    //[KSH_QT]@LED@0xff  ==> @KSH_QT@LED@0xff
    strRecvData.replace("[","@");
    strRecvData.replace("]","@");
    QStringList strList = strRecvData.split("@");
    if(strList[2].indexOf("LED") == 0)
    {
        bool bFlag;
        int ledNo = strList[3].toInt(&bFlag,16);
        if(bFlag)
            emit ledWriteSig(ledNo);
    }
    else if((strList[2].indexOf("LAMP") == 0) || (strList[2].indexOf("PLUG") == 0) || (strList[2].indexOf("GAS") == 0))
    {
        emit tab3RecvDataSig(strRecvData);
    }
    else if(strList[2].indexOf("SENSOR") == 0)
    {
        emit tab4RecvDataSig(strRecvData);
        emit tab5RecvDataSig(strRecvData);
    }
}

void Socket::socketSendToLinux(int keyNo)
{
    pSocketClient->socketWriteDataSlot("[KSH_LIN]KEY@"+QString::number(keyNo));
}

SocketClient * Socket::getpSocketClient()
{
    return pSocketClient;
}



void Socket::on_pPBDelete_clicked()
{
    ui->pTERecvData->clear();
}


void Socket::on_pPBSendToId_clicked()
{
    QString strRecvId = ui->pLEId->text();
    QString strSendData = ui->pLESend->text();
    if(strRecvId.isEmpty())
    {
        strSendData = "[ALLMSG]" + strSendData;
    }
    else
    {
        strSendData = "["+strRecvId+"]" + strSendData;
    }
    pSocketClient->socketWriteDataSlot(strSendData);
    ui->pLESend->clear();
}


void Socket::on_pLESend_selectionChanged()
{
    QLineEdit *pQLineEdit = (QLineEdit *)sender();
    pKeyBoard->setLineEdit(pQLineEdit);
    pKeyBoard->show();
}


void Socket::on_pLEId_selectionChanged()
{
    QLineEdit *pQLineEdit = (QLineEdit *)sender();
    pKeyBoard->setLineEdit(pQLineEdit);
    pKeyBoard->show();
}



