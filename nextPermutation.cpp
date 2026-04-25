//
// Created by A on 2026/4/25.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;

        // 1. 从后往前，找第一个被降维的拐点 i
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // 2. 如果找到了拐点 (说明不是纯降序的极限状态)
        if (i >= 0) {
            // 从后往前，找第一个比 nums[i] 大的数 nums[j]
            int j = n - 1;
            while (j >= 0 &&nums[j]<=nums[i]) {
                j--;
            }
            // 极其利落地交换
            swap(nums[i], nums[j]);
        }

        // 3. 无论如何，把 i 之后的部分全部翻转
        // (如果 i < 0，说明整体翻转；否则就是重置后缀)
        // 使用 std::reverse，给它传入正确的起始和结束迭代器！
        reverse(nums.begin()+i+1,nums.end());
    }
};