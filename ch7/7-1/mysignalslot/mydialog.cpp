#include "mydialog.h"
#include "ui_mydialog.h"
#include <QDebug>

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_pushButton_clicked()  //这种形式的是从UI设计师界面中自动生成的信号与槽关联
{
    int value = ui->spinBox->value();  //获取输入的值
    emit dlgReturn(value);             //发射信号,emit为发射函数
    qDebug()<<QString::fromLocal8Bit("MyDialog对话框中的信号发射");
    close();
}
