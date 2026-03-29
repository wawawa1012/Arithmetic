#include <iostream>
#include <vector>
#include <algorithm> // 你可能会用到 max() 函数
#include <climits> // 引入 INT_MIN
using namespace std;

//递归实现
/*class Solution {
private:
    int findMax(vector<int>& nums,int left,int right)
    {
        //递归终点
        if (left==right) return nums[left];
        //分
        int mid=(right-left)/2+left;
        //治
        int rightMax=findMax(nums,mid+1,right);
        int leftMax=findMax(nums,left,mid);
        //中间向左向右延伸找跨越中线的最大值
        int current_sum=0,left_part_max=INT_MIN,right_part_max=INT_MIN;
        for (int cur=mid;cur>=left;cur--)
        {
            current_sum+=nums[cur];
            left_part_max=max(left_part_max,current_sum);
        }
        current_sum=0;
        for (int cur=mid+1;cur<=right;cur++)
        {
            current_sum+=nums[cur];
            right_part_max=max(right_part_max,current_sum);
        }
        int crossMax = left_part_max + right_part_max;

        // 4. 经理做决断：返回左、右、跨界 三者中的最大值！
        // C++ 的 max 只能两两比较，所以要嵌套一下
        return max(crossMax, max(leftMax, rightMax));
    }
public:
    int maxSubArray(vector<int>& nums)
    {
        return findMax(nums, 0, nums.size() - 1);
    }
};*/

//DP实现
class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> dp(n,INT_MIN);
        //元素的含义是前i个数字最大和
        dp[0]=nums[0];
        int res=dp[0];
        for (int i=1;i<n;i++)
        {
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            res=max(res,dp[i]);
        }
        return res;
    }
};