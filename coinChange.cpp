//
// Created by A on 2026/3/24.
//
//可以用小数的最优解来递进地求解大数的解，因此我们可以选择DP
//用一个vector数组存n元最少硬币个数
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount+1,amount+1);//初始化成极大值
        //base case
        dp[0]=0;

        //通过公式递推
        for (int i=1;i<=amount;i++)
        {
            for (int coin:coins)
            {
                if (i >= coin)
                {
                    dp[i]=min(dp[i],dp[i-coin]+1);
                }
            }
        }
        //返回结果
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int min_coins = sol.coinChange(coins, amount);
    cout << "凑齐 " << amount << " 元最少需要硬币数: " << min_coins << " 枚！" << endl; // 预期输出 3

    return 0;
}