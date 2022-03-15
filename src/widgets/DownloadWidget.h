#pragma once
#include <QWidget>

QT_BEGIN_NAMESPACE
class QTabWidget;
QT_END_NAMESPACE

class DownloadWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DownloadWidget(QWidget* parent = nullptr);
    ~DownloadWidget();

protected:


private:
    QTabWidget* tabWidget;

};