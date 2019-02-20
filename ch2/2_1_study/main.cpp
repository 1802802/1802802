#include "hellodialog.h"
#include <QApplication>

//2019_2_20 上传
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HelloDialog w;
    w.show();

    return a.exec();
}
