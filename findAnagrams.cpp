//
// Created by A on 2026/4/14.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        // 绝对防线：如果主串比模式串还短，直接下班！
        if (s.size() < p.size()) return res;

        // 1. 建立两个 26 位的超级账本
        vector<int> pCount(26, 0);
        vector<int> sCount(26, 0);
        for (char c:p)
        {
            pCount[c-'a']++;
        }
        //初始化sCount
        for (int i=0;i<p.size();i++)
        {
            char c=s[i];
            sCount[c-'a']++;
        }
        if (sCount==pCount) res.push_back(0);
        int index=p.size();
        while (index<s.size())
        {
            sCount[s[index-p.size()]-'a']--;
            sCount[s[index]-'a']++;
            if (pCount==sCount) res.push_back(index-p.size()+1);
            index++;
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> res1 = sol.findAnagrams("cbaebabacd", "abc");
    cout << "测试 1 (预期 0 6): ";
    for (int x : res1) cout << x << " "; cout << endl;

    vector<int> res2 = sol.findAnagrams("abab", "ab");
    cout << "测试 2 (预期 0 1 2): ";
    for (int x : res2) cout << x << " "; cout << endl;

    return 0;
}