#pragma execution_character_set("utf-8") 

#include "DownloadingItem.h"

#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "utils/NothingStyleHelper.h"

DownloadingItem::DownloadingItem(QWidget* parent)
    : QWidget(parent)
{
    _fileName = new QLabel("C++ Primer(第五版)");
    _fileName->setAlignment(Qt::AlignCenter);

    QHBoxLayout* infoLayout = new QHBoxLayout;
    _fileSize = new QLabel(tr("11.2GB"), this);
    _restTime = new QLabel(tr("00:19:32"), this);
    _speed = new QLabel(tr("17.2MB/s"), this);
    _fileSize->setAlignment(Qt::AlignLeft);
    _restTime->setAlignment(Qt::AlignCenter);
    _speed->setAlignment(Qt::AlignRight);
    infoLayout->addWidget(_fileSize);
    infoLayout->addWidget(_restTime);
    infoLayout->addWidget(_speed);

    QVBoxLayout* layout = new QVBoxLayout;
    _progressBar = new QProgressBar(this);
    _progressBar->setValue(70);
    layout->addLayout(infoLayout);
    layout->addWidget(_progressBar);

    QVBoxLayout* midLayout = new QVBoxLayout;
    midLayout->addWidget(_fileName);
    midLayout->addLayout(layout);

    QHBoxLayout* mainLayout = new QHBoxLayout;
    _fileIcon = new QLabel(this);
    QIcon icon = Utils::awesome()->icon(fa::folder);
    QPixmap pixmap = icon.pixmap(icon.actualSize(QSize(64, 64)));
    _fileIcon->setPixmap(pixmap);
    _downloadCtrl = new QPushButton(this);
    _downloadCtrl->setFlat(true);
    _downloadCtrl->setIcon(Utils::awesome()->icon(fa::pause));

    mainLayout->addWidget(_fileIcon);
    mainLayout->addLayout(midLayout);
    mainLayout->addWidget(_downloadCtrl);

    setLayout(mainLayout);
}

DownloadingItem::~DownloadingItem()
{
}