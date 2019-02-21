#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QGraphicsBlurEffect>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //窗口整体透明化  可以配合窗口内矩形选定来使用
//    setWindowOpacity(0.5);

    //窗口完全透明化，同时部件正常
//    setWindowFlags(Qt::FramelessWindowHint);
//    setAttribute(Qt::WA_TranslucentBackground);

        // 创建阴影效果
        QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
        // 设置阴影颜色
        effect->setColor(QColor(100, 100, 100, 100));
        // 设置阴影模糊半径
        effect->setBlurRadius(2);
        // 设置阴影偏移值
        effect->setOffset(10);
        // 标签部件使用阴影效果
        ui->label->setGraphicsEffect(effect);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.fillRect(rect(),QColor(255,155,255,100));
}
