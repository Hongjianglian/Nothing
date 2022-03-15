#pragma once

#include <QSystemTrayIcon>

/// <summary>
/// 托盘类，用于软件后台的托盘功能
/// </summary>
class NothingTrayIcon : public QSystemTrayIcon
{
    Q_OBJECT
public:
    NothingTrayIcon(const QIcon& icon, QObject* parent = 0);
    ~NothingTrayIcon();

public slots:
    void onMessageClicked();
    void showMessage(const QString& title, const QString& msg,
        QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::Information, int msecs = 10000);

};