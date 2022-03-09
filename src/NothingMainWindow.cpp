#pragma execution_character_set("utf-8") 
#include "NothingMainWindow.h"
#include "utils/NothingStyleHelper.h"
#include "widgets/NothingTrayIcon.h"

#include <QBoxLayout>
#include <QMenu>
#include <QCloseEvent>
#include <QMessageBox>
#include <QSystemTrayIcon>


NothingMainWindow::NothingMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , _tray(nullptr)
    , _trayMenu(nullptr)
{
    ui.setupUi(this);
    //setWindowFlags(Qt::FramelessWindowHint);
    //setAttribute(Qt::WA_TranslucentBackground);
    setContentsMargins(0, 0, 0, 0);


    QLayout* windowLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    setLayout(windowLayout);
    windowLayout->setContentsMargins(0, 0, 0, 0);
    windowLayout->setSpacing(0);
    //
    int shadowSize = 25;
    QWidget* w = new QWidget(this);
    w->setContentsMargins(shadowSize, shadowSize, shadowSize, shadowSize);
    windowLayout->addWidget(w);
    //
    QLayout* rootLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    w->setLayout(rootLayout);
    rootLayout->setContentsMargins(0, 0, 0, 0);
    rootLayout->setSpacing(0);

    QWidget* shadowClientWidget = new QWidget(w);
    rootLayout->addWidget(shadowClientWidget);
    //
    QLayout* shadowClientLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    shadowClientLayout->setContentsMargins(0, 0, 0, 0);
    shadowClientLayout->setSpacing(0);
    shadowClientWidget->setLayout(shadowClientLayout);
    shadowClientWidget->setAutoFillBackground(true);
    shadowClientWidget->setCursor(QCursor(Qt::ArrowCursor));
    //
    // m_titleBar = new WizWindowTitleBar(shadowClientWidget, this, w, canResize);
    //shadowClientLayout->addWidget(m_titleBar);
    //
    QWidget* m_clientWidget = new QWidget(shadowClientWidget);
    shadowClientLayout->addWidget(m_clientWidget);

    //
    QBoxLayout* m_clientLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    m_clientWidget->setLayout(m_clientLayout);
    //
    m_clientLayout->setSpacing(0);
    m_clientLayout->setContentsMargins(0, 0, 0, 0);

    setSystemTrayIconVisible(false);  // TODO: 为调试方便，暂时置为false
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

