#include "RightTopButton.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QVariant>
#include <QApplication>
#include <QMainWindow>

#include "utils/NothingStyleHelper.h"

RightTopButton::RightTopButton(QWidget* parent)
    : QWidget(parent)
{
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    _btnMini = new QPushButton;
    _btnMax = new QPushButton;
    _btnQuit = new QPushButton;

    mainLayout->addWidget(_btnMini);
    mainLayout->addWidget(_btnMax);
    mainLayout->addWidget(_btnQuit);

    _btnMini->setIcon(Utils::awesome()->icon(fa::windowminimize));
    _btnMax->setIcon(Utils::awesome()->icon(fa::windowmaximize));
    _btnQuit->setIcon(Utils::awesome()->icon(fa::windowclose));

    _btnMini->setFlat(true);
    _btnMax->setFlat(true);
    _btnQuit->setFlat(true);
}

RightTopButton::~RightTopButton()
{
}

