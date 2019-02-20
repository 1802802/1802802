#include "mywidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    w.setWindowTitle(QString::fromLocal8Bit("3.3节"));
    w.show();

    return a.exec();
}
