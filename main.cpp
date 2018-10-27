#include "mainwindow.h"
#include <QApplication>
#include <auto-files-bkup/src/Transfer.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    Transfer transfer("/home/jakaria/C++/apps");

//    transfer.setTargetDir("/home/jakaria/C++/xyz");
//    transfer.setDelay(2);

//    transfer.move();

    return a.exec();
}
