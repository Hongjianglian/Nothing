#pragma once

#include <QDialog>
#include <QTcpSocket>

namespace Ui
{
    class Dialog;
}


class ServerTest : public QDialog
{
    Q_OBJECT
public:
    ServerTest(QWidget* parent = nullptr);
    ~ServerTest() = default;

public slots:
    void onBtnClicked();

    void onSuccessConn();


private:
    Ui::Dialog* ui;
    QTcpSocket* socket;
};