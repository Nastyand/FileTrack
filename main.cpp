#include <QCoreApplication>
#include<QTimer>
#include "filetracker.h"
#include <iostream>


using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    FilePrinter* printer=new FilePrinter();// Создаем объект класса FilePrinter
    FileMonitor* monitor = new FileMonitor(); // Создаем объект класса FileMonitor
    monitor->AddFile("C:/qtproject/FileTrack/file1.txt");
    monitor->AddFile("C:/qtproject/FileTrack/file2.txt");
    monitor->DelFile("C:/qtproject/FileTrack/file2.txt");
    QObject::connect(monitor, &FileMonitor::FileCreated, printer, &FilePrinter::PrintIfFileCreated);
    QObject::connect(monitor, &FileMonitor::FileSizeChanged, printer, &FilePrinter::PrintIfFileChanged);
    QObject::connect(monitor, &FileMonitor::FileDeleted, printer, &FilePrinter::PrintIfFileDeleted);
    //Написать таймер
    while (true) {
               monitor->FileChanged();
           }
    return app.exec();
}
