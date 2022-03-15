#pragma execution_character_set("utf-8") 

#include "DoneTab.h"

#include <QListWidget>
#include <QVBoxLayout>

#include "DoneItem.h"

DoneTab::DoneTab(QWidget* parent)
    : QWidget(parent)
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    _listWidget = new QListWidget;

    DoneItem* doneItem1 = new DoneItem;
    DoneItem* doneItem2 = new DoneItem;

    QListWidgetItem* item1 = new QListWidgetItem;
    QListWidgetItem* item2 = new QListWidgetItem;

    item1->setSizeHint(QSize(400, 100));
    item2->setSizeHint(QSize(400, 100));

    _listWidget->addItem(item1);
    _listWidget->addItem(item2);

    _listWidget->setItemWidget(item1, doneItem1);
    _listWidget->setItemWidget(item2, doneItem2);

    mainLayout->addWidget(_listWidget);
}

DoneTab::~DoneTab()
{
}