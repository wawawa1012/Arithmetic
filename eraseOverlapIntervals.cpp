//
// Created by A on 2026/4/7.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size()==1) return 0;
        int count=0;
        //预排序（第二个元素大小）
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a, const vector<int>& b)
        {
            return a[1]<b[1];
        });
        int curr_end=intervals[0][1];
        //逻辑就是为后面的会议预留最长时间（贪心）
        for (int i=1;i<intervals.size();i++)
        {
            if (intervals[i][0]<curr_end)
                // 新会议的起点比我当前会议的终点还要早，冲突了！
                    // 因为我已经排好序，当前会议是最早结束的，所以必须砍掉这个新会议。
                        count++;
            else curr_end=intervals[i][1];
        }
        return count;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> i1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << "测试 1 (预期 1): " << sol.eraseOverlapIntervals(i1) << endl;

    vector<vector<int>> i2 = {{1, 2}, {1, 2}, {1, 2}};
    cout << "测试 2 (预期 2): " << sol.eraseOverlapIntervals(i2) << endl;

    vector<vector<int>> i3 = {{1, 2}, {2, 3}};
    cout << "测试 3 (预期 0): " << sol.eraseOverlapIntervals(i3) << endl;

    return 0;
}