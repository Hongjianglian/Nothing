#pragma once
#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
class QProgressBar;
class QPushButton;
QT_END_NAMESPACE

class DownloadingItem : public QWidget
{
    Q_OBJECT

public:
    explicit DownloadingItem(QWidget* parent = nullptr);
    ~DownloadingItem();

protected:

private:
    QLabel* _fileIcon;              // 文件图标
    QLabel* _fileName;              // 文件名
    QPushButton* _downloadCtrl;     // 下载控制按钮

    QProgressBar* _progressBar;     // 进度条
    QLabel* _fileSize;              // 文件大小
    QLabel* _restTime;              // 剩余时间
    QLabel* _speed;                 // 下载速度
};