#include "filemonitor.h"

FileMonitor::FileMonitor(){}

void FileMonitor::FileChanged()
{
    for (int i = 0; i < objects.count(); i++)       // цикл по файлам
    {
        StateFile file(objects[i].GetFileName());
        if (file.GetExist()==true && file.GetExist() != objects[i].GetExist()) {//создание нового файла
            objects[i]=file;
            emit FileCreated(objects[i].GetFileName(),objects[i].GetSize());
        }
        else if (file.GetExist()==true && objects[i].GetSize()!=file.GetSize()) {//изменение размера
            objects[i]=file;
            emit FileSizeChanged(objects[i].GetFileName(),objects[i].GetSize());
        }
        else if (file.GetExist()==false && file.GetExist() != objects[i].GetExist()) {//удаление файла
            objects[i]=file;
            emit FileDeleted(objects[i].GetFileName());
        }
    }
}

bool FileMonitor:: AddFile(QString FN)
{
    StateFile file(FN);
    if (!objects.contains(file)){
            objects.append(file);
            return true;
    }
    return false;
}

bool FileMonitor:: DelFile(QString FN)
{
    StateFile file(FN);
    return objects.removeOne(file);//Функция должна вернуть действительно ли был удален элемент
}


