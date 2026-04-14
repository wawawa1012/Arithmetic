//
// Created by A on 2026/4/14.
//
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> frequent(26,0);
        int left=0,right=0,maxLength=0;
        while (right<s.size())
        {
            char c=s[right];
            frequent[c-'A']++;
            int maxCount=*max_element(frequent.begin(),frequent.end());//当前窗口最大频率元素
            int currLength=right-left+1;
            int less=currLength-maxCount;//杂鱼元素
            while ((right - left + 1) - *max_element(frequent.begin(), frequent.end()) > k)
            {
                frequent[s[left]-'A']--;
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
    }
};