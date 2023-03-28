#ifndef FILETRACKER_H
#define FILETRACKER_H

#include <QObject>
#include <QFileInfo>
#include <QString>
#include <QVector>
#include <iostream>

using namespace std;

class StateFile//класс, хранящий состояние одного файла
{
public:
    StateFile();//конструктор по умолчанию
    StateFile(const QString& FN);//конструктор с аргументом
    QString GetFileName();//геттеры
    qint64 GetSize();
    bool GetExist();
    bool operator==(const StateFile file)const;//перегрузка оператора==
private:
    QString FileName;
    qint64 size;
    bool isExist;
};

class FileMonitor:public QObject//класс, который следит за состояниями всех файлов
{
     Q_OBJECT
    QVector<StateFile>objects;
public:
    FileMonitor(QObject* parent = nullptr);//конструктор
    bool AddFile(QString FN);//Добавился ли файл, добавить, если нет
    bool DelFile(QString FN);//Удалился ли файл, если существует, удалить
signals:
    void FileCreated(QString FN,qint64 Size);//Изменения при создании файла
    void FileSizeChanged(QString FN, qint64 newSize);//Изменения размера файла
    void FileDeleted(QString FN);//Изменения при удалении файла

public slots:
    void FileChanged();
};

class FilePrinter:public QObject//класс, который выводит сообщение на консоль
{
    Q_OBJECT
public:
     FilePrinter(QObject* parent = nullptr);//конструктор

public slots:
    void PrintIfFileCreated(QString FN, qint64 size);//вывод при создании файла
    void PrintIfFileChanged(QString FN, qint64 size);//вывод при изменении файла
    void PrintIfFileDeleted(QString FN);//вывод при удалении файла
};


#endif // FILETRACKER_H
