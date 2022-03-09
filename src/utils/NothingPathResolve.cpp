#include "NothingPathResolve.h"

#include <QtGlobal>
#include <QApplication>
#include <QDir>
#include <QDebug>

namespace Utils
{
QString NothingPathResolve::appPath()
{
    QString strPath = QApplication::applicationDirPath();
    addBackslash(strPath);
    return strPath;
}

QString NothingPathResolve::resourcesPath()
{
    QDir dir(appPath());
    dir.cdUp();
    dir.cd("share/nothing");
    QString strPath = dir.path();
    addBackslash(strPath);
    return strPath;
}

QString NothingPathResolve::logFilePath()
{
    QString strPath;

    strPath = dataStorePath() + "log/";

    ensurePathExists(strPath);
    return strPath;
}

QString NothingPathResolve::logFile()
{
    QString strLogfile = logFilePath() + "nothing.log";
    return strLogfile;
}

void NothingPathResolve::addBackslash(QString& strPath)
{
    strPath.replace('\\', '/');

    if (strPath.endsWith('/'))
        return;

    strPath += '/';
}

void NothingPathResolve::ensurePathExists(const QString& path)
{
    QDir dir;
    dir.mkpath(path);
}

QString NothingPathResolve::dataStorePath()
{
    QString strPath;
    strPath = QDir::homePath();
    strPath += "/Nothing/";
    ensurePathExists(strPath);
    //
    return strPath;
}


}