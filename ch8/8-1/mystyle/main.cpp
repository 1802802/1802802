#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyle(QStyleFactory::create("fuison"));  //整体风格

    MainWindow w;
    w.show();

    return a.exec();
}
