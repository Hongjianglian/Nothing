#pragma once
#include <QWidget>

QT_BEGIN_NAMESPACE
class QPushButton;
QT_END_NAMESPACE

/// <summary>
/// 主窗体右上角的按钮组，包括最小化、最大化、退出
/// </summary>
class RightTopButton : public QWidget
{
    Q_OBJECT

public:
    explicit RightTopButton(QWidget* parent = nullptr);
    ~RightTopButton();




protected:


public:
    QPushButton* _btnMini;   // 最小化
    QPushButton* _btnMax;    // 最大化
    QPushButton* _btnQuit;   // 退出

};