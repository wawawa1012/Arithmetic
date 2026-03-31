//
// Created by A on 2026/3/30.
//
#include <iostream>
#include <vector>
#include <algorithm> // 你的雷达告诉你，需不需要用到它？

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        int n=intervals.size();
        vector<vector<int>> res;
        if (n==0) return res;
        //按键的大小排序
        sort(intervals.begin(),intervals.end());

        res.push_back(intervals[0]);
        for (int i=1;i<n;i++)
        {
            if (intervals[i].front()<=res.back()[1])//有重叠
            {
                res.back()[1]=max(res.back()[1],intervals[i].back());
            }
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> res = sol.merge(intervals);

    cout << "合并后的会议时间轴：" << endl;
    for (const auto& interval : res) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl; // 预期输出: [1, 6] [8, 10] [15, 18]

    return 0;
}