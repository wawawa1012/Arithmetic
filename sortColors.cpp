//
// Created by A on 2026/4/6.
//
#include <iostream>
#include <vector>
#include <algorithm> // 允许你使用 swap() 函数交换元素

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;               // 左门卫，准备接收 0
        int right = nums.size() - 1; // 右门卫，准备接收 2
        int curr = 0;               // 巡逻兵，从头开始走

        // 只要巡逻兵还没越过右门卫的防线，就继续巡逻
        while (curr <= right) {
            if (nums[curr] == 0) {
                // 看到 0，扔给左门卫
                swap(nums[curr], nums[left]);
                left++;  // 左门卫防线推进一步
                curr++;  // 巡逻兵继续往前走
            }
            else if (nums[curr] == 2) {
                // 看到 2，扔给右门卫
                swap(nums[curr], nums[right]);
                right--; // 右门卫防线推进一步
                // 注意！curr 绝对不能 ++，因为从右边换过来的数字还没检查！
            }
            else {
                // 看到 1，直接无视
                curr++;
            }
        }
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums1);
    cout << "测试 1 (预期 0 0 1 1 2 2): ";
    for (int x : nums1) cout << x << " ";
    cout << endl;

    vector<int> nums2 = {2, 0, 1};
    sol.sortColors(nums2);
    cout << "测试 2 (预期 0 1 2): ";
    for (int x : nums2) cout << x << " ";
    cout << endl;

    return 0;
}
