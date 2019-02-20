#include "hellodialog.h"
#include "ui_2_2_study.h"

Dialog::Dialog(QWidget*parent):QDialog(parent)
{
    ui=new Ui::Dialog;
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
