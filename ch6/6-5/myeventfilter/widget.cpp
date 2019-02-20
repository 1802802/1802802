#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>
#include <QWheelEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->textEdit->installEventFilter(this);  //在这两个部件上安装事件过滤器，this指本部件widget
    ui->spinBox->installEventFilter(this);

    QKeyEvent myEvent(QEvent::KeyPress,Qt::Key_Up,Qt::NoModifier);  //手动写的事件
    qApp->sendEvent(ui->spinBox,&myEvent);  //通过调用全局指针的sendEvent函数，将事件发送到部件
    QKeyEvent myEvent2(QEvent::KeyPress,Qt::Key_Down,Qt::NoModifier);  //手动写的事件
    qApp->sendEvent(ui->spinBox,&myEvent2);  //通过调用全局指针的sendEvent函数，将事件发送到部件
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *obj,QEvent *event)
{
    if(obj == ui->textEdit)
    {
        if(event->type() == QEvent::Wheel)
        {
            QWheelEvent *wheelEvent = static_cast<QWheelEvent*>(event);
            //将event强制转换为wheelEvent类型，并赋值给wheelEvent事件
            if(wheelEvent->delta()>0)
                ui->textEdit->zoomIn();
            else
                ui->textEdit->zoomOut();
            return true;            //表示该事件已经被处理，返回true，表示该事件无需继续被传递和被处理
        }
        else
            return false;           //表示该事件不处理，返回false，表示该事件需要继续被传递和被处理
    }
    else if(obj == ui->spinBox)
    {
        if(event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            if(keyEvent->key() == Qt::Key_Space)
            {
                ui->spinBox->setValue(0);
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
    else
        return QWidget::eventFilter(obj,event);  //如果事件不是过滤器所需要的操作，则转交QWidget的事件过滤器来处理该事件
}
