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

void StateFile::FileChanged(const QString& FN)//Здесь ли выводить сообщения о состоянии файла или в принтере
{
    QFileInfo info(FN);
    bool exist = info.exists();
    if (exist && exist != isExist) {//создание нового файла
        size = info.size();
        isExist = true;
        emit FileCreated(FN,size);
    }
    else if (exist && size!=info.size()) {//изменение размера
        size = info.size();
        emit FileSizeChanged(FN,size);
    }
    else if (!exist && exist != isExist) {//удаление файла
        isExist = false;
        emit FileDeleted(FN);
    }
}

bool FileMonitor:: AddFile(QString FN)
{
    if(objects.contains(FN)){//Если такой файл существует, то возвращаем false, то есть файл не добавился
        return false;
    }
    else{
        objects.append(FN);//Иначе добавляем
    }
}
bool FileMonitor:: DelFile(QString FN)
{
    objects.removeOne(FN);//Функция должна вернуть действительно ли был удален элемент
}
