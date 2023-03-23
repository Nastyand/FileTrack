#include "filetracker.h"
#include <iostream>

using namespace std;

//class StateFile
StateFile::StateFile(QObject* parent):QObject(parent)
{
}
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

void StateFile::FileChanged()//Здесь ли выводить сообщения о состоянии файла или в принтере
{
    {
        QFileInfo info(FileName);
        bool exist = info.exists();
        if (exist && exist != isExist) {//создание нового файла
            size = info.size();
            isExist = true;
            emit FileCreated(FileName,size);
        }
        else if (exist && size!=info.size()) {//изменение размера
            size = info.size();
            emit FileSizeChanged(FileName,size);
        }
        else if (!exist && exist != isExist) {//удаление файла
            isExist = false;
            emit FileDeleted(FileName);
        }
    }
}

//class FileMonitor
/*FileMonitor::FileMonitor(QObject* parent):QObject(parent)
{
}
bool FileMonitor:: AddFile(QString FN)
{
    //if(objects.contains(FN)){//Если такой файл существует, то возвращаем false, то есть файл не добавился
    //   return false;
    //}
    //else{
        objects.append(FN);
    //    return true;//Иначе добавляем
    //}
}
bool FileMonitor:: DelFile(QString FN)
{
    objects.removeOne(FN);//Функция должна вернуть действительно ли был удален элемент
}
*/
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
