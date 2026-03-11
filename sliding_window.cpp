//
// Created by A on 2026/3/11.
//
#include <unordered_set>
#include <vector>
#include <algorithm> // 为了使用 max()
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int sum=0;  //记录总和
        int left=0; //左窗口
        int min_len=INT_MAX;
        for (int right=0;right<nums.size();right++)
        {
            int n=nums[right];
            sum+=n;
            while (sum>=target)
            {
                min_len=min(min_len,right-left+1);//先记录
                sum-=nums[left];//尝试缩小窗口
                left++;
            }
        }
        return min_len == INT_MAX ? 0 : min_len; //防止达不到target的情况
    }
};

