//
// Created by A on 2026/3/29.
//
#include <iostream>
#include <vector>
#include <algorithm>
//这个题是求可行性，直觉告诉我要用DP或贪心
//建一个bool型的dp数组，但我不知道存什么有意义,难道是能不能走到第i格子吗
//失败的条件是所有前置的只能走到0，是不是可以遍历找到所有0？从0入手？这样又是什么用到什么方法呢？递归？暴力？
#include <vector>
using namespace std;

//DP,复杂度很高
/*class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int target = nums.size() - 1;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = 1; i < target + 1; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j]&&j + nums[j] >= i) dp[i] = true;
            }
        }
        return dp[target];
    }
};*/
//贪心
class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int target=nums.size()-1;
        int farthest=0;//记录当前能覆盖最大长度
        for (int i=0;i<target;i++)
        {
            if (farthest>=i) farthest = max(farthest, i + nums[i]);
            if (farthest >= target) return true;
        }
        return farthest>=target;
    }
};
int main()
{
    Solution sol;

    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};

    cout << "地图 1 能否通关: " << (sol.canJump(nums1) ? "True" : "False") << endl; // 预期 True
    cout << "地图 2 能否通关: " << (sol.canJump(nums2) ? "True" : "False") << endl; // 预期 False

    return 0;
}
