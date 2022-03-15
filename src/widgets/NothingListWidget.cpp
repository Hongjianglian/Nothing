#include <QPen>
#include <QPainter>
#include <QDebug>
#include "NothingListWidget.h"

//文字开始位置
const int TEXT_LEFT_MARGIN = 50;
//指示条宽度
const int INDICATOR_WIDTH = 5;

NothingListWidget::NothingListWidget(QWidget *parent, int paintType) :
    QListWidget(parent), _paintType(paintType)
{
    this->setFrameShape(NoFrame);
    this->setSpacing(0);

    connect(this, &NothingListWidget::itemSelectionChanged, this, &NothingListWidget::onItemSelectionChanged);

    _itemHeight = 35;

    _color = QColor(198, 198, 198);
    _backgroundColor = QColor(34, 37, 48);
    _selectionColor = QColor(99, 176, 72);
    _selectionBackgroundColor =  QColor(76, 83, 89);
    _gridLineColor = QColor(87, 95, 103);
    this->setIconSize(QSize(32, 32));
}

int NothingListWidget::itemHeight()
{
    return _itemHeight;
}

void NothingListWidget::setItemHeight(int height)
{
    _itemHeight = height;

    QListWidgetItem * pItem = NULL;
    QSize size;
    for (int i = 0; i < this->count(); i++) {
        pItem = this->item(i);
        if (i == 0) {
            size = pItem->sizeHint();
            size.setHeight(_itemHeight);
        }
        pItem->setSizeHint(size);
    }
}

const QColor & NothingListWidget::color() const
{
    return _color;
}

void NothingListWidget::setColor(const QColor &color)
{
    if (color != _color) {
        _color = color;
        this->update();
    }
}

const QColor & NothingListWidget::backgroundColor()
{
    return _backgroundColor;
}

void NothingListWidget::setBackgroundColor(const QColor &color)
{
    if (color != _backgroundColor) {
        _backgroundColor = color;
        this->update();
    }
}

const QColor & NothingListWidget::gridLineColor() const
{
    return _gridLineColor;
}

void NothingListWidget::setGridLineColor(const QColor &color)
{
    if (color != _gridLineColor) {
        _gridLineColor = color;
        this->update();
    }
}

const QColor & NothingListWidget::selectionColor() const
{
    return _selectionColor;
}

void NothingListWidget::setSelectionColor(const QColor &color)
{
    if (color != _selectionColor) {
        _selectionColor = color;
        this->update();
    }
}

const QColor & NothingListWidget::selectionBackgroundColor() const
{
    return _selectionBackgroundColor;
}

void NothingListWidget::setSelectionBackgroundColor(const QColor &color)
{
    if (color != _selectionBackgroundColor) {
        _selectionBackgroundColor = color;
        this->update();
    }
}

void NothingListWidget::showEvent(QShowEvent *event)
{
    if (this->count() > 0) {
        QListWidgetItem * pItem = this->item(0);
        if (pItem->sizeHint().height() != _itemHeight) {
            setItemHeight(_itemHeight);
        }
    }

    QListWidget::showEvent(event);
}


void NothingListWidget::onItemSelectionChanged()
{
    //当spacing大于0时，如果不repaint，spacing区域不会更新，导致显示不正常
    if (this->spacing() > 0)
        this->viewport()->repaint();
}


void NothingListWidget::paintEvent(QPaintEvent * event)
{
    if (_paintType != 0) {
        QListWidget::paintEvent(event);
        return;
    }

    QPainter painter(this->viewport());
    QRect paintRect = this->rect();
    QListWidgetItem * pItem = NULL;
    QSize size(paintRect.width(), _itemHeight);
    QPoint point;

    //绘制背景色
    painter.fillRect(paintRect.x(), paintRect.y(), paintRect.width(), paintRect.height(), _backgroundColor);

    //设置图标区域
    int iconX = (TEXT_LEFT_MARGIN - this->iconSize().width() - INDICATOR_WIDTH) / 2 + INDICATOR_WIDTH;
    int iconY = 0;
    int iSpacing = this->spacing();
    int y = iSpacing;

    point.setX(TEXT_LEFT_MARGIN);

    //确定要显示的item范围
    int iFrom = this->indexAt(QPoint(paintRect.x() + iSpacing, paintRect.y() + iSpacing)).row();
    int iTo = this->indexAt(QPoint(paintRect.x() + iSpacing, paintRect.height() - iSpacing)).row();
    iTo = iTo == -1 ? this->count()-1 : iTo;
    iTo = iTo < iFrom ? iFrom : iTo;
    QFont font = this->font();

    for (int i = iFrom; i <= iTo ; i++) {
        pItem = this->item(i);
        //画背景
        if (pItem->isSelected()) {
            painter.fillRect(0, y, size.width(), size.height(), _selectionBackgroundColor);
            painter.fillRect(0, y, INDICATOR_WIDTH, size.height(), _selectionColor);
            painter.setPen(_selectionColor);
            font.setBold(true);
        }
        else {
            painter.fillRect(0, y, size.width(), size.height(), _backgroundColor);
            painter.setPen(_color);
            font.setBold(false);
        }

        //画图标
        QIcon icon = pItem->icon();
        if (!icon.isNull()) {
            iconY = (_itemHeight - this->iconSize().height()) / 2 + y;
            QRect iconRect(QPoint(iconX, iconY), this->iconSize());
            if (pItem->isSelected()) {
                icon.paint(&painter, iconRect, Qt::AlignCenter, QIcon::Selected, QIcon::Off);
            }
            else {
                icon.paint(&painter, iconRect);
            }
        }

        //写字
        point.setY(y);
        painter.setFont(font);
        QRect rectItem(point, size);
        painter.drawText(rectItem, Qt::AlignLeft | Qt::AlignVCenter, pItem->text(), NULL);

        //画分隔线
        if (i > 0) {
            painter.setPen(_gridLineColor);
            painter.drawLine(0, y - this->spacing(), paintRect.width(), y - this->spacing());
        }

        y += size.height() + this->spacing() * 2;
    }

    painter.end();
}
