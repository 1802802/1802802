#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStyleFactory>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->progressBar->setStyle(QStyleFactory::create("windows"));  //单独部件的风格

    QPalette palette = ui->pushButton->palette();
    palette.setColor(QPalette::Button,Qt::red);
    palette.setColor(QPalette::Base,Qt::yellow);
    palette.setColor(QPalette::ButtonText,Qt::yellow);
    ui->pushButton->setPalette(palette);
    ui->spinBox->setDisabled(true);
    QPalette palette2 = ui->spinBox->palette();
    palette2.setColor(QPalette::Disabled,QPalette::Base,Qt::green);
    ui->spinBox->setPalette(palette2);
}

MainWindow::~MainWindow()
{
    delete ui;
}
