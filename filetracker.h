#ifndef FILETRACKER_H
#define FILETRACKER_H

#include <QObject>
#include <QFileInfo>
#include <QString>
#include <QVector>

class StateFile
{
public:
    StateFile(const QString& FN);
    ~StateFile();
    QString GetFileName();
    qint64 GetSize();
    bool GetExist();
private:
    QString FileName;
    qint64 size;
    bool isExist;
};

class FileMonitor:public QObject
{
    Q_OBJECT
    StateFile *objects;
    QVector<StateFile>objects;
public:
    // explicit FileMonitor(QObject* parent = nullptr);
    FileMonitor();
    ~FileMonitor();
    bool AddFile(QString FN);//Добавился ли файл
    bool DelFile(QString FN);//Удалился ли файл
signals:
    void FileCreated(const QString& FN);//Изменения при создании файла
    void FileSizeChanged(const QString& FN, qint64 newSize);//Изменения размера файла
    void FileDeleted(const QString& FN);//Изменения при удалении файла

private slots:
    void FileChanged(const QString& FN);
};


#endif // FILETRACKER_H
