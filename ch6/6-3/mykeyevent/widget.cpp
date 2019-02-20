#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    setFocus();  //使主界面获得焦点
    keyUp = false;
    keyLeft = false;
    move = false;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    //Ctrl+M键盘事件
//    if(event->modifiers() == Qt::ControlModifier)   //是否按下了Ctrl+M键
//    {
//        if(event->key() == Qt::Key_M)
//            setWindowState(Qt::WindowMaximized);   //窗口最大化
//    }
//    else
//        QWidget::keyPressEvent(event);    //不知道干什么用的，可能是体现一定要先ctrl+M？

    //测试自动重复按键
//    if(event->key() == Qt::Key_Up)
//        qDebug()<<"press:"<<event->isAutoRepeat();  //一直按着上键则自动重复

    //上左键同时按下
    if(event->key() == Qt::Key_Up)
    {
        if(event->isAutoRepeat())    //按键重复时不处理，同时将向上键标记为按下
            return;
        keyUp=true;
    }
    else if(event->key() == Qt::Key_Left)
    {
        if(event->isAutoRepeat())    //同理对付左键
            return;
        keyLeft = true;
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    //不作为的释放事件
//    Q_UNUSED(event);
//    qDebug()<<"release!";

    //测试自动重复按键
//    if(event->key() == Qt::Key_Up)
//    {
//        qDebug()<<"release:"<<event->isAutoRepeat();
//        qDebug()<<"up";
//    }

    //上左键同时按下
    if(event->key() == Qt::Key_Up)
    {
        if(event->isAutoRepeat())  //按键重复时直接跳出
            return;
        keyUp=false;   //将keyup的状态归位
        if(move)
        {
            move=false;   //如果发生了移动，move归位
            return;
        }
        if(keyLeft)       //如果同时也按下了左方向键，按钮左上方斜移
        {
            ui->pushButton->move(30,80);
            move = true;
        }
        else
            ui->pushButton->move(120,80);  //否则直接向上移动即可
    }
    else if(event->key() == Qt::Key_Left)
    {
        if(event->isAutoRepeat())  //按键重复时直接跳出
            return;
        keyLeft=false;   //将keyleft的状态归位
        if(move)
        {
            move=false;   //如果发生了移动，move归位
            return;
        }
        if(keyUp)       //如果同时也按下了上方向键，按钮左上方斜移
        {
            ui->pushButton->move(30,80);
            move = true;
        }
        else
            ui->pushButton->move(30,120);  //否则直接向左移动即可
    }
    else if(event->key() == Qt::Key_Down)  //使用下键来使按钮归位
        ui->pushButton->move(120,120);
}
