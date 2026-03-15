//
// Created by A on 2026/3/14.
//
//path存单轮递归的结果，return之前放到所有递归共享的res数组中
#include <vector>
#include <iostream>
using namespace std;
const string letterMap[10]={
    {},{},{"abc"},{"def"},{"ghi"},
    {"jkl"},{"mno"},{"pqrs"},{"tuv"},{"wxyz"}
};

class Solution {
private:
    void dfs(string& digits,int index,string path,vector<string>& res)
    {
        if (index==digits.size())//递归结束条件
        {
            res.push_back(path);
            return;
        }
            int i=digits[index]-'0';
            string str=letterMap[i];
            for (char c:str)
            {
                dfs(digits,index+1,path+c,res);
            }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        dfs(digits,0,"",res);
        return res;
    }
};