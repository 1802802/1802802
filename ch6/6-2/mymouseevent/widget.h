#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QPoint offset;  //用于存储鼠标指针位置与窗口位置的差值

protected:    //只要在头文件中声明了的函数，都必须要声明后才能运行。这里的函数都是已有的，此处只是对其进行重载，所以对应的操作—函数接口都是不需要改变的
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
};

#endif // WIDGET_H
