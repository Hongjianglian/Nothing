#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
class QPushButton;
class QListWidget;
QT_END_NAMESPACE


class LoginButton;
class NothingListWidget;

/// <summary>
/// 主窗口左侧导航栏，包括头像框, 下载、论坛的ListWidget
/// </summary>
class LeftBar : public QWidget
{
    Q_OBJECT

public:
    explicit LeftBar(QWidget* parent = 0);
    ~LeftBar();

    QSize sizeHint() const override;
protected:


private:
    LoginButton* btn_avatar;

    NothingListWidget* listWidget;
};