#include <QCoreApplication>
#include <QDebug>
#include <QStringList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << QString::fromLocal8Bit("以下是编辑字符串操作：") << endl;
    //字符串的编辑操作
    QString str = "hello";
    qDebug() << QString::fromLocal8Bit("字符串大小：") << str.size(); // 大小为5
    str[0] = QChar('H');      // 将第一个字符换为‘H'  Hello
    qDebug() << QString::fromLocal8Bit("第一个字符：") << str[0]; // 结果为‘H'
    str.append(" Qt");        // 向字符串后添加"Qt"   Hello Qt
    str.replace(1,4,"i");     // 将第1个字符开始的后面4个字符替换为字符串"i"  Hi Qt
    str.insert(2," my");      // 在第2个字符处插入" my"  Hi my Qt
    qDebug() << QString::fromLocal8Bit("str为：") << str; // 结果为Hi my Qt
    str = str + "!!!";        // 将两个字符串组合
    qDebug() << QString::fromLocal8Bit("str为：") << str; // 结果为Hi my Qt！！！

    str = " hi\r\n Qt!\n  ";
    qDebug() << QString::fromLocal8Bit("str为：") << str;
    QString str1 = str.trimmed();    // 除去字符串两端的空白字符
    qDebug() << QString::fromLocal8Bit("str1为：") << str1;
    QString str2 = str.simplified(); // 除去字符串两端和中间多余的空白字符
    qDebug() << QString::fromLocal8Bit("str2为：") << str2; //结果为hi Qt！

    str = "hi,my,,Qt";
    // 从字符串中有","的地方将其分为多个子字符串，
    // QString::SkipEmptyParts表示跳过空的条目
    QStringList list = str.split(",",QString::SkipEmptyParts);
    qDebug() << QString::fromLocal8Bit("str拆分后为：") << list;  // 结果为hi,my,Qt
    str = list.join(" "); // 将各个子字符串组合为一个字符串，中间用" "隔开
    qDebug() << QString::fromLocal8Bit("list组合后为：") << str;  // 结果为hi my Qt

    qDebug() << QString().isNull();     // 结果为true
    qDebug() << QString().isEmpty();    // 结果为true
    qDebug() << QString("").isNull();   // 结果为false
    qDebug() << QString("").isEmpty();  // 结果为true

    //字符串的查询操作
    qDebug() << endl << QString::fromLocal8Bit("以下是在字符串中进行查询的操作：") <<endl;
    str = "yafeilinux";
    qDebug() << QString::fromLocal8Bit("字符串为：") << str;
    // 执行下面一行代码后，结果为linux
    qDebug() << QString::fromLocal8Bit("包含右侧5个字符的子字符串：") << str.right(5);
    // 执行下面一行代码后，结果为yafei
    qDebug() << QString::fromLocal8Bit("包含左侧5个字符的子字符串：") << str.left(5);
    // 执行下面一行代码后，结果为fei
    qDebug() << QString::fromLocal8Bit("包含第2个字符以后3个字符的子字符串：") << str.mid(2, 3);
    qDebug() << QString::fromLocal8Bit("'fei'的位置：") << str.indexOf("fei"); //结果为2
    qDebug() << QString::fromLocal8Bit("str的第0个字符：") << str.at(0); //结果为y
    qDebug() << QString::fromLocal8Bit("str中'i'字符的个数：") << str.count('i'); //结果为2
    // 执行下面一行代码后，结果为true
    qDebug() << QString::fromLocal8Bit("str是否以”ya“开始？") << str.startsWith("ya");
    // 执行下面一行代码后，结果为true
    qDebug() << QString::fromLocal8Bit("str是否以”linux“结尾？") << str.endsWith("linux");
    // 执行下面一行代码后，结果为true
    qDebug() << QString::fromLocal8Bit("str是否包含”lin“字符串？") << str.contains("lin");
    QString temp = "hello";
    if(temp > str) qDebug() << temp; // 两字符串进行比较，结果为yafeilinux
    else qDebug() << str;

    qDebug() << endl << QString::fromLocal8Bit("以下是字符串的转换操作：") << endl;
    str = "100";
    qDebug() << QString::fromLocal8Bit("字符串转换为整数：") << str.toInt(); // 结果为100
    int num = 45;
    qDebug() << QString::fromLocal8Bit("整数转换为字符串：") << QString::number(num);//结果为"45"
    str = "FF";
    bool ok;
    int hex = str.toInt(&ok, 16);
    // 结果为ok：true 255
    qDebug() << "ok: "<< ok << QString::fromLocal8Bit("转换为十六进制：") << hex;
    num = 26;
    qDebug() << QString::fromLocal8Bit("使用十六进制将整数转换为字符串：")
                  << QString::number(num, 16);//结果为1a
    str = "123.456";
    qDebug() << QString::fromLocal8Bit("字符串转换为浮点型：") << str.toFloat();//结果为123.456
    str = "abc";
    qDebug() << QString::fromLocal8Bit("转换为大写：") << str.toUpper();// 结果为ABC
    str = "ABC";
    qDebug() << QString::fromLocal8Bit("转换为小写：") <<str.toLower();// 结果为abc
    int age = 25;
    QString name = "yafei";
    // name代替%1，age代替%2
    str = QString("name is %1, age is %2").arg(name).arg(age);
    // 结果为name is yafei, age is 25
    qDebug() << QString::fromLocal8Bit("更改后的str为：") << str;
    str = "%1 %2";
    qDebug() << str.arg("%1f","hello");      // 结果为%1f hello  这种arg的重载模式属于常规，但当其中有%1等标识时就会变奇怪。所以最好使用常规形式的arg函数。
    qDebug() << str.arg("%1f").arg("hello"); // 结果为hellof %2
    str = QString("ni%1").arg("hi",5,'*');
    qDebug() << QString::fromLocal8Bit("设置字段宽度为5，使用'*'填充：") << str;//结果为ni***hi
    qreal value = 123.456;
    str = QString("number: %1").arg(value,0,'f',2);
    qDebug() << QString::fromLocal8Bit("设置小数点位数为两位：") << str;  //结果为"number:123.45
    // 执行下面一行代码，结果为number:123.45不会显示引号
    qDebug() << QString::fromLocal8Bit("将str转换为const char* :") << qPrintable(str);

    return a.exec();
}

