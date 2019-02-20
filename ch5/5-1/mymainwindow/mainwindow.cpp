#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QMdiSubWindow>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //5.1.1 QT资源系统
    //菜单栏
    QActionGroup *group = new QActionGroup(this);                                 //程序创建的QActionGroup，做到以下三个选项均为单选
    QAction *action_L = group->addAction(QString::fromLocal8Bit("左对齐(&L)"));
    action_L->setCheckable(true);
    QAction *action_R = group->addAction(QString::fromLocal8Bit("右对齐(&R)"));
    action_R->setCheckable(true);
    QAction *action_C = group->addAction(QString::fromLocal8Bit("居中(&C)"));
    action_C->setCheckable(true);

    action_L->setChecked(true);  //左对齐为默认选中状态
    ui->menu_E->addSeparator();
    ui->menu_E->addAction(action_L);
    ui->menu_E->addAction(action_R);
    ui->menu_E->addAction(action_C);

    //工具栏
    QToolButton *toolbtn = new QToolButton(this);
    toolbtn->setText(QString::fromLocal8Bit("颜色"));
    QMenu *colormenu = new QMenu(this);
    colormenu->addAction(QString::fromLocal8Bit("红色"));
    colormenu->addAction(QString::fromLocal8Bit("绿色"));
    toolbtn->setMenu(colormenu);   //当前toolbtn配置上菜单colormenu
    toolbtn->setPopupMode(QToolButton::MenuButtonPopup);  //设置弹出模式
    ui->mainToolBar->addWidget(toolbtn);
    QSpinBox *spinbox = new QSpinBox(this);
    ui->mainToolBar->addWidget(spinbox);

    //5.1.4 状态栏
    ui->statusBar->showMessage(QString::fromLocal8Bit("欢迎使用多文档编辑器"),2000);  //显示2s
    QLabel *permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Box|QFrame::Sunken);
    permanent->setText(QString::fromLocal8Bit("杨梓桐"));
    ui->statusBar->addPermanentWidget(permanent);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_N_triggered()
{
    QTextEdit *edit = new QTextEdit();
    QMdiSubWindow *child = ui->mdiArea->addSubWindow(edit);               //通过mdiarea的添加子窗口来实现新建文件
    child->setWindowTitle(QString::fromLocal8Bit("多文档编辑器子窗口"));
    child->show();
}

void MainWindow::on_action_Dock_triggered()
{
    ui->dockWidget_2->show();   //用于显示被关闭了的dock工具箱
}
