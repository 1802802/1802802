#ifndef MYSYNTAXHIGHLIGHTER_H
#define MYSYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>

class MySyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT      //在Qt中，如果一个类要使用信号/槽功能，就必须在其中声明Q_OBJECT
public:
    explicit MySyntaxHighlighter(QTextDocument *parent = 0);

protected:
    void highlightBlock(const QString &text); //必须重新实现该函数
};

#endif // MYSYNTAXHIGHLIGHTER_H
