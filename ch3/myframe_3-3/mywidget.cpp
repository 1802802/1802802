#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QCompleter>
#include <QTimer>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //3.3.1
    QFont font;
    font.setFamily("微软雅黑");
    font.setPointSize(8);
    font.setBold(true);
    font.setItalic(true);
    ui->label->setFont(font);

    QString string = QString::fromLocal8Bit("标题太长，需要进行省略！");  //关于这个tr，似乎在使用label时可以中文。在widget中使用时用fromlocal8bit
    QString str = ui->label->fontMetrics().elidedText(string,Qt::ElideRight,180);
    ui->label->setText(str);

    ui->lcdNumber->display(123.4567);

    //3.3.3
    QValidator *validator = new QIntValidator(100,999,this);
    ui->lineEdit3->setValidator(validator);

    QStringList wordlist;
    wordlist<<"QT"<<"QT Creator"<<"Queen"<<QString::fromLocal8Bit("你好");   //自动补全的单词
    QCompleter *completer = new QCompleter(wordlist,this);  //新建自动完成器
    completer->setCaseSensitivity(Qt::CaseInsensitive);     //对新建的自动完成器设置大小不敏感的自动完成
    ui->lineEdit4->setCompleter(completer);

    //3.3.4
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());  //设置时间为现在的系统时间
    ui->dateTimeEdit->setDisplayFormat(QString::fromLocal8Bit("yyyy年MM月dd日A ddd HH时 mm分 ss秒"));  //设置时间的显示格式为中国人格式，这里的字符对应的格式都有讲究的
}

MyWidget::~MyWidget()
{
    delete ui;
}


void MyWidget::on_checkBox_stateChanged(int arg1)    //根据argl的值，判断当前的选项是什么状态
{
    qDebug()<<QString::fromLocal8Bit("选中了");
}

void MyWidget::on_lineEdit2_returnPressed()
{
    ui->lineEdit3->setFocus();                                                       //得到焦点，即光标随着回车移动到下一行
    qDebug()<<QString::fromLocal8Bit("输入的数据为：")<<ui->lineEdit2->text();         //输出lineeidt2的内容
    qDebug()<<QString::fromLocal8Bit("显示的数据为：")<<ui->lineEdit2->displayText();  //输出lineedit2显示的内容
}

void MyWidget::on_lineEdit3_returnPressed()
{
    qDebug()<<QString::fromLocal8Bit("输入的数据为：")<<ui->lineEdit3->text();
}
