#include "LoginDialog.h"

LoginDialog::LoginDialog(QWidget* parent):
    QWidget(parent)
{
    setFixedSize(400, 600);

    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(Qt::white));
    setPalette(pal);


    setWindowFlag(Qt::FramelessWindowHint, true);
}

LoginDialog::~LoginDialog()
{
}