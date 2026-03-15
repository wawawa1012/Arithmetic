//
// Created by A on 2026/3/15.
//
//这是一道求所有可行解的题目，可以采用递归思想
//dfs函数需要传入原字符串，一个下标index，一个记录单次递归的string型变量path，一个记录所有结果的res数组
//每段由0-3个数字组成，因此每次递归都是index增加1-3
//还有一个约束是段数，段数只可能为4
//不过在dfs函数的最开始需要先判断（不是数字），直接return掉,起始是0可以在递归阶段判断？我觉得一开始不好判断
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
private:
    void dfs(string& s, int index,int segment, string path, vector<string>& res)
    {
        if (segment == 4) {
            // 且刚好切到了字符串末尾，说明没有剩余字符，完美成功！
            if (index == s.size()) {
                res.push_back(path);
            }
            return; // 无论成败，只要切够4段，当前克隆人立刻死亡
        }
        int num=0;
        for (int i=index;i<s.size()&&i<index+3;i++)//每次1-3个字符
        {
            if (s[index]=='0'&&i>index) break; //0开头的非0数字，如01
            num=num*10+s[i]-'0';
            if (num>255) break;
            string str=s.substr(index,i-index+1);
            string nextPath=path+str+(segment==3?"":".");
            dfs(s,i+1,segment+1,nextPath,res);
        }
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        if (s.size() < 4 || s.size() > 12) return res; //剪枝
        dfs(s, 0, 0,"", res);
        return res;
    }
};
