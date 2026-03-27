//
// Created by A on 2026/3/27.
//
#include <iostream>
#include <vector>
#include <numeric> // 用 accumulate 算总和极其方便

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //base case:必须是偶数
        int sum=0;
        for (int num:nums)
        {
            sum+=num;
        }
        if (sum%2!=0) return false;
        int target=sum/2; //平分的目标
        //创建DP数组，dp[i]的含义是前i-1个元素能否凑到target或target-nums[i]
        int n=nums.size();
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));
        //初始化第一行
        for (int i=0;i<=target;i++)
        {
            dp[0][i]=nums[0]==i;
        }
        for (int i=1;i<n;i++)
        {
            for (int j=0;j<=target;j++)
            {
                if (j >= nums[i]) {
                    // 容量够大，才有“拿”和“不拿”两条历史线
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                } else {
                    // 背包容量根本装不下这颗宝石，只能被迫选择“不拿”！
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n-1][target];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 5, 11, 5};

    if (sol.canPartition(nums)) {
        cout << "分赃成功！完美平分！" << endl; // 预期输出 true
    } else {
        cout << "分赃失败！准备打架！" << endl;
    }

    return 0;
}