//
// Created by A on 2026/3/27.
//装进背包的可以设定为正负，定义P是正值、N是负值
//sum+target=2P;sum-target=2N
//sum和target已知，进而可以求出P的值。用01背包的思想求P，不管N
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for (const int num:nums) sum+=num;
        if ((sum+target)%2!=0) return 0; //若无法整除则不可能有解
        if (abs(target) > sum) return 0;
        int positive=(sum+target)/2;
        //创建二维整形dp数组，dp[i][j]存的内容是前i个数有n个方法凑到j
        int n=nums.size();
        // 2. 建立 N+1 的终极账本！第一行代表“一颗宝石都没有”
        vector<vector<int>> dp(n + 1, vector<int>(positive + 1, 0));

        // 3. 极其纯粹的 Base Case
        // 一颗宝石都没有的情况下，凑出容量 0 有几种方法？1 种（什么都不拿）。
        // 凑出其他容量呢？绝对不可能，全是 0。
        dp[0][0] = 1;

        // 4. 开启时空推演（从第 1 颗宝石开始，对应 nums[i-1]）
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= positive; j++) {
                if (j >= nums[i-1]) {
                    // 能装下：不拿这颗的方法数 + 拿这颗的方法数
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
                } else {
                    // 装不下：只能继承不拿的方法数
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][positive];
    }
};