#ifndef HELLODIALOG_H
#define HELLODIALOG_H
#include<QDialog>

namespace Ui //前置声明
{
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget * parent = 0);
    ~Dialog();
private:
    Ui::Dialog *ui;  //定义的指针
};

#endif // HELLODIALOG_H
