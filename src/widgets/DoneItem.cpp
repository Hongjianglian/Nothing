#pragma execution_character_set("utf-8") 

#include "DoneItem.h"

#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "utils/NothingStyleHelper.h"


DoneItem::DoneItem(QWidget* parent)
    : QWidget(parent)
{
    _fileName = new QLabel("金瓶梅（名著赏析）");
    _fileName->setAlignment(Qt::AlignCenter);

    QHBoxLayout* infoLayout = new QHBoxLayout;
    _fileSize = new QLabel(tr("1.3GB"), this);
    _time = new QLabel(tr("2021-10-08 12:19"), this);
    _fileState = new QLabel("文件已移除", this);
    _fileSize->setAlignment(Qt::AlignCenter);
    _time->setAlignment(Qt::AlignCenter);
    _fileState->setAlignment(Qt::AlignCenter);
    infoLayout->addWidget(_fileSize);
    infoLayout->addWidget(_time);
    infoLayout->addWidget(_fileState);

    QVBoxLayout* midLayout = new QVBoxLayout;
    midLayout->addWidget(_fileName);
    midLayout->addLayout(infoLayout);

    QHBoxLayout* mainLayout = new QHBoxLayout;
    _fileIcon = new QLabel(this);
    QIcon icon = Utils::awesome()->icon(fa::folder);
    QPixmap pixmap = icon.pixmap(icon.actualSize(QSize(64, 64)));
    _fileIcon->setPixmap(pixmap);
    _btnPlay = new QPushButton(this);
    _btnPlay->setFlat(true);
    _btnPlay->setIcon(Utils::awesome()->icon(fa::play));
    _btnPlay->setFixedSize(QSize(64, 64));

    mainLayout->addWidget(_fileIcon);
    mainLayout->addLayout(midLayout);
    mainLayout->addWidget(_btnPlay);

    mainLayout->setStretch(0, 2);
    mainLayout->setStretch(1, 6);
    mainLayout->setStretch(2, 2);


    setLayout(mainLayout);
}

DoneItem::~DoneItem()
{
}