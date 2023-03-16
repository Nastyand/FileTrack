#ifndef FILETRACKER_H
#define FILETRACKER_H

#include <QObject>

class StateFile
{
public:
    StateFile(QString);
    ~StateFile();
    GetState();
private:
    QString FileName;
    qint64 size;
    bool isExist;
};

class FileMonitor:public QObject
{
    Q_OBJECT
    StateFile *objects;
    QVector<FileState>objects;
public:
    // explicit FileMonitor(const QString& FileName, QObject* parent = nullptr);
    FileMonitor();
    ~FileMonitor();
signals:
    void SizeChanged(qint64 newSize);

private slots:
    void FileChanged(const QString& fileName);

};


#endif // FILETRACKER_H
