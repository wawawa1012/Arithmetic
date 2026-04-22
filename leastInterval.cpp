//
// Created by A on 2026/4/22.
//
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // 1. 统计频率
        vector<int> count(26,0);
        for (char task:tasks)
        {
            count[task-'A']++;
        }
        // 2. 找到最高频率 max_freq
        int max_freq=*max_element(count.begin(),count.end());
        // 3. 统计有多少任务频率等于 max_freq，记为 max_count
        int max_count=0;
        for (int c:count)
        {
            if (c==max_freq) max_count++;
        }
        // 4. 计算公式结果： (max_freq - 1) * (n + 1) + max_count
        int m=max_count+(max_freq-1)*(n+1);
        // 5. 在公式结果和 tasks.size() 之间取最大值返回
        int size=tasks.size();
        return max(size,m);
    }
};