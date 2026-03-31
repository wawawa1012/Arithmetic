//
// Created by A on 2026/3/31.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,0);
        vector<int> L(n,1);
        vector<int> R(n,1);
        for (int i=1;i<n;i++)
        {
            L[i]=L[i-1]*nums[i-1];
            R[n-i-1]=R[n-i]*nums[n-i];
        }
        for (int i=0;i<n;i++)
        {
            res[i]=L[i]*R[i];
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> res = sol.productExceptSelf(nums);

    cout << "除自身以外的乘积数组：" << endl;
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl; // 预期输出: 24 12 8 6

    return 0;
}