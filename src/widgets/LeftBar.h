#pragma once

#include <QWidget>


class QPushButton;
class LoginButton;
class QListWidget;

class LeftBar : public QWidget
{
    Q_OBJECT

public:
    explicit LeftBar(QWidget* parent = 0);
    ~LeftBar();

protected:


private:
    LoginButton* btn_avatar;
    QPushButton* btn_download;
    QPushButton* btn_forum;


    QListWidget* listWidget;

};