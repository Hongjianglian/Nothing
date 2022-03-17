#pragma execution_character_set("utf-8") 
#include "LoginWidget.h"

#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRegularExpressionValidator>

#include "utils/NothingStyleHelper.h"

LoginWidget::LoginWidget(QWidget* parent):
    QWidget(parent)
{
    setWindowFlag(Qt::FramelessWindowHint, true);
    setFixedSize(400, 600);

    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(189,189,189));
    setPalette(pal);

    setFont(QFont("Microsoft YaHei"));

    QHBoxLayout* topLayout = new QHBoxLayout;

    _backup = new QLabel;
    _backup->setText("");
    _backup->setAlignment(Qt::AlignCenter);

    _btnQuit = new QPushButton;
    _btnQuit->setFlat(true);
    _btnQuit->setIcon(Utils::awesome()->icon(fa::windowclose));
    topLayout->addWidget(_backup);
    topLayout->addWidget(_btnQuit);
    topLayout->setStretch(0, 10);
    topLayout->setStretch(1, 1);

    _userName = new QLineEdit;
    _userName->setFixedHeight(40);
    _userName->setAlignment(Qt::AlignCenter);
    _userName->setPlaceholderText("请输入账号");
    _userName->setValidator(new QRegularExpressionValidator(QRegularExpression("^[a-zA-Z1-9]*[a-zA-Z0-9]*$")));
    _userName->setMaxLength(15);
    _password = new QLineEdit;
    _password->setFixedHeight(40);
    _password->setAlignment(Qt::AlignCenter);
    _password->setPlaceholderText("请输入密码");
    _password->setEchoMode(QLineEdit::Password);

    QVBoxLayout* userBoxLayout = new QVBoxLayout;
    userBoxLayout->addWidget(_userName);
    userBoxLayout->addWidget(_password);



    _btnLogin = new QPushButton("登录");
    _btnLogin->setFixedHeight(40);
    QVBoxLayout* mainLayout = new QVBoxLayout;

    mainLayout->addLayout(topLayout);
    mainLayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding));
    mainLayout->addLayout(userBoxLayout);
    mainLayout->addWidget(_btnLogin);
    mainLayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding));

    mainLayout->setStretch(0, 1);
    mainLayout->setStretch(1, 4);
    mainLayout->setStretch(2, 4);
    mainLayout->setStretch(3, 1);
    mainLayout->setStretch(4, 4);

    setLayout(mainLayout);

    connect(_btnQuit, &QPushButton::clicked, this, &LoginWidget::onBtnQuitClicked);
}

LoginWidget::~LoginWidget()
{
}

void LoginWidget::onBtnQuitClicked()
{
    close();
}