//
// Created by A on 2026/4/4.
//
#include <iostream>
#include <vector>
#include <unordered_map>
//看到这个题感觉像是DP
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector<int> dp(n, 0); //dp[i]表示走到第i格的和为k子数组个数
        dp[0] = nums[0] == k ? 1 : 0;
        int currSum = nums[0];
        for (int i = 1; i < n; i++)
        {
            currSum += nums[i];
            dp[i] = dp[i - 1];
            if (nums[i] == k||currSum == k)
            {
                currSum = 0;
                dp[i] = dp[i - 1] + 1;
            }
        }
        return dp[n - 1];
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {1, 1, 1};
    cout << "测试 1 的子数组个数: " << sol.subarraySum(nums1, 2) << endl; // 预期 2

    vector<int> nums2 = {1, 2, 3};
    cout << "测试 2 的子数组个数: " << sol.subarraySum(nums2, 3) << endl; // 预期 2

    vector<int> nums3 = {1, -1, 0};
    cout << "测试 3 的子数组个数: " << sol.subarraySum(nums3, 0) << endl; // 预期 3

    return 0;
}
