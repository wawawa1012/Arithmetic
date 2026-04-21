//
// Created by A on 2026/4/21.
//
#include <vector>
using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>>& trust)
    {
        vector<int> scores(n + 1, 0);


        for (auto& relation : trust)
        {
            scores[relation[0]]--;
            scores[relation[1]]++;
        }


        // 遍历所有人，谁的分数等于 n-1，谁就是法官
        for (int i=1;i<=n;i++)
        {
            if (scores[i]==n-1) return i;
        }
        return -1;
    }
};
