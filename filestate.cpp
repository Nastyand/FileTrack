#include "filestate.h"

StateFile::StateFile(){}
StateFile::StateFile(QString FN)
{
    FileName = FN;
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

bool StateFile::operator==(StateFile file)const
{
    if (FileName != file.FileName)return false;
    return true;
}
