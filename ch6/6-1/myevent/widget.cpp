#include "widget.h"
#include "ui_widget.h"
#include "mylineedit.h"
#include <QKeyEvent>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    lineEdit = new MyLineEdit(this);
    lineEdit->move(150,150);

    lineEdit2 = new MyLineEdit(this);   //创建了一个新的lineedit，其没有安装过滤器，直接执行该部件的事件函数
    lineEdit2->move(100,100);

    lineEdit->installEventFilter(this); //为当前widget安装事件过滤器
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<QString::fromLocal8Bit("Widget键盘按下事件")<<endl;
}

bool Widget::eventFilter(QObject *obj,QEvent *event)
{
    if(obj == lineEdit)   //如果是lineedit部件上的事件
    {
        if(event->type() == QEvent::KeyPress)  //如果输入事件为键盘输入事件
            qDebug()<<QString::fromLocal8Bit("Widget的事件过滤器");
    }
    return QWidget::eventFilter(obj,event);
}
