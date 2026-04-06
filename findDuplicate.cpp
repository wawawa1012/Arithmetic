//
// Created by A on 2026/4/6.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int fast=0,slow=0;
        slow = nums[slow];
        fast = nums[nums[fast]];
        while (slow!=fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }slow=0;
        while (slow!=fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {4, 3, 1, 4, 2};
    cout << "测试 1 重复的数字是: " << sol.findDuplicate(nums1) << endl; // 预期 2

    vector<int> nums2 = {3, 1, 3, 4, 2};
    cout << "测试 2 重复的数字是: " << sol.findDuplicate(nums2) << endl; // 预期 3

    return 0;
}