#pragma once
#include <QWidget>

QT_BEGIN_NAMESPACE
class QListWidget;
QT_END_NAMESPACE

class DownloadingTab : public QWidget
{
    Q_OBJECT

public:
    explicit DownloadingTab(QWidget* parent = nullptr);
    ~DownloadingTab();

protected:

private:
    QListWidget* _listWidget;
};