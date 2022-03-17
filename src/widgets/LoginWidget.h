#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QCheckBox;
class QLineEdit;
QT_END_NAMESPACE


/// <summary>
/// 登录对话框
/// </summary>
class LoginWidget: public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget* parent = NULL);
    ~LoginWidget();

public slots:
    void onBtnQuitClicked();

protected:

private:
    QPushButton* _btnQuit;   // 退出

    QWidget* _topPanel;  // 用于放置占位widget、_btnQuit
    QLabel* _backup; // 占位widget，位于_btnQuit左侧


    QLineEdit* _userName;
    QLineEdit* _password;

    //QPushButton* _btnToListUserName;   // 用于列出曾经登录过的用户名
    //QPushButton* _btnMaskPassword;     // 隐藏密码

    QPushButton* _btnLogin;



};