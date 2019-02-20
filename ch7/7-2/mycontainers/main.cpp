#include <QCoreApplication>
#include <QList>
#include <list>
#include <QMap>
#include <QMultiMap>
#include <QDebug>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    list<QString> list2;
    list2.push_back("aa");
    list2.push_back("bb");
    list2.push_back("cc");
    for(auto &s : list2)
        qDebug()<<s<<endl;

    //QList库
    QList<QString> list;
    list << "aa" << "bb" << "cc"; // 插入项目   //说真的，这个操作简直天秀
    if(list[1] == "bb") list[1] = "ab";
    list.replace(2, "bc");        // 将“cc”换为“bc”
    qDebug() << "the list is: ";  // 输出整个列表
    for(int i=0; i<list.size(); ++i)
    {
        qDebug() << list.at(i);   // 现在列表为aa ab bc
    }
    //list.push_back("dd");       //使用STL的函数都是可以的，QT只是在原库的基础上进行了改良
    list.append("dd");            // 在列表尾部添加
    //list.push_front("mm");
    list.prepend("mm");           // 在列表头部添加
    QString str = list.takeAt(2); // 从列表中删除第3个项目，并获取它
    qDebug() << "at(2) item is: " << str;
    qDebug() << "the list is: ";
    for(int i=0; i<list.size(); ++i)
    {
        qDebug() << list.at(i);   // 现在列表为mm aa bc dd
    }
    list.insert(2, "mm");         // 在位置2插入项目
    list.swap(1,3);               // 交换项目1和项目3
    qDebug() << "the list is: ";
    for(int i=0; i<list.size(); ++i)
    {
        qDebug() << list.at(i);   // 现在列表为mm bc mm aa dd
    }
    qDebug() << "contains 'mm' ?" << list.contains("mm"); // 列表中是否包含“mm”
    qDebug() << "the 'mm' count: " << list.count("mm"); // 包含“mm”的个数
    // 第一个“mm”的位置，默认从位置0开始往前查找，返回第一个匹配的项目的位置
    qDebug() << "the first 'mm' index: " << list.indexOf("mm");
    // 第二个“mm”的位置，我们指定从位置1开始往前查找
    qDebug() << "the second 'mm' index: " << list.indexOf("mm", 1);
    qDebug() << endl;

    //QMap库
    QMap<QString, int> map;
    map["one"] = 1;          // 向map中插入("one",1)
    map["three"] = 3;
    map.insert("seven", 7);   // 使用insert()函数进行插入

    // 获取键的值，使用“[ ]”操作符时如果map中没有该键，那么会自动插入
    int value1 = map["six"];
    qDebug() << "value1:" << value1;
    qDebug() << "contains 'six' ?" << map.contains("six");

    // 使用value()函数获取键的值，这样当键不存在时,不会自动插入
    int value2 = map.value("five");
    qDebug() << "value2:" << value2;
    qDebug() << "contains 'five' ?" << map.contains("five");

    // 当键不存在时，value()默认返回0，这里可以设定该值，比如这里设置为9
    int value3 = map.value("nine", 9);
    qDebug() << "value3:" << value3;

    // map默认是一个键对应一个值，如果重新给该键设置了值，那么以前的会被擦除
    map.insert("ten", 10);
    map.insert("ten", 100);
    qDebug() << "ten: " << map.value("ten");

    // 可以使用insertMulti()函数来实现一键多值，然后使用values()函数来获取值的列表
    map.insertMulti("two", 2);
    map.insertMulti("two", 4);
    QList<int> values = map.values("two");
    qDebug() << "two: " << values;

    // 也可以使用QMultiMap类来实现一键多值
    QMultiMap<QString, int> map1, map2, map3;
    map1.insert("values", 1);
    map1.insert("values", 2);
    map2.insert("values", 3);
    // 可以进行相加，这样map3的“values”键将包含2,1,3三个值
    map3 = map2 + map1;
    QList<int> myValues = map3.values("values");
    qDebug() << "the values are: ";
    for (int i=0; i<myValues.size(); ++i) {
        qDebug() << myValues.at(i);
    }

    return a.exec();
}
