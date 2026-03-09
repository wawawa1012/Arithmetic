//
// Created by A on 2026/3/9.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int row = grid.size();
        int column = grid[0].size();
        static const int dirs[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};

        // 1. 【守门员】：第一步绝对是查越界！敢越雷池一步直接打回！
        if (r < 0 || c < 0 || r >= row || c >= column) return;

        // 2. 【查水表】：越界查完了，现在可以安全读取地图了。如果是水，撤退！
        if (grid[r][c] == '0') return;

        // 3. 【沉岛】：不是越界也不是水，那必定是没踩过的陆地 '1'，踩沉它！
        grid[r][c] = '0';

        // 4. 【召唤】：利用方向数组，直接派兵！
        for (const auto& dir : dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            dfs(grid, nr, nc); // 大胆召唤！越没越界让下一个克隆人的第1步去查！
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    count++;
                    dfs(grid, r, c);
                }
            }
        }
        return count;
    }
};