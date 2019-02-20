#include "widget.h"
#include "ui_widget.h"
#include "myclass.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    MyClass *my = new MyClass(this);
    connect(my,&MyClass::userNameChanged,this,&Widget::userChanged);
    my->setUserName("yangzitong");
    qDebug()<<"userName1:"<<my->getUsername();    //第一次，通过对类的操作，定义与输出原属性名字
    my->setProperty("userName","kelisi");
    qDebug()<<"userName2:"<<my->property("userName").toString();  //第二次，通过属性修改并输出名字（这里的输出将property的输出格式强转成了qstring）

    my->setProperty("myValue",10);   //动态的额外添加一个myValue属性
    qDebug()<<"myValue:"<<my->property("myValue").toInt();   //然后输出这个属性的特性
}

Widget::~Widget()
{
    delete ui;
}

void Widget::userChanged(QString userName)
{
    qDebug()<<"user changed:"<<userName;
}
