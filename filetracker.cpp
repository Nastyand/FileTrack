#include "filetracker.h"

StateFile::StateFile(const QString& FN)
{
    FileName = fileName;
    QFileInfo info(FileName);
    size = info.size();
    isExist = info.exists();
}

QString StateFile::GetFileName()
{
    return FileName;
}
qint64 StateFile::GetSize()
{
    return size;
}
bool StateFile::GetExist()
{
    return isExist;
}

