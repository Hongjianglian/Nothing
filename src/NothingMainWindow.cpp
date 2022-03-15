#pragma execution_character_set("utf-8") 
#include "NothingMainWindow.h"

#include <QApplication>
#include <QBoxLayout>
#include <QMenu>
#include <QCloseEvent>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QStackedWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSplitter>

#include <Windows.h> // for SendMessage

#include "utils/NothingStyleHelper.h"
#include "widgets/NothingTrayIcon.h"
#include "widgets/LeftBar.h"
#include "widgets/RightTopButton.h"
#include "widgets/ForumWidget.h"
#include "widgets/DownloadWidget.h"

NothingMainWindow::NothingMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , _tray(nullptr)
    , _trayMenu(nullptr)
{
    setAutoFillBackground(true);
    setContentsMargins(0, 0, 0, 0);
    
    //设置背景白色
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(Qt::white));
    setPalette(pal);

    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    setMinimumSize(QSize(1280,800));
    setWindowFlag(Qt::FramelessWindowHint,true);
    //setAttribute(Qt::WA_TranslucentBackground);

    QHBoxLayout* rootLayout = new QHBoxLayout(centralWidget);
    rootLayout->setSpacing(0);
    rootLayout->setMargin(0);

    QHBoxLayout* leftBarLayout = new QHBoxLayout;
    _leftBar = new LeftBar(this);
    leftBarLayout->addWidget(_leftBar);

    QVBoxLayout* rightLayout = new QVBoxLayout;

    _topPanel = new QWidget(this);
    QHBoxLayout* topLayout = new QHBoxLayout;

    _backup = new QLabel;
    _backup->setText("some function to complement...");
    _backup->setAlignment(Qt::AlignCenter);

    _rightTopButton = new RightTopButton;
    topLayout->addWidget(_backup);
    topLayout->addWidget(_rightTopButton);
    topLayout->setStretch(0, 10);
    topLayout->setStretch(1, 1);

    _topPanel->setLayout(topLayout);

    _stackWidget = new QStackedWidget(this);
    rightLayout->addWidget(_topPanel);
    rightLayout->addWidget(_stackWidget);

    rootLayout->addLayout(leftBarLayout);
    rootLayout->addLayout(rightLayout);
    rootLayout->setStretch(0, 2);
    rootLayout->setStretch(1, 6);

    setSystemTrayIconVisible(false);  // TODO: 为调试方便，暂时置为false

    DownloadWidget* downloadWidget = new DownloadWidget;
    _stackWidget->addWidget(downloadWidget);
    ForumWidget* forumWidget = new ForumWidget;
    _stackWidget->addWidget(forumWidget);

    connect(_rightTopButton->_btnMini, &QPushButton::clicked, this, &NothingMainWindow::btnMiniClicked);
    connect(_rightTopButton->_btnMax, &QPushButton::clicked, this, &NothingMainWindow::btnMaxClicked);
    connect(_rightTopButton->_btnQuit, &QPushButton::clicked, this, &NothingMainWindow::btnQuitClicked);
}

void NothingMainWindow::closeEvent(QCloseEvent* event)
{
    if (_tray->isVisible()) {
        // TODO: 询问用户退出还是后台运行
        //QMessageBox::information(this, tr("Systray"),
        //    tr("The program will keep running in the "));
        hide();
        event->ignore();
    }
}

void NothingMainWindow::mouseMoveEvent(QMouseEvent* event)
{
    if ( (event->buttons() && Qt::LeftButton) && event)
    {
        move(event->globalPos() - z);
        event->accept();
    }
}

void NothingMainWindow::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        z = event->globalPos() - this->pos();
        event->accept();
    }
}

void NothingMainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    QMainWindow::mouseReleaseEvent(event);
}

void NothingMainWindow::setSystemTrayIconVisible(bool bVisible)
{
    if (!_tray)
    {
        _tray = new NothingTrayIcon(QApplication::windowIcon(), this);
        initTrayIcon(_tray);
        _tray->show();
    }

    _tray->setVisible(bVisible);
}

void NothingMainWindow::initTrayIcon(QSystemTrayIcon* trayIcon)
{
    assert(trayIcon);
    _trayMenu = new QMenu(this);

    QAction* actionShow = _trayMenu->addAction("显示主界面");
    connect(actionShow, SIGNAL(triggered()), SLOT(shiftVisableStatus()));

    _trayMenu->addSeparator();
    QAction* actionSettings = _trayMenu->addAction("设置");
    connect(actionSettings, SIGNAL(triggered()), SLOT(on_actionSettings_clicked()));
    //
    _trayMenu->addSeparator();
    // TODO: 登出
    QAction* actionLogout = _trayMenu->addAction("退出登录");
    //connect(actionLogout, SIGNAL(triggered()), SLOT(on_actionLogout_triggered()));
    QAction* actionExit = _trayMenu->addAction("关闭");
    connect(actionExit, SIGNAL(triggered()), SLOT(on_actionExit_triggered()));

    //
    trayIcon->setContextMenu(_trayMenu);

}

void NothingMainWindow::shiftVisableStatus()
{
    if (Qt::WindowMinimized & windowState())
    {
        setWindowState(Qt::WindowActive);
        raise();
        showNormal();
    }
    else if (!isActiveWindow())
    {
        setWindowState(Qt::WindowActive);
        raise();
        showNormal();
    }
    else
    {
        setWindowState(Qt::WindowMinimized);
    }
}

void NothingMainWindow::on_actionExit_triggered()
{
    qApp->exit();
}

void NothingMainWindow::on_actionSettings_clicked()
{
    // TODO:
}

void NothingMainWindow::btnMiniClicked()
{
    showMinimized();
}

void NothingMainWindow::btnMaxClicked()
{
    // 如果当前窗口已经是最大化
    if (Qt::WindowMaximized & windowState())
        showNormal();
    else
        showMaximized();
}

void NothingMainWindow::btnQuitClicked()
{
    close();
}


