#include "widget.h"
#include "ui_widget.h"
#include <QDialog>
#include <QTime>
#include <QTimer>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QFont font;
    font.setPointSize(20);
    font.setFamily("微软雅黑");
    ui->label->setFont(font);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_2_clicked()
{
    int rand1 = qrand() % 700;
    int rand2 = qrand() % 300;
    ui->pushButton_2->move(rand1,rand2);
}

void Widget::on_pushButton_clicked()
{
    QDialog *dialog = new QDialog(this);
    dialog->resize(500,100);

    QLabel *label = new QLabel(dialog);
    QFont font;
    font.setPointSize(20);
    font.setFamily("微软雅黑");
    label->setFont(font);

    label->setText(QString::fromLocal8Bit("没错！杨梓桐就是李鹏程的爹！"));
    dialog->show();
}
