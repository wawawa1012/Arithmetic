//
// Created by A on 2026/3/13.
//
//从start_index开始选，只能选下标>=start_index的
//dfs需要传入start_index，当前的target，目标数组
#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    void dfs(vector<int>& candidates, int target,int start_index,vector<int>& path,vector<vector<int>>& res)
    {
        //结束条件
        if (target==0)
        {
            res.push_back(path);
            return;
        }
        //失败直接返回
        if (target<0) return;
        for (int i=start_index;i<candidates.size();i++)
        {
            path.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],i,path,res);//派克隆人去，自己休眠
            path.pop_back();//回溯
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(candidates,target,0,path,res);
        return res;
    }
};