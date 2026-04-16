//
// Created by A on 2026/4/16.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // 初始状态：利润为0，
        int max_profit = 0;
        for (int i=0;i<n-1;i++)
        {
           if (prices[i]<prices[i+1]) max_profit+=prices[i+1]-prices[i];
        }
        return max_profit;
    }
};