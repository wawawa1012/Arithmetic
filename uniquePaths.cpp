//
// Created by A on 2026/3/23.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m,vector<int>(n,0));
        //填写 Base Case：第一列和第一排
        // 一直往下走，只有 1 条路
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        // 一直往右走，也只有 1 条路
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }
        for (int i=1;i<m;i++)
        {
            for (int j=1;j<n;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};