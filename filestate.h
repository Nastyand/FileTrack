#ifndef FILESTATE_H
#define FILESTATE_H

#include <QFileInfo>
#include <QString>

class StateFile//класс, хранящий информацию о файле
{
public:
    StateFile();//конструктор по умолчанию
    StateFile(QString FN);//конструктор с аргументом
    QString GetFileName();//геттеры
    qint64 GetSize();
    bool GetExist();
    bool operator==(StateFile file)const;//перегрузка оператора==
private:
    QString FileName;
    qint64 size;
    bool isExist;
};

#endif // FILESTATE_H
