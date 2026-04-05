#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int currSum=0,res=0;
        for (int i=0;i<nums.size();i++)
        {
            currSum+=nums[i];
            // mp.count(key) 会在 O(1) 时间内告诉你这个 key 存不存在
            if (mp.count(currSum - k)) {
                res += mp[currSum - k]; // 存在，就直接把次数加上去！
            }
            mp[currSum]+=1;
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {1, 1, 1};
    cout << "测试 1 (预期 2): " << sol.subarraySum(nums1, 2) << endl; 
    
    vector<int> nums2 = {1, 2, 3};
    cout << "测试 2 (预期 2): " << sol.subarraySum(nums2, 3) << endl; 
    
    vector<int> nums3 = {1, -1, 0};
    cout << "测试 3 (预期 3): " << sol.subarraySum(nums3, 0) << endl; 

    return 0;
}