#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <iostream>
#include <deque>
#include <QTime>
#include <QDebug>
#include <QList>
using namespace std;

//这是最小路径的实现函数，通过BFS方式步步遍历的到；如果使用DFS算法，需要穷尽所有的到达终点的路径，最后取最短的

/*迷宫寻径主流的三大算法：广度/深度优先搜素算法，以及A*算法*/
/*相对而言，深度优先搜索是最适合迷宫最短路径寻径的，通过一轮一轮的扁铝，找到的第一条路径也就是最短的路径*/
typedef enum { AVAILABLE, ROUTE, BACKTRACKED, WALL } Status;
typedef enum { UNKNOWN, EAST, SOUTH, WEST, NORTH, NO_WAY } ESWN;
inline ESWN nextESWN(ESWN eswn) { return ESWN(eswn + 1); }
int labySize;  //此处借用dascpp中邓公的随机迷宫生成程序

struct Cell
{
    int x, y = 0;
    Status status = AVAILABLE;  //xy的坐标与类型
    ESWN incoming, outgoing = UNKNOWN;  //进入的方向与出去的方向
    Cell *prev;				  //运行BFS时建立前缀，用于建图形成反推
};

#define LABY_MAX 40
Cell laby[LABY_MAX][LABY_MAX];
int ncheck, nback, length;
Cell* startCell;
Cell* goalCell;

inline Cell *neighbor(Cell *cell) //移动的探测，即得到当前cell的邻居，根据outgoing确定方向
{
    switch (cell->outgoing)
    {
    case EAST:return cell + LABY_MAX;
    case SOUTH:return cell + 1;
    case WEST:return cell - LABY_MAX;
    case NORTH:return cell - 1;
    default:exit(-1); //如果不是这四个方向，即UNKNOWN和NO_WAY，则直接退出这个switch循环
    }
}

inline Cell* advance(Cell* cell)  //实质性的移动，根据cell的incoming移动当前cell到对应的cell
{
    Cell *next;
    switch (cell->outgoing)
    {
    case EAST:next = cell + LABY_MAX; next->incoming = WEST; next->x = cell->x + 1; break;  //这里的操作意思是，现节点的进入为西，即相当于原节点的出是东
    case SOUTH:next = cell + 1;		  next->incoming = NORTH; next->y = cell->y + 1; break;
    case WEST:next = cell - LABY_MAX; next->incoming = EAST; next->x = cell->x - 1; break;
    case NORTH:next = cell - 1;		  next->incoming = SOUTH; next->y = cell->y - 1; break;
    default: exit(-1);
    }
    return next;
}

QList<Cell*> shortestpath;
void inline shortest_path()  //此函数用于根据传递到终点goalCell的数据，来进行路径反推
{
    Cell *c = goalCell;
    c->status = ROUTE;   //所有反推的路径全部将状态改为ROUTE，便于显示路径
    shortestpath.push_front(c);
    while (c->incoming)  //一直反推到最短路径的初始点，即起点，起点的incoming是=0的
    {
        length++;        //length开始循环计数
        auto in = c->incoming;
        c = c->prev;
        switch (in)		 //根据上一个cell的incoming，来反推出当前cell的outgoing，相对取反即可
        {
        case EAST:  c->outgoing = WEST;   break;
        case SOUTH: c->outgoing = NORTH;   break;
        case WEST: c->outgoing = EAST;   break;
        case NORTH: c->outgoing = SOUTH;   break;
        default: exit(-1);
        }
        c->status = ROUTE;
        shortestpath.push_front(c);
    }
    //cout << "shortest path's long is " << length + 1 << endl;  //由于终点是在循环外面做的，所以此处需要加1
}

bool bfs(Cell Laby[LABY_MAX][LABY_MAX], Cell *s, Cell *t)
{
    if ((AVAILABLE != s->status) || (AVAILABLE != t->status)) return false;  //首先，起点和终点必须是能访问的
    deque<Cell*> bfs_path;   //采用BFS算法，所以这里改为使用队列结构
    s->incoming = UNKNOWN; s->status = ROUTE; bfs_path.push_back(s);  //将起点的进入点设为无，然后状态设为在路径上，最后入队列
    do
    {
        Cell *c = bfs_path.front();
        bfs_path.pop_front();
        if (c == t)
        {
            t = c;    //当达到终点时，将此时的c传递给goalCell，因为其中储存了其所有的prev前缀
            return true;
        }
        while (NO_WAY != (c->outgoing = nextESWN(c->outgoing)))   //此处改为遍历当前cell的所有方向一次
        {
            if (AVAILABLE == neighbor(c)->status)  //只要cell的一个方向可以，就将其入队
            {
                Cell* temp = advance(c);
                temp->outgoing = UNKNOWN; temp->status = ROUTE;
                temp->prev = c;					   //每个从当前cell出去的cell，都将原cell设为前缀，由此实现当前图（树）结构的实现
                bfs_path.push_back(temp);
                ncheck++;
            }
        }
        c->status = BACKTRACKED;  //而被bfs过的cell，借用BACKTRACKED状态，表示其已经被扫描过但没有到达终点
    } while (!bfs_path.empty());
    return false;
}

void randLaby(int size)    //根据输入的size生成随机的迷宫
{
    qsrand(QTime(0,0,0).secsTo((QTime::currentTime())));
    labySize = size;  //生成一个输入size的迷宫
    for (int i = 0; i < labySize; i++)
        for (int j = 0; j < labySize; j++)
        {
            laby[i][j].x = i;
            laby[i][j].y = j;
            laby[i][j].incoming =
                laby[i][j].outgoing = UNKNOWN;
            laby[i][j].status = WALL; //边界格点必须是墙
        }
    for (int i = 1; i < labySize - 1; i++)
        for (int j = 1; j < labySize - 1; j++)
            if (rand() % 3) laby[i][j].status = AVAILABLE; //75%的格点为空可用，增加迷宫难度在此酌情修改
    startCell = &laby[rand() % (labySize - 2) + 1][rand() % (labySize - 2) + 1];
    goalCell = &laby[rand() % (labySize - 2) + 1][rand() % (labySize - 2) + 1];
    startCell->status = goalCell->status = AVAILABLE; //起始格点必须可用
}

#endif // LABYRINTH_H
