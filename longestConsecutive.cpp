//
// Created by A on 2026/4/5.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        unordered_set<int> s;
        int res=0;
        for (int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }
        for (int x:s)
        {
            if (!s.count(x-1))
            {
                int curr=x;
                int len=1;
                while (s.count(curr+1))
                {
                    curr++;
                    len++;
                }
                res=max(res,len);
            }
        }
return res;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << "测试 1 最长连续长度: " << sol.longestConsecutive(nums1) << endl; // 预期 4

    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "测试 2 最长连续长度: " << sol.longestConsecutive(nums2) << endl; // 预期 9

    vector<int> nums3 = {};
    cout << "测试 3 最长连续长度: " << sol.longestConsecutive(nums3) << endl; // 预期 0

    return 0;
}