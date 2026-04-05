//
// Created by A on 2026/4/4.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
//字符计数频次法
/*
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> res;
        for (string& str:strs)
        {
            vector<int> count(26,0);//统计每个字符出现的个数
            for (char c:str)
            {
                count[c-'a']++;
            }
            string key;  //map中唯一
            for (int x:count)
            {
                key+=to_string(x)+ "#";
            }
            mp[key].push_back(str);
        }
        for (auto& pair:mp)
        {
            res.push_back(pair.second);
        }
        return res;
    }
};*/

//预排序
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> res;
        for (string& str:strs)
        {
            string key=str;
            sort(key.begin(),key.end());
            mp[key].push_back(str);
        }
        for (auto& pair:mp)
        {
            res.push_back(pair.second);
        }
        return res;
    }
};
int main() {
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> res = sol.groupAnagrams(strs);

    cout << "分组结果:" << endl;
    for (const auto& group : res) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}