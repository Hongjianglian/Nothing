#include "NothingTrayIcon.h"

#include <QApplication>
#include <QWidget>
#include <QDebug>

NothingTrayIcon::NothingTrayIcon(const QIcon& icon, QObject* parent)
    : QSystemTrayIcon(icon, parent)
{
    connect(this, SIGNAL(messageClicked()), SLOT(onMessageClicked()));
}

NothingTrayIcon::~NothingTrayIcon()
{
}

void NothingTrayIcon::showMessage(const QString& title, const QString& msg, QSystemTrayIcon::MessageIcon icon, int msecs)
{
    // TODO: 托盘的气泡消息显示不出来，原因未知。
    QSystemTrayIcon::showMessage(title, msg, icon, msecs);
}

void NothingTrayIcon::onMessageClicked()
{
}