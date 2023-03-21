#include <QCoreApplication>
#include "filetracker.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    StateFile file1("file1.txt");
    FileMonitor Monitor;
    Monitor.AddFile(file1);
    QObject::connect(file1, &StateFile::FileChanged, PrintIfFileCreated);
}
