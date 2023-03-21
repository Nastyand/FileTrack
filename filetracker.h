#ifndef FILETRACKER_H
#define FILETRACKER_H

#include <QObject>
#include <QFileInfo>
#include <QString>
#include <QVector>
#include <iostream>

using namespace std;

class StateFile : public QObject  //отслеживает состояние каждого отдельного файла
{
     Q_OBJECT
public:
    StateFile(const QString& FN);
    QString GetFileName();//Нужны ли геттеры?
    qint64 GetSize();
    bool GetExist();
signals:
    void FileCreated(QString FN,qint64 Size);//Изменения при создании файла
    void FileSizeChanged(QString FN, qint64 newSize);//Изменения размера файла
    void FileDeleted(QString FN);//Изменения при удалении файла

public slots:
    void FileChanged(const QString& FN);
private:
    QString FileName;
    qint64 size;
    bool isExist;
};

class FileMonitor:public QObject//Какая связь с классом StateFile
{
    QVector<StateFile>objects;
public:
    //FileMonitor(QObject* parent = nullptr);//какой конструктор, что он будет делать
    //FileMonitor();
    //~FileMonitor();
    bool AddFile(StateFile FN);//Добавился ли файл, добавить, если нет
    bool DelFile(StateFile FN);//Удалился ли файл, если существует, удалить
};

class FilePrinter
{
    void PrintIfFileCreated(StateFile FN);
    void PrintIfFileChanged(StateFile FN);
    void PrintIfFileDeleted(StateFile FN);
};


#endif // FILETRACKER_H
