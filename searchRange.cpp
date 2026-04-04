//
// Created by A on 2026/4/4.
//
#include <iostream>
#include <vector>
//题干要求我nlogn复杂度，且是有序数组，果断使用二分查找
//找target，找到了先存，再左右找
using namespace std;

//二分定位 + 线性扩展
/*class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        if (nums.size()==0) return res;
        int left=0,right=nums.size()-1;
        while (left<=right)
        {
            int mid=left+(right-left)/2;
            if (target==nums[mid])
            {
                int l=left,r=right;
                while (nums[l]<target) l++;
                while (nums[r]>target) r--;
                res[0]=l;res[1]=r;
                break;
            }
            if (target<nums[mid])
            {
                right=mid-1;
            }
            if (target>nums[mid])
            {
                left=mid+1;
            }
        }
        return res;
    }
};*/

//边界偏置的二分查找
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        if (nums.empty()) return res;

        // 第一次空降：寻找左边界 (First Position)
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                res[0] = mid;      // 先记录下来！这可能是一个备选答案！
                right = mid - 1;   // 核心：不要停！极其偏执地向左继续挤压！
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // 如果左边界都没找到，说明数组里根本没有这个数，直接返回 [-1, -1]
        if (res[0] == -1) return res;

        // 第二次空降：寻找右边界 (Last Position)
        left = 0;
        right = nums.size() - 1; // 游标归位，重新开始
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                res[1] = mid;      // 先记录下来！
                left = mid + 1;    // 核心：不要停！极其偏执地向右继续挤压！
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return res;
    }
};
int main() {
    Solution sol;

    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    vector<int> res1 = sol.searchRange(nums1, 8);
    cout << "测试 1: [" << res1[0] << ", " << res1[1] << "]" << endl; // 预期 [3, 4]

    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    vector<int> res2 = sol.searchRange(nums2, 6);
    cout << "测试 2: [" << res2[0] << ", " << res2[1] << "]" << endl; // 预期 [-1, -1]

    vector<int> nums3 = {};
    vector<int> res3 = sol.searchRange(nums3, 0);
    cout << "测试 3: [" << res3[0] << ", " << res3[1] << "]" << endl; // 预期 [-1, -1]

    return 0;
}