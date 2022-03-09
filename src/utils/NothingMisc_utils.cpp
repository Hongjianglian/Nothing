#include "NothingMisc_utils.h"
#include <QFileInfo>
#include <QDir>


namespace Utils
{
/// <summary>
/// 提取文件路径
/// /usr/include/crypto.h ===> /usr/include/
/// </summary>
/// <param name="strFileName"></param>
/// <returns></returns>
QString NothingMisc::extractFilePath(const QString& strFileName)
{
        QString str = strFileName;
    str.replace('\\', '/');
    int index = str.lastIndexOf('/');
    if (-1 == index)
        return strFileName;
    //
    return str.left(index + 1); //include separator
}

/// <summary>
/// 提取文件名
/// /usr/include/cypto.h ===> crypto.h
/// </summary>
/// <param name="strFileName"></param>
/// <returns></returns>
QString NothingMisc::extractFileName(const QString& strFileName)
{
    QString str = strFileName;
    str.replace('\\', '/');
    int index = str.lastIndexOf('/');
    if (-1 == index)
        return strFileName;

    return strFileName.right(str.length() - index - 1);
}

/// <summary>
/// 获取文件大小（Byte）
/// </summary>
/// <param name="strFileName"></param>
/// <returns></returns>
qint64 NothingMisc::getFileSize(const QString& strFileName)
{
    QFileInfo info(strFileName);
    return info.size();
}

/// <summary>
/// 删除文件
/// </summary>
/// <param name="strFileName"></param>
void NothingMisc::deleteFile(const QString& strFileName)
{
    QDir dir(extractFilePath(strFileName));
    dir.remove(extractFileName(strFileName));
}

}


