//
// Created by A on 2026/3/9.
//
#include <iostream>
#include <vector>
using namespace std;
constexpr int ROW=3;
constexpr int COLUMN=4;

struct point
{
    int row,column;
    char charactor;
};
class solution
{
private:
    char board[3][4] = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    vector<point> visited;
    string target="DECFSAB";
    bool dfs(int r,int c,int index)
    {
        //越界条件
        if (c<0||r<0||c>=COLUMN||r>=ROW) return false;
        if (board[r][c]==' ') return false;
        //字母不匹配
        if (target.at(index)!=board[r][c]) return false;
        //结束条件
        if (index == target.size() - 1) {
            visited.push_back({r, c, board[r][c]});
            return true;
        }
        //存档
        visited.push_back({r,c,board[r][c]});
        char temp = board[r][c]; // 记住当前字母
        board[r][c]=' ';
        //探路
        if (dfs(r+1,c,index+1)) return true;
        if (dfs(r-1,c,index+1)) return true;
        if (dfs(r,c-1,index+1)) return true;
        if (dfs(r,c+1,index+1)) return true;
        //回溯
        board[r][c]=temp;
        visited.pop_back();
        return false;
    }
public:
    void solve() {
        // 遍历密码盘上的每一个格子，当作起点来尝试
        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COLUMN; c++) {

                visited.clear(); // 每次换新起点前，清空旧的路径

                // 从第 0 个字母开始找！
                if (dfs(r, c, 0)) {
                    cout << "成功找到路线" << endl;
                    for (int i = 0; i < visited.size(); i++) {
                        cout << "(" << visited[i].row << ", " << visited[i].column << ")['" << visited[i].charactor << "']";
                        if (i != visited.size() - 1) cout << " -> ";
                    }
                    cout << endl;
                    return; // 【关键】找到了就直接结束整个 solve 函数，不再找了！
                }
            }
        }
        cout << "无法找到密码对应路线" << endl;
    }
};

int main()
{
    solution s;
    s.solve();
}