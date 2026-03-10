//
// Created by A on 2026/3/10.
//题干提到“每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。”，传染速度相同，那么可以使用BFS求最小时间（最短路径）
//又因为腐烂橘子的个数和位置不确定，那么可以在外层嵌套双层for循环找到腐烂橘子，多源bfs
//1.确定边界(?)
//2.初始化队列、时间，所有腐烂橘子入队
//3.while队列非空，出队-传染（先讨论边界）（变值）-时间++,受到Gemini代码启发想到记录fresh_count，可以知道没有感染完的情况（有死角）;
//4.return time
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        queue<pair<int,int>> q;
        int time=0;
        int fresh_count=0;

        for (int r=0;r<rows;r++)
        {
            for (int c=0;c<cols;c++)
            {
                if (grid[r][c]==2)
                {
                    q.push({r,c});
                }
                if (grid[r][c]==1) fresh_count++;
            }
        }
        if (fresh_count == 0) return 0;
        static const int dirs[4][2]={{1,0}, {-1,0}, {0,1}, {0,-1}};
        while (!q.empty())
        {
            bool infected_this_minute = false; // 标记这一分钟有没有橘子被咬
            int current_layer_size = q.size();
            for (int i=0;i<current_layer_size;i++)//对该层每个元素讨论，下一分钟会传染到谁
            {
                auto currFront=q.front();
                q.pop();
                int r=currFront.first,c=currFront.second;
                for (auto dir:dirs)
                {
                    int nr=r+dir[0],nc=c+dir[1];
                    if (nr<0||nc<0||nr>=rows||nc>=cols) continue;
                    if (grid[nr][nc]==0||grid[nr][nc]==2) continue;
                    if (grid[nr][nc]==1)
                    {
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                        infected_this_minute=true;
                        fresh_count--;
                    }
                }
            }
            if (infected_this_minute) time++;
        }
        if (fresh_count > 0) return -1; //总有死角

        return time;
    }
};