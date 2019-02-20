#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVariant v1(15);
    qDebug()<<v1.toInt();

    QVariant v2(12.3);
    qDebug()<<v2.toFloat();

    QVariant v3("nihao");
    qDebug()<<v3.toString();

//    QColor color = QColor(Qt::red);
//    QVariant v4 = color;
//    qDebug()<<v4.type();
//    qDebug()<<v4.value<QColor>();

    QString str = "hello";
    QVariant v5 = str;
    qDebug()<<v5.canConvert(QVariant::Int);
    qDebug()<<v5.toString();
    qDebug()<<v5.canConvert(QVariant::Bool);
    qDebug()<<v5.toBool();
    qDebug()<<v5.convert(QVariant::Int);
    qDebug()<<v5.toString();   //此处由于上一步的转换失败，v5被清空，从而输出为0


    return a.exec();
}
