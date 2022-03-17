#include "ServerTest.h"
#include <QDialog>
#include <QString>
#include "ui_ServerTest.h"
#include <QHostAddress>
#include <QMessageBox>


ServerTest::ServerTest(QWidget* parent)
    : QDialog(parent)
{
    ui = new Ui::Dialog;
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &ServerTest::onBtnClicked);

}

void ServerTest::onBtnClicked()
{
    QString ip = ui->ip->text();
    QString port = ui->port->text();

    if (!ip.isEmpty() && !port.isEmpty())
    {
        socket = new QTcpSocket(this);
        QHostAddress* serverIP = new QHostAddress();

        if (!serverIP->setAddress(ip))//用这个函数判断IP地址是否可以被正确解析
        {
            QMessageBox::warning(this, "错误", "IP地址格式不正确");
            return;
        }
        socket->connectToHost(*serverIP, port.toInt());
        connect(socket, &QTcpSocket::connected, this, &ServerTest::onSuccessConn);
    }
}

void ServerTest::onSuccessConn()
{
    qDebug() << "成功连接......................";
}