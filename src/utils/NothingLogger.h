#pragma once
#include <QtGlobal>
#include <QObject>
#include <QMutex>
#include "Singleton.h"

class QBuffer;

namespace Utils
{
class NothingLogger : 
    public QObject,
    noncopyable
{
    Q_OBJECT

public:
    NothingLogger();
    ~NothingLogger();

public:
    static void messageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg);
    static void writeLog(const QString& strMsg);
    static void getAllLogs(QString& text);
    static NothingLogger* logger();

private:
    void getAll(QString& text);

    QString logFileName();
    QString msg2LogMsg(const QString& strMsg);
    void saveToLogFile(const QString& strMsg);
    void addToBuffer(const QString& strMsg);

private:
    QBuffer* _buffer;
    QMutex _mutex;


};


} // namespace Utils


