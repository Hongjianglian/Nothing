#pragma once

#include <QListWidget>
#include <QPaintEvent>
#include <QRegion>

/// <summary>
/// ListWidget
/// </summary>
class NothingListWidget : public QListWidget
{
    Q_OBJECT

    Q_PROPERTY(int itemHeight READ itemHeight WRITE setItemHeight)
    Q_PROPERTY(QColor color READ color WRITE setColor)
    Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor)
    Q_PROPERTY(QColor gridLineColor READ gridLineColor WRITE setGridLineColor)
    Q_PROPERTY(QColor selectionColor READ selectionColor WRITE setSelectionColor)
    Q_PROPERTY(QColor selectionBackgroundColor READ selectionBackgroundColor WRITE setSelectionBackgroundColor)
public:
    NothingListWidget(QWidget *parent = 0, int paintType = 0);

    //设置每个item的高度
    int itemHeight();
    void setItemHeight(int height);
    //设置颜色
    const QColor & color() const;
    void setColor(const QColor & color);
    const QColor & backgroundColor();
    void setBackgroundColor(const QColor & color);
    const QColor & gridLineColor() const;
    void setGridLineColor(const QColor & color);
    const QColor & selectionColor() const;
    void setSelectionColor(const QColor & color);
    const QColor & selectionBackgroundColor() const;
    void setSelectionBackgroundColor(const QColor & color);
private:
    int _paintType;
    int _itemHeight;
    QColor _color;
    QColor _backgroundColor;
    QColor _gridLineColor;
    QColor _selectionColor;
    QColor _selectionBackgroundColor;

protected:
    void paintEvent(QPaintEvent *event);
    void showEvent(QShowEvent * event);

    void onItemSelectionChanged();
};
