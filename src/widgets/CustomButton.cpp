#pragma execution_character_set("utf-8")
#include "CustomButton.h"
#include <QPainter>
#include <QPropertyAnimation>
#include <QDebug>

CustomButton::CustomButton(QWidget* parent) : QWidget(parent)
{
    enter = true;
    leave = false;
    pixWidth = 0;
    pixHeight = 0;
    oldWidth = 0;
    oldHeight = 0;

    enterAnimation = new QPropertyAnimation(this, "");
    enterAnimation->setStartValue(0);
    enterAnimation->setEndValue(5);
    enterAnimation->setDuration(200);
    connect(enterAnimation, SIGNAL(valueChanged(QVariant)), this, SLOT(enterImageChanged(QVariant)));

    leaveAnimation = new QPropertyAnimation(this, "");
    leaveAnimation->setStartValue(0);
    leaveAnimation->setEndValue(5);
    leaveAnimation->setDuration(200);
    connect(leaveAnimation, SIGNAL(valueChanged(QVariant)), this, SLOT(leaveImageChanged(QVariant)));
}

CustomButton::~CustomButton()
{
    delete enterAnimation;
    delete leaveAnimation;
}

void CustomButton::enterEvent(QEvent*)
{
    enter = true;
    leave = false;
    pixWidth = pixWidth - 25;
    pixHeight = pixHeight - 25;
    enterAnimation->start();
}

void CustomButton::leaveEvent(QEvent*)
{
    enter = false;
    leave = true;
    pixWidth = oldWidth;
    pixHeight = oldHeight;
    leaveAnimation->start();
}

void CustomButton::paintEvent(QPaintEvent*)
{
    if (imageName.isEmpty()) {
        return;
    }

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    QPixmap pix(imageName);
    pix = pix.scaled(targetWidth, targetHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    if (enter || leave) {
        int pixX = rect().center().x() - targetWidth / 2;
        int pixY = rect().center().y() - targetHeight / 2;
        QPoint point(pixX, pixY);
        painter.drawPixmap(point, pix);
    }
}

void CustomButton::enterImageChanged(QVariant index)
{
    int i = index.toInt();
    targetWidth = pixWidth + i * 5;
    targetHeight = pixHeight + i * 5;
    update();
}

void CustomButton::leaveImageChanged(QVariant index)
{
    int i = index.toInt();
    targetWidth = pixWidth - i * 5;
    targetHeight = pixWidth - i * 5;
    update();
}

QString CustomButton::getImageName() const
{
    return this->imageName;
}

QSize CustomButton::sizeHint() const
{
    return QSize(95, 95);
}

QSize CustomButton::minimumSizeHint() const
{
    return QSize(10, 10);
}

void CustomButton::setImageName(const QString& imageName)
{
    if (this->imageName != imageName) {
        this->imageName = imageName;
        QPixmap pix(imageName);
        pixWidth = pix.width();
        pixHeight = pix.height();
        oldWidth = pixWidth;
        oldHeight = pixHeight;
        targetWidth = pixWidth - 25;
        targetHeight = pixHeight - 25;
        update();
    }
}

