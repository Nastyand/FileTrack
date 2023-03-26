#ifndef FILETRACKER_H
#define FILETRACKER_H

#include <QObject>
#include <QFileInfo>
#include <QString>
#include <QVector>
#include <iostream>

using namespace std;

class StateFile
{
public:
    StateFile() = default;
    StateFile(const QString& FN);
    QString GetFileName();
    qint64 GetSize();
    bool GetExist();
    bool operator==(StateFile file);
private:
    QString FileName;
    qint64 size;
    bool isExist;
};

class FileMonitor:public QObject
{
     Q_OBJECT
    QVector<StateFile>objects;
public:
    FileMonitor(QObject* parent = nullptr);
    //~FileMonitor();
    void AddFile(QString FN);//Добавился ли файл, добавить, если нет
    void DelFile(QString FN);//Удалился ли файл, если существует, удалить
signals:
    void FileCreated(QString FN,qint64 Size);//Изменения при создании файла
    void FileSizeChanged(QString FN, qint64 newSize);//Изменения размера файла
    void FileDeleted(QString FN);//Изменения при удалении файла

public slots:
    void FileChanged();
};

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
