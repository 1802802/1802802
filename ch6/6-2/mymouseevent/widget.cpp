#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QCursor cursor;                             //创建一个新的光标对象
    cursor.setShape(Qt::OpenHandCursor);        //对新光标设置形状（张开的手）
    setCursor(cursor);                          //将新光标设置为当前使用的光标

    setMouseTracking(true);    //开启窗口模式（Widget）的鼠标跟踪
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)  //左右键按下后切换光标
{
    if(event->button() == Qt::LeftButton)         //如果传递的鼠标事件是鼠标左键按下事件
    {
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor);  //将鼠标指针暂时变为闭合的手的形状
        offset = event->globalPos() - pos();      //获取指针的位置和窗口位置的差值
        qDebug()<<tr("offset x:%1 y:%2").arg(offset.x()).arg(offset.y());
    }
    else if(event->button() == Qt::RightButton)   //如果传递的鼠标事件是鼠标右键按下事件
    {
        QCursor cursor(QPixmap("D:/Users/CAD/Documents/QT_Study/ch6/6-2/mymouseevent/logo.png"));
        QApplication::setOverrideCursor(cursor);  //将自定义的图片作为鼠标指针
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)   //按住左键后可以拖动窗口移动
{
    if(event->buttons() & Qt::LeftButton)  //鼠标移动时所有的键都会被检测，所以判断buttons和左键的“与”是否为真
    {
        QPoint temp;
        temp = event->globalPos() - offset;//此数据是随着鼠标的移动而不断实时计算的
        qDebug()<<tr("temp x:%1 y:%2").arg(temp.x()).arg(temp.y());
        move(temp);                  //使用鼠标指针当前的位置减去差值，就得到了窗口应该移动到的位置
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)  //释放鼠标左键后，光标形状复原
{
    Q_UNUSED(event);            //明示不使用形参event，从而不产生警报
    QApplication::restoreOverrideCursor();  //光标形状复原
}

void Widget::mouseDoubleClickEvent(QMouseEvent *event)  //双击鼠标左键全屏，右键提示
{
    if(event->button() == Qt::LeftButton)     //这是双击鼠标左键的操作
    {
        if(windowState()!= Qt::WindowFullScreen)   //如果不是全屏就全屏，是全屏就回到原大小
            setWindowState(Qt::WindowFullScreen);
        else
            setWindowState(Qt::WindowNoState);
    }
    else if(event->button() == Qt::RightButton)
        qDebug()<<QString::fromLocal8Bit("双击左键全屏");
}

void Widget::wheelEvent(QWheelEvent *event)   //滑动滚轮使文本编辑区的字放大/缩小
{
    if(event->delta()>0)          //向前滑和向后滑的区别就是这个delta的值
        ui->textEdit->zoomIn();   //文本编辑区的字放大
    else
        ui->textEdit->zoomOut();  //文本编辑区的字缩小
}
