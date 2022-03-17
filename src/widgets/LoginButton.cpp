#pragma execution_character_set("utf-8") 
#include "LoginButton.h"
#include <QPainter>
#include <QMessageBox>
#include <QMouseEvent>

#include "LoginWidget.h"
#include "ServerTest.h"

LoginButton::LoginButton(QWidget* parent) :
    QWidget(parent),
    _parent(parent),
    _avatar(QPixmap(":/avatar.png")),
    bIsOnline(false)
{
    _avatar.scaled(avatar_width, avatar_height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    setFixedSize(100, 100);
   //setMaximumSize(100, 100);
    connect(this, SIGNAL(clicked()), SLOT(on_btn_clicked()));

}

LoginButton::~LoginButton()
{
}

void LoginButton::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.drawPixmap(QRect(0, 0, avatar_width, avatar_height), _avatar);
}

void LoginButton::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit clicked();
    }
    QWidget::mouseReleaseEvent(event);
}

void LoginButton::on_btn_clicked()
{
    if (!bIsOnline)
    {
        //LoginWidget* dialog = new LoginWidget;
        //dialog->setWindowModality(Qt::ApplicationModal);
        //dialog->show();

        ServerTest* dlg = new ServerTest;
        dlg->show();
    }
}