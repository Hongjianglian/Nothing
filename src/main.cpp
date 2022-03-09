#pragma execution_character_set("utf-8")
#include "NothingMainWindow.h"
#include <QtWidgets/QApplication>
#include <QDebug>
#include <QTextCodec>

#include "utils/NothingLogger.h"
#include "utils/NothingStyleHelper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 设置编码
    QTextCodec* codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);

    qInstallMessageHandler(Utils::NothingLogger::messageHandler);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QApplication::setApplicationName(QObject::tr("Nothing"));
    QApplication::setOrganizationName(QObject::tr("cn.nothing"));

    // 设置app图标
    QIcon icon;
    icon.addPixmap(QPixmap(":/logo_16.png"));
    icon.addPixmap(QPixmap(":/logo_32.png"));
    icon.addPixmap(QPixmap(":/logo_48.png"));
    icon.addPixmap(QPixmap(":/logo_64.png"));
    icon.addPixmap(QPixmap(":/logo_128.png"));
    icon.addPixmap(QPixmap(":/logo_256.png"));
    QApplication::setWindowIcon(icon);

    // 初始化全局QtAwesome
    Utils::awesome()->initFontAwesome();

    NothingMainWindow w;
    w.show();
    return a.exec();
}
