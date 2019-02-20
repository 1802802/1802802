#include "mainwindow.h"
#include "ui_mainwindow.h"

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

}

MainWindow::~MainWindow()
{
    delete ui;
}
