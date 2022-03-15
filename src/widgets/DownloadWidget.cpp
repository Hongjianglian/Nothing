#pragma execution_character_set("utf-8") 

#include "DownloadWidget.h"

#include <QTabWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTabBar>

#include "DownloadingTab.h"
#include "DoneTab.h"


DownloadWidget::DownloadWidget(QWidget* parent)
    : QWidget(parent)
{
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setMargin(0);

    tabWidget = new QTabWidget(this);
    DownloadingTab* downloadingTab = new DownloadingTab; 
    DoneTab* doneTab = new DoneTab;

    tabWidget->addTab(downloadingTab, "下载中");
    tabWidget->addTab(doneTab, "已完成");
    tabWidget->setTabShape(QTabWidget::TabShape::Triangular);
    tabWidget->setStyleSheet("QTabBar::tab { height: 35px; width:150px; padding: 0px;}");

    mainLayout->addWidget(tabWidget);
}
DownloadWidget::~DownloadWidget()
{
}