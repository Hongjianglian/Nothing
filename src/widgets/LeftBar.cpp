#pragma execution_character_set("utf-8") 
#include "LeftBar.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <QListWidget>

#include "utils/NothingStyleHelper.h"
#include "widgets/LoginButton.h"

LeftBar::LeftBar(QWidget* parent):
    QWidget(parent)
{
    //QPalette pal = palette();
    //pal.setColor(QPalette::Window, QColor("#272727"));
    //pal.setColor(QPalette::Base, QColor("#272727"));
    //setPalette(pal);
    //setAutoFillBackground(true);
    //setStyleSheet("background-color: #448aff;");
    QVBoxLayout* layout = new QVBoxLayout(this);
    

    btn_avatar = new LoginButton(this);
    QHBoxLayout* hlayout = new QHBoxLayout;
    hlayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Expanding));
    hlayout->addWidget(btn_avatar);
    hlayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Expanding));



    btn_download = new QPushButton("下载");
    QVariantMap options_download;
    options_download.insert("anim", qVariantFromValue(new QtAwesome(btn_download)));
    btn_download->setIcon(Utils::awesome()->icon(fa::download, options_download));

    btn_forum = new QPushButton("论坛");
    QVariantMap options_forum;
    options_forum.insert("anim", qVariantFromValue(new QtAwesome(btn_forum)));
    btn_forum->setIcon(Utils::awesome()->icon(fa::forumbee, options_forum));

    listWidget = new QListWidget();
    listWidget->setFrameShape(QListWidget::NoFrame);
    QListWidgetItem* downloadItem = new QListWidgetItem();
    listWidget->addItem(downloadItem);
    QListWidgetItem* forumItem = new QListWidgetItem();
    listWidget->addItem(forumItem);
    listWidget->setItemWidget(downloadItem, btn_download);
    listWidget->setItemWidget(forumItem,btn_forum);
    layout->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Expanding));
    layout->addLayout(hlayout);
    layout->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Expanding));
    layout->addWidget(listWidget);



    setLayout(layout);


}

LeftBar::~LeftBar()
{

}