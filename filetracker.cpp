#include "filetracker.h"

//class StateFile
StateFile::StateFile(){}
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

bool StateFile::operator==(const StateFile file)const
{
    if (FileName != file.FileName)return false;
    return true;
}

//class FileMonitor
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

//class FilePrinter
FilePrinter::FilePrinter(){}
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
