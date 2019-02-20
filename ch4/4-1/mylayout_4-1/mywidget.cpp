#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QGridLayout>


MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //4.1.1
//    QHBoxLayout *layout = new QHBoxLayout;
//    layout->addWidget(ui->fontComboBox);
//    layout->addWidget(ui->textEdit);
//    layout->setSpacing(50);                    //部件的间距
//    layout->setContentsMargins(0,0,50,100);    //布局管理器到边界的距离，左上右下
//    setLayout(layout);  //将上面新建的layout布局管理器设置为当前的widget的管理器

//    QGridLayout *layout = new QGridLayout;
//    layout->addWidget(ui->fontComboBox,0,0,1,2);   //添加部件，从第0行0列开始，占据1行2列
//    layout->addWidget(ui->pushButton,0,2,1,1);   //添加部件，从第0行2列开始，占据1行1列
//    layout->addWidget(ui->textEdit,1,0,1,3);   //添加部件，从第1行0列开始，占据1行3列
//    setLayout(layout);

    //4.1.3
    ui->textEdit->hide();  //保证文本编辑器在开始时即为隐藏的

    //4.3
//    setTabOrder(ui->nLineEdit,ui->sComboBox);
//    setTabOrder(ui->sComboBox,ui->aSpinBox);
//    setTabOrder(ui->aSpinBox,ui->mLineEdit);

}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_toggled(bool checked)
{
    ui->textEdit->setVisible(checked);   //根据按钮返回值确定textedit是否隐藏
    if(checked)
        ui->pushButton->setText(QString::fromLocal8Bit("隐藏可扩展窗口"));
    else
        ui->pushButton->setText(QString::fromLocal8Bit("显示可扩展窗口"));
}
