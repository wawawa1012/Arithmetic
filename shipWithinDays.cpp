//
// Created by A on 2026/4/18.
//
#include <algorithm>
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left=*max_element(weights.begin(),weights.end());
        int right=0;
        for (int weight:weights) right+=weight;
        while (left<right)
        {
            int mid=left+(right-left)/2;
            int need_days = 1; // 极其致命的细节：第一天已经开始了！
            int current_weight = 0; // 今天船上已经装了多重？
            for (int weight:weights)
            {
                if (current_weight+weight>mid)
                {
                    need_days++;
                    current_weight=0;
                }
                current_weight+=weight;
            }
            if (need_days<=days)
            {
                right=mid;
            }
            else left=mid+1;
        }
        return left;
    }
};