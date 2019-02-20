#include <QCoreApplication>
#include <QList>
#include <QMap>
#include <QMultiMap>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QString> list;
    list<<"A"<<"B"<<"C";
    qDebug()<<"the list is";
    foreach (QString str, list)
        qDebug()<<str;

    QMap<QString,int> map;
    map.insert("first",1);
    map.insert("second",2);
    map.insert("third",3);
    qDebug()<<endl<<"the map is:";
    foreach(QString str,map.keys())
        qDebug()<<str<<":"<<map.value(str);

    QMultiMap<QString,int> map2;
    map2.insert("first",1);
    map2.insert("first",2);
    map2.insert("first",3);
    map2.insert("second",2);
    map2.insert("third",3);
    qDebug()<<endl<<"the map2 is";
    foreach(QString str,map2.uniqueKeys())
        foreach(int i,map2.values(str))
            qDebug()<<str<<":"<<i;

    return a.exec();
}
