#include "mylineedit.h"
#include <QKeyEvent>
#include <QDebug>

MyLineEdit::MyLineEdit(QWidget *parent):QLineEdit(parent)
{

}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<QString::fromLocal8Bit("MyLineEdit键盘按下事件");
    event->ignore();
}

bool MyLineEdit::event(QEvent *event)  //事件
{
    if(event->type()==QEvent::KeyPress)  //如果事件类型为键盘输入
        qDebug()<<QString::fromLocal8Bit("MyLineEdit的event()函数");
    return QLineEdit::event(event);      //这里使用QLineEdit基类的event函数来处理此事件
}
