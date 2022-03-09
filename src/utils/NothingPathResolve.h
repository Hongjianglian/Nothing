#pragma once
#include <QString>

namespace Utils
{
class NothingPathResolve
{
public:
    static QString appPath();
    static QString resourcesPath();

    static QString dataStorePath();


    static QString logFile();

    // helpers
    static void addBackslash(QString& strPath);
    static void ensurePathExists(const QString& path);

private:
    static QString logFilePath();
};
}