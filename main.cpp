#include <QCoreApplication>
#include<QTimer>
#include "filestate.h"
#include "filemonitor.h"
#include "fileprinter.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    FilePrinter printer;// Создаем объект класса FilePrinter
    FileMonitor monitor;// Создаем объект класса FileMonitor
    monitor.AddFile("C:/qtproject/FileTrack/file1.txt");
    monitor.AddFile("C:/qtproject/FileTrack/file2.txt");
    monitor.AddFile("C:/qtproject/FileTrack/file1.txt");
    //monitor.DelFile("C:/qtproject/FileTrack/file2.txt");
    //monitor.DelFile("C:/qtproject/FileTrack/file3.txt");
    QObject::connect(&monitor, &FileMonitor::FileCreated, &printer, &FilePrinter::PrintIfFileCreated);
    QObject::connect(&monitor, &FileMonitor::FileSizeChanged, &printer, &FilePrinter::PrintIfFileChanged);
    QObject::connect(&monitor, &FileMonitor::FileDeleted, &printer, &FilePrinter::PrintIfFileDeleted);
    //Таймер
    QTimer timer;
    timer.setInterval(1000);
    QObject::connect(&timer, &QTimer::timeout, &monitor, &FileMonitor::FileChanged);
    timer.start();
    return app.exec();
}
