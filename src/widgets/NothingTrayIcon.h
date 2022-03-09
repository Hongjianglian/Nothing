#pragma once

#include <QSystemTrayIcon>


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