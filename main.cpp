#include <QCoreApplication>
#include<QTimer>
#include "filetracker.h"
#include <iostream>


using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    StateFile file1("C:/qtproject/FileTrack/file1.txt");
    FilePrinter printer;
    //FileMonitor Monitor;
    //Monitor.AddFile("C:/qtproject/FileTrack/file1.txt");
    QObject::connect(&file1, &StateFile::FileCreated, &printer, &FilePrinter::PrintIfFileCreated);
    QObject::connect(&file1, &StateFile::FileSizeChanged, &printer, &FilePrinter::PrintIfFileChanged);
    QObject::connect(&file1, &StateFile::FileDeleted, &printer, &FilePrinter::PrintIfFileDeleted);
    //Написать таймер
    //QTimer::singleShot(0, &app, SLOT(quit()));
       return app.exec();
}
