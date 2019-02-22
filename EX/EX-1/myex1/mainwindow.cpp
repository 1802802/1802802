#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "labyrinth.h"
#include <QFont>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reset()
{
    ui->textEdit->clear();
    shortestpath.clear();
    length = 0;
    Cell zero;
    startCell = &zero;
    goalCell = &zero;
    for(int i =0; i<LABY_MAX;i++)
        for(int j =0; j<LABY_MAX;j++)
            laby[i][j]=zero;
}

void MainWindow::on_lineEdit_returnPressed()
{
    size = ui->lineEdit->text().toInt();
    randLaby(size);
    ui->textEdit->textCursor().insertText(tr("This laby's size is %1 \n").arg(size));

    //重置最短路径
    shortestpath.clear();
    length = 0;
}

void MainWindow::on_pushButton_clicked()
{
    static char* pattern[5][5] =
    {
        " +", " +", " +", " +", " +",
        " +", "  ", " =", " -", " =",
        " +", " =", "  ", " =", " |",
        " +", " -", " =", "  ", " =",
        " +", " =", " |", " =", "  "
    };
    ui->textEdit->textCursor().insertText("  ");
    for (int j = 0; j < labySize; j++)
        (j < 10) ? ui->textEdit->textCursor().insertText(tr(" %1").arg(j)) : ui->textEdit->textCursor().insertText(tr("%1").arg(j));
    ui->textEdit->textCursor().insertText("\n");
    for (int j = 0; j < labySize; j++)
    {
        (j < 10) ? ui->textEdit->textCursor().insertText(tr(" %1").arg(j)) : ui->textEdit->textCursor().insertText(tr("%1").arg(j));
        for (int i = 0; i < labySize; i++)
        {
            if ((goalCell == &laby[i][j])||(startCell == &laby[i][j]))
            {
                if (goalCell == &laby[i][j])
                    ui->textEdit->textCursor().insertText(" $");
                else
                    ui->textEdit->textCursor().insertText(" #");
            }
            else
                switch (laby[i][j].status)
                {
                case WALL:  ui->textEdit->textCursor().insertText("[]");   break;
                case BACKTRACKED: ui->textEdit->textCursor().insertText("<>");   break;
                case AVAILABLE: ui->textEdit->textCursor().insertText("  ");   break;
                default: ui->textEdit->textCursor().insertText(tr("%1").arg(pattern[laby[i][j].outgoing][laby[i][j].incoming]));  break;
                //老师这里的代码%s后面没有空格，需要加上，不然迷宫会乱掉
                }
        }
        ui->textEdit->textCursor().insertText("\n");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if (bfs(laby, startCell, goalCell))  //判断当前迷宫能否从起点走到终点，如果行的话，输出如下
    {
        qDebug() << "true";
        ui->textEdit->textCursor().insertText(tr("This laby's start point is (%1,%2), end point is (%3,%4)\n")
                                              .arg(startCell->x).arg(startCell->y).arg(goalCell->x).arg(goalCell->y));
        shortest_path();//输出当前迷宫从起点到终点的最短路径与长度
        ui->textEdit->textCursor().insertText(tr("The shortest path's distance is %1 \n").arg(length+1));
    }
    else
    {
        qDebug() << "false";
        ui->textEdit->textCursor().insertText(tr("This laby can't go out \n"));
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    foreach (Cell* c, shortestpath)
    {
        ui->textEdit->textCursor().insertText(tr("%1 -> (%2, %3) -> %4 \n")
                                              .arg(c->incoming).arg(c->x).arg(c->y).arg(c->outgoing));
    }
}

void MainWindow::on_actionReset_triggered()
{
    reset();
}
