#pragma once
#include <QWidget>

QT_BEGIN_NAMESPACE
class QListWidget;
QT_END_NAMESPACE

class DoneTab : public QWidget
{
    Q_OBJECT

public:
    explicit DoneTab(QWidget* parent = nullptr);
    ~DoneTab();

protected:

private:
    QListWidget* _listWidget;

};