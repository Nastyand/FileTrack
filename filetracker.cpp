#include "filetracker.h"
#include <iostream>

using namespace std;

StateFile::StateFile(const QString& FN)
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

bool StateFile::operator==(StateFile file)
{
    if (FileName != file.FileName)return false;
    return true;
}

//class FileMonitor
FileMonitor::FileMonitor(QObject* parent):QObject(parent)
{
}

void FileMonitor::FileChanged()
{
    for (int i = 0; i < objects.count(); i++)       // цикл по файлам
    {
        StateFile file(objects[i].GetFileName());
        QFileInfo info(objects[i].GetFileName());
        bool exist = info.exists();
        if (exist && exist != objects[i].GetExist()) {//создание нового файла
            objects[i]=file;
            emit FileCreated(objects[i].GetFileName(),objects[i].GetSize());
        }
        else if (exist && objects[i].GetSize()!=info.size()) {//изменение размера
            objects[i]=file;
            emit FileSizeChanged(objects[i].GetFileName(),objects[i].GetSize());
        }
        else if (!exist && exist != objects[i].GetExist()) {//удаление файла
            objects[i]=file;
            emit FileDeleted(objects[i].GetFileName());
        }
    }
}

void FileMonitor:: AddFile(QString FN)
{
    StateFile file(FN);
    objects.append(file);
}

void FileMonitor:: DelFile(QString FN)
{
    StateFile file(FN);
    objects.removeOne(file);//Функция должна вернуть действительно ли был удален элемент
}

//class FilePrinter
FilePrinter::FilePrinter(QObject* parent):QObject(parent)
{
}
void FilePrinter::PrintIfFileCreated(QString FN, qint64 size)
{
    QByteArray ba = FN.toLocal8Bit();//Перевод из QString в char*
    const char *FN1 = ba.data();
    cout<<"File "<<FN1<<" exists, his size "<<size<<endl;
}
void FilePrinter::PrintIfFileChanged(QString FN, qint64 size)
{
    QByteArray ba = FN.toLocal8Bit();
    const char *FN1 = ba.data();
    cout<<"File "<<FN1<<" changed, his size "<<size<<endl;
}
void FilePrinter::PrintIfFileDeleted(QString FN)
{
    QByteArray ba = FN.toLocal8Bit();
    const char *FN1 = ba.data();
    cout<<"File "<<FN1<<" deleted"<<endl;
}
