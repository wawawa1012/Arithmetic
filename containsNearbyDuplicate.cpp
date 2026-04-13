//
// Created by A on 2026/4/13.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (int i=0;i<nums.size();i++)
        {
            if (mp.count(nums[i]))
            {
                if (i-k<=mp[nums[i]]) return true;
            }
            mp[nums[i]]=i;
        }
        return false;
    }
};