#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QTime>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //传统的TimerEvent事件触发，定时器溢出时产生事件，使用事件处理函数来接应
    id1 = startTimer(1000);
    id2 = startTimer(1500);
    id3 = startTimer(2000);

    //适用性更强的QTimer类，定时器溢出时发出信号，使用槽来接应
    QTimer *timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&Widget::timerUpdate);  //将新timer的timeout信号与timerupdate槽绑定
    timer->start(1000);   //timer定时器每隔一秒计时一次，在其溢出后发出timeout信号

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));  //secsTo表示从当前时间点到对应时间点所包含的秒数
    //这里表示从零点整到当前时间点的秒数差距，用于给qsrand函数设置初值，使每次随机的数据都不一样

    //只运行一次的定时器，将其timeout信号与窗口关闭的槽对应
    QTimer::singleShot(10000,this,&Widget::close);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)  //当任何一个定时器溢出时，执行此函数
{
    if(event->timerId() == id1)
        qDebug()<<"timer1";
    else if(event->timerId() == id2)
        qDebug()<<"timer2";
    else if(event->timerId() == id3)
        qDebug()<<"timer3";
}

void Widget::timerUpdate()
{
    QTime time = QTime::currentTime();   //获取当前时间
    QString text = time.toString("hh:mm");  //转换为字符串
    if((time.second()%2) == 0)   //first为分，second为秒。每隔一秒显示空格（即闪烁一下）
        text[2] = ' ';  //[0到4]分别是hh:mm
    ui->lcdNumber->display(text);

    int rand = qrand() % 300;    //使随机数rand的取值处于0-299之间
    ui->lcdNumber->move(rand,rand);  //每秒随机移动
}
