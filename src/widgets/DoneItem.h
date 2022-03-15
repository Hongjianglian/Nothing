#pragma once
#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
QT_END_NAMESPACE


class DoneItem : public QWidget
{
    Q_OBJECT

public:
    explicit DoneItem(QWidget* parent = nullptr);
    ~DoneItem();

protected:

private:
    QLabel* _fileIcon;              // 文件图标
    QLabel* _fileName;              // 文件名
    QPushButton* _btnPlay;          // 播放按钮

    QLabel* _fileSize;              // 文件大小
    QLabel* _time;                  // 下载完成时间
    QLabel* _fileState;             // 文件状态（是否已被删除或移动），该信息默认隐藏
};