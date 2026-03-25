//
// Created by A on 2026/3/25.
//
#include <iostream>
#include <vector>
#include <algorithm> // min() 必不可少

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));//初始化dp数组，其值的含义是下降到(i,j)所受最小伤害
        //为第一行初始化
        for (int col=0;col<n;col++) dp[0][col]=matrix[0][col];
        for (int row=1;row<n;row++)
        {
            for (int col = 0; col < n; col++) {
                int up = dp[row-1][col];

                if (col == 0) {
                    int right = dp[row-1][col+1];
                    dp[row][col] = min(up, right) + matrix[row][col];
                } else if (col == n - 1) {
                    int left = dp[row-1][col-1];
                    dp[row][col] = min(up, left) + matrix[row][col];
                } else {
                    int left = dp[row-1][col-1];
                    int right = dp[row-1][col+1];
                    dp[row][col] = min({up, left, right}) + matrix[row][col];
                }
            }
        }
        int min_cost=dp[n-1][0];
        for (int col=1;col<n;col++)
        {
            min_cost=min(dp[n-1][col],min_cost);
        }
        return min_cost;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };

    int result = sol.minFallingPathSum(matrix);
    cout << "深渊坠落的最小累计伤害是: " << result << endl; // 预期输出 13

    return 0;
}