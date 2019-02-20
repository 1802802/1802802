#include "widget.h"
#include "ui_widget.h"
#include "mydialog.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    MyDialog *dlg = new MyDialog(this);
    //connect(dlg,SIGNAL(dlgReturn(int)),this,SLOT(showValue(int)));  //关联对话框的数值返回信号与窗口的显示数的槽
    connect(dlg,&MyDialog::dlgReturn,this,&Widget::showValue);  //关联的另一种重载形式
    //connect(dlg,SIGNAL(dlgReturn(int)),this,SLOT(showValue(int)),Qt::QueuedConnection);   //最后的type为连接关系
    dlg->show();
    dlg->exec(); //用于实现模态对话框
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showValue(int Value)
{
    ui->label->setText(QString::fromLocal8Bit("显示的数值为：%1").arg(Value));
}
