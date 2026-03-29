//
// Created by A on 2026/3/29.
//
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
//DP
/*class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,INT_MAX); //存跳到第i格跳的最少次数
        dp[0]=0;
        for (int i=1;i<n;i++)
        {
            for (int j=0;j<i;j++)
            {
                if (j+nums[j]>=i) dp[i]=min(dp[j]+1,dp[i]);
            }
        }
        return dp[n-1];
    }
};*/
//贪心
class Solution
{
public:
    int jump(vector<int>& nums)
    {
        int target=nums.size()-1;
        int jumps=0,farthest=0,current_end=0;
        for (int i=0;i<target;i++)
        {
            farthest=max(farthest,nums[i]+i);
            if (i==current_end)
            {
                jumps+=1;
                current_end=farthest;
            }
        }
        return jumps;
    }
};
int main() {
    Solution sol;

    vector<int> nums = {2, 3, 1, 1, 4};

    int result = sol.jump(nums);
    cout << "极限速通的最少跳跃次数是: " << result << " 次！" << endl; // 预期输出 2

    return 0;
}