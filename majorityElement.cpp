//
// Created by A on 2026/3/16.
//
#include <vector>
using namespace std;
class Solution {
private:
    int findMajority(vector<int>& nums,int left,int right)
    {
        //边界情况
        if (left==right) return nums[right];
        //divide
        int mid=left+(right-left)/2;
        //conquer
        int left_majority=findMajority(nums,left,mid);
        int right_majority=findMajority(nums,mid+1,right);
        //比较左右两边究竟谁更多
        //1.相等说明这个元素在左右都最多，直接返回最多元素
        if (left_majority==right_majority) return left_majority;
        //2.不相等则比较哪个更多,O(N)遍历
        int l_num=0,r_num=0;
        for (int i=left;i<=right;i++)
        {
            if (nums[i]==left_majority) l_num++;
            if (nums[i]==right_majority) r_num++;
        }
        return l_num>r_num?left_majority:right_majority;
    }
public:
    int majorityElement(vector<int>& nums) {
       return  findMajority(nums,0,nums.size()-1);
    }
};