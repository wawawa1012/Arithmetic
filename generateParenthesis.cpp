//
// Created by A on 2026/3/12.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    void dfs(int left,int right,int n,string currentStr,vector<string>& res)
    {
        if (currentStr.size()==2*n)
        {
            res.push_back(currentStr);
            return;
        } //结束条件
        if (left<n)
        {
            dfs(left+1,right,n,currentStr+"(",res);
        }
        if (right<left)
        {
            dfs(left,right+1,n,currentStr+')',res);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(0,0,n,"",res);
        return res;
    }
};