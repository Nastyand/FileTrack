#ifndef FILETRACKER_H
#define FILETRACKER_H

#include <QObject>
#include <QVector>
#include "filestate.h"

class FileMonitor:public QObject//класс, который следит за состояниями всех файлов
{
     Q_OBJECT
    QVector<StateFile>objects;
public:
    FileMonitor();//конструктор
    bool AddFile(QString FN);//Добавился ли файл, добавить, если нет
    bool DelFile(QString FN);//Удалился ли файл, если существует, удалить
signals:
    void FileCreated(QString FN,qint64 Size);//Изменения при создании файла
    void FileSizeChanged(QString FN, qint64 newSize);//Изменения размера файла
    void FileDeleted(QString FN);//Изменения при удалении файла

public slots:
    void FileChanged();
};

#endif // FILETRACKER_H
