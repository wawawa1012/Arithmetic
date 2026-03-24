//
// Created by A on 2026/3/24.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();

        // 1. 建账本 & Base Case：每个桩哪怕只踩一次，长度也是 1
        vector<int> dp(n, 1);
        // 记录全场的最高连招记录
        int max_len = 1;
        //2.向前推进
        for (int i=1;i<n;i++)
        {
            for (int j=0;j<i;j++)//通过回头看前面的来知道自己的最长子序列长度
            {
                if (nums[i]>nums[j]) dp[i]=max(dp[i],dp[j]+1);
            }
            max_len=max(max_len,dp[i]);
        }
        return max_len;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    int max_combo = sol.lengthOfLIS(nums);
    cout << "刺客的最长连招数: " << max_combo << " 次！" << endl; // 预期输出 4

    return 0;
}