#pragma execution_character_set("utf-8") 

#include "DownloadingTab.h"
#include "DownloadingItem.h"

#include <QListWidget>
#include <QVBoxLayout>

DownloadingTab::DownloadingTab(QWidget* parent)
    : QWidget(parent)
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    _listWidget = new QListWidget;

    DownloadingItem* downloadItem1 = new DownloadingItem;
    DownloadingItem* downloadItem2 = new DownloadingItem;

    QListWidgetItem* item1 = new QListWidgetItem;
    QListWidgetItem* item2 = new QListWidgetItem;

    item1->setSizeHint(QSize(400, 100));
    item2->setSizeHint(QSize(400, 100));

    _listWidget->addItem(item1);
    _listWidget->addItem(item2);

    _listWidget->setItemWidget(item1, downloadItem1);
    _listWidget->setItemWidget(item2, downloadItem2);


    mainLayout->addWidget(_listWidget);
}

DownloadingTab::~DownloadingTab()
{

}