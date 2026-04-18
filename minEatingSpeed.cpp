//
// Created by A on 2026/4/18.
//
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // 1. 极其迅速地找到速度的上界 right (piles 里的最大值)
        int left = 1;
        int right =*max_element(piles.begin(),piles.end());

        // 2. 在 [left, right] 速度空间里展开极其冷酷的二分
        while (left < right) {
            int mid = left + (right - left) / 2;

            // 3. 验证函数：拿着 mid 速度，去算一遍总耗时
            long long hours = 0; // 极其致命的细节：总小时数可能爆 int，必须用 long long
            for (int pile : piles) {
                hours+=(pile+mid-1)/mid;
            }

            // 4. 生死判决，压缩空间！
            if (hours <= h) {
                right=mid;
            } else {
                // 吃不完，必须提速！
                left=mid+1;
            }
        }

        // 当 left == right 时，这就是被你极其精准逼近的极限最小速度！
        return left;
    }
};