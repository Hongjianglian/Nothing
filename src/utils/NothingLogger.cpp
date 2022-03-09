#include "NothingLogger.h"
#include "NothingMisc_utils.h"
#include "NothingPathResolve.h"
#include <QBuffer>
#include <QDateTime>
#include <fstream>

namespace Utils
{
NothingLogger::NothingLogger() : 
    _buffer(new QBuffer),
    _mutex(QMutex::Recursive)
{
}

NothingLogger::~NothingLogger()
{
}

void NothingLogger::messageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
    Q_UNUSED(context);

    // 忽略Qt内部的一些无用警告
    if (type == QtWarningMsg && msg.startsWith("Property") && msg.indexOf("has no notify signal") != -1)
        return;

    logger()->saveToLogFile(msg);
    logger()->addToBuffer(msg);

    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "[DEBUG] %s\n", msg.toUtf8().constData());
        break;
#if QT_VERSION >= 0x050500
    case QtInfoMsg:
        fprintf(stderr, "[INFO] %s\n", msg.toUtf8().constData());
        break;
#endif
    case QtWarningMsg:
        fprintf(stderr, "[WARNING]: %s (%s:%u, %s)\n", msg.toUtf8().constData(), context.file, context.line, context.function);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "[CRITICAL]: %s (%s:%u, %s)\n", msg.toUtf8().constData(), context.file, context.line, context.function);
        break;
    case QtFatalMsg:
        fprintf(stderr, "[FATAL]: %s (%s:%u, %s)\n", msg.toUtf8().constData(), context.file, context.line, context.function);
        break;
    }
}

QString NothingLogger::logFileName()
{
    QString strFileName = NothingPathResolve::logFile();

    if (NothingMisc::getFileSize(strFileName) > 10 * 1024 * 1024)
    {
        NothingMisc::deleteFile(strFileName);
    }
    //
    return strFileName;
}

QString NothingLogger::msg2LogMsg(const QString& strMsg)
{
    QString strTime = QDateTime::currentDateTime().toString(Qt::ISODate);
    return strTime + ": " + strMsg + "\n";
}

void NothingLogger::saveToLogFile(const QString& strMsg)
{
    QMutexLocker locker(&_mutex);

    std::ofstream logFile(logFileName().toUtf8().constData(), std::ios::out | std::ios::app);
    logFile << msg2LogMsg(strMsg).toUtf8().constData() << std::endl;
    logFile.close();
}

void NothingLogger::addToBuffer(const QString& strMsg)
{
    QMutexLocker locker(&_mutex);

    _buffer->open(QIODevice::Append);
    _buffer->write(msg2LogMsg(strMsg).toUtf8());
    _buffer->close();
}

void NothingLogger::getAll(QString& text)
{
    QMutexLocker locker(&_mutex);
    Q_UNUSED(locker);
    //
    _buffer->open(QIODevice::ReadOnly);
    QByteArray data = _buffer->readAll();
    text = QString::fromUtf8(data.data());
    _buffer->close();
    _buffer->setBuffer(NULL);
}

NothingLogger* NothingLogger::logger()
{
    return &Utils::Singleton<NothingLogger>::instance();
}

void NothingLogger::writeLog(const QString& strMsg)
{
    if (strMsg.startsWith("[WARNING]: Property "))
        return;
    logger()->saveToLogFile(strMsg);
    logger()->addToBuffer(strMsg);

    fprintf(stderr, "[INFO] %s\n", strMsg.toUtf8().constData());
}

void NothingLogger::getAllLogs(QString& text)
{
    logger()->getAll(text);
}

} // namespace Utils