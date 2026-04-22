//
// Created by A on 2026/4/22.
//
#include <vector>
#include <numeric> // 为了用 accumulate 求和
#include <algorithm>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        // 1. 初始化，每个人保底 1 颗
        vector<int> candies(n, 1);

        // 2. 左向右扫：只要我比左边强，我就比左边多拿一颗
        for (int i=1;i<n;i++)
        {
            if (ratings[i-1]<ratings[i]) candies[i]=candies[i-1]+1;
        }

        // 3. 右向左扫：只要我比右边强，我要保持我当前和"右边+1"中的最大值
        for (int i=n-2;i>=0;i--)
        {
            if (ratings[i]>ratings[i+1])  candies[i]=max(candies[i+1]+1,candies[i]);
        }

        // 4. 求和返回
        return accumulate(candies.begin(), candies.end(), 0);
    }
};