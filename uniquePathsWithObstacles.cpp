//
// Created by A on 2026/3/26.
//
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows=obstacleGrid.size(),cols=obstacleGrid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));//初始化
        for (int i=0;i<cols;i++) //首行
        {
            if (obstacleGrid[0][i]==1) break;
            dp[0][i]=1;
        }
        for (int j=0;j<rows;j++)//首列
        {
            if (obstacleGrid[j][0]==1) break;
            dp[j][0]=1;
        }
        for (int i=1;i<rows;i++)
        {
            for (int j=1;j<cols;j++)
            {
                if (obstacleGrid[i][j]==1) dp[i][j]=0;
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[rows-1][cols-1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    int result = sol.uniquePathsWithObstacles(obstacleGrid);
    cout << "避开障碍物的总路线数量是: " << result << " 条！" << endl; // 预期输出 2

    return 0;
}