#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_NothingMainWindow.h"

class NothingTrayIcon;
class QSystemTrayIcon;
class QMenu;
class QCloseEvent;

class NothingMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    NothingMainWindow(QWidget *parent = Q_NULLPTR);




    void setSystemTrayIconVisible(bool bVisible);


protected:
    void closeEvent(QCloseEvent* event) override;
private:
    void initTrayIcon(QSystemTrayIcon* trayIcon);


public slots:
    void shiftVisableStatus();

    void on_actionExit_triggered();
    void on_actionSettings_clicked();
private:
    NothingTrayIcon* _tray;
    QMenu* _trayMenu;

    Ui::NothingClientClass ui;
};
