#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int max_gold = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // 只要有金子，就把这里当成空投降落点
                if (grid[r][c] != 0) {
                    // 直接获取这个降落点能带来的绝对最大收益
                    max_gold = max(max_gold, dfs(grid, r, c));
                }
            }
        }
        return max_gold;
    }

    // 情报员返回：从 (r, c) 出发能挖到的最大黄金数
    int dfs(vector<vector<int>>& grid, int r, int c) {
        int rows = grid.size(), cols = grid[0].size();
        static const int dirs[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};

        // 极其冷酷的越界与死墙防御
        if (r < 0 || r >= rows || c < 0 || c >= cols) return 0;
        if (grid[r][c] == 0) return 0;

        int curr = grid[r][c]; // 记住脚下这块金砖
        grid[r][c] = 0;        // 挖走！(极其关键的状态标记)

        int max_branch = 0;    // 探测周围四个平行宇宙的最大值
        for (auto& dir : dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            // 极其势利地比较：哪条路钱多，我就记录哪条路！
            max_branch = max(max_branch, dfs(grid, nr, nc));
        }

        grid[r][c] = curr;     // 恢复现场！(离开平行宇宙，把金砖放回去)

        // 返回我的绝对收益：我脚下的这块金砖 + 四条路里最赚钱的那条路的收益
        return curr + max_branch;
    }
};