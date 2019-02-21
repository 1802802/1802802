#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;   //翻译的代码务必放在MainWindow的创建之前
    translator.load("D:/Users/CAD/Documents/QT_Study/ch9/9-1/myI18N/myI18N_zh_CN.qm");
    a.installTranslator(&translator);

    MainWindow w;
    w.show();

    return a.exec();
}
