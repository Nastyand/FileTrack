#ifndef FILETRACKER_H
#define FILETRACKER_H

#include <QObject>
#include <QFileInfo>
#include <QString>
#include <QVector>

class StateFile:public QObject//отслеживает состояние каждого отдельного файла
{
     Q_OBJECT
public:
    StateFile(const QString& FN);
    ~StateFile();//Подумать нужен ли
    QString GetFileName();
    qint64 GetSize();
    bool GetExist();
signals:
    void FileCreated(const QString& FN,qint64 Size);//Изменения при создании файла
    void FileSizeChanged(const QString& FN, qint64 newSize);//Изменения размера файла
    void FileDeleted(const QString& FN);//Изменения при удалении файла

private slots:
    void FileChanged(const QString& FN);
private:
    QString FileName;
    qint64 size;
    bool isExist;
};

class FileMonitor//Какая связь с классом StateFile
{
    StateFile *objects;
    QVector<StateFile>objects;
public:
    // explicit FileMonitor(QObject* parent = nullptr);//какой конструктор, что он будет делать
    FileMonitor();
    ~FileMonitor();
    bool AddFile(QString FN);//Добавился ли файл, добавить, если нет
    bool DelFile(QString FN);//Удалился ли файл, если существует, удалить
};


#endif // FILETRACKER_H
