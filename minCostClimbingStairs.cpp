//
// Created by A on 2026/4/16.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,0);
        for (int i=2;i<=n;i++)
        {
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }
};*/

class Solution
{
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();
        int prev2=0,prev1=0;
        for (int i=2;i<=n;i++)
        {
            int curr=min(prev1+cost[i-1],prev2+cost[i-2]);

            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};
int main() {
    Solution sol;

    vector<int> cost1 = {10, 15, 20};
    cout << "测试 1 (预期 15): " << sol.minCostClimbingStairs(cost1) << endl;

    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "测试 2 (预期 6): " << sol.minCostClimbingStairs(cost2) << endl;

    return 0;
}