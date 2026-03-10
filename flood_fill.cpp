//
// Created by A on 2026/3/10.
//
//此题类似于岛屿数量，可以沿用其“沉岛”原理来实现
//那么步骤就是1.越界检测（超出数组范围或者邻接只有非相同颜色）
//2.不用判断终点，因为return以后肯定已经DFS完了
//3.如果color和初始点颜色相同，直接return，否则颜色=color（染色）
//4.四个方向递归
//5.无需回溯，道理同2，这不是探路，是施工！
#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor)
    {
        int rows=image.size();
        int cols=image[0].size();
        static const int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        if (r<0||c<0||r>=rows||c>=cols) return;
        if (image[r][c] != oldColor) return;
        image[r][c]=newColor;
        for (const auto& dir : dirs)
        {
            int nr=r+dir[0];
            int nc=c+dir[1];
            dfs(image, nr, nc, oldColor, newColor);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image.empty() || image[0].empty()) return image;
        int oldColor = image[sr][sc];
        if (oldColor == color) return image;
        dfs(image, sr, sc, oldColor, color);
        return image;
    }
};