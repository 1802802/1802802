#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //7.3.1 正则表达式介绍
    QRegExp rx("^\\d\\d?$");    //创建一个正则表达式，两字符开头都必须是数字，第二个字符可以没有(正则表达式不要没事打空格）
    qDebug()<<rx.indexIn("a1");
    qDebug()<<rx.indexIn("5");
    qDebug()<<rx.indexIn("5b");
    qDebug()<<rx.indexIn("12");
    qDebug()<<rx.indexIn("123");
    qDebug()<<"***********************************";
    rx.setPattern("\\b(mail|letter)\\b");  //在接下来的字符串中匹配这两单词其中一个第一次出现的位置（一定是单词，不是词中字）（因为\\b的存在）
    qDebug()<<rx.indexIn("emailletter");
    qDebug()<<rx.indexIn("my mail");
    qDebug()<<rx.indexIn("my email letter");
    qDebug()<<rx.indexIn("tletter to me the mail i don't know");
    qDebug()<<"***********************************";
    rx.setPattern("M(?!ail)");  //匹配字符M，但是其后面不能跟有ail字符
    QString str1 = "this is M";
    str1.replace(rx,"Mail");
    qDebug()<<"str1:"<<str1;
    QString str2 = "my M,your Ms,his Mail";
    str2.replace(rx,"Mail");
    qDebug()<<"str2:"<<str2;
    qDebug()<<"***********************************";
    QString str3 = "One Eric another Eirik, and an Eric Ericsson."
    "How many Eiriks,Eric?";
    QRegExp rx2("\\bEi?ri[ck]\\b");  //这里是E i? ri[ck]  中间的i可出现可不出现，最后的数可为c可为k
    int pos = 0;
    int count = 0;
    while(pos>=0)
    {
        pos = rx2.indexIn(str3,pos);
        if(pos>=0)
        {
            ++pos;      //从匹配的字符的下一个字符开始继续搜搜
            ++count;    //搜到一次就计数器+1
        }
    }
    qDebug()<<"count:"<<count;
    qDebug()<<"***********************************";

    //7.3.3 文本捕获
    QRegExp rx4("(\\d+)");   //正则表达式中使用括号（捕获文本）  多次不断地匹配数字
    QString str4 = "Offsets:12 8s2 14 99 231 7";
    QStringList list;
    int pos2 = 0;
    while((pos2 = rx4.indexIn(str4,pos2)) != -1)  //当在str4中还能捕获到数字时继续
    {
          list<<rx4.cap(1);    //cap函数中，为0时返回所有结果，从1开始由最左边括号开始计数
          pos2 += rx4.matchedLength();  //pos2不断增加上一次捕获到的字符串的长度
    }
    qDebug()<<"list:"<<list;
    qDebug()<<"***********************************";
    QRegExp rxlen("(\\d+)(?:\\s*)(cm|inch)");   //\\d+ 重复捕获数字  ?:\\s* 组合元素(将两者之间的空白元素组合）  cm|inch 捕获cm或inch
    int pos3 = rxlen.indexIn("Length:  s   189   cm");
    qDebug()<<tr("pos3:%1").arg(pos3);
    if(pos3>-1)
    {
        QString value = rxlen.cap(1);
        QString unit = rxlen.cap(2);
        QString string = rxlen.cap(0);
        qDebug()<<value<<unit<<string;
    }
    qDebug()<<"***********************************";
    QRegExp rx5("\\b(\\w+)\\W+\\1\\b");  //此处意思为：先捕获一个单词w，之后的单词W与w不同，再是单词w（\\1对应）。即查找重复单词
    rx5.setCaseSensitivity(Qt::CaseInsensitive);  //不区分大小写
    qDebug()<<rx5.indexIn("Hello--hello");
    qDebug()<<rx5.cap(1);
    QRegExp rx6("\\bme\\b");
    qDebug()<<rx6.indexIn("you and me , xin lian xin");
    qDebug()<<rx6.cap(0);
    qDebug()<<"***********************************";

    //7.3.4 新的QRegualExpression类
    QRegularExpression re("^(\\d\\d)/(\\d\\d)/(\\d\\d\\d\\d)$");
    QRegularExpressionMatch match = re.match("08/12/1985");
    if(match.hasMatch())
    {
        QString matched = match.captured(0);
        QString day = match.captured(1);
        QString month = match.captured(2);
        QString year = match.captured(3);
        qDebug()<<tr("matched:%1  day:%2  month:%3  year:%4").arg(matched,day,month,year);
    }
    QString pattern("^(Jan|Feb|Mar|Apr|May)\\s+\\d\\d?,\\d\\d\\d\\d$");
    QRegularExpression re1(pattern);
    QString input("Jan         21,");   //这些输入的数据，和正则表达式的处理式子，都很讲究，输错，输多输少都会有问题
    //第一个参数为正则表达式匹配的字符串，第二个为偏移量（跳过前N个匹配结果），第三个为匹配类型（此处表示部分匹配，若完全匹配则返回完全匹配）
    QRegularExpressionMatch match1 = re1.match(input,0,QRegularExpression::PartialPreferCompleteMatch);
    bool hasMatch = match1.hasMatch();
    bool hasPartialMatch = match1.hasPartialMatch();
    qDebug()<<"hasMatch:"<<hasMatch<<"hasPartialMatch:"<<hasPartialMatch;
}

Widget::~Widget()
{
    delete ui;
}
