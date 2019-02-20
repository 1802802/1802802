#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class MyLineEdit;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    bool eventFilter(QObject *obj,QEvent *event);  //事件过滤器，接受QOBject（事件对象），QEvent（事件）
    ~Widget();

private:
    Ui::Widget *ui;
    MyLineEdit *lineEdit;
    MyLineEdit *lineEdit2;

protected:
    void keyPressEvent(QKeyEvent *event);   //widget的事件处理函数，接受QkeyEvent（键盘按下事件）
};

#endif // WIDGET_H
