#include "fileprinter.h"

FilePrinter::FilePrinter(){}

void FilePrinter::PrintIfFileCreated(QString FN, qint64 size)
{
    cout<<"File "<<FN.toStdString()<<" exists, his size "<<size<<endl;
}
void FilePrinter::PrintIfFileChanged(QString FN, qint64 size)
{
    cout<<"File "<<FN.toStdString()<<" changed, his size "<<size<<endl;
}
void FilePrinter::PrintIfFileDeleted(QString FN)
{
    cout<<"File "<<FN.toStdString()<<" deleted"<<endl;
}
