#include "mydesignerplugin.h"
#include <QPushButton>
#include <QHBoxLayout>

MyDesignerplugin::MyDesignerplugin(QWidget *parent) :
    QWidget(parent)
{
    QPushButton *button1 = new QPushButton(this);
    QPushButton *button2 = new QPushButton(this);
    button1->setText("hello");
    button2->setText("Qt!");
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(button1);   //建两个新按钮，然后把新按钮加到布局里去
    layout->addWidget(button2);
    setLayout(layout);
}
