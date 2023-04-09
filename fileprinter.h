#ifndef FILEPRINTER_H
#define FILEPRINTER_H

#include <iostream>
#include <QObject>
#include <QString>

using namespace std;

class FilePrinter:public QObject//класс, который выводит сообщение на консоль
{
    Q_OBJECT
public:
    FilePrinter();//конструктор
    void PrintIfFileCreated(QString FN, qint64 size);//вывод при создании файла
    void PrintIfFileChanged(QString FN, qint64 size);//вывод при изменении файла
    void PrintIfFileDeleted(QString FN);//вывод при удалении файла
};
#endif // FILEPRINTER_H
