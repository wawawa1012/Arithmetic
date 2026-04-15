//
// Created by A on 2026/4/15.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transitiveClosure(vector<vector<int>>& graph) {
        int n = graph.size();
        // 1. 初始化 DP 账本
        vector<vector<int>> dp = graph;

        // 2. 极其暴躁的三层嵌套循环！
        for (int k=0;k<n;k++)//中转站
        {
            for (int i=0;i<n;i++)//遍历行
            {
                for (int j=0;j<n;j++)//列
                {
                    dp[i][j]=max(dp[i][j],dp[i][k]*dp[k][j]);
                }
            }
        }


        return dp;
    }
};

int main() {
    Solution sol;

    // 初始化测试地图
    vector<vector<int>> graph = {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    };

    vector<vector<int>> res = sol.transitiveClosure(graph);

    cout << "最终的传递闭包矩阵:" << endl;
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    // 预期第一行输出应该是 1 1 1 1

    return 0;
}