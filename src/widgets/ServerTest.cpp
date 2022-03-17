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

        if (!serverIP->setAddress(ip))//����������ж�IP��ַ�Ƿ���Ա���ȷ����
        {
            QMessageBox::warning(this, "����", "IP��ַ��ʽ����ȷ");
            return;
        }
        socket->connectToHost(*serverIP, port.toInt());
        connect(socket, &QTcpSocket::connected, this, &ServerTest::onSuccessConn);
    }
}

void ServerTest::onSuccessConn()
{
    qDebug() << "�ɹ�����......................";
}