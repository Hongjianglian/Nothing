#pragma execution_character_set("utf-8") 
#include "LeftBar.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <QListWidget>
#include <QFont>

#include "utils/NothingStyleHelper.h"
#include "widgets/LoginButton.h"
#include "widgets/NothingListWidget.h"

LeftBar::LeftBar(QWidget* parent):
    QWidget(parent)
{
    setMinimumSize(200,800);
    setMaximumWidth(300);

    setContentsMargins(0, 0, 0, 0);


    QPalette pal(palette());

    //设置背景黑色
    pal.setColor(QPalette::Background, QColor(34, 37, 48));
    setAutoFillBackground(true);
    setPalette(pal);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    
    btn_avatar = new LoginButton(this);
    QHBoxLayout* avatarLayout = new QHBoxLayout;
    avatarLayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Expanding));
    avatarLayout->addWidget(btn_avatar);
    avatarLayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Expanding));
    
    listWidget = new NothingListWidget;
    listWidget->setFont(QFont("Microsoft YaHei"));
    // 下载
    QListWidgetItem* downloadItem = new QListWidgetItem("DOWNLOAD", listWidget);
    QVariantMap downloadOption;
    downloadOption.insert("color", QColor(Qt::green));
    downloadItem->setIcon(Utils::awesome()->icon(fa::download, downloadOption));
    // 论坛
    QListWidgetItem* forumItem = new QListWidgetItem("FORUM", listWidget);
    QVariantMap forumOption;
    forumOption.insert("color", QColor(Qt::green));
    //forumOption.insert("color-off", QColor(Qt::red));

    forumItem->setIcon(Utils::awesome()->icon(fa::forumbee, forumOption));

    listWidget->setItemHeight(60);

    listWidget->setCurrentRow(0);

    mainLayout->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Expanding));
    mainLayout->addLayout(avatarLayout);
    mainLayout->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Expanding));
    mainLayout->addWidget(listWidget);
}

QSize LeftBar::sizeHint() const
{
    return QSize(300, 800);
}

LeftBar::~LeftBar()
{

}