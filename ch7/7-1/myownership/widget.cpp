#include "widget.h"
#include "ui_widget.h"
#include "mybutton.h"
#include <QDebug>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    MyButton *button = new MyButton(this);   //创建一个按钮,(this)用于指定其府部件为当前Widget
    button->setText(QString::fromLocal8Bit("button"));

    MyButton *button2 = new MyButton;
    MyButton *button3 = new MyButton;
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(button2);
    layout->addWidget(button3);  //将两个新的按钮增加到新建的布局中
    setLayout(layout);  //将新建的布局设置为当前的布局。在此操作之后，系统会自动地将两个按钮和布局的的父部件设置为当前Widget
    qDebug()<<children();  //输出当前Widget的所有子部件的列表
}

Widget::~Widget()
{
    delete ui;
    qDebug()<<"delete widget";
}
