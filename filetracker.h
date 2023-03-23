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
    StateFile(QObject* parent = nullptr);
    StateFile(const QString& FN);
    QString GetFileName();//Нужны ли геттеры?
    qint64 GetSize();
    bool GetExist();
signals:
    void FileCreated(QString FN,qint64 Size);//Изменения при создании файла
    void FileSizeChanged(QString FN, qint64 newSize);//Изменения размера файла
    void FileDeleted(QString FN);//Изменения при удалении файла

public slots:
    void FileChanged();
private:
    QString FileName;
    qint64 size;
    bool isExist;
};

/*class FileMonitor:public QObject//Какая связь с классом StateFile
{
    QVector<StateFile>objects;
public:
    FileMonitor(QObject* parent = nullptr);
    //FileMonitor();
    //~FileMonitor();
    bool AddFile(QString FN);//Добавился ли файл, добавить, если нет
    bool DelFile(QString FN);//Удалился ли файл, если существует, удалить
};*/

class FilePrinter:public QObject
{
    Q_OBJECT
public:
     FilePrinter(QObject* parent = nullptr);

public slots:
    void PrintIfFileCreated(QString FN, qint64 size);
    void PrintIfFileChanged(QString FN, qint64 size);
    void PrintIfFileDeleted(QString FN);
};


#endif // FILETRACKER_H
