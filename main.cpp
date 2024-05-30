#include <QApplication>
#include "mainwindow.h"
#include <iostream>

int main(int argc, char *argv[])
{
    qInfo() << "Hello, World!" << "\n";
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return QApplication::exec();
}
