//
// Created by A on 2026/4/16.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];
        return max(robRange(nums,0,n-2),robRange(nums,1,n-1));
    }

    int robRange(vector<int>& nums,int start,int end)//线性DP的空间压缩
    {
        int prev1=0,prev2=0;
        for (int i=start;i<=end;i++)
        {
            int curr=max(prev1,prev2+nums[i]);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2, 3, 2};
    cout << "测试 1 (预期 3): " << sol.rob(nums1) << endl;

    vector<int> nums2 = {1, 2, 3, 1};
    cout << "测试 2 (预期 4): " << sol.rob(nums2) << endl;

    vector<int> nums3 = {0};
    cout << "测试 3 (预期 0): " << sol.rob(nums3) << endl;

    return 0;
}