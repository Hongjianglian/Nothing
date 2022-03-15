#pragma once

#include <QtWidgets/QMainWindow>

QT_BEGIN_NAMESPACE
class QSystemTrayIcon;
class QMenu;
class QCloseEvent;
class QStackedWidget;
class QPushButton;
class QLabel;
QT_END_NAMESPACE

class NothingTrayIcon;
class LeftBar;
class RightTopButton;

class NothingMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    NothingMainWindow(QWidget *parent = Q_NULLPTR);


    void setSystemTrayIconVisible(bool bVisible);


protected:

    virtual void closeEvent(QCloseEvent* event) override;
    virtual void mouseMoveEvent(QMouseEvent* event) override;
    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;

private:
    void initTrayIcon(QSystemTrayIcon* trayIcon);


public slots:
    void shiftVisableStatus();

    void on_actionExit_triggered();
    void on_actionSettings_clicked();

    void btnMiniClicked();
    void btnMaxClicked();
    void btnQuitClicked();

private:
    NothingTrayIcon* _tray;
    QMenu* _trayMenu;

    LeftBar* _leftBar;
    RightTopButton* _rightTopButton;

    QWidget* _topPanel;  // 用于放置占位widget、RightTopButton
    QLabel* _backup; // 占位widget，位于RightTopButton左侧

    QStackedWidget* _stackWidget;

    QPoint z;

};
