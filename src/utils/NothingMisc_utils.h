#pragma once

#include <QtGlobal>

namespace Utils {

class NothingMisc
{
public:


    static QString extractFilePath(const QString& strFileName);
    static QString extractFileName(const QString& strFileName);


    // file operations
    static qint64 getFileSize(const QString& strFileName);
    static void deleteFile(const QString& strFileName);



};


}