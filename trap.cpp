//
// Created by A on 2026/4/18.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1;
        int l_max=height[left],r_max=height[right];
        int res=0;
        while (left<right)
        {
            if (l_max<r_max)
            {
                res+=l_max-height[left];
                left++;
                l_max=max(l_max,height[left]);
            }
            else
            {
                res+=r_max-height[right];
                right--;
                r_max=max(r_max,height[right]);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "测试 1 (预期 6): " << sol.trap(height1) << endl;

    vector<int> height2 = {4,2,0,3,2,5};
    cout << "测试 2 (预期 9): " << sol.trap(height2) << endl;

    return 0;
}