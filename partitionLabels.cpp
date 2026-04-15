//
// Created by A on 2026/4/15.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // 大老板极其冷酷地撤走了所有提示
        // 1. 记账：每个字母最后出现的坐标
        vector<int> res;
        vector<int> dict(26,-1);
        for (int i=0;i<s.size();i++)
        {
            char c=s[i];
            dict[c-'a']=i;
        }
        // 2. 贪心切割：i 追赶 end，追上了就切一刀
        int start=0,end=0;
        for (int i=0;i<s.size();i++)
        {
            char c=s[i];
            end=max(end,dict[c-'a']);
            if (i==end)
            {
                res.push_back(end-start+1);
                start=end+1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s1 = "ababcbacadefegdehijhklij";
    vector<int> res1 = sol.partitionLabels(s1);
    cout << "测试 1 (预期 9 7 8): ";
    for (int x : res1) cout << x << " "; cout << endl;

    string s2 = "eccbbbbdec";
    vector<int> res2 = sol.partitionLabels(s2);
    cout << "测试 2 (预期 10): ";
    for (int x : res2) cout << x << " "; cout << endl;

    return 0;
}