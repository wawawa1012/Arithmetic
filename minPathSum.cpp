//
// Created by A on 2026/3/23.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        dp[0][0]=grid[0][0];
        for (int i=1;i<cols;i++)//首行
        {
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        for (int j=1;j<rows;j++)//首列
        {
            dp[j][0]=dp[j-1][0]+grid[j][0];
        }
        for (int i=1;i<rows;i++)
        {
            for (int j=1;j<cols;j++)
            {
                int right=dp[i-1][j];//向右走到
                int down=dp[i][j-1];//向下走到
                dp[i][j]=grid[i][j]+min(right,down);
            }
        }
        return dp[rows-1][cols-1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int min_damage = sol.minPathSum(grid);
    cout << "通关迷宫受到的最小伤害是: " << min_damage << endl; // 预期输出 7 (1->3->1->1->1)

    return 0;
}