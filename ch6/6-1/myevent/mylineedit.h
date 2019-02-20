#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H
#include <QLineEdit>

class MyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit MyLineEdit(QWidget *parent = 0);
    bool event(QEvent *event);    //当前部件的事件函数，当此部件为焦点时，首先执行此函数
protected:
    void keyPressEvent(QKeyEvent *event);  //当前部件的事件处理函数，在此部件的事件函数处理完毕后执行
};

#endif // MYLINEEDIT_H
