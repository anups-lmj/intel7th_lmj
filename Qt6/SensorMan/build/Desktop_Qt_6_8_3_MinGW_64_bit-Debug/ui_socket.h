/********************************************************************************
** Form generated from reading UI file 'socket.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOCKET_H
#define UI_SOCKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Socket
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *pPBDelete;
    QPushButton *pPBConnect;
    QTextEdit *pTERecvData;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *pLEId;
    QLineEdit *pLESend;
    QPushButton *pPBSendToId;

    void setupUi(QWidget *Socket)
    {
        if (Socket->objectName().isEmpty())
            Socket->setObjectName("Socket");
        Socket->resize(646, 495);
        gridLayout = new QGridLayout(Socket);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(Socket);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        pPBDelete = new QPushButton(Socket);
        pPBDelete->setObjectName("pPBDelete");

        horizontalLayout->addWidget(pPBDelete);

        pPBConnect = new QPushButton(Socket);
        pPBConnect->setObjectName("pPBConnect");
        pPBConnect->setCheckable(true);
        pPBConnect->setChecked(false);

        horizontalLayout->addWidget(pPBConnect);

        horizontalLayout->setStretch(0, 8);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        pTERecvData = new QTextEdit(Socket);
        pTERecvData->setObjectName("pTERecvData");

        verticalLayout->addWidget(pTERecvData);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pLEId = new QLineEdit(Socket);
        pLEId->setObjectName("pLEId");

        horizontalLayout_2->addWidget(pLEId);

        pLESend = new QLineEdit(Socket);
        pLESend->setObjectName("pLESend");

        horizontalLayout_2->addWidget(pLESend);

        pPBSendToId = new QPushButton(Socket);
        pPBSendToId->setObjectName("pPBSendToId");

        horizontalLayout_2->addWidget(pPBSendToId);

        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 2);

        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(verticalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Socket);
        QObject::connect(pLEId, &QLineEdit::returnPressed, pPBSendToId, qOverload<>(&QPushButton::click));

        QMetaObject::connectSlotsByName(Socket);
    } // setupUi

    void retranslateUi(QWidget *Socket)
    {
        Socket->setWindowTitle(QCoreApplication::translate("Socket", "Form", nullptr));
        label->setText(QCoreApplication::translate("Socket", "\354\210\230\354\213\240 \353\215\260\354\235\264\355\204\260", nullptr));
        pPBDelete->setText(QCoreApplication::translate("Socket", "\354\210\230\354\213\240 \354\202\255\354\240\234", nullptr));
        pPBConnect->setText(QCoreApplication::translate("Socket", "\354\204\234\353\262\204 \354\227\260\352\262\260", nullptr));
        pPBSendToId->setText(QCoreApplication::translate("Socket", "\354\206\241\354\213\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Socket: public Ui_Socket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOCKET_H
