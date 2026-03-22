//
// Created by A on 2026/3/22.
//
#include <vector>
#include <iostream>
#include <algorithm> // 咱们需要用 max() 来更新最大面积

using namespace std;

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int rows=grid.size(),cols=grid[0].size();
        int max_area = 0;
        for (int i=0;i<rows;i++)
        {
            for (int j=0;j<cols;j++)
            {
                if (grid[i][j]==1)
                max_area=max(max_area,dfs(grid,i,j));
            }
        }
        return max_area;
    }
private:
    int dfs(vector<vector<int>>& grid,int r,int c)
    {
        int rows=grid.size(),cols=grid[0].size();
        //边界
        if (r<0||r>=rows||c<0||c>=cols) return 0;
        if (grid[r][c]==0) return 0;
        //操作，沉岛
        grid[r][c]=0;
        //相邻的岛执行同样操作,记录面积
        int under=dfs(grid,r+1,c);
        int up=dfs(grid,r-1,c);
        int left=dfs(grid,r,c-1);
        int right=dfs(grid,r,c+1);
        return 1+under+up+left+right;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };

    int result = sol.maxAreaOfIsland(grid);
    cout << "最大岛屿的面积是: " << result << endl; // 应该输出 4

    return 0;
}