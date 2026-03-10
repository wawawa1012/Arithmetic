#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // 1. 落地成盒：出生点或终点是墙，直接没救
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
        
        // 2. 特判：如果是 1x1 的网格，出生就在终点，踩了 1 个格子
        if (n == 1) return 1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1; // 踩过的立刻变墙，防止别人走回头路！

        int step = 1; // 起点自己就算第 1 个格子
        
        // 极其优雅的 8 方向数组（不需要任何特殊对待！）
        static const int dirs[8][2] = {
            {1,0}, {-1,0}, {0,1}, {0,-1}, 
            {1,1}, {1,-1}, {-1,1}, {-1,-1}
        };

        // 3. 开始水波蔓延
        while (!q.empty()) {
            // 【极其核心】：看看当前这一圈水波有几个点！
            int current_layer_size = q.size();
            
            // 把这一圈的水点全部向外扩散一次
            for (int i = 0; i < current_layer_size; i++) {
                auto currHead = q.front();
                q.pop();
                int r = currHead.first;
                int c = currHead.second;

                // 往 8 个方向无脑扔克隆人
                for (const auto& dir : dirs) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    // 越界拦截
                    if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
                    // 撞墙拦截
                    if (grid[nr][nc] == 1) continue;
                    
                    // 【胜利条件】：如果在探路时一眼看到了终点！
                    if (nr == n - 1 && nc == n - 1) {
                        return step + 1; // 现在的步数 + 终点这最后 1 步
                    }

                    // 如果是空地，加入队列，并立刻“沉岛”
                    q.push({nr, nc});
                    grid[nr][nc] = 1; 
                }
            }
            // 当前这一整圈水波都扩散完了，整体向外进了一步
            step++;
        }

        return -1; // 水波把能走的地方都淹没了，还是没碰到终点，死路
    }
};