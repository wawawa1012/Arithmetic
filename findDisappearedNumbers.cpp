//
// Created by A on 2026/4/5.
//
#include <iostream>
#include <vector>
#include <cmath> // 也许你需要极其冷酷的数学手段？

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n=nums.size();
        for (int i=0;i<n;i++)
        {
            int curr=abs(nums[i]);
            if (nums[curr-1]>0) nums[curr-1]=-nums[curr-1];
        }
        for (int i=0;i<n;i++)
        {
            if (nums[i]>0) res.push_back(i+1);
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> res1 = sol.findDisappearedNumbers(nums1);
    cout << "测试 1 失踪名单: ";
    for(int x : res1) cout << x << " ";
    cout << endl; // 预期: 5 6

    vector<int> nums2 = {1, 1};
    vector<int> res2 = sol.findDisappearedNumbers(nums2);
    cout << "测试 2 失踪名单: ";
    for(int x : res2) cout << x << " ";
    cout << endl; // 预期: 2

    return 0;
}