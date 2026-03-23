//
// Created by A on 2026/3/23.
//
//我动态规划的第一题
//小偷只能隔房间偷，如果用DFS决定每个房间偷或不偷，每个房间有两个状态，则复杂度会2^n
//DP的本质是简化了DFS复杂的平行宇宙机制，消去了很多非法情况或者不可能最优的情况

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        //base case
        if (n==0) return 0;
        if (n==1) return nums[0];
        vector<int> dp(n); //动态规划数组
        dp[0]=nums[0];
        dp[1]=max(dp[0],nums[1]);
        for (int i=2;i<n;i++)//小偷走遍每个房间
        {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1]; //dp是单调非减的
    }
};