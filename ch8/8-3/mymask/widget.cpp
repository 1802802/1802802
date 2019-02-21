#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QBitmap>
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //对于标签Label部件的遮罩操作
    //QPixmap pixmap("D:/Users/CAD/Documents/QT_Study/ch8/8-3/mymask/yafeilinux.png");
//    QPixmap pixmap(":/image/yafeilinux.png"); //使用资源系统，先qmake（利用源文件生成工程）一下才行！
//    ui->label->setPixmap(pixmap);
//    ui->label->setMask(pixmap.mask());  //标签部件的遮罩

    //对于窗口的遮罩
    QPixmap pix(":/image/yafeilinux.png");
    resize(pix.size());   //将标签的大小变为图片的大小
    setMask(pix.mask());
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);     //顺便一提，这张图太小了，窗口的边框界面无法绘制出来
    painter.drawPixmap(0,0,QPixmap(":/image/yafeilinux.png"));  //从左上角开始绘制
}

void Widget::mousePressEvent(QMouseEvent *)
{
    close();
}
