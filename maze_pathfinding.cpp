//
// Created by A on 2026/3/8.
//
//0可以走，1不能走
//上下左右寻路
//思路：递归与回溯，一行行向下走，走过的路标记，若走到死胡同（超出数组下标或碰到1或碰到标记，即四周没有一个0）回溯
//递归终点：r==c==4
//可视化：遍历输出visited数组

#include <iostream>
#include <vector>
using namespace std;
constexpr int MAZE_SIZE=5;
struct point
{
    int row,column;
};
class solution
{
public:
    vector<point> visited;
    int maze[MAZE_SIZE][MAZE_SIZE]={
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0}
    };
    bool find_path(int r, int c)
    {
        //1.越界判断
        if (r>=MAZE_SIZE||r<0||c>=MAZE_SIZE||c<0)   return false;
        if (maze[r][c]==1||maze[r][c]==2)   return false;
        //2.判断成功
        if (r==4&&c==4)
        {
            visited.push_back({r,c});
            return true;
        }
        //3.存档，当前安全，如果递归发现进入死胡同就回到此处（并将已访问的标记防止无限递归）
        visited.push_back({r,c});
        maze[r][c]=2;
        //4.上下左右探路
        if (find_path(r+1,c)) return true;
        if (find_path(r-1,c)) return true;
        if (find_path(r,c-1)) return true;
        if (find_path(r,c+1)) return true;
        //5.false则回溯到存档点
        visited.pop_back();
        maze[r][c]=0;
        return false;
    }
    void print_path() {
        if (find_path(0, 0)) {
            cout << "找到出路啦！路径如下：" << endl;
            for (int i = 0; i < visited.size(); i++) {
                cout << "(" << visited[i].row << ", " << visited[i].column << ")";
                if (i != visited.size() - 1) cout << " -> ";
            }
            cout << endl;
        } else {
            cout << "这个迷宫根本没有出路！" << endl;
        }
    }
};

int main() {
    solution s;
    s.print_path();
    return 0;
}