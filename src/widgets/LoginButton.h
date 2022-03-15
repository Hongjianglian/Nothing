#pragma once

#include <QWidget>
#include <QPixmap>
#include <QLabel>

/// <summary>
/// 登录按钮，同时用于显示头像
/// </summary>
class LoginButton : public QWidget
{
    Q_OBJECT

public:
    explicit LoginButton(QWidget* parent = NULL);
    ~LoginButton();

protected:
    virtual void paintEvent(QPaintEvent* event);

    virtual void mouseReleaseEvent(QMouseEvent* event);
signals:
    void clicked();

public slots:
    void on_btn_clicked();
private:
    QPixmap _avatar;  // 头像
    int avatar_width = 100;
    int avatar_height = 100;


    QWidget* _parent;


    bool bIsOnline;  // 是否已经是登录状态

};