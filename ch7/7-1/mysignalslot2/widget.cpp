#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    QPushButton *button = new QPushButton(this);
    button->setObjectName("myButton");    //创建一个按钮，并修改其对象名字，以匹配定义的信号槽函数
    button->setText(tr("close"));

    ui->setupUi(this);    //此函数会调用connectSlotsByName函数（即自动关联的引导函数），所以需要自动关联的部件都需要在此语句之前创建
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_myButton_clicked()
{
    close();
}
