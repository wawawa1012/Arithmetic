//
// Created by A on 2026/4/14.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(128,-1); //每个字符出现的最后一次下标
        int left=0,right=0,maxLength = 0;
        while (right<s.size())
        {
            char c=s[right];
            if (dict[c]>=left) left=dict[c]+1;
            dict[c]=right;
            maxLength=max(right-left+1,maxLength);
            right++;
        }
        return maxLength;
    }
};

int main() {
    Solution sol;
    cout << "测试 1 (预期 3): " << sol.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << "测试 2 (预期 1): " << sol.lengthOfLongestSubstring("bbbbb") << endl;
    cout << "测试 3 (预期 3): " << sol.lengthOfLongestSubstring("pwwkew") << endl;
    cout << "测试 4 (预期 2): " << sol.lengthOfLongestSubstring("abba") << endl;
    return 0;
}