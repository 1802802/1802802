#include<QApplication>
#include<QDialog>
#include<QLabel>
int main(int argc,char* argv[])
{
    QApplication a(argc,argv);   //基本对象，管理全局
    QDialog w;   //w表示一个对话框
    w.resize(400,300);
    QLabel label(&w);  //表示标签label的父对象为w
    label.move(120,120);
    label.setText(QObject::tr("Welcome to the world!"));
    w.show();
    return a.exec();
}
