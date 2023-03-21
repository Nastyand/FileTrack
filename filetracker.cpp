#include "filetracker.h"
#include <iostream>

using namespace std;

//class StateFile
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

void StateFile::FileChanged(QString FN)//Здесь ли выводить сообщения о состоянии файла или в принтере
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

//class FileMonitor

bool FileMonitor:: AddFile(StateFile FN)
{
    //if(objects.contains(FN)){//Если такой файл существует, то возвращаем false, то есть файл не добавился
    //   return false;
    //}
    //else{
        objects.append(FN);
    //    return true;//Иначе добавляем
    //}
}
bool FileMonitor:: DelFile(StateFile FN)
{
    objects.removeOne(FN);//Функция должна вернуть действительно ли был удален элемент
}

//class FilePrinter
void FilePrinter::PrintIfFileCreated(StateFile FN)
{
    cout<<"Файл "<<FN.GetFileName()<<" был создан, его размер "<<FN.GetSize()<<endl;
}
void FilePrinter::PrintIfFileChanged(StateFile FN)
{
    cout<<"Файл "<<FN.GetFileName()<<" был изменен, его размер "<<FN.GetSize()<<endl;
}
void FilePrinter::PrintIfFileDeleted(StateFile FN)
{
    cout<<"Файл "<<FN.GetFileName()<<" был удален"<<endl;
}
