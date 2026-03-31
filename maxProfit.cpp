//
// Created by A on 2026/3/31.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//DP，算法上界
/*class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int n=prices.size();
        vector<int> dp(n,0); //存每天的最大利润
        int max_profit=0;
        for (int i=0;i<n;i++)
        {
            for (int j=i;j<n;j++)
            {
                dp[i]=max(dp[i],prices[j]-prices[i]);
            }
            max_profit=max(dp[i],max_profit);
        }
        return max_profit;
    }
};*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        // 初始状态：利润为0，
        int max_profit = 0;
        int min_price = prices[0]; // 或者用 INT_MAX

       for (int i=1;i<prices.size();i++)
       {
           min_price=min(min_price,prices[i]); //更新最小进货价
           max_profit=max(max_profit,prices[i]-min_price);
       }
        return max_profit;
    }
};
int main() {
    Solution sol;

    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    vector<int> prices2 = {7, 6, 4, 3, 1};

    cout << "图纸 1 的最大利润: " << sol.maxProfit(prices1) << endl; // 预期 5
    cout << "图纸 2 的最大利润: " << sol.maxProfit(prices2) << endl; // 预期 0

    return 0;
}