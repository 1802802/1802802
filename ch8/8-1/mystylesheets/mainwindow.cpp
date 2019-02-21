#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //单独对部件设置样式表（注意样式表stylesheets和风格style不是一种东西）
//    ui->pushButton->setStyleSheet("background:yellow");
//    ui->horizontalSlider->setStyleSheet("background:red");

    //对所有的PushButton和QSlide部件进行样式表设置
//    setStyleSheet("QPushButton{background:yellow}QSlider{background:red}");

    //样式表的换肤/设置操作  （顺便一提，不知道为什么，对于资源文件调用只能用绝对路径，用别的简化路径都无效）
    qssFile = new QFile("D:/Users/CAD/Documents/QT_Study/ch8/8-1/mystylesheets/my.qss",this);
    qssFile->open(QFile::ReadOnly);   //先是以只读方式打开文件
    QString styleSheet = QString(qssFile->readAll());  //然后建立一个样式表读取qss文件中的内容
    qApp->setStyleSheet(styleSheet);  //使用该样式表
    qssFile->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(qssFile->fileName() == "D:/Users/CAD/Documents/QT_Study/ch8/8-1/mystylesheets/my.qss")
        qssFile->setFileName("D:/Users/CAD/Documents/QT_Study/ch8/8-1/mystylesheets/my1.qss");
    else
        qssFile->setFileName("D:/Users/CAD/Documents/QT_Study/ch8/8-1/mystylesheets/my.qss");
    qssFile->open(QFile::ReadOnly);   //先是以只读方式打开文件
    QString styleSheet = QString(qssFile->readAll());  //然后建立一个样式表读取qss文件中的内容
    qApp->setStyleSheet(styleSheet);  //使用该样式表
    qssFile->close();
}
